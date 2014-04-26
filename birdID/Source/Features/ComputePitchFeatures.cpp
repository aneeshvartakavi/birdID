/*
  ==============================================================================

    ComputePitchFeatures.cpp
    Created: 25 Mar 2014 7:23:04pm
    Author:  Aneesh

  ==============================================================================
*/

#include "ComputePitchFeatures.h"

ComputePitchFeatures::ComputePitchFeatures(emxArray_real_T* time_, int numCols)
{
	numFeatures = 10;
	
	blockSize = 1024;
	hopSize = 512;
	yin = new Yin();
	// Call initialize when file is read
	// Basic file formats
	formatManager.registerBasicFormats();
	rightData = NULL;

	// Deep copy time

	time = emxCreate_real_T(1,numCols);
	for(int i=0;i<numCols;i++)
	{
		time->data[i] = time_->data[i];
	}
	
	features = new real_T[numFeatures];

	pitch = NULL;

}

ComputePitchFeatures::~ComputePitchFeatures()
{
	//delete yin;
	yin = NULL;
	if(rightData!=NULL)
	{
		delete rightData;
	}
	rightData = NULL;

	//delete leftData;
	leftData=NULL;
	if(pitch!=NULL)
	{
		delete pitch;
		pitch = NULL;
	}

	emxDestroyArray_real_T(denoisedSpec);
	emxDestroyArray_real_T(time);
	emxDestroyArray_real_T(pitchEMX);
	emxDestroyArray_boolean_T(onsets);

	delete features;
	features = NULL;
	
}


void ComputePitchFeatures::extractFeatures(File& audioFile, float* magnitudeSpec, int numRows, int numCols,bool* onsets_)
{
	// Deep copy denoisedSpec
	denoisedSpec = emxCreate_real_T(numRows,numCols);
		
	for (int i=0;i<numRows*numCols;i++)
	{
		denoisedSpec->data[i] = static_cast<real_T>(magnitudeSpec[i]);
	}
	
	// Deep copy onsets
	onsets = emxCreate_boolean_T(1,numCols);
	for(int i=0;i<numCols;i++)
	{
		onsets->data[i] = static_cast<boolean_T>(onsets_[i]);
	}



	// Compute pitch
	computePitch(audioFile);
	
	// Copy pitch
	pitchEMX = emxCreate_real_T(1,static_cast<int>(numBlocks));

	for(int i=0;i<numBlocks;i++)
	{
		pitchEMX->data[i] = pitch[i];
	}

	
	// Threshold it
	computePitchFeatures_exp_initialize();
	computePitchFeatures_exp(pitchEMX,denoisedSpec,onsets,time,static_cast<real_T>(sampleRate),static_cast<real_T>(numSamples),features);


	//processPitch(100,8000);
	// Compute the derivative
	//computeFirstDerivative();
	
}

void ComputePitchFeatures::computePitch(File& audioFile)
{
	ScopedPointer<AudioFormatReader> fileReader = formatManager.createReaderFor(audioFile);
		int numChannels = fileReader->numChannels;
		sampleRate = static_cast<int>(fileReader->sampleRate);
		numSamples = fileReader->lengthInSamples;

		numBlocks = numSamples%hopSize;
		
		// Accounting for non-integer multiples of blockSize
		numBlocks = (numSamples+numBlocks)/hopSize;
		numBlocks+=1;

		ScopedPointer<AudioSampleBuffer> sampleBuffer = new AudioSampleBuffer(1,static_cast<int>(numSamples));
		// Just in case
		sampleBuffer->clear();
		// Initialize Yin
		yin->initialize(static_cast<float>(sampleRate),blockSize);

		pitch = new float[static_cast<int>(numBlocks)];

		for (int j=0;j<numBlocks;j++)
		{
			fileReader->read(sampleBuffer,0,blockSize,j*hopSize,true,false);

			leftData = sampleBuffer->getSampleData(0);
			
			if(numChannels==2)
			{
				rightData = sampleBuffer->getSampleData(1);
				
				// Convert from stereo to mono
				for(int i=0; i<blockSize;i++)
				{
					leftData[i] = (leftData[i] + rightData[i])/2;
				}

			}

			pitch[j] = yin->getPitch(leftData);
		
		}
}

void ComputePitchFeatures::returnFeatures(float* featureVector)
{
		
	for(int i=0;i<numFeatures;i++)
	{
		featureVector[i] = static_cast<float>(features[i]);
	}
		

}

int ComputePitchFeatures::getNumFeatures()
{
	return numFeatures;
}

//void ComputePitchFeatures::computeFirstDerivative()
//{
//	for(int i=1;i<numBlocks;i++)
//	{
//		pitch[i] = pitch[i]-pitch[i-1];
//	}
//	pitch[0] = 0.f;
//
//}

//void ComputePitchFeatures::processPitch(int lowF0,int highF0)
//{
//	for(int i=1;i<numBlocks;i++)
//	{
//		if(pitch[i]<lowF0 || pitch[i]>highF0)
//		{
//			pitch[i] = 0;
//		}
//	}
//}
