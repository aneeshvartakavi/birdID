/*
  ==============================================================================

    ComputeSpectralFeatures.cpp
    Created: 20 Mar 2014 12:15:46am
    Author:  Aneesh

  ==============================================================================
*/

#include "ComputeSpectralFeatures.h"
#include <math.h>
#include <cmath>
#include <limits>

ComputeSpectralFeatures::ComputeSpectralFeatures()
{
	/*numIterMean = 0;
	numIterStd = 0;
	numIterdMean = 0;
	numIterdStd = 0;*/
}

ComputeSpectralFeatures::~ComputeSpectralFeatures()
{
	delete featureVector;
	featureVector = nullptr;
	
	delete subFeatureVector;
	subFeatureVector = nullptr;

	delete lastFeatureVector;
	lastFeatureVector = nullptr;
	
	delete lastFrame;
	lastFrame = nullptr;
	
	delete frame;
	frameSquared = nullptr;
	
	delete frameSquared;
	frame = nullptr;
	
	
	if(meanFlag)
	{
		delete oldMean;
		delete newMean;
		oldMean = nullptr;
		newMean = nullptr;
	}
	if(stdFlag)
	{
		delete oldStd;
		delete newStd;
		oldStd = nullptr;
		newStd = nullptr;
	}

	if(dMeanFlag)
	{
		delete dOldMean;
		delete dNewMean;
		dOldMean = nullptr;
		dNewMean = nullptr;
	}
	
	if(dStdFlag)
	{
		delete dOldStd;
		delete dNewStd;
		dOldStd = nullptr;
		dNewStd = nullptr;
	}
}


void ComputeSpectralFeatures::setSpectralFeatureExtractionProps(int stftFrameLength,int featureflags, int subFeatureFlags)
{
	if(featureflags<1024 && subFeatureFlags<16 && stftFrameLength>0)
	{
		// Simple initialization
		firstRun = true;
		numIter = 0;
		
		// Allocating memory for frames and temporary variables
		numElementsInFrame = stftFrameLength;
		frame = new float[numElementsInFrame];
		frameSquared = new float [numElementsInFrame];
		lastFrame = new float [numElementsInFrame];

		// Setting flags for features
		featuresToCompute = featureflags;
		numFeatures = getSetBitCount(featureflags);
		// Setting flags for subfeatures
		subFeaturesToCompute = subFeatureFlags;
		numSubFeatures = getSetBitCount(subFeatureFlags);
		
		//Allocating
		featureVector = new float[numFeatures];
		lastFeatureVector = new float[numFeatures];
		
		// Allocating memory for running mean and std
		subFeatureVector = new float[numFeatures*numSubFeatures];

		// Set flags and allocate memory for subfeatures
		for(int j=0;j<numSubFeatures;j++)
		{
			if((subFeaturesToCompute & spectralSubFeatures::mean) == spectralSubFeatures::mean)
			{
				meanFlag = true;
				oldMean = new float[numFeatures];
				newMean = new float[numFeatures];
				subFeaturesToCompute = subFeaturesToCompute & ~spectralSubFeatures::mean;
			}

			else if((subFeaturesToCompute & spectralSubFeatures::std) == spectralSubFeatures::std)
			{
				stdFlag = true;
				oldStd = new float[numFeatures];
				newStd = new float[numFeatures];
				subFeaturesToCompute = subFeaturesToCompute & ~spectralSubFeatures::std;
			}

			else if((subFeaturesToCompute & spectralSubFeatures::meanFirstDerivative) == spectralSubFeatures::meanFirstDerivative)
			{
				dMeanFlag = true;
				dOldMean = new float[numFeatures];
				dOldStd = new float[numFeatures];
				subFeaturesToCompute = subFeaturesToCompute & ~spectralSubFeatures::meanFirstDerivative;
			}

			else if((subFeaturesToCompute & spectralSubFeatures::stdFirstDerivative) == spectralSubFeatures::stdFirstDerivative)
			{
				dStdFlag = true;
				dNewMean = new float[numFeatures];
				dNewStd = new float[numFeatures];
				subFeaturesToCompute = subFeaturesToCompute & ~spectralSubFeatures::stdFirstDerivative;
			}
			else
			{
				//DBG("Incorrect flag!");
			}

			//return numFeatures*numSubFeatures;
		}
	}
	else
	{
		// DBG("Flags over the limit set");
	}


}


void ComputeSpectralFeatures::getFeatureVector(float* computedFeatureVector, const int length)
{
	if(length==numFeatures)
	{
		// Deep copy feature vector
		copyFrame(featureVector,computedFeatureVector,numFeatures);
	}
	else
	{
		//DBG("Incorrect vector length");
	}
		
}

void ComputeSpectralFeatures::getSubFeatureVector(float* computedSubFeatureVector, const int length)
{
	if(length==numSubFeatures*numFeatures)
	{
		int offset=0;

		// Fill the vector with the subfeatures
		for(int w=0;w<numFeatures;w++)
		{
			offset = 0;

			if(meanFlag)
			{
				if(numIter>0)
				{
					subFeatureVector[(offset*numFeatures)+w] = newMean[w];
				}
				else
				{
					subFeatureVector[(offset*numFeatures)+w] = 0;
				}
				offset++;
			}
			
			if(stdFlag)
			{
				if(numIter>1)
				{
					subFeatureVector[(offset*numFeatures)+w] = sqrtf(newStd[w]/static_cast<float>((numIter-1)));
				}
				else
				{
					subFeatureVector[(offset*numFeatures)+w] = 0;
				}
				offset++;
			}

			if(dMeanFlag)
			{
				if(numIter>0)
				{
					subFeatureVector[(offset*numFeatures)+w] = dNewMean[w];
				}
				else
				{
					subFeatureVector[(offset*numFeatures)+w] = 0;
				}
				offset++;
			}

			if(dStdFlag)
			{
				if(numIter>1)
				{
					subFeatureVector[(offset*numFeatures)+w] = sqrtf(dNewStd[w]/static_cast<float>((numIter-1)));
				}
				else
				{
					subFeatureVector[(offset*numFeatures)+w] = 0;
				}
				offset++;
			}
		}

		
		// Deep copy feature vector
		copyFrame(subFeatureVector,computedSubFeatureVector,numFeatures*numSubFeatures);
	}
	else
	{
		//DBG("Incorrect vector length");
	}

	
}

void ComputeSpectralFeatures::computeFeatures(const float* stftFrame)
{
	// Allocate feature vector in setFeaturesToComputeFunction
	
	//Store the frame
	copyFrame(stftFrame,frame,numElementsInFrame);
	// Take the absolute value just in case
	absFrame(frame,numElementsInFrame);
	// Compute temporary variables
		
	// Frame sum
	frameSum = sumFrame(frame,numElementsInFrame);
	// Squared frame
	squareFrame(frame,numElementsInFrame,frameSquared);
	// Squared frame sum
	squaredFrameSum = sumFrame(frameSquared,numElementsInFrame);
	// Store last frame for flux
	
	int tempFeaturesToCompute = featuresToCompute;
		
	// Check flags and call feature functions
	for(int j=0;j<numFeatures;j++)
	{
		if((tempFeaturesToCompute & spectralFeatures::spectralCentroid) == spectralFeatures::spectralCentroid)
		{
			featureVector[j] = featureSpectralCentroid();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralCentroid;
		}
				
		else if((tempFeaturesToCompute & spectralFeatures::spectralCrest) == spectralFeatures::spectralCrest)
		{
			featureVector[j] = featureSpectralCrest();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralCrest;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralDecrease) == spectralFeatures::spectralDecrease)
		{
			featureVector[j] = featureSpectralDecrease();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralDecrease;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralFlatness) == spectralFeatures::spectralFlatness)
		{
			featureVector[j] = featureSpectralFlatness();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralFlatness;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralFlux) == spectralFeatures::spectralFlux)
		{
			featureVector[j] = featureSpectralFlux();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralFlux;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralKurtosis) == spectralFeatures::spectralKurtosis)
		{
			featureVector[j] = featureSpectralKurtosis();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralKurtosis;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralRolloff) == spectralFeatures::spectralRolloff)
		{
			featureVector[j] = featureSpectralRolloff();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralRolloff;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralSkewness) == spectralFeatures::spectralSkewness)
		{
			featureVector[j] = featureSpectralSkewness();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralSkewness;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralSlope) == spectralFeatures::spectralSlope)
		{
			featureVector[j] = featureSpectralSlope();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralSlope;
		}

		else if((tempFeaturesToCompute & spectralFeatures::spectralSpread) == spectralFeatures::spectralSpread)
		{
			featureVector[j] = featureSpectralSpread();
			// Reset the flag
			tempFeaturesToCompute = tempFeaturesToCompute & ~spectralFeatures::spectralSpread;
		}
		else
		{
			// DBG("Incorrect flag!");
			featureVector[j] = 0;
		}

	}
	
	computeRunningStats(featureVector,numFeatures);

	copyFrame(frame,lastFrame, numElementsInFrame);

	if(firstRun)
	{
		firstRun = false;
	}
}

float ComputeSpectralFeatures::featureSpectralCentroid()
{
	float retVal = 0;
	
	if(frameSum!=0)
	{
	
		for(int i=0;i<numElementsInFrame;i++)
		{
			retVal+= static_cast<float>(i)*frameSquared[i];
		}

		retVal/=squaredFrameSum;
	}
	return retVal;
}

float ComputeSpectralFeatures::featureSpectralCrest()
{
	float retVal = 0;
	
	if(frameSum!=0)
	{
		retVal = maxFrame(frame,numElementsInFrame);
	
		retVal /= frameSum;
	}
	
	return retVal;
}

float ComputeSpectralFeatures::featureSpectralDecrease()
{
	float retVal = 0;
	
	if(frameSum!=0)
	{
		for(int i=1;i<numElementsInFrame;i++)
		{
			retVal+= (1.0f/static_cast<float>(i)) * (frame[i]-frame[0]);
		}

		retVal/= frameSum;
	}

	return retVal;

}

float ComputeSpectralFeatures::featureSpectralFlatness()
{
	float retVal = 0;
	
	if(frameSum!=0)
	{
		// Effecient Geometric mean without overflow
		// http://stackoverflow.com/a/19982259
		double mantissa = 1.0;
		long long exponent = 0;
		double invN = 1.0/ static_cast<double>(numElementsInFrame);

		for(int i=0;i<numElementsInFrame;i++)
		{
			int r;
			double f1 = std::frexp(frame[i],&r);
			mantissa*=f1;
			exponent+=r;
		}

		retVal = std::pow( std::numeric_limits<double>::radix,exponent * invN) * std::pow(mantissa,invN);
	}
	//retVal = 1.0f;
	//	for(int i=0;i<numElementsInFrame;i++)
	//	{
	//		retVal*= frame[i];
	//	}
	//	// Taking nth root, Geometric mean complete
	//	retVal = powf(retVal,(1.0f/static_cast<float>(numElementsInFrame)));
	//	// Dividing by sum
	//	retVal/= frameSum;
	//	// Operation complete
	//	retVal *=numElementsInFrame;
	//}

	return retVal;
}

float ComputeSpectralFeatures::featureSpectralFlux()
{
	float retVal = 0;
	if(firstRun)
	{
		copyFrame(frame,lastFrame, numElementsInFrame);
	}

	for(int i=0;i<numElementsInFrame;i++)
	{
		retVal+= pow((frame[i]-lastFrame[i]),2);
	}
	retVal = sqrtf(retVal);

	retVal /= numElementsInFrame;
	
	//copyFrame(frame,lastFrame, numElementsInFrame);

	return retVal;
}

float ComputeSpectralFeatures::featureSpectralKurtosis()
{
	float retVal = 0;
	float frameMean = frameSum/static_cast<float>(numElementsInFrame);
	float frameStd = stdFrame(frame,numElementsInFrame);
	if(frameStd!=0.0f)
	{
		for(int i=0;i<numElementsInFrame;i++)
		{
			retVal+= pow(frame[i]-frameMean,4);
		}

		retVal*=2;
		// TODO - Check normalization here
		retVal/=static_cast<float>(numElementsInFrame);

		retVal/=pow(frameStd,4);

		retVal-=3;
	}
	return retVal;
}

float ComputeSpectralFeatures::featureSpectralRolloff()
{
	float retVal = 0;
	float kappa = 0.85f;

	float thresh = frameSum*kappa;

	for(int i=0;i<numElementsInFrame;i++)
	{
		retVal +=frame[i];
		if(retVal>=thresh)
		{
			retVal = static_cast<float>(i);
			break;
		}

	}

	return retVal;

}

float ComputeSpectralFeatures::featureSpectralSkewness()
{
	float retVal = 0;
	float frameMean = frameSum/static_cast<float>(numElementsInFrame);
	float frameStd = stdFrame(frame,numElementsInFrame);
	
	if(frameStd!=0.0f)
	{
		for(int i=0;i<numElementsInFrame;i++)
		{
			retVal+= pow(frame[i]-frameMean,3);
		}

		retVal*=2;
		// TODO - Check normalization here
		retVal/=static_cast<float>(numElementsInFrame);

		retVal/=pow(frameStd,3);

		
	}
	return retVal;
}

float ComputeSpectralFeatures::featureSpectralSlope()
{
	float retVal = 0;
	float a = 0;
	float b = 0;
	float c = 0;

	for(int i=0;i<numElementsInFrame;i++)
	{
		a += frame[i] * static_cast<float>(i);
		b += static_cast<float>(i);
		c += pow(b,2);
	}

	a*=numElementsInFrame;
	a-=(b*frameSum);

	c = numElementsInFrame*(c-pow(b,2));

	retVal = a/c;

	return retVal;
}

float ComputeSpectralFeatures::featureSpectralSpread()
{
	float retVal = 0;
	
	if(squaredFrameSum!=0.0f)
	{
		float specCentroid = featureSpectralCentroid();
		

		for(int i=0;i<numElementsInFrame;i++)
		{
			retVal+= pow(static_cast<float>(i) - specCentroid,2) * frameSquared[i];
		}
		retVal/=squaredFrameSum;
		
		retVal = sqrtf(retVal);	
	}

	return retVal;
}


float ComputeSpectralFeatures::sumFrame(const float* stftFrame, int numElementsInFrame)
{
	float returnVal = 0.f;

	for(int i=0;i<numElementsInFrame;i++)
	{
		returnVal += stftFrame[i];
	}

	//returnVal /= numElementsInFrame;
	
	return returnVal;

}

float ComputeSpectralFeatures::maxFrame(const float* stftFrame, int numElementsInFrame)
{
	float returnVal = 0;

	for(int i=0;i<numElementsInFrame;i++)
	{
		if(fabsf(stftFrame[i])>returnVal)
		{
			returnVal = fabsf(stftFrame[i]);
		}
	}

	return returnVal;
}

void ComputeSpectralFeatures::absFrame(float* stftFrame, int numElementsInFrame)
{
	
	for(int i=0;i<numElementsInFrame;i++)
	{
		stftFrame[i] = fabsf(stftFrame[i]);
	}

}

void ComputeSpectralFeatures::squareFrame(const float* stftFrame, int numElementsInFrame, float* squaredFrame)
{
	for(int i=0;i<numElementsInFrame;i++)
	{
		squaredFrame[i] = stftFrame[i] * stftFrame[i];
	}
}

float ComputeSpectralFeatures::stdFrame(const float* stftFrame, int numElementsInFrame)
{
	
	float retVal = 0;
	
	float meanVal = frameSum/static_cast<float>(numElementsInFrame);

	for(int i=0;i<numElementsInFrame;i++)
	{
		retVal += pow(stftFrame[i] - meanVal,2);
	}

	retVal/=(numElementsInFrame-1);

	retVal = sqrtf(retVal);

	return retVal;
}


void ComputeSpectralFeatures::copyFrame(const float* sourceFrame, float* destinationFrame, int numElementsInFrame)
{
	for(int i=0;i<numElementsInFrame;i++)
	{
		destinationFrame[i] = sourceFrame[i];
	}

}

int ComputeSpectralFeatures::getSetBitCount(int value)
{
  int iCount = 0;

  //Loop the value while there are still bits
  while (value != 0)
  {
    //Remove the end bit
    value = value & (value - 1);

    iCount++;
  }

   return iCount;
}

void ComputeSpectralFeatures::computeRunningStats(float* vector, int numElements)
{
	numIter++;
	
	for(int w=0; w<numElements ; w++)
	{
		if(numIter==1)
		{
			// If this is the first time, initialize variables
			if(meanFlag)
			{
				oldMean[w] = vector[w];
				newMean[w] = vector[w];
			}
			if(stdFlag)
			{
				oldStd[w] = 0.0f;
				newStd[w] = 0.0f;
			}
			if(dMeanFlag)
			{
				dOldMean[w] = 0.0f;
				dNewMean[w] = 0.0f;
				lastFeatureVector[w] = 0.0f;
			}
			if(dStdFlag)
			{
				dOldStd[w] = 0.0f;
				dNewStd[w] = 0.0f;
				lastFeatureVector[w] = 0.0f;
			}
			
		}

		else
		{
			if(dMeanFlag||dStdFlag)
			{
				// If we need to calculate the derivative, do it here
				lastFeatureVector[w] = vector[w] - lastFeatureVector[w];
			}

			if(meanFlag)
			{
				newMean[w] = oldMean[w] + (vector[w]-oldMean[w])/numIter;
				oldMean[w] = newMean[w];
			}
			if(stdFlag)
			{
				newStd[w] = oldStd[w] + (vector[w]-oldMean[w])*(vector[w]-newMean[w]);
				oldStd[w] = newStd[w];
			}
			if(dMeanFlag)
			{
				dNewMean[w] = dOldMean[w] + (lastFeatureVector[w]-dOldMean[w])/numIter;
				dOldMean[w] = dNewMean[w];
			}
			if(dStdFlag)
			{
				dNewStd[w] = dOldStd[w] + (lastFeatureVector[w]-dOldMean[w])*(lastFeatureVector[w]-dNewMean[w]);
				dOldStd[w] = dNewStd[w];
			}

		}
		

	}
	
	if(dMeanFlag||dStdFlag)
	{
		// Copy current frame into last frame
		copyFrame(vector,lastFeatureVector,numElements);
	}

}
