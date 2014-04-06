/*
 * featureMFCCAndDerivative_types.h
 *
 * Code generation for function 'featureMFCCAndDerivative'
 *
 * C source code generated on: Sat Apr 05 16:27:04 2014
 *
 */

#ifndef __FEATUREMFCCANDDERIVATIVE_TYPES_H__
#define __FEATUREMFCCANDDERIVATIVE_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T_1x1
#define struct_emxArray_int32_T_1x1
struct emxArray_int32_T_1x1
{
    int32_T data[1];
    int32_T size[2];
};
#endif /*struct_emxArray_int32_T_1x1*/
#ifndef typedef_emxArray_int32_T_1x1
#define typedef_emxArray_int32_T_1x1
typedef struct emxArray_int32_T_1x1 emxArray_int32_T_1x1;
#endif /*typedef_emxArray_int32_T_1x1*/
#ifndef struct_emxArray_int32_T_1x34
#define struct_emxArray_int32_T_1x34
struct emxArray_int32_T_1x34
{
    int32_T data[34];
    int32_T size[2];
};
#endif /*struct_emxArray_int32_T_1x34*/
#ifndef typedef_emxArray_int32_T_1x34
#define typedef_emxArray_int32_T_1x34
typedef struct emxArray_int32_T_1x34 emxArray_int32_T_1x34;
#endif /*typedef_emxArray_int32_T_1x34*/
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
#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1
{
    real_T data[1];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x1*/
#ifndef typedef_emxArray_real_T_1x1
#define typedef_emxArray_real_T_1x1
typedef struct emxArray_real_T_1x1 emxArray_real_T_1x1;
#endif /*typedef_emxArray_real_T_1x1*/

#endif
/* End of code generation (featureMFCCAndDerivative_types.h) */
