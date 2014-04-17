/*
  ==============================================================================

    ComputeCCFeatures.h
    Created: 29 Mar 2014 3:12:39pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef COMPUTECCFEATURES_H_INCLUDED
#define COMPUTECCFEATURES_H_INCLUDED

#include "JuceHeader.h"
#include "../Core/ConnectedComponents.h"

extern "C"
{
#include "../Export/processLabelMatrix.h"
#include "../Export/denoiseSpectrogram.h"
}

class ComputeCCFeatures
{
public:
	ComputeCCFeatures();
	ComputeCCFeatures(float* image,int numRows_, int numCols_);
	
	~ComputeCCFeatures();

	void computeFeatures();
	
	void performCCDenoising(float *denoisedSpectrum);

	
private:
	
	void extractConnectedComponents();

	void relabelComponents();

	/*void featureArea(int indexInFeatureVector);
	void featurePerimeter(int indexInFeatureVector);
	void featureWeightedCentroid(int indexInFeatureVector);
	void featureMeanIntensity(int indexInFeatureVector);*/

	bool* mask;
	int* labelImage;
	
	// Stores the number of labels in the labelImage
	int numLabels;


	//Eigen::MatrixXi labels;
	//Eigen::MatrixXf pixelValues;
	
	emxArray_real_T* labels;
	emxArray_real_T* originalSpec;
	emxArray_real_T* denoisedSpec;
	
	ConnectedComponents cc;

	int numRows,numCols;

	// The features themselves
	//float** featureVector;
	int numFeatures;

};

#endif  // COMPUTECCFEATURES_H_INCLUDED
