/*
 * featureMFCCAndDerivative.h
 *
 * Code generation for function 'featureMFCCAndDerivative'
 *
 * C source code generated on: Sat Apr 05 17:10:41 2014
 *
 */

#ifndef __FEATUREMFCCANDDERIVATIVE_H__
#define __FEATUREMFCCANDDERIVATIVE_H__
/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "featureMFCCAndDerivative_types.h"

/* Function Declarations */
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void featureMFCCAndDerivative(const emxArray_real_T *denoisedSignal, real_T Fs, real_T featureVector1[64]);
extern void featureMFCCAndDerivative_initialize(void);
extern void featureMFCCAndDerivative_terminate(void);
#endif
/* End of code generation (featureMFCCAndDerivative.h) */
