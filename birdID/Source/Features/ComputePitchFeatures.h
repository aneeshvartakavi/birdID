/*
  ==============================================================================

	ComputePitchFeatures.h
	Created: 25 Mar 2014 7:23:04pm
	Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTEPITCHFEATURES_H_INCLUDED
#define COMPUTEPITCHFEATURES_H_INCLUDED

#include "../Yin/Yin.h"
#include "JuceHeader.h"

extern "C"
{
#include "../Export/computePitchFeatures_exp.h"
#include "../Export/denoiseSpectrogram.h"
#include "../Export/computeOnsetFeatures_export.h"
}

class ComputePitchFeatures
{
public:
	ComputePitchFeatures(emxArray_real_T* time_, int numCols);
	~ComputePitchFeatures();

	void extractFeatures(File& audioFile, float* magnitudeSpec, int numRows, int numCols,bool* onsets_);

	void getFeatureVector();
	void returnFeatures(float* featureVector);
	int getNumFeatures();

private:
	
	void computePitch(File& audioFile);
	
	void processPitch(int lowF0,int highF0);

	void computeFirstDerivative();
	
	emxArray_real_T* denoisedSpec;
	emxArray_real_T* time;
	emxArray_boolean_T* onsets;
	emxArray_real_T* pitchEMX;

	real_T* features;
	
	int numRows,numCols;

	ScopedPointer<Yin> yin;
	
	float* rightData;
	float* leftData;

	float* pitch;
	AudioFormatManager formatManager;

	int blockSize;
	int hopSize;
	int64 numBlocks;
	int sampleRate;
	int64 numSamples;
	int numFeatures;
};




#endif  // COMPUTEPITCHFEATURES_H_INCLUDED
