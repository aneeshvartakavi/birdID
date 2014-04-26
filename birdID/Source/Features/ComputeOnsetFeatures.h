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
		numFeatures = 12;
		numRows = numRows_;
		numCols = numCols_;

		denoisedSpec = emxCreate_real_T(numRows,numCols);
		onsets = emxCreate_boolean_T(1,numCols);
		time = emxCreate_real_T(1,numCols);
		// Copy over the array
		for (int i=0;i<numRows*numCols;i++)
		{
			denoisedSpec->data[i] = static_cast<real_T>(magnitudeSpec[i]);
		}

		// Copy time array
		for (int i=0;i<numCols;i++)
		{
			time->data[i] = static_cast<real_T>(time_->data[i]);
		}

		features = new real_T[numFeatures];
		
	}

	~ComputeOnsetFeatures()
	{
		emxDestroyArray_real_T(denoisedSpec);
		emxDestroyArray_real_T(time);
	
		emxDestroyArray_boolean_T(onsets);

		delete features;
	}

	
	void extractFeatures()
	{
		computeOnsetFeatures_initialize();

		computeOnsetFeatures(denoisedSpec,time,features,onsets);
	}

	void returnFeatures(float* featureVector)
	{
		
		for(int i=0;i<numFeatures;i++)
		{
			featureVector[i] = static_cast<float>(features[i]);
		}
		

	}

	int getNumFeatures()
	{
		return numFeatures;
	}

	void returnOnsets(bool* onsets_)
	{
		for(int i=0;i<numCols;i++)
		{
			onsets_[i] = static_cast<bool>(onsets->data[i]);
		}
	}

private:

	emxArray_real_T* denoisedSpec;
	emxArray_real_T* time;
	emxArray_boolean_T* onsets;
	real_T* features;
	int numRows,numCols;
	int numFeatures;
};




#endif  // COMPUTEONSETFEATURES_H_INCLUDED
