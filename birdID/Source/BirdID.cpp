/*
  ==============================================================================

    BirdID.cpp
    Created: 20 Mar 2014 12:07:26am
    Author:  Aneesh

  ==============================================================================
*/

#include "BirdID.h"

BirdID::BirdID(int blockSize_, int hopSize_): blockSize(blockSize_),hopSize(hopSize_)
{
	halfBlockSize = (blockSize/2)+1;
	
	// Register basic formats to read
	formatManager.registerBasicFormats();

	numFeatures = 10;

	//featureExtractor = new FeatureExtractor();

	//featureVector = Eigen::MatrixXf::Zero(numFeatures,1);
}

BirdID::~BirdID()
{
	featureExtractor = nullptr;
	//delete featureVector;
	featureVector = nullptr;
}


void BirdID::readAudioFile(const File &audioFile_)
{
	audioFile = audioFile_;
}

void BirdID::process()
{
	// Order of operations

	// 1. Downsample
	// 2. Compute Spectrum
	computeMagnitudeSpectrum();
	// 3. Denoising
	
	// 4. Extract features
	featureExtractor = new FeatureExtractor(magSpec);
	featureExtractor->setSpectralFeatureExtractionProperties();
	featureExtractor->extractFeatures(featureVector,numFeatures);

	// 5. Classify

}

void BirdID::computeMagnitudeSpectrum()
{
	// Creating a reader for the file, depending on its format
		ScopedPointer<AudioFormatReader> fileReader = formatManager.createReaderFor(audioFile);
		int numChannels = fileReader->numChannels;
		
		ScopedPointer<AudioSampleBuffer> sampleBuffer = new AudioSampleBuffer(1,blockSize);
		sampleBuffer->clear();
		
		//int sampleRate = static_cast<int>(fileReader->sampleRate);
		int64 numSamples = fileReader->lengthInSamples;
		int64 numBlocks= numSamples%hopSize;
		
		// Accounting for non-integer multiples of blockSize
		numBlocks = (numSamples+numBlocks)/hopSize;
		numBlocks+=1;

		// Define a matrix to hold all the audio
		Eigen::MatrixXf audioBuffer(blockSize,numBlocks);

		// For FFT
		for (int j=0;j<numBlocks;j++)
		{
			// Check if blockSize, hopSize implementation is correct
			fileReader->read(sampleBuffer,0,blockSize,j*hopSize,true,false);

			float* sampleData = sampleBuffer->getSampleData(0);
			
			if(numChannels==2)
			{
				float* rightData = sampleBuffer->getSampleData(1);
				
				// Convert from stereo to mono
				for(int i=0; i<blockSize;i++)
				{
					audioBuffer(i,j) = (sampleData[i] + rightData[i])/2;
				}

				rightData = nullptr;
			}
			else
			{
				// If file is mono
				for(int i=0;i<blockSize;i++)
				{				// Copy the samples into the matrix
					audioBuffer(i,j) = sampleData[i];
				}
			}

			sampleData = nullptr;
		}
		// Compute FFT
		Eigen::FFT<float> fft;
		fft.SetFlag(fft.HalfSpectrum);
		
		// Compute the magnitude spectrum
		Eigen::MatrixXcf stftc(halfBlockSize,numBlocks);
		Eigen::MatrixXf stft(halfBlockSize,numBlocks);
		for (int k=0;k<audioBuffer.cols();++k)
		{
			stftc.col(k) = fft.fwd(audioBuffer.col(k),blockSize);
			stft.col(k) = stftc.col(k).real().cwiseAbs();
		
		}

		magSpec = stft;
}

