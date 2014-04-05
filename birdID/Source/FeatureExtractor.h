/*
  ==============================================================================

    FeatureExtractor.h
    Created: 11 Mar 2014 10:43:43pm
    Author:  Aneesh

  ==============================================================================
*/

#ifndef FEATUREEXTRACTOR_H_INCLUDED
#define FEATUREEXTRACTOR_H_INCLUDED

#include "JuceHeader.h"
//#include "Eigen\Dense.h"

#include "Features\ComputeSpectralFeatures.h"
#include "Features\ComputePitchFeatures.h"

class FeatureExtractor
{

public:
		
	FeatureExtractor(float* magnitudeSpectrum_, int numRows_,int numCols_, File& audioFile_)
	{
		
		computeSpectralFeatures = new ComputeSpectralFeatures();
		blockSize = 1024;
		hopSize = 512;
		audioFile = audioFile_;

		computePitchFeatures = new ComputePitchFeatures(blockSize,hopSize);

		numRows = numRows_;
		numCols = numCols_;
		magSpec = new float[numRows*numCols];
		// Deep copy spectrum
		for(int i=0;i<numRows*numCols;i++)
		{
			magSpec[i] = magnitudeSpectrum_[i];
		}


	}

	~FeatureExtractor()
	{
		computeSpectralFeatures = nullptr;
		computePitchFeatures = nullptr;
	}


	// Call to set the number of features and subfeatures to extract
	void setSpectralFeatureExtractionProperties(int featuresToCompute = 1023,int subFeaturesToCompute = 15)
	{
		computeSpectralFeatures->setSpectralFeatureExtractionProps(numRows,featuresToCompute,subFeaturesToCompute);
		
		numSpectralFeatures = computeSpectralFeatures->getNumFeatures();
		numSpectralSubFeatures = computeSpectralFeatures->getNumSubFeatures();
	}


	void extractFeatures()
	{
		float *tempData = new float[513];
		
		featureVec = new float[numSpectralFeatures*numSpectralSubFeatures];

		// Extract columns of magnitude spectrum
		for(int i=0;i<numCols;i++)
		{
			for(int j=0;j<numRows;j++)
			{
				tempData[j] = magSpec[i*numRows+j];
			}
			// Compute features
			computeSpectralFeatures->computeFeatures(tempData);

		}

		// Get resulting subfeatures - Move this to a return featureVector function

		//computeSpectralFeatures->getSubFeatureVector(featureVec,numSpectralFeatures*numSpectralSubFeatures);

		// Compute mfcc and derivative features



		computePitchFeatures->computeFeatures(audioFile);

		delete featureVec;
		featureVec = nullptr;
		
		delete tempData;
		tempData=nullptr;
	}

	

	private:
		
		ScopedPointer<ComputeSpectralFeatures> computeSpectralFeatures;
		ScopedPointer<ComputePitchFeatures> computePitchFeatures;

		// Used for Pitch features
		int blockSize;	
		int hopSize;

		int numRows, numCols;

		int numSpectralFeatures;
		int numSpectralSubFeatures;
		int numMFCCFeatures;
		float* featureVec;

		//Eigen::MatrixXf magSpec;
		float *magSpec;

		File audioFile;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
