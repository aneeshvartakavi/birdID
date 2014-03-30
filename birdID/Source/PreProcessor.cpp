/*
  ==============================================================================

	PreProcessor.cpp
	Created: 27 Mar 2014 10:15:17pm
	Author:  Aneesh

  ==============================================================================
*/

#include "PreProcessor.h"
PreProcessor::PreProcessor(Eigen::MatrixXf& stft)//:cc(150)
{
	numRows  = stft.rows();
	numCols = stft.cols();
	
	//numRows = 10;
	//numCols = 4;
	// Allocate memory
	originalSpec = emxCreate_real_T(numRows,numCols);
	denoisedSpec = emxCreate_real_T(numRows,numCols);


	// Copy the array
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			//originalSpec->data[i*numRows+j] = static_cast<real_T>(j);
			originalSpec->data[i*numRows+j] = static_cast<real_T>(stft(j,i));
		}
	}

	// Specifying soft max number of labels.
	//cc = ConnectedComponents(150);

}

PreProcessor::~PreProcessor()
{
	
	delete denoisedSpectrogram;
	denoisedSpectrogram = nullptr;
	// Cleanup
	ccFeatures = nullptr;
	
}

void PreProcessor::process()
{
	// Call spectal denoising
	DenoiseSpectrogram();
	// Call connected component denoising
	ccDenoising();

	//CCDenoising();
	
	//extractCCFeatures();
}


void PreProcessor::DenoiseSpectrogram()
{
	denoiseSpectrogram_initialize();
	// Call the exported function
	denoiseSpectrogram(originalSpec,denoisedSpec);
	// Destroy the first one
	emxDestroyArray_real_T(originalSpec);
	// Copy the output over
	denoisedSpectrogram = new float[numCols*numRows];
	
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			//originalSpec->data[i*numRows+j] = static_cast<real_T>(j);
			denoisedSpectrogram[i*numRows+j] = static_cast<float>(denoisedSpec->data[i*numRows+j]);
			//mask[i*numRows+j] = (denoisedSpectrogram[i*numRows+j]!=0);
		}
	}

	// Delete the old output
	emxDestroyArray_real_T(denoisedSpec);
	
}

void PreProcessor::ccDenoising()
{
	ccFeatures = new ComputeCCFeatures(denoisedSpectrogram,numRows,numCols);
	// The denoised spectrogram is overwritten
	ccFeatures->performCCDenoising(denoisedSpectrogram);
}
