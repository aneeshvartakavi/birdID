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

#if JUCE_WINDOWS
#include "Eigen\Dense.h"
#include "Eigen\FFT.h"
#endif

class FeatureExtractor
{

public:
	FeatureExtractor(int blockSize_, int hopSize_);
	~FeatureExtractor();

	void computeFeatures(const File &audioFile);

private:
	
	Eigen::MatrixXf& computeMagnitudeSpectrum(const File &audioFile); 
	void computeSpectralFeatures(const Eigen::MatrixXf& stft);
	// To manage reading audio formats
	AudioFormatManager formatManager;
	
	// For the FFT
	int blockSize;
	int hopSize;
	int numFeatures;
	int halfBlockSize;
	// Feature vector
	Eigen::MatrixXf featureVector;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
