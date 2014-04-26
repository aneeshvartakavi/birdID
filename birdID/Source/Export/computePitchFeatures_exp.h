/*
 * computePitchFeatures_exp.h
 *
 * Code generation for function 'computePitchFeatures_exp'
 *
 * C source code generated on: Sat Apr 26 01:29:18 2014
 *
 */

#ifndef __COMPUTEPITCHFEATURES_EXP_H__
#define __COMPUTEPITCHFEATURES_EXP_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "computePitchFeatures_exp_types.h"

/* Function Declarations */
extern void computePitchFeatures_exp(const emxArray_real_T *pitch, const emxArray_real_T *denoisedSpectrogram, const emxArray_boolean_T *onsets, const emxArray_real_T *T, real_T Fs1, real_T fileLength, real_T featureVector[10]);
extern void computePitchFeatures_exp_initialize(void);
extern void computePitchFeatures_exp_terminate(void);
//extern emxArray_boolean_T *emxCreateND_boolean_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_boolean_T *emxCreate_boolean_T(int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
//extern void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
#endif
/* End of code generation (computePitchFeatures_exp.h) */
