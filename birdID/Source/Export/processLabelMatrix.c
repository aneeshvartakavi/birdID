/*
 * processLabelMatrix.c
 *
 * Code generation for function 'processLabelMatrix'
 *
 * C source code generated on: Sun Mar 30 00:15:01 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "processLabelMatrix.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

/* Function Declarations */
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static real_T b_sum(const emxArray_real_T *x);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);
static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void sum(const emxArray_boolean_T *x, emxArray_real_T *y);

/* Function Definitions */
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T b_sum(const emxArray_real_T *x)
{
  real_T y;
  int32_T k;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

static int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  int32_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if ((uint32_T)quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  int32_T i;
  int32_T j;
  n = x->size[0] * x->size[1];
  k = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  j = y->size[0];
  y->size[0] = k;
  emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(int32_T));
  j = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
  }
}

static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx)
{
  int32_T nxin;
  int32_T k0;
  int32_T k;
  int32_T nxout;
  emxArray_real_T *b_x;
  nxin = x->size[0];
  k0 = 0;
  for (k = 1; k <= idx->size[0]; k++) {
    k0 += idx->data[k - 1];
  }

  nxout = x->size[0] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx->size[0]) || (!idx->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  if (x->size[0] != 1) {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    emxInit_real_T(&b_x, 1);
    nxout = b_x->size[0];
    b_x->size[0] = k0;
    emxEnsureCapacity((emxArray__common *)b_x, nxout, (int32_T)sizeof(real_T));
    for (nxout = 0; nxout < k0; nxout++) {
      b_x->data[nxout] = x->data[nxout];
    }

    nxout = x->size[0];
    x->size[0] = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)x, nxout, (int32_T)sizeof(real_T));
    k0 = b_x->size[0];
    for (nxout = 0; nxout < k0; nxout++) {
      x->data[nxout] = b_x->data[nxout];
    }

    emxFree_real_T(&b_x);
  } else {
    if (1 > nxout) {
      k0 = -1;
    } else {
      k0 = 0;
    }

    emxInit_real_T(&b_x, 1);
    nxout = b_x->size[0];
    b_x->size[0] = k0 + 1;
    emxEnsureCapacity((emxArray__common *)b_x, nxout, (int32_T)sizeof(real_T));
    nxout = 0;
    while (nxout <= k0) {
      b_x->data[0] = x->data[0];
      nxout = 1;
    }

    nxout = x->size[0];
    x->size[0] = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)x, nxout, (int32_T)sizeof(real_T));
    k0 = b_x->size[0];
    for (nxout = 0; nxout < k0; nxout++) {
      x->data[nxout] = b_x->data[nxout];
    }

    emxFree_real_T(&b_x);
  }
}

static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T dim;
  int32_T vlen;
  emxArray_real_T *vwork;
  int32_T i2;
  int32_T vstride;
  int32_T k;
  emxArray_int32_T *iidx;
  emxArray_int32_T *idx0;
  int32_T i1;
  int32_T j;
  uint32_T unnamed_idx_0;
  boolean_T p;
  int32_T b_j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    vlen = x->size[0] - 1;
  } else {
    vlen = 0;
  }

  emxInit_real_T(&vwork, 1);
  i2 = vwork->size[0];
  vwork->size[0] = vlen + 1;
  emxEnsureCapacity((emxArray__common *)vwork, i2, (int32_T)sizeof(real_T));
  i2 = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)y, i2, (int32_T)sizeof(real_T));
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  emxInit_int32_T(&iidx, 1);
  emxInit_int32_T(&idx0, 1);
  i1 = 0;
  for (j = 1; j <= vstride; j++) {
    i1++;
    dim = i1;
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[dim - 1];
      dim += vstride;
    }

    unnamed_idx_0 = (uint32_T)vwork->size[0];
    i2 = iidx->size[0];
    iidx->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity((emxArray__common *)iidx, i2, (int32_T)sizeof(int32_T));
    if (vwork->size[0] == 0) {
    } else {
      for (k = 1; k <= vwork->size[0]; k++) {
        iidx->data[k - 1] = k;
      }

      for (k = 1; k <= vwork->size[0] - 1; k += 2) {
        if ((vwork->data[k - 1] <= vwork->data[k]) || rtIsNaN(vwork->data[k])) {
          p = TRUE;
        } else {
          p = FALSE;
        }

        if (p) {
        } else {
          iidx->data[k - 1] = k + 1;
          iidx->data[k] = k;
        }
      }

      i2 = idx0->size[0];
      idx0->size[0] = vwork->size[0];
      emxEnsureCapacity((emxArray__common *)idx0, i2, (int32_T)sizeof(int32_T));
      dim = vwork->size[0];
      for (i2 = 0; i2 < dim; i2++) {
        idx0->data[i2] = 1;
      }

      dim = 2;
      while (dim < vwork->size[0]) {
        i2 = dim << 1;
        b_j = 1;
        for (pEnd = 1 + dim; pEnd < vwork->size[0] + 1; pEnd = qEnd + dim) {
          b_p = b_j;
          q = pEnd - 1;
          qEnd = b_j + i2;
          if (qEnd > vwork->size[0] + 1) {
            qEnd = vwork->size[0] + 1;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if ((vwork->data[iidx->data[b_p - 1] - 1] <= vwork->data[iidx->
                 data[q] - 1]) || rtIsNaN(vwork->data[iidx->data[q] - 1])) {
              p = TRUE;
            } else {
              p = FALSE;
            }

            if (p) {
              idx0->data[k] = iidx->data[b_p - 1];
              b_p++;
              if (b_p == pEnd) {
                while (q + 1 < qEnd) {
                  k++;
                  idx0->data[k] = iidx->data[q];
                  q++;
                }
              }
            } else {
              idx0->data[k] = iidx->data[q];
              q++;
              if (q + 1 == qEnd) {
                while (b_p < pEnd) {
                  k++;
                  idx0->data[k] = iidx->data[b_p - 1];
                  b_p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k + 1 <= kEnd; k++) {
            iidx->data[(b_j + k) - 1] = idx0->data[k];
          }

          b_j = qEnd;
        }

        dim = i2;
      }
    }

    dim = i1;
    for (k = 0; k <= vlen; k++) {
      y->data[dim - 1] = vwork->data[iidx->data[k] - 1];
      dim += vstride;
    }
  }

  emxFree_int32_T(&idx0);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      i <<= 1;
    }

    newData = calloc((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = TRUE;
  }
}

static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void sum(const emxArray_boolean_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T ixstart;
  int32_T k;
  int32_T ix;
  int32_T iy;
  int32_T i;
  real_T s;
  for (ixstart = 0; ixstart < 2; ixstart++) {
    sz[ixstart] = (uint32_T)x->size[ixstart];
  }

  ixstart = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)y, ixstart, (int32_T)sizeof(real_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ixstart = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ixstart, (int32_T)sizeof(real_T));
    ixstart = y->size[0] * y->size[1];
    y->size[1] = (int32_T)sz[1];
    emxEnsureCapacity((emxArray__common *)y, ixstart, (int32_T)sizeof(real_T));
    k = (int32_T)sz[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      y->data[ixstart] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[0]; k++) {
        ix++;
        s += (real_T)x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

//emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size)
//{
//  emxArray_real_T *emx;
//  int32_T numEl;
//  int32_T i;
//  b_emxInit_real_T(&emx, numDimensions);
//  numEl = 1;
//  for (i = 0; i < numDimensions; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = (real_T *)calloc((uint32_T)numEl, sizeof(real_T));
//  emx->numDimensions = numDimensions;
//  emx->allocatedSize = numEl;
//  return emx;
//}
//
//emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions,
//  int32_T *size)
//{
//  emxArray_real_T *emx;
//  int32_T numEl;
//  int32_T i;
//  b_emxInit_real_T(&emx, numDimensions);
//  numEl = 1;
//  for (i = 0; i < numDimensions; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = data;
//  emx->numDimensions = numDimensions;
//  emx->allocatedSize = numEl;
//  emx->canFreeData = FALSE;
//  return emx;
//}
//
//emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T
//  cols)
//{
//  emxArray_real_T *emx;
//  int32_T size[2];
//  int32_T numEl;
//  int32_T i;
//  size[0] = rows;
//  size[1] = cols;
//  b_emxInit_real_T(&emx, 2);
//  numEl = 1;
//  for (i = 0; i < 2; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = data;
//  emx->numDimensions = 2;
//  emx->allocatedSize = numEl;
//  emx->canFreeData = FALSE;
//  return emx;
//}
//
//emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols)
//{
//  emxArray_real_T *emx;
//  int32_T size[2];
//  int32_T numEl;
//  int32_T i;
//  size[0] = rows;
//  size[1] = cols;
//  b_emxInit_real_T(&emx, 2);
//  numEl = 1;
//  for (i = 0; i < 2; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = (real_T *)calloc((uint32_T)numEl, sizeof(real_T));
//  emx->numDimensions = 2;
//  emx->allocatedSize = numEl;
//  return emx;
//}
//
//void emxDestroyArray_real_T(emxArray_real_T *emxArray)
//{
//  emxFree_real_T(&emxArray);
//}

void processLabelMatrix(emxArray_real_T *labels, const emxArray_real_T
  *originalSpec, emxArray_real_T *denoisedSpec)
{
  uint32_T outsz[2];
  int32_T ixstop;
  emxArray_real_T *maxval;
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T cdiff;
  int32_T apnd;
  boolean_T exitg5;
  boolean_T exitg4;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_labels;
  emxArray_boolean_T *c_labels;
  real_T ndbl;
  emxArray_real_T *labels_left;
  int32_T d_labels[1];
  emxArray_real_T e_labels;
  real_T b_apnd;
  uint32_T absb;
  uint32_T u0;
  emxArray_real_T *y;
  emxArray_boolean_T *r0;
  emxArray_boolean_T *f_labels;
  boolean_T exitg3;
  boolean_T exitg2;
  emxArray_boolean_T *x;
  emxArray_real_T *b_x;
  emxArray_boolean_T *g_labels;
  emxArray_int32_T *b_ii;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  int32_T h_labels[1];
  uint32_T u1;
  emxArray_boolean_T *i_labels;

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  for (ixstop = 0; ixstop < 2; ixstop++) {
    outsz[ixstop] = (uint32_T)labels->size[ixstop];
  }

  b_emxInit_real_T(&maxval, 2);
  ixstop = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, ixstop, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= labels->size[1]; i++) {
    ixstart = ix;
    ixstop = ix + labels->size[0];
    cdiff = labels->data[ix];
    if (labels->size[0] > 1) {
      if (rtIsNaN(labels->data[ix])) {
        apnd = ix + 1;
        exitg5 = FALSE;
        while ((exitg5 == FALSE) && (apnd + 1 <= ixstop)) {
          ixstart = apnd;
          if (!rtIsNaN(labels->data[apnd])) {
            cdiff = labels->data[apnd];
            exitg5 = TRUE;
          } else {
            apnd++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        for (apnd = ixstart + 1; apnd + 1 <= ixstop; apnd++) {
          if (labels->data[apnd] > cdiff) {
            cdiff = labels->data[apnd];
          }
        }
      }
    }

    iy++;
    maxval->data[iy] = cdiff;
    ix += labels->size[0];
  }

  ixstart = 1;
  cdiff = maxval->data[0];
  if (maxval->size[1] > 1) {
    if (rtIsNaN(maxval->data[0])) {
      ix = 2;
      exitg4 = FALSE;
      while ((exitg4 == FALSE) && (ix <= maxval->size[1])) {
        ixstart = ix;
        if (!rtIsNaN(maxval->data[ix - 1])) {
          cdiff = maxval->data[ix - 1];
          exitg4 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < maxval->size[1]) {
      while (ixstart + 1 <= maxval->size[1]) {
        if (maxval->data[ixstart] > cdiff) {
          cdiff = maxval->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  /*  Avoid label zero */
  /*  Compute area */
  i = 0;
  emxInit_int32_T(&ii, 1);
  emxInit_boolean_T(&b_labels, 2);
  emxInit_boolean_T(&c_labels, 2);
  while (i <= (int32_T)cdiff - 1) {
    ixstop = c_labels->size[0] * c_labels->size[1];
    c_labels->size[0] = labels->size[0];
    c_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)c_labels, ixstop, (int32_T)sizeof
                      (boolean_T));
    ix = labels->size[0] * labels->size[1];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      c_labels->data[ixstop] = (labels->data[ixstop] == 1.0 + (real_T)i);
    }

    sum(c_labels, maxval);
    ndbl = b_sum(maxval);
    if (ndbl <= 30.0) {
      /*  Set that label to zero */
      ixstop = b_labels->size[0] * b_labels->size[1];
      b_labels->size[0] = labels->size[0];
      b_labels->size[1] = labels->size[1];
      emxEnsureCapacity((emxArray__common *)b_labels, ixstop, (int32_T)sizeof
                        (boolean_T));
      ix = labels->size[0] * labels->size[1];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        b_labels->data[ixstop] = (labels->data[ixstop] == 1.0 + (real_T)i);
      }

      eml_li_find(b_labels, ii);
      ix = ii->size[0];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        labels->data[ii->data[ixstop] - 1] = 0.0;
      }
    }

    i++;
  }

  emxFree_boolean_T(&c_labels);
  emxFree_boolean_T(&b_labels);
  emxInit_real_T(&labels_left, 1);

  /*  Re-ordering labels */
  d_labels[0] = labels->size[0] * labels->size[1];
  e_labels = *labels;
  e_labels.size = (int32_T *)&d_labels;
  e_labels.numDimensions = 1;
  eml_sort(&e_labels, labels_left);
  if ((real_T)labels_left->size[0] - 1.0 < 1.0) {
    iy = -1;
    b_apnd = (real_T)labels_left->size[0] - 1.0;
  } else {
    ndbl = floor((((real_T)labels_left->size[0] - 1.0) - 1.0) + 0.5);
    b_apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - ((real_T)labels_left->size[0] - 1.0);
    absb = (uint32_T)fabs((real_T)labels_left->size[0] - 1.0);
    if (1U > absb) {
      u0 = 1U;
    } else {
      u0 = absb;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)u0) {
      ndbl++;
      b_apnd = (real_T)labels_left->size[0] - 1.0;
    } else if (cdiff > 0.0) {
      b_apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    iy = (int32_T)ndbl - 1;
  }

  ixstop = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = iy + 1;
  emxEnsureCapacity((emxArray__common *)maxval, ixstop, (int32_T)sizeof(real_T));
  if (iy + 1 > 0) {
    maxval->data[0] = 1.0;
    if (iy + 1 > 1) {
      maxval->data[iy] = b_apnd;
      ix = iy / 2;
      for (ixstart = 1; ixstart < ix; ixstart++) {
        maxval->data[ixstart] = 1.0 + (real_T)ixstart;
        maxval->data[iy - ixstart] = b_apnd - (real_T)ixstart;
      }

      if (ix << 1 == iy) {
        maxval->data[ix] = (1.0 + b_apnd) / 2.0;
      } else {
        maxval->data[ix] = 1.0 + (real_T)ix;
        maxval->data[ix + 1] = b_apnd - (real_T)ix;
      }
    }
  }

  if (labels_left->size[0] < 2) {
    iy = -1;
    apnd = labels_left->size[0];
  } else {
    ix = (int32_T)floor(((real_T)labels_left->size[0] - 2.0) + 0.5) + 2;
    apnd = ix;
    iy = ix - labels_left->size[0];
    ixstart = labels_left->size[0];
    if (fabs(iy) < 4.4408920985006262E-16 * (real_T)ixstart) {
      ix++;
      apnd = labels_left->size[0];
    } else if (iy > 0) {
      apnd = ix - 1;
    } else {
      ix++;
    }

    iy = ix - 3;
  }

  b_emxInit_real_T(&y, 2);
  ixstop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = iy + 1;
  emxEnsureCapacity((emxArray__common *)y, ixstop, (int32_T)sizeof(real_T));
  if (iy + 1 > 0) {
    y->data[0] = 2.0;
    if (iy + 1 > 1) {
      y->data[iy] = apnd;
      ix = iy / 2;
      for (ixstart = 1; ixstart < ix; ixstart++) {
        y->data[ixstart] = 2.0 + (real_T)ixstart;
        y->data[iy - ixstart] = apnd - ixstart;
      }

      if (ix << 1 == iy) {
        y->data[ix] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ix] = 2.0 + (real_T)ix;
        y->data[ix + 1] = apnd - ix;
      }
    }
  }

  b_emxInit_boolean_T(&r0, 1);
  ixstop = r0->size[0];
  r0->size[0] = maxval->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixstop, (int32_T)sizeof(boolean_T));
  ix = maxval->size[1];
  for (ixstop = 0; ixstop < ix; ixstop++) {
    r0->data[ixstop] = (labels_left->data[(int32_T)maxval->data[ixstop] - 1] ==
                        labels_left->data[(int32_T)y->data[ixstop] - 1]);
  }

  eml_null_assignment(labels_left, r0);
  i = 0;
  emxInit_boolean_T(&f_labels, 2);
  while (i <= (int32_T)((real_T)labels_left->size[0] + -1.0) - 1) {
    ixstop = f_labels->size[0] * f_labels->size[1];
    f_labels->size[0] = labels->size[0];
    f_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)f_labels, ixstop, (int32_T)sizeof
                      (boolean_T));
    ndbl = labels_left->data[(int32_T)(2.0 + (real_T)i) - 1];
    ix = labels->size[0] * labels->size[1];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      f_labels->data[ixstop] = (labels->data[ixstop] == ndbl);
    }

    eml_li_find(f_labels, ii);
    ix = ii->size[0];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      labels->data[ii->data[ixstop] - 1] = (2.0 + (real_T)i) - 1.0;
    }

    i++;
  }

  emxFree_boolean_T(&f_labels);
  for (ixstop = 0; ixstop < 2; ixstop++) {
    outsz[ixstop] = (uint32_T)labels->size[ixstop];
  }

  ixstop = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, ixstop, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= labels->size[1]; i++) {
    ixstart = ix;
    ixstop = ix + labels->size[0];
    cdiff = labels->data[ix];
    if (labels->size[0] > 1) {
      if (rtIsNaN(labels->data[ix])) {
        apnd = ix + 1;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (apnd + 1 <= ixstop)) {
          ixstart = apnd;
          if (!rtIsNaN(labels->data[apnd])) {
            cdiff = labels->data[apnd];
            exitg3 = TRUE;
          } else {
            apnd++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        for (apnd = ixstart + 1; apnd + 1 <= ixstop; apnd++) {
          if (labels->data[apnd] > cdiff) {
            cdiff = labels->data[apnd];
          }
        }
      }
    }

    iy++;
    maxval->data[iy] = cdiff;
    ix += labels->size[0];
  }

  ixstart = 1;
  cdiff = maxval->data[0];
  if (maxval->size[1] > 1) {
    if (rtIsNaN(maxval->data[0])) {
      ix = 2;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (ix <= maxval->size[1])) {
        ixstart = ix;
        if (!rtIsNaN(maxval->data[ix - 1])) {
          cdiff = maxval->data[ix - 1];
          exitg2 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < maxval->size[1]) {
      while (ixstart + 1 <= maxval->size[1]) {
        if (maxval->data[ixstart] > cdiff) {
          cdiff = maxval->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  /*  Compute weighted centroid */
  /*  Avoid zero label */
  i = 0;
  emxInit_boolean_T(&x, 2);
  emxInit_real_T(&b_x, 1);
  emxInit_boolean_T(&g_labels, 2);
  emxInit_int32_T(&b_ii, 1);
  while (i <= (int32_T)cdiff - 1) {
    /*  Get all the y-coords */
    ixstop = x->size[0] * x->size[1];
    x->size[0] = labels->size[0];
    x->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)x, ixstop, (int32_T)sizeof(boolean_T));
    ix = labels->size[0] * labels->size[1];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      x->data[ixstop] = (labels->data[ixstop] == 1.0 + (real_T)i);
    }

    iy = x->size[0] * x->size[1];
    ixstart = 0;
    ixstop = ii->size[0];
    ii->size[0] = iy;
    emxEnsureCapacity((emxArray__common *)ii, ixstop, (int32_T)sizeof(int32_T));
    ix = 1;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (ix <= iy)) {
      guard1 = FALSE;
      if (x->data[ix - 1]) {
        ixstart++;
        ii->data[ixstart - 1] = ix;
        if (ixstart >= iy) {
          exitg1 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        ix++;
      }
    }

    if (iy == 1) {
      if (ixstart == 0) {
        ixstop = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity((emxArray__common *)ii, ixstop, (int32_T)sizeof
                          (int32_T));
      }
    } else {
      if (1 > ixstart) {
        ix = 0;
      } else {
        ix = ixstart;
      }

      ixstop = b_ii->size[0];
      b_ii->size[0] = ix;
      emxEnsureCapacity((emxArray__common *)b_ii, ixstop, (int32_T)sizeof
                        (int32_T));
      for (ixstop = 0; ixstop < ix; ixstop++) {
        b_ii->data[ixstop] = ii->data[ixstop];
      }

      ixstop = ii->size[0];
      ii->size[0] = b_ii->size[0];
      emxEnsureCapacity((emxArray__common *)ii, ixstop, (int32_T)sizeof(int32_T));
      ix = b_ii->size[0];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        ii->data[ixstop] = b_ii->data[ixstop];
      }
    }

    ixstop = labels_left->size[0];
    labels_left->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)labels_left, ixstop, (int32_T)sizeof
                      (real_T));
    ix = ii->size[0];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      labels_left->data[ixstop] = ii->data[ixstop];
    }

    if ((!(labels_left->size[0] == 0)) && (originalSpec->data[(int32_T)
         labels_left->data[0] - 1] != 0.0)) {
      for (ixstop = 0; ixstop < 2; ixstop++) {
        outsz[ixstop] = (uint32_T)originalSpec->size[ixstop];
      }

      ixstop = ii->size[0];
      ii->size[0] = labels_left->size[0];
      emxEnsureCapacity((emxArray__common *)ii, ixstop, (int32_T)sizeof(int32_T));
      ix = labels_left->size[0];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        ii->data[ixstop] = (int32_T)labels_left->data[ixstop] - 1;
      }

      ixstop = ii->size[0];
      emxEnsureCapacity((emxArray__common *)ii, ixstop, (int32_T)sizeof(int32_T));
      ix = ii->size[0];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        ii->data[ixstop] -= div_s32(ii->data[ixstop], (int32_T)outsz[0]) *
          (int32_T)outsz[0];
      }

      ixstop = b_x->size[0];
      b_x->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)b_x, ixstop, (int32_T)sizeof(real_T));
      ix = ii->size[0];
      for (ixstop = 0; ixstop < ix; ixstop++) {
        b_x->data[ixstop] = (real_T)(ii->data[ixstop] + 1) * originalSpec->data
          [(int32_T)labels_left->data[ixstop] - 1];
      }

      ndbl = b_x->data[0];
      for (ixstart = 2; ixstart <= b_x->size[0]; ixstart++) {
        ndbl += b_x->data[ixstart - 1];
      }

      b_apnd = originalSpec->data[(int32_T)labels_left->data[0] - 1];
      for (ixstart = 2; ixstart <= labels_left->size[0]; ixstart++) {
        b_apnd += originalSpec->data[(int32_T)labels_left->data[ixstart - 1] - 1];
      }

      /* imagesc(labels==i); */
      if (ndbl / b_apnd <= 20.0) {
        ixstop = g_labels->size[0] * g_labels->size[1];
        g_labels->size[0] = labels->size[0];
        g_labels->size[1] = labels->size[1];
        emxEnsureCapacity((emxArray__common *)g_labels, ixstop, (int32_T)sizeof
                          (boolean_T));
        ix = labels->size[0] * labels->size[1];
        for (ixstop = 0; ixstop < ix; ixstop++) {
          g_labels->data[ixstop] = (labels->data[ixstop] == 1.0 + (real_T)i);
        }

        eml_li_find(g_labels, ii);
        ix = ii->size[0];
        for (ixstop = 0; ixstop < ix; ixstop++) {
          labels->data[ii->data[ixstop] - 1] = 0.0;
        }
      }
    }

    i++;
  }

  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&g_labels);
  emxFree_real_T(&b_x);
  emxFree_boolean_T(&x);
  h_labels[0] = labels->size[0] * labels->size[1];
  e_labels = *labels;
  e_labels.size = (int32_T *)&h_labels;
  e_labels.numDimensions = 1;
  eml_sort(&e_labels, labels_left);
  if ((real_T)labels_left->size[0] - 1.0 < 1.0) {
    iy = -1;
    b_apnd = (real_T)labels_left->size[0] - 1.0;
  } else {
    ndbl = floor((((real_T)labels_left->size[0] - 1.0) - 1.0) + 0.5);
    b_apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - ((real_T)labels_left->size[0] - 1.0);
    absb = (uint32_T)fabs((real_T)labels_left->size[0] - 1.0);
    if (1U > absb) {
      u1 = 1U;
    } else {
      u1 = absb;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)u1) {
      ndbl++;
      b_apnd = (real_T)labels_left->size[0] - 1.0;
    } else if (cdiff > 0.0) {
      b_apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    iy = (int32_T)ndbl - 1;
  }

  ixstop = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = iy + 1;
  emxEnsureCapacity((emxArray__common *)maxval, ixstop, (int32_T)sizeof(real_T));
  if (iy + 1 > 0) {
    maxval->data[0] = 1.0;
    if (iy + 1 > 1) {
      maxval->data[iy] = b_apnd;
      ix = iy / 2;
      for (ixstart = 1; ixstart < ix; ixstart++) {
        maxval->data[ixstart] = 1.0 + (real_T)ixstart;
        maxval->data[iy - ixstart] = b_apnd - (real_T)ixstart;
      }

      if (ix << 1 == iy) {
        maxval->data[ix] = (1.0 + b_apnd) / 2.0;
      } else {
        maxval->data[ix] = 1.0 + (real_T)ix;
        maxval->data[ix + 1] = b_apnd - (real_T)ix;
      }
    }
  }

  if (labels_left->size[0] < 2) {
    iy = -1;
    apnd = labels_left->size[0];
  } else {
    ix = (int32_T)floor(((real_T)labels_left->size[0] - 2.0) + 0.5) + 2;
    apnd = ix;
    iy = ix - labels_left->size[0];
    ixstart = labels_left->size[0];
    if (fabs(iy) < 4.4408920985006262E-16 * (real_T)ixstart) {
      ix++;
      apnd = labels_left->size[0];
    } else if (iy > 0) {
      apnd = ix - 1;
    } else {
      ix++;
    }

    iy = ix - 3;
  }

  ixstop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = iy + 1;
  emxEnsureCapacity((emxArray__common *)y, ixstop, (int32_T)sizeof(real_T));
  if (iy + 1 > 0) {
    y->data[0] = 2.0;
    if (iy + 1 > 1) {
      y->data[iy] = apnd;
      ix = iy / 2;
      for (ixstart = 1; ixstart < ix; ixstart++) {
        y->data[ixstart] = 2.0 + (real_T)ixstart;
        y->data[iy - ixstart] = apnd - ixstart;
      }

      if (ix << 1 == iy) {
        y->data[ix] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ix] = 2.0 + (real_T)ix;
        y->data[ix + 1] = apnd - ix;
      }
    }
  }

  ixstop = r0->size[0];
  r0->size[0] = maxval->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixstop, (int32_T)sizeof(boolean_T));
  ix = maxval->size[1];
  for (ixstop = 0; ixstop < ix; ixstop++) {
    r0->data[ixstop] = (labels_left->data[(int32_T)maxval->data[ixstop] - 1] ==
                        labels_left->data[(int32_T)y->data[ixstop] - 1]);
  }

  emxFree_real_T(&y);
  emxFree_real_T(&maxval);
  eml_null_assignment(labels_left, r0);
  i = 0;
  emxFree_boolean_T(&r0);
  emxInit_boolean_T(&i_labels, 2);
  while (i <= (int32_T)((real_T)labels_left->size[0] + -1.0) - 1) {
    ixstop = i_labels->size[0] * i_labels->size[1];
    i_labels->size[0] = labels->size[0];
    i_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)i_labels, ixstop, (int32_T)sizeof
                      (boolean_T));
    ndbl = labels_left->data[(int32_T)(2.0 + (real_T)i) - 1];
    ix = labels->size[0] * labels->size[1];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      i_labels->data[ixstop] = (labels->data[ixstop] == ndbl);
    }

    eml_li_find(i_labels, ii);
    ix = ii->size[0];
    for (ixstop = 0; ixstop < ix; ixstop++) {
      labels->data[ii->data[ixstop] - 1] = (2.0 + (real_T)i) - 1.0;
    }

    i++;
  }

  emxFree_boolean_T(&i_labels);
  emxFree_int32_T(&ii);
  emxFree_real_T(&labels_left);
  ixstop = denoisedSpec->size[0] * denoisedSpec->size[1];
  denoisedSpec->size[0] = labels->size[0];
  denoisedSpec->size[1] = labels->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstop, (int32_T)sizeof
                    (real_T));
  ix = labels->size[0] * labels->size[1];
  for (ixstop = 0; ixstop < ix; ixstop++) {
    denoisedSpec->data[ixstop] = (real_T)(labels->data[ixstop] != 0.0) *
      originalSpec->data[ixstop];
  }
}

void processLabelMatrix_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void processLabelMatrix_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (processLabelMatrix.c) */
