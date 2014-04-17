/*
  ==============================================================================

    ComputeCCFeatures.cpp
    Created: 29 Mar 2014 3:12:39pm
    Author:  Aneesh

  ==============================================================================
*/

#include "ComputeCCFeatures.h"

//ComputeCCFeatures::ComputeCCFeatures()
//{
//
//}

ComputeCCFeatures::~ComputeCCFeatures()
{
	delete labelImage;
	labelImage=nullptr;

	delete mask;
	mask = nullptr;

	/*for(int i=0;i<numFeatures;i++)
	{
		delete [] featureVector[i];
	}*/

	//delete featureVector;
	emxDestroyArray_real_T(labels);
	emxDestroyArray_real_T(originalSpec);
	emxDestroyArray_real_T(denoisedSpec);

}


ComputeCCFeatures::ComputeCCFeatures(float* image,int numRows_, int numCols_):cc(150)
{
	numRows = numRows_;
	numCols = numCols_;
	
	// Copy over the array
	labelImage = new int[numCols*numRows];
	mask = new bool[numCols*numRows];
	
	originalSpec = emxCreate_real_T(numRows,numCols);
	denoisedSpec = emxCreate_real_T(numRows,numCols);
	labels = emxCreate_real_T(numRows,numCols);
	//labels = Eigen::MatrixXi(numRows,numCols);
	//pixelValues = Eigen::MatrixXf(numRows,numCols);

	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			//denoisedSpectrogram[i*numRows+j] = static_cast<float>(denoisedSpec->data[i*numRows+j]);
			originalSpec->data[i*numRows+j] = static_cast<real_T>(image[i*numRows+j]);
			mask[i*numRows+j] = (image[i*numRows+j]!=0);
		}
	}

	//mask = pixelValues.cwiseEqual(1).template cast<bool>();
	numFeatures = 4;
	
	extractConnectedComponents();
}

void ComputeCCFeatures::extractConnectedComponents()
{
	//cc.connected(mask,labelImage,numCols,numRows,imageCompare(),true);
	cc.connected(mask,labelImage,numCols,numRows,std::equal_to<bool>(),true);
}

void ComputeCCFeatures::performCCDenoising(float* denoisedSpectrum)
{
	
	// Copy over the labelImage to emxarray
	
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			labels->data[i*numRows+j] = static_cast<real_T>(labelImage[i*numRows+j]) ;
		}
	}
	
	processLabelMatrix_initialize();

	processLabelMatrix(labels,originalSpec,denoisedSpec);
	
	// Copying the denoised spectrum
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			denoisedSpectrum[i*numRows+j] = static_cast<float>(denoisedSpec->data[i*numRows+j]);
		}
	}

	// Adding clearing the old matrices
	//emxDestroyArray_real_T(originalSpec);
	//emxDestroyArray_real_T(labels);
	//emxDestroyArray_real_T(denoisedSpec);


	// The library labels components of zero's as well.
	// Removing the components with zeros
	//relabelComponents();

	// Store the maximum number of labels, useful for feature extraction
	//numLabels = labels.maxCoeff();
	
	// Allocate feature vectors
	//featureVector = new float*[numFeatures];
	//for(int i=0;i<numFeatures;i++)
	//{
	//	featureVector[i] = new float[numLabels];
	//}

}

//void ComputeCCFeatures::computeFeatures()
//{
//	// Calculate features in order
//	featurePerimeter(0);
//	featureArea(0);
//}
//
//void ComputeCCFeatures::featureArea(int indexInFeatureVector)
//{
//	
//	for(int i=0;i<numLabels;i++)
//	{
//		featureVector[indexInFeatureVector][i] = labels.cwiseEqual(i).count();
//	}
//	
//}
//
//void ComputeCCFeatures::featureWeightedCentroid(int indexInFeatureVector)
//{
//	for(int i=0;i<numLabels;i++)
//	{
//		featureVector[indexInFeatureVector][i] = labels.cwiseEqual(i).count();
//	}
//}
//
//
//void ComputeCCFeatures::featurePerimeter(int indexInFeatureVector)
//{
//	
//	Eigen::MatrixXi res = labels.cwiseEqual(1).template cast<int>();
//	//labels.template cast<int>();
//
//	// Every pixel that has a neighbouring pixel of a different index is a border pixel
//	for(int i=0;i<numLabels;i++)
//	{
//		
//	}
//	
//}
//
//void ComputeCCFeatures::relabelComponents()
//{
////	// Work on the labels matrix, remove the ones with zeros
////	int max = labels.maxCoeff();
////	// Loop backwards, should be more effecient
////	for(int i=max;i>0;i--)
////	{
////		
////		// Find pixels from that value
////		Eigen::MatrixXi res = labels.cwiseEqual(i).template cast<int>();
////		// Find the sum of the pixels
//////		float sum = res.cwiseProduct(pixelValues).sum();
////		// If the sum is less than a threshold, remove this index
////		if(sum<=0.001)
////		{
////			// Invert the matrix
////		//	res = res.cwiseEqual(0).template cast<int>();
////			// Remove that label
////		
////
////		}
////
////	}
//
//	// The labels will not be in order
//
//
//
//}
