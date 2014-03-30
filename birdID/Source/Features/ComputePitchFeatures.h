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

class ComputePitchFeatures
{
public:
	ComputePitchFeatures(int blockSize_,int hopSize_);
	~ComputePitchFeatures();

	void computeFeatures(File& audioFile);

	void getFeatureVector();
private:
	
	void computePitch(File& audioFile);
	
	void processPitch(int lowF0,int highF0);

	void computeFirstDerivative();
	
	ScopedPointer<Yin> yin;
	
	int blockSize;
	int hopSize;
	int64 numBlocks;

	float* rightData;
	float* leftData;

	float* pitch;
	AudioFormatManager formatManager;
};




#endif  // COMPUTEPITCHFEATURES_H_INCLUDED
