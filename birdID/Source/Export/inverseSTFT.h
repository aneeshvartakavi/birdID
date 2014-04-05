/*
 * inverseSTFT.h
 *
 * Code generation for function 'inverseSTFT'
 *
 * C source code generated on: Sat Apr 05 16:03:58 2014
 *
 */

#ifndef __INVERSESTFT_H__
#define __INVERSESTFT_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "inverseSTFT_types.h"

/* Function Declarations */
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void inverseSTFT(const emxArray_real_T *magSpec, const emxArray_real_T *phaseSpec, real_T blockSize, real_T hopSize, emxArray_real_T *audioData);
extern void inverseSTFT_initialize(void);
extern void inverseSTFT_terminate(void);
#endif
/* End of code generation (inverseSTFT.h) */
