/*
  ==============================================================================

    ComputeOnsetFeatures.h
    Created: 27 Mar 2014 10:11:51pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTEONSETFEATURES_H_INCLUDED
#define COMPUTEONSETFEATURES_H_INCLUDED

#include "JuceHeader.h"

extern "C"
{
#include "../Export/computeOnsetFeatures_export.h"
	#include "../Export/denoiseSpectrogram.h"
}

class ComputeOnsetFeatures
{

public:
	ComputeOnsetFeatures(float* magnitudeSpec, int numRows_,int numCols_, emxArray_real_T* time_)
	{
		numRows = numRows_;
		numCols = numCols_;

		denoisedSpec = emxCreate_real_T(numRows,numCols);
		
		// Copy over the array
		for (int i=0;i<numRows*numCols;i++)
		{
			denoisedSpec->data[i] = static_cast<real_T>(magnitudeSpec[i]);
		}

		time = time_;
	}

	~ComputeOnsetFeatures();
	
	void extractFeatures()
	{
		computeOnsetFeatures_initialize();

		computeOnsetFeatures(denoisedSpec,time,features,onsets);
	}

	void returnFeatures(float* featureVector)
	{
		
		for(int i=0;i<8;i++)
		{
			featureVector[i] = static_cast<float>(features[i]);
		}
		

	}

	int getNumFeatures()
	{
		return 8;
	}
private:

	ScopedPointer<emxArray_real_T> denoisedSpec;
	ScopedPointer<emxArray_real_T> time;
	ScopedPointer<emxArray_boolean_T> onsets;
	real_T* features;
	int numRows,numCols;

};




#endif  // COMPUTEONSETFEATURES_H_INCLUDED
