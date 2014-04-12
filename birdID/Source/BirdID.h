/*
  ==============================================================================

    BirdID.h
    Created: 20 Mar 2014 12:07:26am
    Author:  Aneesh

	Class that brings functionality together

  ==============================================================================
*/

#ifndef BIRDID_H_INCLUDED
#define BIRDID_H_INCLUDED

#include "JuceHeader.h"
#include "FeatureExtractor.h"
#include "PreProcessor.h"
#include "Classifier.h"

extern "C"
{
	#include "Export\denoiseSpectrogram.h"
	#include "Export\bufferSTFT.h"
	#include "Export\inverseSTFT.h"
}

#if JUCE_WINDOWS
//#include "Eigen\Dense.h"
//#include "Eigen\FFT.h"
#endif

class BirdID : public ThreadWithProgressWindow
{
public:
	BirdID(int blockSize_,int hopSize_);
	~BirdID();

	
	// Run all the operations
	void selectFile(const File &audioFile_)
	{
		audioFile = audioFile_;
	}

	void run();
	
	// Made public
	//AudioFormatManager formatManager;
	//AudioTransportSource transportSource;

	
private:
	// Private functions
	void computeSpectrum(); 
	void recoverAudio();

	void readAudioFileResampled(const File &audioFile_, float targetSampleRate);

	float* denoisedSpectrum;
	// Feature vector
	float* featureVector;
	//int numFeatures;
	// To manage reading audio formats
	AudioFormatManager formatManager;
	AudioTransportSource transportSource;

	// Resampling stuff
	ScopedPointer<LagrangeInterpolator> interpolator;
	float* resampledAudio;
	int resampledAudioLength;
	// Current audio file
	File audioFile;

	ScopedPointer<FeatureExtractor> featureExtractor;
	ScopedPointer<PreProcessor> preProcessor;
	ScopedPointer<Classifier> classifier;

	ScopedPointer<emxArray_real_T> magSpec;
	ScopedPointer<emxArray_real_T> denoisedSpecEMX;
	ScopedPointer<emxArray_real_T> phaseSpec;
	ScopedPointer<emxArray_real_T> resampledAudioEMX;
	ScopedPointer<emxArray_real_T> denoisedAudioEMX;
	int numRows,numCols;

	// For the FFT
	int blockSize;
	int hopSize;
	int numFeatures;
	int numClasses;
	int halfBlockSize;

	
	
};




#endif  // BIRDID_H_INCLUDED
