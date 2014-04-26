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
	ComputeMFCCFeatures(const emxArray_real_T* denoisedAudio_,int sampleRate_, int denoisedAudioLength)
	{
		denoisedAudio =emxCreate_real_T(denoisedAudioLength,1);

		numFeatures = 64;

		// Copy
		for(int i=0;i<denoisedAudioLength;i++)
		{
			denoisedAudio->data[i] = denoisedAudio_->data[i];
		}

		// Create feature vector
		sampleRate = static_cast<real_T>(sampleRate_);
		mfccFeatures = new real_T[numFeatures];
	}

	~ComputeMFCCFeatures()
	{
		emxDestroyArray_real_T(denoisedAudio);
		
		delete mfccFeatures;
		
	}

	void extractMFCCFeatures()
	{
		featureMFCCAndDerivative_initialize();

		featureMFCCAndDerivative(denoisedAudio,sampleRate,mfccFeatures);

	}

	void returnMFCCFeatures(float* mfccFeatures_)
	{
		for(int i=0;i<numFeatures;i++)
		{
			mfccFeatures_[i] = static_cast<float>(mfccFeatures[i]);
		}
		

	}

	int getNumFeatures()
	{
		return numFeatures;
	}


private:

	real_T* mfccFeatures;
	int numFeatures;

	emxArray_real_T* denoisedAudio;
	real_T sampleRate;
	
};




#endif  // COMPUTEMFCCFEATURES_H_INCLUDED
