/*
 * computeSpectralFeatures.h
 *
 * Code generation for function 'computeSpectralFeatures'
 *
 * C source code generated on: Sat Apr 05 23:58:53 2014
 *
 */

#ifndef __COMPUTESPECTRALFEATURES_H__
#define __COMPUTESPECTRALFEATURES_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "computeSpectralFeatures_types.h"

/* Function Declarations */
extern void computeSpectralFeatures(const emxArray_real_T *denoisedSpectrum, real_T features[40]);
extern void computeSpectralFeatures_initialize(void);
extern void computeSpectralFeatures_terminate(void);
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
#endif
/* End of code generation (computeSpectralFeatures.h) */
