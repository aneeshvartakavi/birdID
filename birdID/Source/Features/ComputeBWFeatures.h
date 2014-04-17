/*
  ==============================================================================

    ComputeBWFeatures.h
    Created: 5 Apr 2014 11:21:28pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTEBWFEATURES_H_INCLUDED
#define COMPUTEBWFEATURES_H_INCLUDED

#include "JuceHeader.h"

extern "C"
{
#include "../Export/computeBWFeatures_export.h"
	#include "../Export/denoiseSpectrogram.h"
}

class ComputeBWFeatures
{

public:
	ComputeBWFeatures(float* magnitudeSpec, int numRows_,int numCols_)
	{
		numRows = numRows_;
		numCols = numCols_;

		denoisedSpec = emxCreate_real_T(numRows,numCols);
		
		// Copy over the array
		for (int i=0;i<numRows*numCols;i++)
		{
			denoisedSpec->data[i] = static_cast<real_T>(magnitudeSpec[i]);
		}

		features = new real_T[8];
	}

	ComputeBWFeatures(emxArray_real_T* magSpec)
	{
		denoisedSpec = magSpec;

		features = new real_T[8];
	}


	~ComputeBWFeatures()
	{
		emxDestroyArray_real_T(denoisedSpec);
		delete features;
	}

	void extractFeatures()
	{
		computeBWFeatures_initialize();

		computeBWFeatures(denoisedSpec,features);
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
	
	emxArray_real_T* denoisedSpec;
	real_T* features;
	int numRows,numCols;
};

#endif  // COMPUTEBWFEATURES_H_INCLUDED
