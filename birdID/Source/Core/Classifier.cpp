/*
  ==============================================================================

    Classifier.cpp
    Created: 6 Apr 2014 1:04:29pm
    Author:  Aneesh

  ==============================================================================
*/

#include "Classifier.h"

Classifier::Classifier( int numFeatures_, int numClasses_)
{
	numFeatures = numFeatures_;
	numClasses = numClasses_;
	
	// Allocate memory
	featureVector = new double[numFeatures];
	classProb = new double[numClasses];

	svmTrain = new SVMTrain(numFeatures);
	
	//First load the model
	// Hardcode for now, change it to use a static string from the main class
	modelFile = File("C:\\Users\\Aneesh\\Desktop\\BirdID_Data\\svmTrain.model");
	

	
}

Classifier::~Classifier()
{
	svmTrain = nullptr;
	
	delete featureVector;
	featureVector = nullptr;
	
	delete classProb;
	classProb = nullptr;
}

int Classifier::classify(const float* featureVector_)
{
	svmTrain->loadModelFromDisk( modelFile.getFullPathName().toStdString());
	
	
	// Then copy feature vector

	for(int i=0;i<numFeatures;i++)
	{
		featureVector[i] = static_cast<double>(featureVector_[i]);
	}
	
	// Classify!
	double temp = svmTrain->classify(featureVector,classProb);
	return static_cast<int>(temp);
}
