/*
  ==============================================================================

    Classifier.h
    Created: 6 Apr 2014 1:04:29pm
    Author:  Aneesh

	The class that handles interfacing with LibSVM
  ==============================================================================
*/

#ifndef CLASSIFIER_H_INCLUDED
#define CLASSIFIER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "LibSVM\SVMTrain.h"

class Classifier
{

public:
	Classifier( int numFeatures_, int numClasses_);
	~Classifier();
	
	
	int classify(const float* featureVector_);
private:

	// Path to model file for libSVM
	File modelFile;
	ScopedPointer<SVMTrain> svmTrain;
	
	// Local copy of feature vector
	double* featureVector;
	double* classProb;
	
	//
	int numFeatures;
	int numClasses;
};





#endif  // CLASSIFIER_H_INCLUDED
