/*
 * processLabelMatrix.h
 *
 * Code generation for function 'processLabelMatrix'
 *
 * C source code generated on: Sat Apr 05 00:03:42 2014
 *
 */

#ifndef __PROCESSLABELMATRIX_H__
#define __PROCESSLABELMATRIX_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "processLabelMatrix_types.h"

/* Function Declarations */
//extern emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions, int32_T *size);
//extern emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T cols);
//extern emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols);
//extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void processLabelMatrix(emxArray_real_T *labels, const emxArray_real_T *originalSpec, emxArray_real_T *denoisedSpec);
extern void processLabelMatrix_initialize(void);
extern void processLabelMatrix_terminate(void);
#endif
/* End of code generation (processLabelMatrix.h) */
