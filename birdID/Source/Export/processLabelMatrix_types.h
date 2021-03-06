/*
 * processLabelMatrix_types.h
 *
 * Code generation for function 'processLabelMatrix'
 *
 * C source code generated on: Sun Mar 30 00:15:01 2014
 *
 */

#ifndef __PROCESSLABELMATRIX_TYPES_H__
#define __PROCESSLABELMATRIX_TYPES_H__

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
/* End of code generation (processLabelMatrix_types.h) */
