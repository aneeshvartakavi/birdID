/*
  ==============================================================================

    ComputeMFCCFeatures.h
    Created: 5 Apr 2014 4:16:09pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTEMFCCFEATURES_H_INCLUDED
#define COMPUTEMFCCFEATURES_H_INCLUDED

#include "JuceHeader.h"

extern "C"
{
	#include "../Export/featureMFCCAndDerivative.h"
	#include "../Export/denoiseSpectrogram.h"
}


class ComputeMFCCFeatures
{

public:
	ComputeMFCCFeatures(ScopedPointer<emxArray_real_T> denoisedAudio_,int sampleRate_)
	{
		denoisedAudio = denoisedAudio_;
		// Create feature vector
		sampleRate = static_cast<real_T>(sampleRate_);
		mfccFeatures = new real_T[64];
	}

	~ComputeMFCCFeatures()
	{
		//emxDestroyArray_real_T(mfccFeatures);
		// Is this safe?
		denoisedAudio = nullptr;
		delete mfccFeatures;
	}

	void extractMFCCFeatures()
	{
		featureMFCCAndDerivative_initialize();

		featureMFCCAndDerivative(denoisedAudio,sampleRate,mfccFeatures);

	}

	void returnMFCCFeatures(float* mfccFeatures_)
	{
		for(int i=0;i<64;i++)
		{
			mfccFeatures_[i] = static_cast<float>(mfccFeatures[i]);
		}
		

	}

	int getNumFeatures()
	{
		return 64;
	}


private:

	real_T* mfccFeatures;
	ScopedPointer<emxArray_real_T> denoisedAudio;
	real_T sampleRate;

};




#endif  // COMPUTEMFCCFEATURES_H_INCLUDED
