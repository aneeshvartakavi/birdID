/*
 * bufferSTFT.h
 *
 * Code generation for function 'bufferSTFT'
 *
 * C source code generated on: Mon Apr 14 22:51:01 2014
 *
 */

#ifndef __BUFFERSTFT_H__
#define __BUFFERSTFT_H__
/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "bufferSTFT_types.h"

/* Function Declarations */
extern void bufferSTFT(const emxArray_real_T *samples, real_T blockSize, real_T hopSize, emxArray_real_T *magSTFT, emxArray_real_T *phaseSTFT, emxArray_real_T *T);
extern void bufferSTFT_initialize(void);
extern void bufferSTFT_terminate(void);
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
#endif
/* End of code generation (bufferSTFT.h) */
