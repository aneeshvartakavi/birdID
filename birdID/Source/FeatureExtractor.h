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
#include "Eigen\Dense.h"

#include "Features\ComputeSpectralFeatures.h"
#include "Features\ComputePitchFeatures.h"

class FeatureExtractor
{

public:
		
	FeatureExtractor(const Eigen::MatrixXf magnitudeSpectrum_, File& audioFile_)
	{
		
		computeSpectralFeatures = new ComputeSpectralFeatures();
		blockSize = 8192;
		hopSize = 32;
		audioFile = audioFile_;

		computePitchFeatures = new ComputePitchFeatures(blockSize,hopSize);

		magSpec = magnitudeSpectrum_;
		numRows = magSpec.rows();
		numCols = magSpec.cols();

	}

	~FeatureExtractor()
	{
		computeSpectralFeatures = nullptr;
		computePitchFeatures = nullptr;
	}

	void setSpectralFeatureExtractionProperties(int featuresToCompute = 1023,int subFeaturesToCompute = 15)
	{
		computeSpectralFeatures->setSpectralFeatureExtractionProps(numRows,featuresToCompute,subFeaturesToCompute);
		
		numSpectralFeatures = computeSpectralFeatures->getNumFeatures();
		numSpectralSubFeatures = computeSpectralFeatures->getNumSubFeatures();
	}


	void extractFeatures(/*float* featureVec_, int &numFeatures_*/)
	{
		//int featuresToCompute =  1023; //ComputeSpectralFeatures::spectralFeatures::spectralCentroid; // Set to 1023 for all
		
		computePitchFeatures->computeFeatures(audioFile);
		
		
		featureVec = new float[numSpectralFeatures*numSpectralSubFeatures];
		
		float *tempData = new float[513];
		
		for(int y=0;y<513;y++)
		{
			tempData[y] = 1.0f;
		}


		computeSpectralFeatures->computeFeatures(tempData);
		float* resultVector = new float[numSpectralFeatures*numSpectralSubFeatures];
		computeSpectralFeatures->getSubFeatureVector(resultVector,numSpectralFeatures*numSpectralSubFeatures);

		for(int y=0;y<513;y++)
		{
			tempData[y] = 2.0f;
		}

		computeSpectralFeatures->computeFeatures(tempData);
		computeSpectralFeatures->getSubFeatureVector(resultVector,numSpectralFeatures*numSpectralSubFeatures);

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
		float* featureVec;

		Eigen::MatrixXf magSpec;

		File audioFile;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
