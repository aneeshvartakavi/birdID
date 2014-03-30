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

#include "JuceHeader.h"
#include "Eigen\Dense.h"
#include "Features\ComputeCCFeatures.h"

extern "C"
{
#include "Export\denoiseSpectrogram.h"
//#include "Export\denoiseSpectrogram_emxAPI.h"
//#include "Export\denoiseSpectrogram_initialize.h"
}


class PreProcessor
{
public:
	PreProcessor(Eigen::MatrixXf& stft);
	~PreProcessor();
	
	void process();
	
	void DenoiseSpectrogram();
	
	void ccDenoising();
private:
	
	ScopedPointer<ComputeCCFeatures> ccFeatures;
	//Functions to extract features
	
	

	// Arrays for the interfacing
	emxArray_real_T* originalSpec;
	emxArray_real_T* denoisedSpec;
	

	float* denoisedSpectrogram;
	//int* labelImage;
	//bool* mask;

	//Eigen::MatrixXi labels;

	// Size variables
	int numRows, numCols;

};

#endif  // PREPROCESSOR_H_INCLUDED
