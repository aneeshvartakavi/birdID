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

class FeatureExtractor
{

public:
		
	FeatureExtractor(const Eigen::MatrixXf magnitudeSpectrum_)
	{
		
		computeSpectralFeatures = new ComputeSpectralFeatures();
		
		magSpec = magnitudeSpectrum_;
		numRows = magSpec.rows();
		numCols = magSpec.cols();
		//magSpec = new float[numRows*numCols];
		// Copy Magnitude spectum over
		//featureVec = new float[10];
	}

	~FeatureExtractor()
	{
		computeSpectralFeatures = nullptr;
		//delete magSpec;
		//magSpec = nullptr;
	}

	void setSpectralFeatureExtractionProperties(int featuresToCompute = 1023,int subFeaturesToCompute = 15)
	{
		computeSpectralFeatures->setSpectralFeatureExtractionProps(numRows,featuresToCompute,subFeaturesToCompute);
		
		numSpectralFeatures = computeSpectralFeatures->getNumFeatures();
		numSpectralSubFeatures = computeSpectralFeatures->getNumSubFeatures();
	}


	void extractFeatures(float* featureVec_, int &numFeatures_)
	{
		//int featuresToCompute =  1023; //ComputeSpectralFeatures::spectralFeatures::spectralCentroid; // Set to 1023 for all
		
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

		//for(int t=0;t<numCols;t++)
		//{
//			computeSpectralFeatures->computeFeatures(magSpec.col(t).data(),numRows);
//			// Can now call getFeatureVector at the end
//			// computeSpectralFeatures->getFeatureVector(featureVec);
//			
//		}

		delete featureVec;
		featureVec = nullptr;
		
		delete tempData;
		tempData=nullptr;
	}


	private:
		ScopedPointer<ComputeSpectralFeatures> computeSpectralFeatures;
		
		int numRows, numCols;

		int numSpectralFeatures;
		int numSpectralSubFeatures;
		float* featureVec;

		Eigen::MatrixXf magSpec;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
