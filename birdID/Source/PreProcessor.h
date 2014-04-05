/*
  ==============================================================================

    PreProcessor.h
    Created: 27 Mar 2014 10:15:17pm
    Author:  Aneesh

	Main class for preprocessing, will interface to Coder export.

	Gets the magnitude spectrum from BirdID in the constructor, and converts it into emxarray.

	Performs spectral subtraction denoising, will now have to implement CC denoising.
  ==============================================================================
*/

#ifndef PREPROCESSOR_H_INCLUDED
#define PREPROCESSOR_H_INCLUDED


#include "Features\ComputeCCFeatures.h"

extern "C"
{
	#include "Export\denoiseSpectrogram.h"
}


class PreProcessor
{
public:
	PreProcessor(ScopedPointer<emxArray_real_T> magSpec,int numRows_,int numCols_);
	~PreProcessor();
	
	void process();
	
	void DenoiseSpectrogram();
	
	void ccDenoising();

	void returnDenoisedSpectrogram(float* denoisedSpectrogram_);
	//void returnDenoisedSpectrogramEMX(ScopedPointer<emxArray_real_T> denoisedSpectrogram_);
private:
	
	ScopedPointer<ComputeCCFeatures> ccFeatures;
	//Functions to extract features
	
	// Arrays for the interfacing
	ScopedPointer<emxArray_real_T> originalSpec;
	ScopedPointer<emxArray_real_T> denoisedSpec;
	

	float* denoisedSpectrogram;


	// Size variables
	int numRows, numCols;

};

#endif  // PREPROCESSOR_H_INCLUDED
