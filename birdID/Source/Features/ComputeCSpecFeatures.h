/*
  ==============================================================================

    ComputeCSpecFeatures.h
    Created: 6 Apr 2014 12:02:40am
    Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTECSPECFEATURES_H_INCLUDED
#define COMPUTECSPECFEATURES_H_INCLUDED

#include "JuceHeader.h"

extern "C"
{
#include "../Export/computeSpectralFeatures_export.h"
	#include "../Export/denoiseSpectrogram.h"
}

class ComputeCSpecFeatures
{
public:

	ComputeCSpecFeatures(float* magnitudeSpec, int numRows_,int numCols_)
	{
		numRows = numRows_;
		numCols = numCols_;

		denoisedSpec = emxCreate_real_T(numRows,numCols);
		
		// Copy over the array
		for (int i=0;i<numRows*numCols;i++)
		{
			denoisedSpec->data[i] = static_cast<real_T>(magnitudeSpec[i]);
		}

		features = new real_T[40];

	}

	ComputeCSpecFeatures(emxArray_real_T* magSpec)
	{
		denoisedSpec = magSpec;

		features = new real_T[40];
	}


	~ComputeCSpecFeatures()
	{
		//emxDestroyArray_real_T(denoisedSpec);
		denoisedSpec = nullptr;
		delete features;
	}

	void extractFeatures()
	{
		computeSpectralFeatures_initialize();

		computeSpectralFeatures(denoisedSpec,features);
	}

	void returnFeatures(float* featureVector)
	{
		
		for(int i=0;i<40;i++)
		{
			featureVector[i] = static_cast<float>(features[i]);
		}
		

	}

	int getNumFeatures()
	{
		return 40;
	}



private:
	ScopedPointer<emxArray_real_T> denoisedSpec;
	real_T* features;
	int numRows,numCols;
};




#endif  // COMPUTECSPECFEATURES_H_INCLUDED
