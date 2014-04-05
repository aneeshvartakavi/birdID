/*
 * processLabelMatrix.c
 *
 * Code generation for function 'processLabelMatrix'
 *
 * C source code generated on: Sat Apr 05 00:03:42 2014
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
static void b_eml_sort(const emxArray_real_T *x, emxArray_real_T *y);
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static real_T b_sum(const emxArray_real_T *x);
static void c_eml_sort(const emxArray_real_T *x, emxArray_real_T *y);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);
static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y);
static void eml_sort_idx(const emxArray_real_T *x, emxArray_int32_T *idx);
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
static void b_eml_sort(const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T dim;
  int32_T vlen;
  emxArray_real_T *vwork;
  int32_T i1;
  int32_T vstride;
  int32_T k;
  emxArray_int32_T *iidx;
  int32_T ix;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    vlen = x->size[0] - 1;
  } else {
    vlen = 0;
  }

  b_emxInit_real_T(&vwork, 1);
  i1 = vwork->size[0];
  vwork->size[0] = vlen + 1;
  emxEnsureCapacity((emxArray__common *)vwork, i1, (int32_T)sizeof(real_T));
  i1 = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  emxInit_int32_T(&iidx, 1);
  i1 = 0;
  for (dim = 1; dim <= vstride; dim++) {
    i1++;
    ix = i1;
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[ix - 1];
      ix += vstride;
    }

    eml_sort_idx(vwork, iidx);
    ix = i1;
    for (k = 0; k <= vlen; k++) {
      y->data[ix - 1] = vwork->data[iidx->data[k] - 1];
      ix += vstride;
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

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

static void c_eml_sort(const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_real_T *vwork;
  uint32_T unnamed_idx_0;
  int32_T ix;
  int32_T k;
  emxArray_int32_T *iidx;
  b_emxInit_real_T(&vwork, 1);
  unnamed_idx_0 = (uint32_T)x->size[1];
  ix = vwork->size[0];
  vwork->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)vwork, ix, (int32_T)sizeof(real_T));
  for (ix = 0; ix < 2; ix++) {
    k = y->size[0] * y->size[1];
    y->size[ix] = x->size[ix];
    emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T));
  }

  emxInit_int32_T(&iidx, 1);
  ix = 0;
  for (k = 0; k < x->size[1]; k++) {
    vwork->data[k] = x->data[ix];
    ix++;
  }

  eml_sort_idx(vwork, iidx);
  ix = 0;
  for (k = 0; k < x->size[1]; k++) {
    y->data[ix] = vwork->data[iidx->data[k] - 1];
    ix++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
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

    b_emxInit_real_T(&b_x, 1);
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

    b_emxInit_real_T(&b_x, 1);
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
  emxArray_real_T *vwork;
  uint32_T unnamed_idx_0;
  int32_T vstride;
  int32_T k;
  int32_T vspread;
  int32_T npages;
  int32_T i2;
  int32_T i;
  emxArray_int32_T *iidx;
  int32_T i1;
  int32_T j;
  int32_T ix;
  dim = 1;
  if (x->size[0] != 1) {
    dim = 0;
  }

  b_emxInit_real_T(&vwork, 1);
  unnamed_idx_0 = (uint32_T)x->size[dim];
  vstride = vwork->size[0];
  vwork->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)vwork, vstride, (int32_T)sizeof(real_T));
  for (vstride = 0; vstride < 2; vstride++) {
    k = y->size[0] * y->size[1];
    y->size[vstride] = x->size[vstride];
    emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T));
  }

  vstride = 1;
  k = 1;
  while (k <= dim) {
    vstride *= x->size[0];
    k = 2;
  }

  vspread = (x->size[dim] - 1) * vstride;
  npages = 1;
  k = dim + 2;
  while (k < 3) {
    npages *= x->size[1];
    k = 3;
  }

  i2 = 0;
  i = 1;
  emxInit_int32_T(&iidx, 1);
  while (i <= npages) {
    i1 = i2 - 1;
    i2 += vspread;
    for (j = 1; j <= vstride; j++) {
      i1++;
      i2++;
      ix = i1;
      for (k = 0; k < x->size[dim]; k++) {
        vwork->data[k] = x->data[ix];
        ix += vstride;
      }

      eml_sort_idx(vwork, iidx);
      ix = i1;
      for (k = 0; k < x->size[dim]; k++) {
        y->data[ix] = vwork->data[iidx->data[k] - 1];
        ix += vstride;
      }
    }

    i++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

static void eml_sort_idx(const emxArray_real_T *x, emxArray_int32_T *idx)
{
  uint32_T unnamed_idx_0;
  int32_T k;
  boolean_T p;
  emxArray_int32_T *idx0;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  unnamed_idx_0 = (uint32_T)x->size[0];
  k = idx->size[0];
  idx->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)idx, k, (int32_T)sizeof(int32_T));
  if (x->size[0] == 0) {
  } else {
    for (k = 1; k <= x->size[0]; k++) {
      idx->data[k - 1] = k;
    }

    for (k = 1; k <= x->size[0] - 1; k += 2) {
      if ((x->data[k - 1] <= x->data[k]) || rtIsNaN(x->data[k])) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      if (p) {
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    emxInit_int32_T(&idx0, 1);
    k = idx0->size[0];
    idx0->size[0] = x->size[0];
    emxEnsureCapacity((emxArray__common *)idx0, k, (int32_T)sizeof(int32_T));
    i = x->size[0];
    for (k = 0; k < i; k++) {
      idx0->data[k] = 1;
    }

    i = 2;
    while (i < x->size[0]) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < x->size[0] + 1; pEnd = qEnd + i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > x->size[0] + 1) {
          qEnd = x->size[0] + 1;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((x->data[idx->data[b_p - 1] - 1] <= x->data[idx->data[q] - 1]) ||
              rtIsNaN(x->data[idx->data[q] - 1])) {
            p = TRUE;
          } else {
            p = FALSE;
          }

          if (p) {
            idx0->data[k] = idx->data[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                idx0->data[k] = idx->data[q];
                q++;
              }
            }
          } else {
            idx0->data[k] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                k++;
                idx0->data[k] = idx->data[b_p - 1];
                b_p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          idx->data[(j + k) - 1] = idx0->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&idx0);
  }
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
//
//emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size)
//{
//  emxArray_real_T *emx;
//  int32_T numEl;
//  int32_T i;
//  emxInit_real_T(&emx, numDimensions);
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
//  emxInit_real_T(&emx, numDimensions);
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
//  emxInit_real_T(&emx, 2);
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
//  emxInit_real_T(&emx, 2);
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
  int32_T iy;
  emxArray_real_T *maxval;
  int32_T ix;
  int32_T i;
  int32_T ixstart;
  int32_T i1;
  real_T mtmp;
  int32_T apnd;
  boolean_T exitg5;
  boolean_T exitg4;
  emxArray_real_T *vwork;
  emxArray_real_T *v;
  emxArray_real_T *b_v;
  real_T b_mtmp;
  real_T cdiff;
  int32_T k;
  real_T zeroLabel;
  emxArray_real_T *b_maxval;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_labels;
  emxArray_boolean_T *c_labels;
  emxArray_boolean_T *d_labels;
  int32_T e_labels[1];
  emxArray_real_T f_labels;
  uint32_T absb;
  uint32_T u0;
  emxArray_real_T *y;
  emxArray_boolean_T *r0;
  emxArray_boolean_T *g_labels;
  boolean_T exitg3;
  boolean_T exitg2;
  emxArray_boolean_T *x;
  emxArray_boolean_T *h_labels;
  emxArray_int32_T *b_ii;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  int32_T i_labels[1];
  uint32_T u1;
  emxArray_boolean_T *j_labels;

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  for (iy = 0; iy < 2; iy++) {
    outsz[iy] = (uint32_T)labels->size[iy];
  }

  emxInit_real_T(&maxval, 2);
  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= labels->size[1]; i++) {
    ixstart = ix;
    i1 = ix + labels->size[0];
    mtmp = labels->data[ix];
    if (labels->size[0] > 1) {
      if (rtIsNaN(labels->data[ix])) {
        apnd = ix + 1;
        exitg5 = FALSE;
        while ((exitg5 == FALSE) && (apnd + 1 <= i1)) {
          ixstart = apnd;
          if (!rtIsNaN(labels->data[apnd])) {
            mtmp = labels->data[apnd];
            exitg5 = TRUE;
          } else {
            apnd++;
          }
        }
      }

      if (ixstart + 1 < i1) {
        for (apnd = ixstart + 1; apnd + 1 <= i1; apnd++) {
          if (labels->data[apnd] > mtmp) {
            mtmp = labels->data[apnd];
          }
        }
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += labels->size[0];
  }

  ixstart = 1;
  mtmp = maxval->data[0];
  if (maxval->size[1] > 1) {
    if (rtIsNaN(maxval->data[0])) {
      ix = 2;
      exitg4 = FALSE;
      while ((exitg4 == FALSE) && (ix <= maxval->size[1])) {
        ixstart = ix;
        if (!rtIsNaN(maxval->data[ix - 1])) {
          mtmp = maxval->data[ix - 1];
          exitg4 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < maxval->size[1]) {
      while (ixstart + 1 <= maxval->size[1]) {
        if (maxval->data[ixstart] > mtmp) {
          mtmp = maxval->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  for (iy = 0; iy < 2; iy++) {
    outsz[iy] = (uint32_T)labels->size[iy];
  }

  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
  b_emxInit_real_T(&vwork, 1);
  b_emxInit_real_T(&v, 1);
  if ((labels->size[0] == 0) || (labels->size[1] == 0)) {
    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
    iy = maxval->size[0] * maxval->size[1];
    maxval->size[1] = (int32_T)outsz[1];
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
    i1 = (int32_T)outsz[1];
    for (iy = 0; iy < i1; iy++) {
      maxval->data[iy] = rtNaN;
    }
  } else if ((int32_T)outsz[1] == 1) {
    emxInit_real_T(&b_v, 2);
    eml_sort(labels, b_v);
    b_mtmp = b_v->data[0];
    i1 = 1;
    cdiff = b_v->data[0];
    ixstart = 1;
    iy = b_v->size[0] * b_v->size[1];
    for (k = 0; k < (int32_T)((real_T)iy + -1.0); k++) {
      if (b_v->data[(int32_T)(2.0 + (real_T)k) - 1] == cdiff) {
        ixstart++;
      } else {
        if (ixstart > i1) {
          b_mtmp = cdiff;
          i1 = ixstart;
        }

        cdiff = b_v->data[(int32_T)(2.0 + (real_T)k) - 1];
        ixstart = 1;
      }
    }

    emxFree_real_T(&b_v);
    if (ixstart > i1) {
      b_mtmp = cdiff;
    }

    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
    maxval->data[0] = b_mtmp;
  } else {
    outsz[0] = (uint32_T)labels->size[0];
    iy = vwork->size[0];
    vwork->size[0] = (int32_T)outsz[0];
    emxEnsureCapacity((emxArray__common *)vwork, iy, (int32_T)sizeof(real_T));
    ix = 1;
    iy = -1;
    for (i = 1; i <= labels->size[1]; i++) {
      i1 = ix;
      ix += labels->size[0];
      for (k = 0; k < labels->size[0]; k++) {
        vwork->data[k] = labels->data[i1 - 1];
        i1++;
      }

      b_eml_sort(vwork, v);
      cdiff = v->data[0];
      ixstart = 1;
      b_mtmp = v->data[0];
      i1 = 1;
      for (k = 0; k < (int32_T)((real_T)v->size[0] + -1.0); k++) {
        if (v->data[(int32_T)(2.0 + (real_T)k) - 1] == b_mtmp) {
          i1++;
        } else {
          if (i1 > ixstart) {
            cdiff = b_mtmp;
            ixstart = i1;
          }

          b_mtmp = v->data[(int32_T)(2.0 + (real_T)k) - 1];
          i1 = 1;
        }
      }

      if (i1 > ixstart) {
        cdiff = b_mtmp;
      }

      iy++;
      maxval->data[iy] = cdiff;
    }
  }

  if (maxval->size[1] == 0) {
    zeroLabel = rtNaN;
  } else {
    emxInit_real_T(&b_maxval, 2);
    iy = b_maxval->size[0] * b_maxval->size[1];
    b_maxval->size[0] = 1;
    b_maxval->size[1] = maxval->size[1];
    emxEnsureCapacity((emxArray__common *)b_maxval, iy, (int32_T)sizeof(real_T));
    i1 = maxval->size[0] * maxval->size[1];
    for (iy = 0; iy < i1; iy++) {
      b_maxval->data[iy] = maxval->data[iy];
    }

    c_eml_sort(b_maxval, maxval);
    zeroLabel = maxval->data[0];
    i1 = 1;
    cdiff = maxval->data[0];
    ixstart = 1;
    k = 0;
    emxFree_real_T(&b_maxval);
    while (k <= (int32_T)((real_T)maxval->size[1] + -1.0) - 1) {
      if (maxval->data[(int32_T)(2.0 + (real_T)k) - 1] == cdiff) {
        ixstart++;
      } else {
        if (ixstart > i1) {
          zeroLabel = cdiff;
          i1 = ixstart;
        }

        cdiff = maxval->data[(int32_T)(2.0 + (real_T)k) - 1];
        ixstart = 1;
      }

      k++;
    }

    if (ixstart > i1) {
      zeroLabel = cdiff;
    }
  }

  /*  Avoid label zero */
  /*  Compute area */
  i = 0;
  emxInit_int32_T(&ii, 1);
  emxInit_boolean_T(&b_labels, 2);
  emxInit_boolean_T(&c_labels, 2);
  while (i <= (int32_T)(mtmp + 1.0) - 1) {
    iy = c_labels->size[0] * c_labels->size[1];
    c_labels->size[0] = labels->size[0];
    c_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)c_labels, iy, (int32_T)sizeof
                      (boolean_T));
    i1 = labels->size[0] * labels->size[1];
    for (iy = 0; iy < i1; iy++) {
      c_labels->data[iy] = (labels->data[iy] == i);
    }

    sum(c_labels, maxval);
    b_mtmp = b_sum(maxval);
    if (b_mtmp <= 30.0) {
      /*  Set that label to zero */
      iy = b_labels->size[0] * b_labels->size[1];
      b_labels->size[0] = labels->size[0];
      b_labels->size[1] = labels->size[1];
      emxEnsureCapacity((emxArray__common *)b_labels, iy, (int32_T)sizeof
                        (boolean_T));
      i1 = labels->size[0] * labels->size[1];
      for (iy = 0; iy < i1; iy++) {
        b_labels->data[iy] = (labels->data[iy] == i);
      }

      eml_li_find(b_labels, ii);
      i1 = ii->size[0];
      for (iy = 0; iy < i1; iy++) {
        labels->data[ii->data[iy] - 1] = 0.0;
      }
    }

    i++;
  }

  emxFree_boolean_T(&c_labels);
  emxFree_boolean_T(&b_labels);
  emxInit_boolean_T(&d_labels, 2);

  /*  Setting the zero label to zero */
  iy = d_labels->size[0] * d_labels->size[1];
  d_labels->size[0] = labels->size[0];
  d_labels->size[1] = labels->size[1];
  emxEnsureCapacity((emxArray__common *)d_labels, iy, (int32_T)sizeof(boolean_T));
  i1 = labels->size[0] * labels->size[1];
  for (iy = 0; iy < i1; iy++) {
    d_labels->data[iy] = (labels->data[iy] == zeroLabel);
  }

  eml_li_find(d_labels, ii);
  i1 = ii->size[0];
  emxFree_boolean_T(&d_labels);
  for (iy = 0; iy < i1; iy++) {
    labels->data[ii->data[iy] - 1] = 0.0;
  }

  /*  Re-ordering labels */
  e_labels[0] = labels->size[0] * labels->size[1];
  f_labels = *labels;
  f_labels.size = (int32_T *)&e_labels;
  f_labels.numDimensions = 1;
  b_eml_sort(&f_labels, vwork);
  if ((real_T)vwork->size[0] - 1.0 < 1.0) {
    ix = -1;
    zeroLabel = (real_T)vwork->size[0] - 1.0;
  } else {
    b_mtmp = floor((((real_T)vwork->size[0] - 1.0) - 1.0) + 0.5);
    zeroLabel = 1.0 + b_mtmp;
    cdiff = (1.0 + b_mtmp) - ((real_T)vwork->size[0] - 1.0);
    absb = (uint32_T)fabs((real_T)vwork->size[0] - 1.0);
    if (1U > absb) {
      u0 = 1U;
    } else {
      u0 = absb;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)u0) {
      b_mtmp++;
      zeroLabel = (real_T)vwork->size[0] - 1.0;
    } else if (cdiff > 0.0) {
      zeroLabel = 1.0 + (b_mtmp - 1.0);
    } else {
      b_mtmp++;
    }

    ix = (int32_T)b_mtmp - 1;
  }

  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
  if (ix + 1 > 0) {
    maxval->data[0] = 1.0;
    if (ix + 1 > 1) {
      maxval->data[ix] = zeroLabel;
      i1 = ix / 2;
      for (k = 1; k < i1; k++) {
        maxval->data[k] = 1.0 + (real_T)k;
        maxval->data[ix - k] = zeroLabel - (real_T)k;
      }

      if (i1 << 1 == ix) {
        maxval->data[i1] = (1.0 + zeroLabel) / 2.0;
      } else {
        maxval->data[i1] = 1.0 + (real_T)i1;
        maxval->data[i1 + 1] = zeroLabel - (real_T)i1;
      }
    }
  }

  if (vwork->size[0] < 2) {
    ix = -1;
    apnd = vwork->size[0];
  } else {
    i1 = (int32_T)floor(((real_T)vwork->size[0] - 2.0) + 0.5) + 2;
    apnd = i1;
    ix = i1 - vwork->size[0];
    ixstart = vwork->size[0];
    if (fabs(ix) < 4.4408920985006262E-16 * (real_T)ixstart) {
      i1++;
      apnd = vwork->size[0];
    } else if (ix > 0) {
      apnd = i1 - 1;
    } else {
      i1++;
    }

    ix = i1 - 3;
  }

  emxInit_real_T(&y, 2);
  iy = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
  if (ix + 1 > 0) {
    y->data[0] = 2.0;
    if (ix + 1 > 1) {
      y->data[ix] = apnd;
      i1 = ix / 2;
      for (k = 1; k < i1; k++) {
        y->data[k] = 2.0 + (real_T)k;
        y->data[ix - k] = apnd - k;
      }

      if (i1 << 1 == ix) {
        y->data[i1] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[i1] = 2.0 + (real_T)i1;
        y->data[i1 + 1] = apnd - i1;
      }
    }
  }

  b_emxInit_boolean_T(&r0, 1);
  iy = r0->size[0];
  r0->size[0] = maxval->size[1];
  emxEnsureCapacity((emxArray__common *)r0, iy, (int32_T)sizeof(boolean_T));
  i1 = maxval->size[1];
  for (iy = 0; iy < i1; iy++) {
    r0->data[iy] = (vwork->data[(int32_T)maxval->data[iy] - 1] == vwork->data
                    [(int32_T)y->data[iy] - 1]);
  }

  eml_null_assignment(vwork, r0);
  i = 0;
  emxInit_boolean_T(&g_labels, 2);
  while (i <= (int32_T)((real_T)vwork->size[0] + -1.0) - 1) {
    iy = g_labels->size[0] * g_labels->size[1];
    g_labels->size[0] = labels->size[0];
    g_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)g_labels, iy, (int32_T)sizeof
                      (boolean_T));
    b_mtmp = vwork->data[(int32_T)(2.0 + (real_T)i) - 1];
    i1 = labels->size[0] * labels->size[1];
    for (iy = 0; iy < i1; iy++) {
      g_labels->data[iy] = (labels->data[iy] == b_mtmp);
    }

    eml_li_find(g_labels, ii);
    i1 = ii->size[0];
    for (iy = 0; iy < i1; iy++) {
      labels->data[ii->data[iy] - 1] = (2.0 + (real_T)i) - 1.0;
    }

    i++;
  }

  emxFree_boolean_T(&g_labels);
  for (iy = 0; iy < 2; iy++) {
    outsz[iy] = (uint32_T)labels->size[iy];
  }

  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= labels->size[1]; i++) {
    ixstart = ix;
    i1 = ix + labels->size[0];
    mtmp = labels->data[ix];
    if (labels->size[0] > 1) {
      if (rtIsNaN(labels->data[ix])) {
        apnd = ix + 1;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (apnd + 1 <= i1)) {
          ixstart = apnd;
          if (!rtIsNaN(labels->data[apnd])) {
            mtmp = labels->data[apnd];
            exitg3 = TRUE;
          } else {
            apnd++;
          }
        }
      }

      if (ixstart + 1 < i1) {
        for (apnd = ixstart + 1; apnd + 1 <= i1; apnd++) {
          if (labels->data[apnd] > mtmp) {
            mtmp = labels->data[apnd];
          }
        }
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += labels->size[0];
  }

  ixstart = 1;
  mtmp = maxval->data[0];
  if (maxval->size[1] > 1) {
    if (rtIsNaN(maxval->data[0])) {
      ix = 2;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (ix <= maxval->size[1])) {
        ixstart = ix;
        if (!rtIsNaN(maxval->data[ix - 1])) {
          mtmp = maxval->data[ix - 1];
          exitg2 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < maxval->size[1]) {
      while (ixstart + 1 <= maxval->size[1]) {
        if (maxval->data[ixstart] > mtmp) {
          mtmp = maxval->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  /*  Compute weighted centroid */
  /*  Avoid zero label */
  i = 0;
  emxInit_boolean_T(&x, 2);
  emxInit_boolean_T(&h_labels, 2);
  emxInit_int32_T(&b_ii, 1);
  while (i <= (int32_T)mtmp - 1) {
    /*  Get all the y-coords */
    iy = x->size[0] * x->size[1];
    x->size[0] = labels->size[0];
    x->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)x, iy, (int32_T)sizeof(boolean_T));
    i1 = labels->size[0] * labels->size[1];
    for (iy = 0; iy < i1; iy++) {
      x->data[iy] = (labels->data[iy] == 1.0 + (real_T)i);
    }

    ix = x->size[0] * x->size[1];
    ixstart = 0;
    iy = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity((emxArray__common *)ii, iy, (int32_T)sizeof(int32_T));
    i1 = 1;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (i1 <= ix)) {
      guard1 = FALSE;
      if (x->data[i1 - 1]) {
        ixstart++;
        ii->data[ixstart - 1] = i1;
        if (ixstart >= ix) {
          exitg1 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        i1++;
      }
    }

    if (ix == 1) {
      if (ixstart == 0) {
        iy = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity((emxArray__common *)ii, iy, (int32_T)sizeof(int32_T));
      }
    } else {
      if (1 > ixstart) {
        i1 = 0;
      } else {
        i1 = ixstart;
      }

      iy = b_ii->size[0];
      b_ii->size[0] = i1;
      emxEnsureCapacity((emxArray__common *)b_ii, iy, (int32_T)sizeof(int32_T));
      for (iy = 0; iy < i1; iy++) {
        b_ii->data[iy] = ii->data[iy];
      }

      iy = ii->size[0];
      ii->size[0] = b_ii->size[0];
      emxEnsureCapacity((emxArray__common *)ii, iy, (int32_T)sizeof(int32_T));
      i1 = b_ii->size[0];
      for (iy = 0; iy < i1; iy++) {
        ii->data[iy] = b_ii->data[iy];
      }
    }

    iy = vwork->size[0];
    vwork->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)vwork, iy, (int32_T)sizeof(real_T));
    i1 = ii->size[0];
    for (iy = 0; iy < i1; iy++) {
      vwork->data[iy] = ii->data[iy];
    }

    if ((!(vwork->size[0] == 0)) && (originalSpec->data[(int32_T)vwork->data[0]
         - 1] != 0.0)) {
      for (iy = 0; iy < 2; iy++) {
        outsz[iy] = (uint32_T)originalSpec->size[iy];
      }

      iy = ii->size[0];
      ii->size[0] = vwork->size[0];
      emxEnsureCapacity((emxArray__common *)ii, iy, (int32_T)sizeof(int32_T));
      i1 = vwork->size[0];
      for (iy = 0; iy < i1; iy++) {
        ii->data[iy] = (int32_T)vwork->data[iy] - 1;
      }

      iy = ii->size[0];
      emxEnsureCapacity((emxArray__common *)ii, iy, (int32_T)sizeof(int32_T));
      i1 = ii->size[0];
      for (iy = 0; iy < i1; iy++) {
        ii->data[iy] -= div_s32(ii->data[iy], (int32_T)outsz[0]) * (int32_T)
          outsz[0];
      }

      iy = v->size[0];
      v->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)v, iy, (int32_T)sizeof(real_T));
      i1 = ii->size[0];
      for (iy = 0; iy < i1; iy++) {
        v->data[iy] = (real_T)(ii->data[iy] + 1) * originalSpec->data[(int32_T)
          vwork->data[iy] - 1];
      }

      b_mtmp = v->data[0];
      for (k = 2; k <= v->size[0]; k++) {
        b_mtmp += v->data[k - 1];
      }

      zeroLabel = originalSpec->data[(int32_T)vwork->data[0] - 1];
      for (k = 2; k <= vwork->size[0]; k++) {
        zeroLabel += originalSpec->data[(int32_T)vwork->data[k - 1] - 1];
      }

      /* imagesc(labels==i); */
      if (b_mtmp / zeroLabel <= 20.0) {
        iy = h_labels->size[0] * h_labels->size[1];
        h_labels->size[0] = labels->size[0];
        h_labels->size[1] = labels->size[1];
        emxEnsureCapacity((emxArray__common *)h_labels, iy, (int32_T)sizeof
                          (boolean_T));
        i1 = labels->size[0] * labels->size[1];
        for (iy = 0; iy < i1; iy++) {
          h_labels->data[iy] = (labels->data[iy] == 1.0 + (real_T)i);
        }

        eml_li_find(h_labels, ii);
        i1 = ii->size[0];
        for (iy = 0; iy < i1; iy++) {
          labels->data[ii->data[iy] - 1] = 0.0;
        }
      }
    }

    i++;
  }

  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&h_labels);
  emxFree_real_T(&v);
  emxFree_boolean_T(&x);
  i_labels[0] = labels->size[0] * labels->size[1];
  f_labels = *labels;
  f_labels.size = (int32_T *)&i_labels;
  f_labels.numDimensions = 1;
  b_eml_sort(&f_labels, vwork);
  if ((real_T)vwork->size[0] - 1.0 < 1.0) {
    ix = -1;
    zeroLabel = (real_T)vwork->size[0] - 1.0;
  } else {
    b_mtmp = floor((((real_T)vwork->size[0] - 1.0) - 1.0) + 0.5);
    zeroLabel = 1.0 + b_mtmp;
    cdiff = (1.0 + b_mtmp) - ((real_T)vwork->size[0] - 1.0);
    absb = (uint32_T)fabs((real_T)vwork->size[0] - 1.0);
    if (1U > absb) {
      u1 = 1U;
    } else {
      u1 = absb;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)u1) {
      b_mtmp++;
      zeroLabel = (real_T)vwork->size[0] - 1.0;
    } else if (cdiff > 0.0) {
      zeroLabel = 1.0 + (b_mtmp - 1.0);
    } else {
      b_mtmp++;
    }

    ix = (int32_T)b_mtmp - 1;
  }

  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int32_T)sizeof(real_T));
  if (ix + 1 > 0) {
    maxval->data[0] = 1.0;
    if (ix + 1 > 1) {
      maxval->data[ix] = zeroLabel;
      i1 = ix / 2;
      for (k = 1; k < i1; k++) {
        maxval->data[k] = 1.0 + (real_T)k;
        maxval->data[ix - k] = zeroLabel - (real_T)k;
      }

      if (i1 << 1 == ix) {
        maxval->data[i1] = (1.0 + zeroLabel) / 2.0;
      } else {
        maxval->data[i1] = 1.0 + (real_T)i1;
        maxval->data[i1 + 1] = zeroLabel - (real_T)i1;
      }
    }
  }

  if (vwork->size[0] < 2) {
    ix = -1;
    apnd = vwork->size[0];
  } else {
    i1 = (int32_T)floor(((real_T)vwork->size[0] - 2.0) + 0.5) + 2;
    apnd = i1;
    ix = i1 - vwork->size[0];
    ixstart = vwork->size[0];
    if (fabs(ix) < 4.4408920985006262E-16 * (real_T)ixstart) {
      i1++;
      apnd = vwork->size[0];
    } else if (ix > 0) {
      apnd = i1 - 1;
    } else {
      i1++;
    }

    ix = i1 - 3;
  }

  iy = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
  if (ix + 1 > 0) {
    y->data[0] = 2.0;
    if (ix + 1 > 1) {
      y->data[ix] = apnd;
      i1 = ix / 2;
      for (k = 1; k < i1; k++) {
        y->data[k] = 2.0 + (real_T)k;
        y->data[ix - k] = apnd - k;
      }

      if (i1 << 1 == ix) {
        y->data[i1] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[i1] = 2.0 + (real_T)i1;
        y->data[i1 + 1] = apnd - i1;
      }
    }
  }

  iy = r0->size[0];
  r0->size[0] = maxval->size[1];
  emxEnsureCapacity((emxArray__common *)r0, iy, (int32_T)sizeof(boolean_T));
  i1 = maxval->size[1];
  for (iy = 0; iy < i1; iy++) {
    r0->data[iy] = (vwork->data[(int32_T)maxval->data[iy] - 1] == vwork->data
                    [(int32_T)y->data[iy] - 1]);
  }

  emxFree_real_T(&y);
  emxFree_real_T(&maxval);
  eml_null_assignment(vwork, r0);
  i = 0;
  emxFree_boolean_T(&r0);
  emxInit_boolean_T(&j_labels, 2);
  while (i <= (int32_T)((real_T)vwork->size[0] + -1.0) - 1) {
    iy = j_labels->size[0] * j_labels->size[1];
    j_labels->size[0] = labels->size[0];
    j_labels->size[1] = labels->size[1];
    emxEnsureCapacity((emxArray__common *)j_labels, iy, (int32_T)sizeof
                      (boolean_T));
    b_mtmp = vwork->data[(int32_T)(2.0 + (real_T)i) - 1];
    i1 = labels->size[0] * labels->size[1];
    for (iy = 0; iy < i1; iy++) {
      j_labels->data[iy] = (labels->data[iy] == b_mtmp);
    }

    eml_li_find(j_labels, ii);
    i1 = ii->size[0];
    for (iy = 0; iy < i1; iy++) {
      labels->data[ii->data[iy] - 1] = (2.0 + (real_T)i) - 1.0;
    }

    i++;
  }

  emxFree_boolean_T(&j_labels);
  emxFree_int32_T(&ii);
  emxFree_real_T(&vwork);
  iy = denoisedSpec->size[0] * denoisedSpec->size[1];
  denoisedSpec->size[0] = labels->size[0];
  denoisedSpec->size[1] = labels->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, iy, (int32_T)sizeof(real_T));
  i1 = labels->size[0] * labels->size[1];
  for (iy = 0; iy < i1; iy++) {
    denoisedSpec->data[iy] = (real_T)(labels->data[iy] != 0.0) *
      originalSpec->data[iy];
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
