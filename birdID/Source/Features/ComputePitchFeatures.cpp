/*
  ==============================================================================

    ComputePitchFeatures.cpp
    Created: 25 Mar 2014 7:23:04pm
    Author:  Aneesh

  ==============================================================================
*/

#include "ComputePitchFeatures.h"

ComputePitchFeatures::ComputePitchFeatures(int blockSize_,int hopSize_)
{
	blockSize = blockSize_;
	hopSize = hopSize_;
	yin = new Yin();
	// Call initialize when file is read
	// Basic file formats
	formatManager.registerBasicFormats();
	rightData = NULL;
}

ComputePitchFeatures::~ComputePitchFeatures()
{
	yin = nullptr;
	if(rightData!=NULL)
	{
		delete rightData;
	}
	rightData = NULL;

	//delete leftData;
	leftData=NULL;

	delete pitch;
	pitch = NULL;
}

void ComputePitchFeatures::computeFeatures(File& audioFile)
{
	// Compute pitch
	computePitch(audioFile);
	// Threshold it
	processPitch(100,8000);
	// Compute the derivative
	computeFirstDerivative();
	
}

void ComputePitchFeatures::computePitch(File& audioFile)
{
	ScopedPointer<AudioFormatReader> fileReader = formatManager.createReaderFor(audioFile);
		int numChannels = fileReader->numChannels;
		int sampleRate = static_cast<int>(fileReader->sampleRate);
		int64 numSamples = fileReader->lengthInSamples;

		numBlocks = numSamples%hopSize;
		
		// Accounting for non-integer multiples of blockSize
		numBlocks = (numSamples+numBlocks)/hopSize;
		numBlocks+=1;

		ScopedPointer<AudioSampleBuffer> sampleBuffer = new AudioSampleBuffer(1,numSamples);
		// Just in case
		sampleBuffer->clear();
		// Initialize Yin
		yin->initialize(sampleRate,blockSize);

		pitch = new float[numBlocks];

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


void ComputePitchFeatures::computeFirstDerivative()
{
	for(int i=1;i<numBlocks;i++)
	{
		pitch[i] = pitch[i]-pitch[i-1];
	}
	pitch[0] = 0.f;

}

void ComputePitchFeatures::processPitch(int lowF0,int highF0)
{
	for(int i=1;i<numBlocks;i++)
	{
		if(pitch[i]<lowF0 || pitch[i]>highF0)
		{
			pitch[i] = 0;
		}
	}
}
