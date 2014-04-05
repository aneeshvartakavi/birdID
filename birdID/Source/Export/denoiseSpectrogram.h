/*
 * denoiseSpectrogram.h
 *
 * Code generation for function 'denoiseSpectrogram'
 *
 * C source code generated on: Fri Apr 04 18:26:22 2014
 *
 */

#ifndef __DENOISESPECTROGRAM_H__
#define __DENOISESPECTROGRAM_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "denoiseSpectrogram_types.h"

/* Function Declarations */
extern void denoiseSpectrogram(emxArray_real_T *spec, emxArray_real_T *denoisedSpec);
extern void denoiseSpectrogram_initialize(void);
extern void denoiseSpectrogram_terminate(void);
extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
#endif
/* End of code generation (denoiseSpectrogram.h) */
