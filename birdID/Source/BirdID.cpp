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
	interpolator = new LagrangeInterpolator();
	interpolator->reset();
}

BirdID::~BirdID()
{
	featureExtractor = nullptr;
	interpolator = nullptr;
	//delete featureVector;
	//featureVector = nullptr;
	
	preProcessor = nullptr;

	//delete denoisedSpectrum;
	denoisedSpectrum = nullptr;

	emxDestroyArray_real_T(magSpec);

}


void BirdID::readAudioFileResampled(const File &audioFile_, float targetSampleRate)
{
	//Creating a reader for the file, depending on its format
		ScopedPointer<AudioFormatReader> fileReader = formatManager.createReaderFor(audioFile_);
		//int numChannels = fileReader->numChannels;
		
		int64 numSamples = fileReader->lengthInSamples;

		ScopedPointer<AudioSampleBuffer> leftChannelBuffer = new AudioSampleBuffer(1,static_cast<int>(numSamples));
		leftChannelBuffer->clear();
		
		float sampleRate = static_cast<float>(fileReader->sampleRate);
		
		float conversionFactor = sampleRate/targetSampleRate;

		resampledAudioLength = static_cast<int>(floorf(numSamples/conversionFactor));
		// Initialize destination buffer
		resampledAudio = new float[resampledAudioLength];
		
			
		//if(numChannels == 1)
		//{
			// Read audio
			fileReader->read(leftChannelBuffer,0,static_cast<int>(numSamples),0,true,false);
			// Resample
			interpolator->process(conversionFactor,leftChannelBuffer->getReadPointer(0),resampledAudio,resampledAudioLength);

		// Normalize resampledAudio
		float max = resampledAudio[0];
		
		for(int i=1;i<resampledAudioLength;i++)
		{
			if(fabs(resampledAudio[i])>fabs(max))
			{
				max = resampledAudio[i];
			}

		}
		max = fabs(max);

		for(int i=0;i<resampledAudioLength;i++)
		{
			resampledAudio[i] /= max;
		}

}

void BirdID::process(const File &audioFile_)
{
	// Order of operations

	// 1. Read audio and downsample
	readAudioFileResampled(audioFile_,16000);

	// 2. Compute Spectrum
	computeSpectrum();

	// 3. Denoising
	// Initialize memory
	denoisedSpectrum = new float[blockSize*numCols];
	preProcessor = new PreProcessor(magSpec,numRows,numCols);
	preProcessor->process();
	preProcessor->returnDenoisedSpectrogram(denoisedSpectrum);
	//preProcessor->returnDenoisedSpectrogramEMX(magSpec);

	// Convert to audio
	recoverAudio();
	
	
	// Write denoisedSpectrum to file
	/*File logFile("C:\\Users\\Aneesh\\Desktop\\test.txt");
	if(logFile.existsAsFile())
	{
		logFile.deleteFile();
		
	}
	logFile.create();

	ScopedPointer<FileOutputStream> tempStream = logFile.createOutputStream();
	
	for(int i=0;i<numCols*numRows;i++)
	{
		tempStream->writeString(String(denoisedSpectrum[i]));
		tempStream->writeString("\n");
	}*/

	//tempStream->flush();
	
	//// 4. Extract features
	featureExtractor = new FeatureExtractor(denoisedSpectrum,numRows,numCols,audioFile,denoisedAudioEMX);
//	featureExtractor->setSpectralFeatureExtractionProperties();
	featureExtractor->extractFeatures();

	// 5. Classify

}

void BirdID::computeSpectrum()
{
	
	// Create a vector for resampled audio
	resampledAudioEMX = emxCreate_real_T(resampledAudioLength,1);
	
	// Copy it
	for(int i=0;i<resampledAudioLength;i++)
	{
		resampledAudioEMX->data[i] = static_cast<real_T>(resampledAudio[i]);
	}

	// Create a matrix for spectrum
	numCols = (resampledAudioLength-blockSize)/hopSize;
	numCols++;
	numRows = (blockSize/2)+1;
	magSpec = emxCreate_real_T(numRows,numCols);
	phaseSpec = emxCreate_real_T(numRows,numCols);
	// Initialize
	bufferSTFT_initialize();

	bufferSTFT(resampledAudioEMX,static_cast<real_T>(blockSize),static_cast<real_T>(hopSize),magSpec,phaseSpec);
	
	emxDestroyArray_real_T(resampledAudioEMX);
}

void BirdID::recoverAudio()
{
	// Fill magSpec with denoisedAudio
	denoisedSpecEMX = emxCreate_real_T(numRows,numCols);
	
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			denoisedSpecEMX->data[i*numRows+j] = static_cast<real_T>(denoisedSpectrum[i*numRows+j]);
		}

	}


	denoisedAudioEMX = emxCreate_real_T(resampledAudioLength,1);

	inverseSTFT_initialize();

	inverseSTFT(denoisedSpecEMX,phaseSpec,blockSize,hopSize,denoisedAudioEMX);

}
