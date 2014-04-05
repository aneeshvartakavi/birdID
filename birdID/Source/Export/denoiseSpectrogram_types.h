/*
 * denoiseSpectrogram_types.h
 *
 * Code generation for function 'denoiseSpectrogram'
 *
 * C source code generated on: Fri Apr 04 18:26:22 2014
 *
 */

#ifndef __DENOISESPECTROGRAM_TYPES_H__
#define __DENOISESPECTROGRAM_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/

#endif
/* End of code generation (denoiseSpectrogram_types.h) */
