/*
  ==============================================================================

    FeatureExtractor.h
    Created: 11 Mar 2014 10:43:43pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef FEATUREEXTRACTOR_H_INCLUDED
#define FEATUREEXTRACTOR_H_INCLUDED

#include "JuceHeader.h"

#include "../Features/ComputeBWFeatures.h"
#include "../Features/ComputeCSpecFeatures.h"
#include "../Features/ComputePitchFeatures.h"
#include "../Features/ComputeMFCCFeatures.h"
#include "../Features/ComputeOnsetFeatures.h"

class FeatureExtractor
{

public:
		
	FeatureExtractor(float* magnitudeSpectrum_, int numRows_,int numCols_, File& audioFile_,emxArray_real_T* denoisedAudio, int denoisedAudioLength, emxArray_real_T* T)
	//FeatureExtractor(ScopedPointer<emxArray_real_T> denoisedSpec, File& audioFile_,ScopedPointer<emxArray_real_T> denoisedAudio)
	{
		
		numRows = numRows_;
		numCols = numCols_;
		
		magSpec = new float[numRows*numCols];
		// Deep copy spectrum
		for(int i=0;i<numRows*numCols;i++)
		{
			magSpec[i] = magnitudeSpectrum_[i];
		}
		
		//computeSpectralFeatures = new ComputeSpectralFeatures();
		

		blockSize = 1024;
		hopSize = 512;
		audioFile = audioFile_;

		//denoisedSpecEMX = denoisedSpec;


		computeMFCCFeatures = new ComputeMFCCFeatures(denoisedAudio,16000, denoisedAudioLength);
		numMFCCFeatures = computeMFCCFeatures->getNumFeatures();
		mfccFeatures = new float[numMFCCFeatures];

		computeBWFeatures = new ComputeBWFeatures(magSpec,numRows,numCols);
		numBWFeatures = computeBWFeatures->getNumFeatures();
		bwFeatures = new float[numBWFeatures];
		
		computeCSpecFeatures = new ComputeCSpecFeatures(magSpec,numRows,numCols);
		numCSpectralFeatures = computeCSpecFeatures->getNumFeatures();
		spectralFeatures = new float[numCSpectralFeatures];

		computeOnsetFeatures = new ComputeOnsetFeatures(magSpec,numRows,numCols,T);
		numOnsetFeatures = computeOnsetFeatures->getNumFeatures();
		onsetFeatures = new float[numOnsetFeatures];
		
		onsets = new bool[numCols];
		
		computePitchFeatures = new ComputePitchFeatures(T,numCols);
		numPitchFeatures = computePitchFeatures->getNumFeatures();
		pitchFeatures = new float[numPitchFeatures];

		numFeatures = numMFCCFeatures+numBWFeatures+numCSpectralFeatures + numPitchFeatures + numOnsetFeatures;
		//numFeatures  = 150;
		featureVector = new float[numFeatures];

		// For scaling
		featureMin = new float[numFeatures];
		featureRanges = new float[numFeatures];

		
	}

	~FeatureExtractor()
	{
		computeCSpecFeatures = nullptr;
		computeBWFeatures = nullptr;
		computeMFCCFeatures = nullptr;
		computeOnsetFeatures = nullptr;
		computePitchFeatures = nullptr;
		
		deleteIfAllocated(featureMin);
		deleteIfAllocated(featureRanges);
		deleteIfAllocated(mfccFeatures);
		deleteIfAllocated(bwFeatures);
		deleteIfAllocated(spectralFeatures);
		deleteIfAllocated(featureVector);
		deleteIfAllocated(magSpec);
		deleteIfAllocated(onsetFeatures);
		deleteIfAllocated(pitchFeatures);

		if(onsets!=NULL)
		{
			delete onsets;
			onsets = NULL;
		}

	}

	void deleteIfAllocated(float* pointerToBeDeleted)
	{
		if(pointerToBeDeleted!=NULL)
		{
			delete pointerToBeDeleted;
			pointerToBeDeleted = NULL;
		}
	}

	// Call to set the number of features and subfeatures to extract
	//void setSpectralFeatureExtractionProperties(int featuresToCompute = 1023,int subFeaturesToCompute = 15)
	//{
	//	computeSpectralFeatures->setSpectralFeatureExtractionProps(numRows,featuresToCompute,subFeaturesToCompute);
	//	
	//	numSpectralFeatures = computeSpectralFeatures->getNumFeatures();
	//	numSpectralSubFeatures = computeSpectralFeatures->getNumSubFeatures();
	//}


	void extractFeatures()
	{
		
		// First compute BW features
		computeBWFeatures->extractFeatures();
		computeBWFeatures->returnFeatures(bwFeatures);
		
		computeCSpecFeatures->extractFeatures();
		computeCSpecFeatures->returnFeatures(spectralFeatures);

		// Compute mfcc and derivative features
		computeMFCCFeatures->extractMFCCFeatures();
		computeMFCCFeatures->returnMFCCFeatures(mfccFeatures);

		computeOnsetFeatures->extractFeatures();
		computeOnsetFeatures->returnFeatures(onsetFeatures);
		computeOnsetFeatures->returnOnsets(onsets);


		computePitchFeatures->extractFeatures(audioFile,magSpec,numRows,numCols,onsets);
		computePitchFeatures->returnFeatures(pitchFeatures);
		
		// Copy them all to the feature vector
		//for(int i=0;i<numBWFeatures;i++)
		//{
		//	featureVector[i] = bwFeatures[i];
		//}

		//for(int i=0;i<numCSpectralFeatures;i++)
		//{
		//	featureVector[i+numBWFeatures] = spectralFeatures[i];
		//}

		//for(int i=0;i<numMFCCFeatures;i++)
		//{
		//	featureVector[i+numBWFeatures+numCSpectralFeatures] = mfccFeatures[i];
		//}
		//
		//for(int i=0; i<numOnsetFeatures;i++)
		//{
		//	featureVector[i+numBWFeatures+numCSpectralFeatures+numMFCCFeatures] = onsetFeatures[i];
		//}

		//for(int i=0; i<numPitchFeatures;i++)
		//{
		//	featureVector[i+numBWFeatures+numCSpectralFeatures+numMFCCFeatures+numOnsetFeatures] = pitchFeatures[i];
		//}


		// TODO - Check if it is all valid
		// Scale after you have the full feature vector
//		scaleFeatureVector(featureVector);
		
		//float *tempData = new float[513];
		//float* featureVec = new float[numSpectralFeatures*numSpectralSubFeatures];

		//// Extract columns of magnitude spectrum
		//for(int i=0;i<numCols;i++)
		//{
		//	for(int j=0;j<numRows;j++)
		//	{
		//		tempData[j] = magSpec[i*numRows+j];
		//	}
		//	// Compute features
		//	computeSpectralFeatures->computeFeatures(tempData);

		//}

		// Get resulting subfeatures - Move this to a return featureVector function

		//computeSpectralFeatures->getSubFeatureVector(featureVec,numSpectralFeatures*numSpectralSubFeatures);

		
//		computePitchFeatures->computeFeatures(audioFile);

		//delete featureVec;
		//featureVec = nullptr;
		//
		//delete tempData;
		//tempData=nullptr;
	}

	void scaleFeatureVector(float* featureVector_)
	{
		// Replace all undefined

		for(int i=0; i<numFeatures; i++)
		{
			if((featureVector_[i]*0) !=0)	// Check for nan or inf
			{
				featureVector_[i] = 0;
			}

		}

		
		// Uses the saved text files min and range to scale each of the features in the featureVector_
		//File thiss = File::getCurrentWorkingDirectory();
		File minFile("C:\\Users\\Aneesh\\Documents\\GitHub\\birdID\\birdID\\Source\\LibSVM\\min.txt");
		File rangeFile("C:\\Users\\Aneesh\\Documents\\GitHub\\birdID\\birdID\\Source\\LibSVM\\range.txt");
		StringArray minLines,rangeLines;
		if(minFile.existsAsFile() && rangeFile.existsAsFile())
		{
			minFile.readLines(minLines);
			rangeFile.readLines(rangeLines);
			for(int i=0;i<numFeatures;i++)
			{
				featureMin[i] = minLines[i].getFloatValue();
				featureRanges[i] = rangeLines[i].getFloatValue();

			}

		}
		else
		{
			DBG("Min and Range files not present!");
		}

		// Perform the scaling
		for(int i=0;i<numFeatures;i++)
		{
			featureVector_[i] = featureVector_[i] - featureMin[i];
			featureVector_[i] = featureVector_[i]/featureRanges[i];
		}

	}

	void returnFeatureVector(float* featureVector_)
	{
		// Deep copy pointers
		for(int i=0;i<numFeatures;i++)
		{
			featureVector_[i] = featureVector[i];
		}

	}

	int getNumFeatures()
	{
		return numFeatures;
	}


private:
		
	//ScopedPointer<ComputeSpectralFeatures> computeSpectralFeatures;
	ScopedPointer<ComputeCSpecFeatures> computeCSpecFeatures;
	ScopedPointer<ComputePitchFeatures> computePitchFeatures;
	ScopedPointer<ComputeMFCCFeatures> computeMFCCFeatures;
	ScopedPointer<ComputeBWFeatures> computeBWFeatures;
	ScopedPointer<ComputeOnsetFeatures> computeOnsetFeatures;


	// Used for features
	float* mfccFeatures;
	float* bwFeatures;
	float* spectralFeatures;
	float* onsetFeatures;
	float* pitchFeatures;

	float* featureVector;
	float* featureMin;
	float* featureRanges;
	float *magSpec;

	bool* onsets;
	
	// Used for Pitch features
	int blockSize;	
	int hopSize;

	int numRows, numCols;

	//int numSpectralFeatures;
	//int numSpectralSubFeatures;
	int numCSpectralFeatures;
	int numMFCCFeatures;
	int numBWFeatures;
	int numFeatures;
	int numOnsetFeatures;
	int numPitchFeatures;

	File audioFile;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
