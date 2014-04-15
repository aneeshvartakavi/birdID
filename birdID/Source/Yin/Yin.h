/*
  ==============================================================================

    Yin.h
    Created: 25 Mar 2014 7:04:29pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef YIN_H_INCLUDED
#define YIN_H_INCLUDED

class Yin{

public: 
	// Default constructor
	Yin();	
	~Yin();
	// This internally calls initialize
	Yin(float sampleRate,int bufferSize);
	// Pretty obvious what this does
	void initialize(float sampleRate,int bufferSize);
	// Call this function to return pitch
	float getPitch(float* buffer);

	float getProbability();

private: 
	// Internal functions
	float parabolicInterpolation(int tauEstimate);
	int absoluteThreshold();
	void cumulativeMeanNormalizedDifference();
	void difference(float* buffer);

	double threshold;
	int bufferSize;
	int halfBufferSize;
	float sampleRate;
	float* yinBuffer;
	float probability;
};



#endif  // YIN_H_INCLUDED
