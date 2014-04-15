/*
 * bufferSTFT.c
 *
 * Code generation for function 'bufferSTFT'
 *
 * C source code generated on: Mon Apr 14 22:51:01 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bufferSTFT.h"

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

#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T

struct emxArray_creal_T
{
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_creal_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct emxArray_creal_T emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

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
static void b_emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_creal_T(emxArray_creal_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void fft(const emxArray_real_T *x, real_T varargin_1, emxArray_creal_T *y);
static void padarray(const emxArray_real_T *varargin_1, real_T varargin_2,
                     emxArray_real_T *b);
static real_T rt_atan2d_snf(real_T u0, real_T u1);
static real_T rt_hypotd_snf(real_T u0, real_T u1);
static real_T rt_remd_snf(real_T u0, real_T u1);
static real_T rt_roundd_snf(real_T u);

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

static void b_emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_creal_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_creal_T *)malloc(sizeof(emxArray_creal_T));
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
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

static void eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx)
{
  int32_T unnamed_idx_1;
  int32_T nrows;
  int32_T i2;
  int32_T j;
  int32_T i;
  emxArray_boolean_T *b;
  int32_T loop_ub;
  int32_T i3;
  emxArray_real_T *b_x;
  if (idx->size[1] == 1) {
    unnamed_idx_1 = x->size[0];
    nrows = x->size[0] - 1;
    i2 = x->size[1];
    for (j = 0; j + 1 <= i2; j++) {
      for (i = (int32_T)idx->data[0]; i < unnamed_idx_1; i++) {
        x->data[(i + x->size[0] * j) - 1] = x->data[i + x->size[0] * j];
      }
    }
  } else {
    b_emxInit_boolean_T(&b, 2);
    i2 = b->size[0] * b->size[1];
    b->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b, i2, (int32_T)sizeof(boolean_T));
    unnamed_idx_1 = x->size[0];
    i2 = b->size[0] * b->size[1];
    b->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)b, i2, (int32_T)sizeof(boolean_T));
    loop_ub = x->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      b->data[i2] = FALSE;
    }

    for (loop_ub = 1; loop_ub <= idx->size[1]; loop_ub++) {
      b->data[(int32_T)idx->data[loop_ub - 1] - 1] = TRUE;
    }

    unnamed_idx_1 = 0;
    for (loop_ub = 1; loop_ub <= b->size[1]; loop_ub++) {
      unnamed_idx_1 += b->data[loop_ub - 1];
    }

    nrows = x->size[0] - unnamed_idx_1;
    i = 0;
    i2 = x->size[0];
    for (loop_ub = 1; loop_ub <= i2; loop_ub++) {
      if ((loop_ub > b->size[1]) || (!b->data[loop_ub - 1])) {
        i3 = x->size[1];
        for (j = 0; j + 1 <= i3; j++) {
          x->data[i + x->size[0] * j] = x->data[(loop_ub + x->size[0] * j) - 1];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  if (1 > nrows) {
    loop_ub = 0;
  } else {
    loop_ub = nrows;
  }

  emxInit_real_T(&b_x, 2);
  unnamed_idx_1 = x->size[1];
  i2 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = loop_ub;
  b_x->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)b_x, i2, (int32_T)sizeof(real_T));
  for (i2 = 0; i2 < unnamed_idx_1; i2++) {
    for (i3 = 0; i3 < loop_ub; i3++) {
      b_x->data[i3 + b_x->size[0] * i2] = x->data[i3 + x->size[0] * i2];
    }
  }

  i2 = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, i2, (int32_T)sizeof(real_T));
  loop_ub = b_x->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    unnamed_idx_1 = b_x->size[0];
    for (i3 = 0; i3 < unnamed_idx_1; i3++) {
      x->data[i3 + x->size[0] * i2] = b_x->data[i3 + b_x->size[0] * i2];
    }
  }

  emxFree_real_T(&b_x);
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

static void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
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

static void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions)
{
  emxArray_creal_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_creal_T *)malloc(sizeof(emxArray_creal_T));
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
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

static void fft(const emxArray_real_T *x, real_T varargin_1, emxArray_creal_T *y)
{
  int32_T ju;
  int32_T nd2;
  int32_T minval;
  emxArray_real_T *costab1q;
  int32_T ixDelta;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T lastChan;
  real_T e;
  int32_T k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int32_T ix;
  int32_T chanStart;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T iDelta;
  int32_T iDelta2;
  int32_T iheight;
  int32_T ihi;
  real_T twid_im;
  ju = y->size[0];
  y->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
  if ((int32_T)varargin_1 > x->size[0]) {
    ju = y->size[0];
    y->size[0] = (int32_T)varargin_1;
    emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
    nd2 = (int32_T)varargin_1;
    for (ju = 0; ju < nd2; ju++) {
      y->data[ju].re = 0.0;
      y->data[ju].im = 0.0;
    }
  }

  if (x->size[0] == 0) {
  } else {
    if ((int32_T)varargin_1 < x->size[0]) {
      minval = (int32_T)varargin_1;
    } else {
      minval = x->size[0];
    }

    emxInit_real_T(&costab1q, 2);
    nd2 = (x->size[0] - minval) + 1;
    if (1 >= nd2) {
      ixDelta = 1;
    } else {
      ixDelta = nd2;
    }

    ju = (int32_T)varargin_1;
    nRowsD2 = ju / 2;
    nRowsD4 = nRowsD2 / 2;
    lastChan = (int32_T)varargin_1 * (div_s32(x->size[0], x->size[0]) - 1);
    e = 6.2831853071795862 / (real_T)(int32_T)varargin_1;
    ju = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = nRowsD4 + 1;
    emxEnsureCapacity((emxArray__common *)costab1q, ju, (int32_T)sizeof(real_T));
    costab1q->data[0] = 1.0;
    nd2 = nRowsD4 / 2;
    for (k = 1; k <= nd2; k++) {
      costab1q->data[k] = cos(e * (real_T)k);
    }

    for (k = nd2 + 1; k < nRowsD4; k++) {
      costab1q->data[k] = sin(e * (real_T)(nRowsD4 - k));
    }

    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    costab1q->data[nRowsD4] = 0.0;
    nd2 = (costab1q->size[1] - 1) << 1;
    ju = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, ju, (int32_T)sizeof(real_T));
    ju = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, ju, (int32_T)sizeof(real_T));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k < costab1q->size[1]; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[(costab1q->size[1] - k) - 1];
    }

    for (k = costab1q->size[1]; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[(k - costab1q->size[1]) + 1];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    chanStart = 0;
    while (((int32_T)varargin_1 > 0) && (chanStart <= lastChan)) {
      ju = 0;
      nd2 = chanStart;
      for (i = 1; i < minval; i++) {
        y->data[nd2].re = x->data[ix];
        y->data[nd2].im = 0.0;
        nd2 = (int32_T)varargin_1;
        tst = TRUE;
        while (tst) {
          nd2 >>= 1;
          ju ^= nd2;
          tst = ((ju & nd2) == 0);
        }

        nd2 = chanStart + ju;
        ix++;
      }

      y->data[nd2].re = x->data[ix];
      y->data[nd2].im = 0.0;
      ix += ixDelta;
      nd2 = (chanStart + (int32_T)varargin_1) - 2;
      if ((int32_T)varargin_1 > 1) {
        for (i = chanStart; i <= nd2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      iDelta = 2;
      iDelta2 = 4;
      k = nRowsD4;
      iheight = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        ihi = chanStart + iheight;
        while (i < ihi) {
          nd2 = i + iDelta;
          temp_re = y->data[nd2].re;
          temp_im = y->data[nd2].im;
          y->data[i + iDelta].re = y->data[i].re - y->data[nd2].re;
          y->data[i + iDelta].im = y->data[i].im - y->data[nd2].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += iDelta2;
        }

        nd2 = chanStart + 1;
        for (ju = k; ju < nRowsD2; ju += k) {
          e = costab->data[ju];
          twid_im = sintab->data[ju];
          i = nd2;
          ihi = nd2 + iheight;
          while (i < ihi) {
            temp_re = e * y->data[i + iDelta].re - twid_im * y->data[i + iDelta]
              .im;
            temp_im = e * y->data[i + iDelta].im + twid_im * y->data[i + iDelta]
              .re;
            y->data[i + iDelta].re = y->data[i].re - temp_re;
            y->data[i + iDelta].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += iDelta2;
          }

          nd2++;
        }

        k /= 2;
        iDelta = iDelta2;
        iDelta2 <<= 1;
        iheight -= iDelta;
      }

      chanStart += (int32_T)varargin_1;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

static void padarray(const emxArray_real_T *varargin_1, real_T varargin_2,
                     emxArray_real_T *b)
{
  real_T padSize[2];
  int32_T i1;
  real_T sizeB[2];
  int32_T b_sizeB[2];
  int32_T outsize[2];
  int32_T cdiff;
  emxArray_real_T *idxB;
  emxArray_int32_T *r3;
  emxArray_real_T *r4;
  int32_T k;
  int32_T nm1d2;
  int32_T ndbl;
  int32_T apnd;
  emxArray_boolean_T *x;
  real_T idxB1;
  real_T idxB2;
  for (i1 = 0; i1 < 2; i1++) {
    padSize[i1] = 0.0;
  }

  padSize[0] = varargin_2;
  if (varargin_1->size[0] == 0) {
    for (i1 = 0; i1 < 2; i1++) {
      sizeB[i1] = (real_T)i1 + padSize[i1];
    }

    b_sizeB[0] = (int32_T)sizeB[0];
    b_sizeB[1] = (int32_T)sizeB[1];
    for (i1 = 0; i1 < 2; i1++) {
      outsize[i1] = b_sizeB[i1];
    }

    i1 = b->size[0] * b->size[1];
    b->size[0] = outsize[0];
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T));
    i1 = b->size[0] * b->size[1];
    b->size[1] = outsize[1];
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T));
    cdiff = outsize[0] * outsize[1];
    for (i1 = 0; i1 < cdiff; i1++) {
      b->data[i1] = 0.0;
    }
  } else {
    for (i1 = 0; i1 < 2; i1++) {
      sizeB[i1] = 0.0;
    }

    emxInit_real_T(&idxB, 2);
    cdiff = varargin_1->size[0];
    i1 = idxB->size[0] * idxB->size[1];
    idxB->size[0] = cdiff;
    idxB->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)idxB, i1, (int32_T)sizeof(real_T));
    cdiff <<= 1;
    for (i1 = 0; i1 < cdiff; i1++) {
      idxB->data[i1] = 0.0;
    }

    emxInit_int32_T(&r3, 1);
    emxInit_real_T(&r4, 2);
    for (k = 0; k < 2; k++) {
      if (1 + k <= 1) {
        nm1d2 = varargin_1->size[0];
      } else {
        nm1d2 = 1;
      }

      sizeB[k] = (real_T)nm1d2 + padSize[k];
      i1 = r3->size[0];
      r3->size[0] = nm1d2;
      emxEnsureCapacity((emxArray__common *)r3, i1, (int32_T)sizeof(int32_T));
      for (i1 = 0; i1 < nm1d2; i1++) {
        r3->data[i1] = i1;
      }

      ndbl = (int32_T)floor(((real_T)nm1d2 - 1.0) + 0.5);
      apnd = ndbl + 1;
      cdiff = (ndbl - nm1d2) + 1;
      if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)nm1d2) {
        ndbl++;
        apnd = nm1d2;
      } else if (cdiff > 0) {
        apnd = ndbl;
      } else {
        ndbl++;
      }

      i1 = r4->size[0] * r4->size[1];
      r4->size[0] = 1;
      r4->size[1] = ndbl;
      emxEnsureCapacity((emxArray__common *)r4, i1, (int32_T)sizeof(real_T));
      if (ndbl > 0) {
        r4->data[0] = 1.0;
        if (ndbl > 1) {
          r4->data[ndbl - 1] = apnd;
          i1 = ndbl - 1;
          nm1d2 = i1 / 2;
          for (cdiff = 1; cdiff < nm1d2; cdiff++) {
            r4->data[cdiff] = 1.0 + (real_T)cdiff;
            r4->data[(ndbl - cdiff) - 1] = apnd - cdiff;
          }

          if (nm1d2 << 1 == ndbl - 1) {
            r4->data[nm1d2] = (1.0 + (real_T)apnd) / 2.0;
          } else {
            r4->data[nm1d2] = 1.0 + (real_T)nm1d2;
            r4->data[nm1d2 + 1] = apnd - nm1d2;
          }
        }
      }

      cdiff = r3->size[0];
      for (i1 = 0; i1 < cdiff; i1++) {
        idxB->data[r3->data[i1] + idxB->size[0] * k] = r4->data[i1];
      }
    }

    emxFree_real_T(&r4);
    emxFree_int32_T(&r3);
    emxInit_boolean_T(&x, 1);
    cdiff = idxB->size[0];
    i1 = x->size[0];
    x->size[0] = cdiff;
    emxEnsureCapacity((emxArray__common *)x, i1, (int32_T)sizeof(boolean_T));
    for (i1 = 0; i1 < cdiff; i1++) {
      x->data[i1] = (idxB->data[i1] != 0.0);
    }

    idxB1 = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      idxB1 += (real_T)x->data[k - 1];
    }

    cdiff = idxB->size[0];
    i1 = x->size[0];
    x->size[0] = cdiff;
    emxEnsureCapacity((emxArray__common *)x, i1, (int32_T)sizeof(boolean_T));
    for (i1 = 0; i1 < cdiff; i1++) {
      x->data[i1] = (idxB->data[i1 + idxB->size[0]] != 0.0);
    }

    idxB2 = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      idxB2 += (real_T)x->data[k - 1];
    }

    emxFree_boolean_T(&x);
    b_sizeB[0] = (int32_T)sizeB[0];
    b_sizeB[1] = (int32_T)sizeB[1];
    for (i1 = 0; i1 < 2; i1++) {
      outsize[i1] = b_sizeB[i1];
    }

    i1 = b->size[0] * b->size[1];
    b->size[0] = outsize[0];
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T));
    i1 = b->size[0] * b->size[1];
    b->size[1] = outsize[1];
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T));
    cdiff = outsize[0] * outsize[1];
    for (i1 = 0; i1 < cdiff; i1++) {
      b->data[i1] = 0.0;
    }

    for (cdiff = 0; cdiff < (int32_T)idxB1; cdiff++) {
      for (nm1d2 = 0; nm1d2 < (int32_T)idxB2; nm1d2++) {
        b->data[((int32_T)idxB->data[(int32_T)(1.0 + (real_T)cdiff) - 1] +
                 b->size[0] * ((int32_T)idxB->data[((int32_T)(1.0 + (real_T)
                    nm1d2) + idxB->size[0]) - 1] - 1)) - 1] = varargin_1->data
          [(int32_T)(1.0 + (real_T)cdiff) - 1];
      }
    }

    emxFree_real_T(&idxB);
  }
}

static real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T b_u0;
  int32_T b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  real_T b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

static real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T b_y;
  boolean_T c_y;
  real_T tr;
  if (u1 < 0.0) {
    y = ceil(u1);
  } else {
    y = floor(u1);
  }

  b_y = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
  c_y = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
  if ((u1 != 0.0) && (u1 != y) && (b_y && c_y)) {
    tr = u0 / u1;
    if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

static real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

void bufferSTFT(const emxArray_real_T *samples, real_T blockSize, real_T hopSize,
                emxArray_real_T *magSTFT, emxArray_real_T *phaseSTFT,
                emxArray_real_T *T)
{
  emxArray_real_T *b_samples;
  int32_T cdiff;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  real_T b_cdiff;
  emxArray_real_T *t1;
  int32_T i0;
  int32_T nm1d2;
  int32_T k;
  emxArray_real_T *W;
  emxArray_real_T *b_W;
  real_T b;
  real_T absb;
  real_T d0;
  emxArray_creal_T *stft;
  emxArray_creal_T *r0;
  emxArray_real_T *c_samples;
  int32_T b_apnd;
  uint32_T uv0[2];
  emxArray_real_T *b_blockSize;
  emxArray_real_T *r1;
  emxArray_real_T *c_blockSize;
  emxArray_real_T *r2;
  emxInit_real_T(&b_samples, 2);

  /* BUFFERSTFT Meant for code export */
  /*    Detailed explanation goes here */
  padarray(samples, rt_remd_snf(samples->size[0], hopSize), b_samples);

  /*  Normalizing samples */
  /* samples = samples/max(abs(samples)); */
  if (rtIsNaN(blockSize - 1.0)) {
    cdiff = 0;
    anew = rtNaN;
    apnd = blockSize - 1.0;
  } else if (blockSize - 1.0 < 0.0) {
    cdiff = -1;
    anew = 0.0;
    apnd = blockSize - 1.0;
  } else if (rtIsInf(blockSize - 1.0)) {
    cdiff = 0;
    anew = rtNaN;
    apnd = blockSize - 1.0;
  } else {
    anew = 0.0;
    ndbl = floor((blockSize - 1.0) + 0.5);
    apnd = ndbl;
    b_cdiff = ndbl - (blockSize - 1.0);
    if (fabs(b_cdiff) < 4.4408920985006262E-16 * fabs(blockSize - 1.0)) {
      ndbl++;
      apnd = blockSize - 1.0;
    } else if (b_cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      cdiff = (int32_T)ndbl - 1;
    } else {
      cdiff = -1;
    }
  }

  emxInit_real_T(&t1, 2);
  i0 = t1->size[0] * t1->size[1];
  t1->size[0] = 1;
  t1->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)t1, i0, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    t1->data[0] = anew;
    if (cdiff + 1 > 1) {
      t1->data[cdiff] = apnd;
      nm1d2 = cdiff / 2;
      for (k = 1; k < nm1d2; k++) {
        t1->data[k] = anew + (real_T)k;
        t1->data[cdiff - k] = apnd - (real_T)k;
      }

      if (nm1d2 << 1 == cdiff) {
        t1->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        t1->data[nm1d2] = anew + (real_T)nm1d2;
        t1->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  apnd = 6.2831853071795862 * (1.0 / (2.0 * (blockSize - 1.0)));
  i0 = t1->size[0] * t1->size[1];
  t1->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)t1, i0, (int32_T)sizeof(real_T));
  nm1d2 = t1->size[0];
  cdiff = t1->size[1];
  cdiff *= nm1d2;
  for (i0 = 0; i0 < cdiff; i0++) {
    t1->data[i0] *= apnd;
  }

  emxInit_real_T(&W, 2);
  i0 = W->size[0] * W->size[1];
  W->size[0] = 1;
  W->size[1] = t1->size[1];
  emxEnsureCapacity((emxArray__common *)W, i0, (int32_T)sizeof(real_T));
  cdiff = t1->size[0] * t1->size[1];
  for (i0 = 0; i0 < cdiff; i0++) {
    W->data[i0] = t1->data[i0];
  }

  for (k = 0; k < t1->size[1]; k++) {
    W->data[k] = sin(W->data[k]);
  }

  b_emxInit_real_T(&b_W, 1);
  i0 = b_W->size[0];
  b_W->size[0] = W->size[1];
  emxEnsureCapacity((emxArray__common *)b_W, i0, (int32_T)sizeof(real_T));
  cdiff = W->size[1];
  for (i0 = 0; i0 < cdiff; i0++) {
    b_W->data[i0] = W->data[i0];
  }

  emxFree_real_T(&W);
  if ((0 == b_samples->size[0]) || (0 == b_samples->size[1])) {
    cdiff = 0;
  } else if (b_samples->size[0] > b_samples->size[1]) {
    cdiff = b_samples->size[0];
  } else {
    cdiff = b_samples->size[1];
  }

  b = (real_T)cdiff - blockSize;
  if (rtIsNaN(hopSize) || rtIsNaN(b)) {
    cdiff = 0;
    anew = rtNaN;
  } else if ((hopSize == 0.0) || ((1.0 < b) && (hopSize < 0.0)) || ((b < 1.0) &&
              (hopSize > 0.0))) {
    cdiff = -1;
    anew = 1.0;
  } else if (rtIsInf(b)) {
    cdiff = 0;
    anew = rtNaN;
  } else if (rtIsInf(hopSize)) {
    cdiff = 0;
    anew = 1.0;
  } else {
    anew = 1.0;
    ndbl = floor((b - 1.0) / hopSize + 0.5);
    apnd = ndbl * hopSize;
    if (hopSize > 0.0) {
      b_cdiff = (1.0 + apnd) - b;
    } else {
      b_cdiff = b - (1.0 + apnd);
    }

    absb = fabs(b);
    if (1.0 > absb) {
      d0 = 1.0;
    } else {
      d0 = absb;
    }

    if (fabs(b_cdiff) < 4.4408920985006262E-16 * d0) {
      ndbl++;
    } else if (b_cdiff > 0.0) {
      b = 1.0 + (ndbl - 1.0) * hopSize;
    } else {
      ndbl++;
      b = 1.0 + apnd;
    }

    if (ndbl >= 0.0) {
      cdiff = (int32_T)ndbl - 1;
    } else {
      cdiff = -1;
    }
  }

  i0 = t1->size[0] * t1->size[1];
  t1->size[0] = 1;
  t1->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)t1, i0, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    t1->data[0] = anew;
    if (cdiff + 1 > 1) {
      t1->data[cdiff] = b;
      nm1d2 = cdiff / 2;
      for (k = 1; k < nm1d2; k++) {
        apnd = (real_T)k * hopSize;
        t1->data[k] = anew + apnd;
        t1->data[cdiff - k] = b - apnd;
      }

      if (nm1d2 << 1 == cdiff) {
        t1->data[nm1d2] = (anew + b) / 2.0;
      } else {
        apnd = (real_T)nm1d2 * hopSize;
        t1->data[nm1d2] = anew + apnd;
        t1->data[nm1d2 + 1] = b - apnd;
      }
    }
  }

  emxInit_creal_T(&stft, 2);
  i0 = stft->size[0] * stft->size[1];
  stft->size[0] = (int32_T)blockSize;
  emxEnsureCapacity((emxArray__common *)stft, i0, (int32_T)sizeof(creal_T));
  nm1d2 = t1->size[1];
  i0 = stft->size[0] * stft->size[1];
  stft->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)stft, i0, (int32_T)sizeof(creal_T));
  cdiff = (int32_T)blockSize * t1->size[1];
  for (i0 = 0; i0 < cdiff; i0++) {
    stft->data[i0].re = 0.0;
    stft->data[i0].im = 0.0;
  }

  nm1d2 = 0;
  b_emxInit_creal_T(&r0, 1);
  b_emxInit_real_T(&c_samples, 1);
  while (nm1d2 <= t1->size[1] - 1) {
    apnd = (t1->data[nm1d2] + blockSize) - 1.0;
    if (t1->data[nm1d2] > apnd) {
      i0 = 0;
      k = 0;
    } else {
      i0 = (int32_T)t1->data[nm1d2] - 1;
      k = (int32_T)apnd;
    }

    /*  Multiplying by window */
    /*  Taking the fft and storing */
    cdiff = c_samples->size[0];
    c_samples->size[0] = k - i0;
    emxEnsureCapacity((emxArray__common *)c_samples, cdiff, (int32_T)sizeof
                      (real_T));
    cdiff = k - i0;
    for (k = 0; k < cdiff; k++) {
      c_samples->data[k] = b_samples->data[i0 + k] * b_W->data[k];
    }

    fft(c_samples, blockSize, r0);
    cdiff = r0->size[0];
    for (i0 = 0; i0 < cdiff; i0++) {
      stft->data[i0 + stft->size[0] * nm1d2] = r0->data[i0];
    }

    nm1d2++;
  }

  emxFree_real_T(&c_samples);
  emxFree_creal_T(&r0);
  emxFree_real_T(&b_W);
  emxFree_real_T(&b_samples);
  emxFree_real_T(&t1);
  if (stft->size[1] - 1 < 0) {
    cdiff = -1;
    b_apnd = stft->size[1] - 1;
  } else {
    nm1d2 = (int32_T)floor(((real_T)stft->size[1] - 1.0) + 0.5);
    b_apnd = nm1d2;
    cdiff = (nm1d2 - stft->size[1]) + 1;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((real_T)stft->size[1] - 1.0))
    {
      nm1d2++;
      b_apnd = stft->size[1] - 1;
    } else if (cdiff > 0) {
      b_apnd = nm1d2 - 1;
    } else {
      nm1d2++;
    }

    if (nm1d2 >= 0) {
      cdiff = nm1d2 - 1;
    } else {
      cdiff = -1;
    }
  }

  i0 = T->size[0] * T->size[1];
  T->size[0] = 1;
  T->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)T, i0, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    T->data[0] = 0.0;
    if (cdiff + 1 > 1) {
      T->data[cdiff] = b_apnd;
      nm1d2 = cdiff / 2;
      for (k = 1; k < nm1d2; k++) {
        T->data[k] = k;
        T->data[cdiff - k] = b_apnd - k;
      }

      if (nm1d2 << 1 == cdiff) {
        T->data[nm1d2] = (real_T)b_apnd / 2.0;
      } else {
        T->data[nm1d2] = nm1d2;
        T->data[nm1d2 + 1] = b_apnd - nm1d2;
      }
    }
  }

  apnd = blockSize / 2.0;
  i0 = T->size[0] * T->size[1];
  T->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)T, i0, (int32_T)sizeof(real_T));
  nm1d2 = T->size[0];
  cdiff = T->size[1];
  cdiff *= nm1d2;
  for (i0 = 0; i0 < cdiff; i0++) {
    T->data[i0] = (T->data[i0] * hopSize + apnd) / 16000.0;
  }

  /*  Discarding redundant data due to symmetry */
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)stft->size[i0];
  }

  i0 = magSTFT->size[0] * magSTFT->size[1];
  magSTFT->size[0] = (int32_T)uv0[0];
  magSTFT->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)magSTFT, i0, (int32_T)sizeof(real_T));
  i0 = stft->size[0] * stft->size[1];
  for (k = 0; k < i0; k++) {
    magSTFT->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_hypotd_snf(stft->data
      [(int32_T)(1.0 + (real_T)k) - 1].re, stft->data[(int32_T)(1.0 + (real_T)k)
      - 1].im);
  }

  emxInit_real_T(&b_blockSize, 2);
  b_emxInit_real_T(&r1, 1);
  apnd = blockSize / 2.0 + 2.0;
  i0 = magSTFT->size[0];
  k = r1->size[0];
  r1->size[0] = (int32_T)floor((real_T)i0 - apnd) + 1;
  emxEnsureCapacity((emxArray__common *)r1, k, (int32_T)sizeof(real_T));
  cdiff = (int32_T)floor((real_T)i0 - apnd);
  for (i0 = 0; i0 <= cdiff; i0++) {
    r1->data[i0] = apnd + (real_T)i0;
  }

  i0 = b_blockSize->size[0] * b_blockSize->size[1];
  b_blockSize->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)b_blockSize, i0, (int32_T)sizeof(real_T));
  nm1d2 = r1->size[0];
  i0 = b_blockSize->size[0] * b_blockSize->size[1];
  b_blockSize->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)b_blockSize, i0, (int32_T)sizeof(real_T));
  cdiff = r1->size[0];
  for (i0 = 0; i0 < cdiff; i0++) {
    b_blockSize->data[i0] = r1->data[i0];
  }

  emxFree_real_T(&r1);
  eml_null_assignment(magSTFT, b_blockSize);
  emxFree_real_T(&b_blockSize);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)stft->size[i0];
  }

  i0 = phaseSTFT->size[0] * phaseSTFT->size[1];
  phaseSTFT->size[0] = (int32_T)uv0[0];
  emxEnsureCapacity((emxArray__common *)phaseSTFT, i0, (int32_T)sizeof(real_T));
  i0 = phaseSTFT->size[0] * phaseSTFT->size[1];
  phaseSTFT->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)phaseSTFT, i0, (int32_T)sizeof(real_T));
  cdiff = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (i0 = 0; i0 < cdiff; i0++) {
    phaseSTFT->data[i0] = 0.0;
  }

  i0 = stft->size[0] * stft->size[1];
  for (k = 0; k < i0; k++) {
    phaseSTFT->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_atan2d_snf(stft->data
      [(int32_T)(1.0 + (real_T)k) - 1].im, stft->data[(int32_T)(1.0 + (real_T)k)
      - 1].re);
  }

  emxFree_creal_T(&stft);
  emxInit_real_T(&c_blockSize, 2);
  b_emxInit_real_T(&r2, 1);
  apnd = blockSize / 2.0 + 2.0;
  i0 = magSTFT->size[0];
  k = r2->size[0];
  r2->size[0] = (int32_T)floor((real_T)i0 - apnd) + 1;
  emxEnsureCapacity((emxArray__common *)r2, k, (int32_T)sizeof(real_T));
  cdiff = (int32_T)floor((real_T)i0 - apnd);
  for (i0 = 0; i0 <= cdiff; i0++) {
    r2->data[i0] = apnd + (real_T)i0;
  }

  i0 = c_blockSize->size[0] * c_blockSize->size[1];
  c_blockSize->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)c_blockSize, i0, (int32_T)sizeof(real_T));
  nm1d2 = r2->size[0];
  i0 = c_blockSize->size[0] * c_blockSize->size[1];
  c_blockSize->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)c_blockSize, i0, (int32_T)sizeof(real_T));
  cdiff = r2->size[0];
  for (i0 = 0; i0 < cdiff; i0++) {
    c_blockSize->data[i0] = r2->data[i0];
  }

  emxFree_real_T(&r2);
  eml_null_assignment(magSTFT, c_blockSize);
  emxFree_real_T(&c_blockSize);
}

void bufferSTFT_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void bufferSTFT_terminate(void)
{
  /* (no terminate code required) */
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

/* End of code generation (bufferSTFT.c) */
