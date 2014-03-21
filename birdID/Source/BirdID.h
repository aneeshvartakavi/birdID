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

#if JUCE_WINDOWS
#include "Eigen\Dense.h"
#include "Eigen\FFT.h"
#endif

class BirdID
{
public:
	BirdID(int blockSize_,int hopSize_);
	~BirdID();

	void readAudioFile(const File &audioFile_);
	// Run all the operations
	void process();

	

private:
	// Private functions
	void computeMagnitudeSpectrum(); 

	// Feature vector
	float* featureVector;
	//int numFeatures;
	// To manage reading audio formats
	AudioFormatManager formatManager;
	// Current audio file
	File audioFile;

	ScopedPointer<FeatureExtractor> featureExtractor;
	Eigen::MatrixXf magSpec;

	// For the FFT
	int blockSize;
	int hopSize;
	int numFeatures;
	int halfBlockSize;
	
	
};




#endif  // BIRDID_H_INCLUDED
