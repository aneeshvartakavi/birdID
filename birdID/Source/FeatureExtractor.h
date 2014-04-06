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

//#include "Features\ComputeSpectralFeatures.h"
#include "Features\ComputeCSpecFeatures.h"
#include "Features\ComputePitchFeatures.h"
#include "Features\ComputeMFCCFeatures.h"
#include "Features\ComputeBWFeatures.h"

class FeatureExtractor
{

public:
		
	FeatureExtractor(float* magnitudeSpectrum_, int numRows_,int numCols_, File& audioFile_,ScopedPointer<emxArray_real_T> denoisedAudio)
	{
		
		numRows = numRows_;
		numCols = numCols_;
		magSpec = new float[numRows*numCols];
		// Deep copy spectrum
		for(int i=0;i<numRows*numCols;i++)
		{
			magSpec[i] = magnitudeSpectrum_[i];
		}
		
		//computeSpectralFeatures = new ComputeSpectralFeatures();
		

		blockSize = 1024;
		hopSize = 512;
		audioFile = audioFile_;

		computePitchFeatures = new ComputePitchFeatures(blockSize,hopSize);

		computeMFCCFeatures = new ComputeMFCCFeatures(denoisedAudio,16000);
		numMFCCFeatures = computeMFCCFeatures->getNumFeatures();
		mfccFeatures = new float[numMFCCFeatures];

		computeBWFeatures = new ComputeBWFeatures(magSpec,numRows,numCols);
		numBWFeatures = computeBWFeatures->getNumFeatures();
		bwFeatures = new float[numBWFeatures];
		
		computeCSpecFeatures = new ComputeCSpecFeatures(magSpec,numRows,numCols);
		numCSpectralFeatures = computeCSpecFeatures->getNumFeatures();
		spectralFeatures = new float[numCSpectralFeatures];

		featureVector = new float[numMFCCFeatures+numBWFeatures+numCSpectralFeatures];

	}

	~FeatureExtractor()
	{
		//computeSpectralFeatures = nullptr;
		computeCSpecFeatures = nullptr;
		computeBWFeatures = nullptr;
		computePitchFeatures = nullptr;

		// TODO - Delete all feature vectors
	}


	// Call to set the number of features and subfeatures to extract
	//void setSpectralFeatureExtractionProperties(int featuresToCompute = 1023,int subFeaturesToCompute = 15)
	//{
	//	computeSpectralFeatures->setSpectralFeatureExtractionProps(numRows,featuresToCompute,subFeaturesToCompute);
	//	
	//	numSpectralFeatures = computeSpectralFeatures->getNumFeatures();
	//	numSpectralSubFeatures = computeSpectralFeatures->getNumSubFeatures();
	//}


	void extractFeatures()
	{
		
		// First compute BW features
		computeBWFeatures->extractFeatures();
		computeBWFeatures->returnFeatures(bwFeatures);
		
		computeCSpecFeatures->extractFeatures();
		computeCSpecFeatures->returnFeatures(spectralFeatures);

		// Compute mfcc and derivative features
		computeMFCCFeatures->extractMFCCFeatures();
		computeMFCCFeatures->returnMFCCFeatures(mfccFeatures);

		// Copy them all to the feature vector
		for(int i=0;i<numBWFeatures;i++)
		{
			featureVector[i] = bwFeatures[i];
		}

		for(int i=0;i<numCSpectralFeatures;i++)
		{
			featureVector[i+numBWFeatures] = spectralFeatures[i];
		}

		for(int i=0;i<numMFCCFeatures;i++)
		{
			featureVector[i+numBWFeatures+numCSpectralFeatures] = mfccFeatures[i];
		}

		//float *tempData = new float[513];
		//float* featureVec = new float[numSpectralFeatures*numSpectralSubFeatures];

		//// Extract columns of magnitude spectrum
		//for(int i=0;i<numCols;i++)
		//{
		//	for(int j=0;j<numRows;j++)
		//	{
		//		tempData[j] = magSpec[i*numRows+j];
		//	}
		//	// Compute features
		//	computeSpectralFeatures->computeFeatures(tempData);

		//}

		// Get resulting subfeatures - Move this to a return featureVector function

		//computeSpectralFeatures->getSubFeatureVector(featureVec,numSpectralFeatures*numSpectralSubFeatures);

		
//		computePitchFeatures->computeFeatures(audioFile);

		//delete featureVec;
		//featureVec = nullptr;
		//
		//delete tempData;
		//tempData=nullptr;
	}

	void scaleFeatureVector(float* featureVector_)
	{
		// Uses the saved text files min and range to scale each of the features in the featureVector_

	}


	private:
		
		//ScopedPointer<ComputeSpectralFeatures> computeSpectralFeatures;
		ScopedPointer<ComputeCSpecFeatures> computeCSpecFeatures;
		ScopedPointer<ComputePitchFeatures> computePitchFeatures;
		ScopedPointer<ComputeMFCCFeatures> computeMFCCFeatures;
		ScopedPointer<ComputeBWFeatures> computeBWFeatures;
		
		// Used for features
		float* mfccFeatures;
		float* bwFeatures;
		float* spectralFeatures;

		// Used for Pitch features
		int blockSize;	
		int hopSize;

		int numRows, numCols;

		//int numSpectralFeatures;
		//int numSpectralSubFeatures;
		int numCSpectralFeatures;
		int numMFCCFeatures;
		int numBWFeatures;
		//int numMFCCFeatures;
		
		float* featureVector;

		float *magSpec;

		File audioFile;
};



#endif  // FEATUREEXTRACTOR_H_INCLUDED
