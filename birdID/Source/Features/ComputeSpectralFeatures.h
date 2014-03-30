/*
  ==============================================================================

	SpectralFeatures.h
	Created: 12 Mar 2014 12:46:52am
	Author:  Aneesh

	A class to compute the spectral features
  ==============================================================================
*/

#ifndef SPECTRALFEATURES_H_INCLUDED
#define SPECTRALFEATURES_H_INCLUDED

class ComputeSpectralFeatures
{

public:
	
	ComputeSpectralFeatures();

	~ComputeSpectralFeatures();

	enum spectralFeatures
	{
		spectralCentroid	= 1 << 0,
		spectralCrest		= 1 << 1,
		spectralDecrease	= 1 << 2,
		spectralFlatness	= 1 << 3,
		spectralFlux		= 1 << 4,
		spectralKurtosis	= 1 << 5,
		spectralRolloff		= 1 << 6,
		spectralSkewness	= 1 << 7,
		spectralSlope		= 1 << 8,
		spectralSpread		= 1 << 9,
	};

	enum spectralSubFeatures
	{
		mean				= 1 << 0,
		std					= 1 << 1,
		meanFirstDerivative	= 1 << 2,
		stdFirstDerivative	= 1 << 3,
	};


	// Handle processing for flags

	friend spectralFeatures operator|(spectralFeatures a, spectralFeatures b)
	{
		return static_cast<spectralFeatures>(static_cast<int>(a) | static_cast<int>(b));
	}

	friend spectralSubFeatures operator|(spectralSubFeatures a, spectralSubFeatures b)
	{
		return static_cast<spectralSubFeatures>(static_cast<int>(a) | static_cast<int>(b));
	}

	// Call to set flags
	void setSpectralFeatureExtractionProps(int stftFrameLength,int featureflags, int subFeatureFlags);
	
	void computeFeatures(const float* stftFrame);

	int getNumFeatures()
	{
		return numFeatures;
	}

	int getNumSubFeatures()
	{
		return numSubFeatures;
	}


	void getFeatureVector(float* computedFeatureVector, const int length);
	void getSubFeatureVector(float* computedSubFeatureVector, const int length);

private:

	float featureSpectralCentroid(); 
	float featureSpectralCrest();
	float featureSpectralDecrease(); 
	float featureSpectralFlatness(); 
	float featureSpectralFlux();
	float featureSpectralKurtosis();
	float featureSpectralRolloff();
	float featureSpectralSkewness();
	float featureSpectralSlope();
	float featureSpectralSpread();

	// Feature vector to  store temporary values from function
	float* featureVector;
	int numFeatures;
	
	// Storing subfeatures
	float* subFeatureVector;
	int numSubFeatures;
	// Store last feature vector for diff
	float* lastFeatureVector;

	// Temporary variables for intermediate operations
	float* frame;
	float* frameSquared;
	// Store last frame for flux
	float* lastFrame;

	float frameSum;
	float squaredFrameSum;
	int numElementsInFrame;
	
	bool firstRun;

	int featuresToCompute;
	int subFeaturesToCompute;

	// General math functions to speed up math, try making this inline
	float sumFrame(const float* stftFrame, int numElementsInFrame);
	void absFrame(float* stftFrame, int numElementsInFrame);
	float stdFrame(const float* stftFrame, int numElementsInFrame);
	float maxFrame(const float* stftFrame, int numElementsInFrame);
	void squareFrame(const float* stftFrame, int numElementsInFrame, float* squaredFrame);
	void copyFrame(const float* sourceFrame, float* destinationFrame, int numElementsInFrame);
	int getSetBitCount(int value);

	// Sub-features
	void computeRunningStats(float* vector, int numElements);

	// Flags for subfeatures
	bool meanFlag;
	bool stdFlag;
	bool dMeanFlag;
	bool dStdFlag;

	// Memory for sub features
	int numIter;

	// Pointers for running statistics
    float* oldMean;
	float* newMean;
	float* oldStd;
	float* newStd;

	float* dOldMean;
	float* dNewMean;
	float* dOldStd;
	float* dNewStd;

};


#endif  // SPECTRALFEATURES_H_INCLUDED
