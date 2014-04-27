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
	#include "../Export/denoiseSpectrogram.h"
	#include "../Export/bufferSTFT.h"
	#include "../Export/inverseSTFT.h"
}

#if JUCE_WINDOWS
//#include "Eigen\Dense.h"
//#include "Eigen\FFT.h"
#endif

class BirdID : public ThreadWithProgressWindow, public ChangeBroadcaster
{
public:
	BirdID(int blockSize_,int hopSize_);
	~BirdID();

	
	inline void selectFile(const File &audioFile_)
	{
		audioFile = audioFile_;
	}
	
	// Run all the operations
	void run();
	
	int returnPredictedClass()
	{
		return predictedClass;
	}

private:
	
	void computeSpectrum(); 
	
	void recoverAudio();

	void readAudioFileResampled(const File &audioFile_, float targetSampleRate);
	
	void deleteIfAllocated(float* pointerToBeDeleted);
	
	void deleteEMX(emxArray_real_T* emxArray);

	float* denoisedSpectrum;
	float* resampledAudio;
	float* featureVector;

	// To manage reading audio formats
	AudioFormatManager formatManager;
	AudioTransportSource transportSource;

	// Resampling stuff
	ScopedPointer<LagrangeInterpolator> interpolator;
	
	// Current audio file to read
	File audioFile;

	ScopedPointer<FeatureExtractor> featureExtractor;
	ScopedPointer<PreProcessor> preProcessor;
	ScopedPointer<Classifier> classifier;

	emxArray_real_T* magSpecEMX;
	emxArray_real_T* denoisedSpecEMX;
	emxArray_real_T* phaseSpecEMX;
	emxArray_real_T* resampledAudioEMX;
	emxArray_real_T* denoisedAudioEMX;
	emxArray_real_T* T;

	int numRows,numCols;
	int resampledAudioLength;
	int blockSize;
	int hopSize;
	int numFeatures;
	int numClasses;
	
	int predictedClass;
};




#endif  // BIRDID_H_INCLUDED
