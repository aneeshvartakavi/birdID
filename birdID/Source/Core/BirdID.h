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
	
	String returnPredictedClass()
	{
		return predictedSpecies;
	}

private:
	// Forward STFT
	void computeSpectrum(); 
	
	// Called by the GUI to update species names
	String returnSpeciesName(int predictedClass);
	// Inverse STFT
	void recoverAudio();
	// Read an input file, and resample to 16kHz
	void readAudioFileResampled(const File &audioFile_, float targetSampleRate);
	// Helper function
	void deleteIfAllocated(float* pointerToBeDeleted);
	 
	void deleteEMX(emxArray_real_T* emxArray);


	float* denoisedSpectrum;
	float* resampledAudio;
	float* featureVector;

	// To manage reading audio formats
	AudioFormatManager formatManager;
	AudioTransportSource transportSource;

	// Interpolator for resampling
	ScopedPointer<LagrangeInterpolator> interpolator;
	
	// Current audio file to read
	File audioFile;

	// Pointers to processing stages
	ScopedPointer<FeatureExtractor> featureExtractor;
	ScopedPointer<PreProcessor> preProcessor;
	ScopedPointer<Classifier> classifier;

	// EMX data structures
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
	
	String predictedSpecies;
	
};




#endif  // BIRDID_H_INCLUDED
