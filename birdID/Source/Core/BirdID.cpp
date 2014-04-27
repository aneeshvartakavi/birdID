/*
  ==============================================================================

    BirdID.cpp
    Created: 20 Mar 2014 12:07:26am
    Author:  Aneesh

  ==============================================================================
*/

#include "BirdID.h"

BirdID::BirdID(int blockSize_, int hopSize_): blockSize(blockSize_),hopSize(hopSize_),ThreadWithProgressWindow("Identifying...",true,false)
{

	// Register basic formats to read
	formatManager.registerBasicFormats();

	numClasses = 30;
	interpolator = new LagrangeInterpolator();
	interpolator->reset();

	// Initializing pointers
	denoisedSpectrum = NULL;
	featureVector = NULL;
	resampledAudio = NULL;

	resampledAudioEMX = NULL;
	denoisedSpecEMX = NULL;
	denoisedAudioEMX = NULL;
	T = NULL;
	phaseSpecEMX = NULL;
	magSpecEMX = NULL;
}

BirdID::~BirdID()
{
	featureExtractor = nullptr;
	interpolator = nullptr;
	classifier = nullptr;

	preProcessor = nullptr;

	deleteIfAllocated(denoisedSpectrum);
	deleteIfAllocated(featureVector);
	deleteIfAllocated(resampledAudio);

	deleteEMX(resampledAudioEMX);
	deleteEMX(denoisedSpecEMX);
	deleteEMX(denoisedAudioEMX);
	deleteEMX(T);
	deleteEMX(phaseSpecEMX);
	deleteEMX(magSpecEMX);
	

}

void BirdID::deleteIfAllocated(float* pointerToBeDeleted)
	{
		if(pointerToBeDeleted!=NULL)
		{
			delete pointerToBeDeleted;
			pointerToBeDeleted = NULL;
		}
	}

void BirdID::deleteEMX(emxArray_real_T* emxArray)
{
	if(emxArray!=NULL)
	{
		emxDestroyArray_real_T(emxArray);
		emxArray = nullptr;
	}

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

void BirdID::run()
{
	// Order of operations
	setProgress(0.0);
	// 1. Read audio and downsample
	readAudioFileResampled(audioFile,16000);
	setProgress(0.25);
	// 2. Compute Spectrum
	computeSpectrum();

	// 3. Denoising
	// Initialize memory
	denoisedSpectrum = new float[blockSize*numCols];
	preProcessor = new PreProcessor(magSpecEMX,numRows,numCols);
	preProcessor->process();
	preProcessor->returnDenoisedSpectrogram(denoisedSpectrum);
//	preProcessor->returnDenoisedSpectrogramEMX(denoisedSpecEMX);
//
//	// Convert to audio
	recoverAudio();
//	
//	setProgress(0.50);
//	
//	//// 4. Extract features
	featureExtractor = new FeatureExtractor(denoisedSpectrum,numRows,numCols,audioFile,denoisedAudioEMX,resampledAudioLength,T);
	//featureExtractor = new FeatureExtractor(denoisedSpecEMX,audioFile,denoisedAudioEMX);
//	featureExtractor->setSpectralFeatureExtractionProperties();
	featureExtractor->extractFeatures();
	// Get features back
	numFeatures = featureExtractor->getNumFeatures();
	featureVector = new float[numFeatures];
	featureExtractor->returnFeatureVector(featureVector);
	setProgress(0.75);
	// 5. Classify
	classifier = new Classifier(numFeatures,numClasses);

	sendChangeMessage();
	predictedClass = 2;
//	int predictedClass = classifier->classify(featureVector);

//	setProgress(0.99);
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

	magSpecEMX = emxCreate_real_T(numRows,numCols);
	phaseSpecEMX = emxCreate_real_T(numRows,numCols);
	T = emxCreate_real_T(numRows,1);

	// Initialize
	bufferSTFT_initialize();

	bufferSTFT(resampledAudioEMX,static_cast<real_T>(blockSize),static_cast<real_T>(hopSize),magSpecEMX,phaseSpecEMX,T);
	
	
}

void BirdID::recoverAudio()
{
	// Fill magSpecEMX with denoisedAudio
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

	inverseSTFT(denoisedSpecEMX,phaseSpecEMX,blockSize,hopSize,denoisedAudioEMX);

}