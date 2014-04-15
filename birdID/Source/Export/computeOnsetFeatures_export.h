/*
 * computeOnsetFeatures.h
 *
 * Code generation for function 'computeOnsetFeatures'
 *
 * C source code generated on: Mon Apr 14 23:15:23 2014
 *
 */

#ifndef __COMPUTEONSETFEATURES_H__
#define __COMPUTEONSETFEATURES_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "computeOnsetFeatures_types.h"

/* Function Declarations */
extern void computeOnsetFeatures(const emxArray_real_T *denoisedSpectrum, const emxArray_real_T *T, real_T ioiFeatures[12], emxArray_boolean_T *onsets);
extern void computeOnsetFeatures_initialize(void);
extern void computeOnsetFeatures_terminate(void);
extern emxArray_boolean_T *emxCreateND_boolean_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
extern emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
extern emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
extern emxArray_boolean_T *emxCreate_boolean_T(int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
extern void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
#endif
/* End of code generation (computeOnsetFeatures.h) */
