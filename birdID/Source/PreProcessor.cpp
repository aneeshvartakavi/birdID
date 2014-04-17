/*
  ==============================================================================

	PreProcessor.cpp
	Created: 27 Mar 2014 10:15:17pm
	Author:  Aneesh

  ==============================================================================
*/

#include "PreProcessor.h"
PreProcessor::PreProcessor(emxArray_real_T* magSpec,int numRows_,int numCols_)//:cc(150)
{
	
	numRows = numRows_;
	numCols = numCols_;
	denoisedSpec = emxCreate_real_T(numRows,numCols);
	originalSpec = emxCreate_real_T(numRows,numCols);
	
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			originalSpec->data[i*numRows+j] = magSpec->data[i*numRows+j];
			
		}
	}

}

PreProcessor::~PreProcessor()
{
	delete denoisedSpectrogram;
	denoisedSpectrogram = nullptr;
	
	ccFeatures = nullptr;

	// Delete the old output
	emxDestroyArray_real_T(denoisedSpec);
	emxDestroyArray_real_T(originalSpec);

}

void PreProcessor::process()
{
	// Call spectal denoising
	DenoiseSpectrogram();
	// Call connected component denoising
	ccDenoising();

}


void PreProcessor::DenoiseSpectrogram()
{
	denoiseSpectrogram_initialize();
	// Call the exported function
	denoiseSpectrogram(originalSpec,denoisedSpec);
	// Destroy the first one
	//emxDestroyArray_real_T(originalSpec);
	// Copy the output over
	denoisedSpectrogram = new float[numCols*numRows];
	
	for(int i=0; i<numCols*numRows;i++)
	{
		denoisedSpectrogram[i] = static_cast<float>(denoisedSpec->data[i]);
	}


}

void PreProcessor::ccDenoising()
{
	ccFeatures = new ComputeCCFeatures(denoisedSpectrogram,numRows,numCols);
	// The denoised spectrogram is overwritten
	ccFeatures->performCCDenoising(denoisedSpectrogram);
}

void PreProcessor::returnDenoisedSpectrogram(float* denoisedSpectrogram_)
{
	// Copy over
	for(int i=0;i<numCols;i++)
	{
		for(int j=0;j<numRows;j++)
		{
			denoisedSpectrogram_[i*numRows+j] = denoisedSpectrogram[i*numRows+j];
			
		}
	}
}

void PreProcessor::returnDenoisedSpectrogramEMX(emxArray_real_T* denoisedSpectrogram)
{
	denoisedSpectrogram = denoisedSpec;
}


//
//void PreProcessor::returnDenoisedSpectrogramEMX(ScopedPointer<emxArray_real_T>  denoisedSpectrogram_)
//{
//	denoisedSpectrogram_ = denoisedSpec;
//}