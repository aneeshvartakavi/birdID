/*
 * featureMFCCAndDerivative.c
 *
 * Code generation for function 'featureMFCCAndDerivative'
 *
 * C source code generated on: Sat Apr 05 17:10:41 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "featureMFCCAndDerivative.h"

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
static void b_eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void b_log(emxArray_real_T *x);
static void b_std(const emxArray_real_T *varargin_1, real_T y[16]);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_li_find(const boolean_T x[34], int32_T y_data[34], int32_T
  y_size[2]);
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);
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
static void fft2melmx(real_T nfft, real_T sr, real_T maxfrq, emxArray_real_T
                      *wts);
static void mean(const emxArray_real_T *x, real_T y[16]);
static void melfcc(const emxArray_real_T *samples, real_T sr, emxArray_real_T
                   *cepstra, emxArray_real_T *aspectrum, emxArray_real_T
                   *pspectrum);
static void myPowspec(emxArray_real_T *x, real_T sr, real_T wintime, real_T
                      steptime, emxArray_real_T *y, emxArray_real_T *e);
static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z);
static real_T rt_hypotd_snf(real_T u0, real_T u1);
static real_T rt_powd_snf(real_T u0, real_T u1);
static real_T rt_remd_snf(real_T u0, real_T u1);
static real_T rt_roundd_snf(real_T u);

/* Function Definitions */
static void b_eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  int32_T i;
  int32_T j;
  n = x->size[1] << 4;
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

static void b_log(emxArray_real_T *x)
{
  int32_T i4;
  int32_T k;
  i4 = x->size[1];
  for (k = 0; k < i4; k++) {
    x->data[(int32_T)(1.0 + (real_T)k) - 1] = log(x->data[(int32_T)(1.0 +
      (real_T)k) - 1]);
  }
}

static void b_std(const emxArray_real_T *varargin_1, real_T y[16])
{
  int32_T ix;
  int32_T iy;
  int32_T j;
  real_T b_y;
  int32_T b_ix;
  real_T xbar;
  int32_T k;
  real_T r;
  ix = -1;
  iy = -1;
  for (j = 0; j < 16; j++) {
    ix++;
    iy++;
    if (varargin_1->size[1] == 0) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix];
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 16;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)varargin_1->size[1];
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 16;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)varargin_1->size[1];
    }

    y[iy] = b_y;
  }

  for (k = 0; k < 16; k++) {
    y[k] = sqrt(y[k]);
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

static void eml_li_find(const boolean_T x[34], int32_T y_data[34], int32_T
  y_size[2])
{
  int32_T k;
  int32_T i;
  k = 0;
  for (i = 0; i < 34; i++) {
    if (x[i]) {
      k++;
    }
  }

  y_size[0] = 1;
  y_size[1] = k;
  k = 0;
  for (i = 0; i < 34; i++) {
    if (x[i]) {
      y_data[k] = i + 1;
      k++;
    }
  }
}

static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx)
{
  int32_T ncols;
  int32_T k;
  int32_T j;
  int32_T i5;
  int32_T i;
  emxArray_real_T *b_x;
  ncols = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    ncols += idx->data[k - 1];
  }

  ncols = x->size[1] - ncols;
  j = 0;
  i5 = x->size[1];
  for (k = 1; k <= i5; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      for (i = 0; i < 16; i++) {
        x->data[i + x->size[0] * j] = x->data[i + x->size[0] * (k - 1)];
      }

      j++;
    }
  }

  if (1 > ncols) {
    ncols = 0;
  }

  emxInit_real_T(&b_x, 2);
  i5 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 16;
  b_x->size[1] = ncols;
  emxEnsureCapacity((emxArray__common *)b_x, i5, (int32_T)sizeof(real_T));
  for (i5 = 0; i5 < ncols; i5++) {
    for (j = 0; j < 16; j++) {
      b_x->data[j + b_x->size[0] * i5] = x->data[j + x->size[0] * i5];
    }
  }

  i5 = x->size[0] * x->size[1];
  x->size[0] = 16;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, i5, (int32_T)sizeof(real_T));
  ncols = b_x->size[1];
  for (i5 = 0; i5 < ncols; i5++) {
    for (j = 0; j < 16; j++) {
      x->data[j + x->size[0] * i5] = b_x->data[j + b_x->size[0] * i5];
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
  int32_T sz[2];
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
  for (ju = 0; ju < 2; ju++) {
    sz[ju] = x->size[ju];
  }

  ju = y->size[0] * y->size[1];
  y->size[0] = (int32_T)varargin_1;
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
  if ((int32_T)varargin_1 > x->size[0]) {
    ju = y->size[0] * y->size[1];
    y->size[0] = (int32_T)varargin_1;
    emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
    ju = y->size[0] * y->size[1];
    y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
    nd2 = (int32_T)varargin_1 * sz[1];
    for (ju = 0; ju < nd2; ju++) {
      y->data[ju].re = 0.0;
      y->data[ju].im = 0.0;
    }
  }

  if ((x->size[0] == 0) || (x->size[1] == 0)) {
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
    lastChan = (int32_T)varargin_1 * (div_s32(x->size[0] * x->size[1], x->size[0])
      - 1);
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
    while ((((int32_T)varargin_1 > 0) && (chanStart <= lastChan)) || (((int32_T)
             varargin_1 < 0) && (chanStart >= lastChan))) {
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

static void fft2melmx(real_T nfft, real_T sr, real_T maxfrq, emxArray_real_T
                      *wts)
{
  int32_T ib;
  int32_T br;
  real_T y;
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  emxArray_real_T *b_y;
  int32_T n;
  int32_T nm1d2;
  emxArray_real_T *fftfrqs;
  boolean_T linpts;
  real_T dv1[1];
  real_T maxfrq_data[1];
  int32_T maxfrq_size[2];
  emxArray_real_T b_maxfrq_data;
  real_T c_maxfrq_data[1];
  int32_T b_maxfrq_size[2];
  emxArray_real_T *c_y;
  emxArray_real_T d_maxfrq_data;
  real_T tmp_data[1];
  real_T dv2[1];
  boolean_T b_linpts[34];
  real_T binfrqs[34];
  static const real_T a[34] = { 0.0, 0.030303030303030304, 0.060606060606060608,
    0.090909090909090912, 0.12121212121212122, 0.15151515151515152,
    0.18181818181818182, 0.21212121212121213, 0.24242424242424243,
    0.27272727272727271, 0.30303030303030304, 0.33333333333333331,
    0.36363636363636365, 0.39393939393939392, 0.42424242424242425,
    0.45454545454545453, 0.48484848484848486, 0.51515151515151514,
    0.54545454545454541, 0.5757575757575758, 0.60606060606060608,
    0.63636363636363635, 0.66666666666666663, 0.696969696969697,
    0.72727272727272729, 0.75757575757575757, 0.78787878787878785,
    0.81818181818181823, 0.84848484848484851, 0.87878787878787878,
    0.90909090909090906, 0.93939393939393945, 0.96969696969696972, 1.0 };

  real_T d_y[34];
  int32_T tmp_size[2];
  int32_T b_tmp_data[34];
  int32_T c_tmp_data[34];
  real_T b_data[34];
  boolean_T c_linpts[34];
  boolean_T d_linpts[34];
  real_T x_data[34];
  emxArray_real_T *loslope;
  emxArray_real_T *hislope;
  emxArray_int32_T *r4;
  emxArray_real_T *minval;
  emxArray_real_T *fs;
  emxArray_real_T *b_fftfrqs;
  int32_T ar;
  real_T b_fs[3];
  int32_T iv0[2];
  real_T z[32];
  real_T d[1024];
  emxArray_real_T *b;
  int32_T ic;
  int32_T ia;

  /*  [wts,frqs] = fft2melmx(nfft, sr, nfilts, width, minfrq, maxfrq, htkmel, constamp) */
  /*       Generate a matrix of weights to combine FFT bins into Mel */
  /*       bins.  nfft defines the source FFT size at sampling rate sr. */
  /*       Optional nfilts specifies the number of output bands required  */
  /*       (else one per "mel/width"), and width is the constant width of each  */
  /*       band relative to standard Mel (default 1). */
  /*       While wts has nfft columns, the second half are all zero.  */
  /*       Hence, Mel spectrum is fft2melmx(nfft,sr)*abs(fft(xincols,nfft)); */
  /*       minfrq is the frequency (in Hz) of the lowest band edge; */
  /*       default is 0, but 133.33 is a common standard (to skip LF). */
  /*       maxfrq is frequency in Hz of upper edge; default sr/2. */
  /*       You can exactly duplicate the mel matrix in Slaney's mfcc.m */
  /*       as fft2melmx(512, 8000, 40, 1, 133.33, 6855.5, 0); */
  /*       htkmel=1 means use HTK's version of the mel curve, not Slaney's. */
  /*       constamp=1 means make integration windows peak at 1, not sum to 1. */
  /*       frqs returns bin center frqs. */
  /*  2004-09-05  dpwe@ee.columbia.edu  based on fft2barkmx */
  /*  default bottom edge at 0 */
  /*  default top edge at nyquist */
  ib = wts->size[0] * wts->size[1];
  wts->size[0] = 32;
  wts->size[1] = (int32_T)nfft;
  emxEnsureCapacity((emxArray__common *)wts, ib, (int32_T)sizeof(real_T));
  br = (int32_T)nfft << 5;
  for (ib = 0; ib < br; ib++) {
    wts->data[ib] = 0.0;
  }

  /*  Center freqs of each FFT bin */
  y = nfft / 2.0;
  ndbl = floor(y + 0.5);
  apnd = ndbl;
  cdiff = ndbl - y;
  if (fabs(cdiff) < 4.4408920985006262E-16 * y) {
    ndbl++;
    apnd = y;
  } else if (cdiff > 0.0) {
    apnd = ndbl - 1.0;
  } else {
    ndbl++;
  }

  emxInit_real_T(&b_y, 2);
  n = (int32_T)ndbl - 1;
  ib = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = n + 1;
  emxEnsureCapacity((emxArray__common *)b_y, ib, (int32_T)sizeof(real_T));
  if (n + 1 > 0) {
    b_y->data[0] = 0.0;
    if (n + 1 > 1) {
      b_y->data[n] = apnd;
      nm1d2 = n / 2;
      for (br = 1; br < nm1d2; br++) {
        b_y->data[br] = br;
        b_y->data[n - br] = apnd - (real_T)br;
      }

      if (nm1d2 << 1 == n) {
        b_y->data[nm1d2] = apnd / 2.0;
      } else {
        b_y->data[nm1d2] = nm1d2;
        b_y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&fftfrqs, 2);
  rdivide(b_y, nfft, fftfrqs);
  ib = fftfrqs->size[0] * fftfrqs->size[1];
  fftfrqs->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)fftfrqs, ib, (int32_T)sizeof(real_T));
  nm1d2 = fftfrqs->size[0];
  n = fftfrqs->size[1];
  br = nm1d2 * n;
  for (ib = 0; ib < br; ib++) {
    fftfrqs->data[ib] *= sr;
  }

  /*  'Center freqs' of mel bands - uniformly spaced between limits */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*   z = hz2mel(f,htk) */
  /*   Convert frequencies f (in Hz) to mel 'scale'. */
  /*   Optional htk = 1 uses the mel axis defined in the HTKBook */
  /*   otherwise use Slaney's formula */
  /*  2005-04-19 dpwe@ee.columbia.edu */
  /*  Mel fn to match Slaney's Auditory Toolbox mfcc.m */
  /*  133.33333; */
  /*  66.66667; */
  /*  starting mel value for log region */
  /*  the magic 1.0711703 which is the ratio needed to get from 1000 Hz to 6400 Hz in 27 steps, and is *almost* the ratio between 1000 Hz and the preceding linear filter center at 933.33333 Hz (actually 1000/933.33333 = 1.07142857142857 and  exp(log(6.4)/27) = 1.07117028749447) */
  linpts = (maxfrq < 1000.0);

  /*  fill in parts separately */
  br = 0;
  if (linpts) {
    br = 1;
  }

  dv1[0] = 0.0 * maxfrq;
  maxfrq_size[0] = 1;
  maxfrq_size[1] = br;
  ib = 0;
  while (ib <= br - 1) {
    maxfrq_data[0] = maxfrq;
    ib = 1;
  }

  b_maxfrq_data.data = (real_T *)&maxfrq_data;
  b_maxfrq_data.size = (int32_T *)&maxfrq_size;
  b_maxfrq_data.allocatedSize = 1;
  b_maxfrq_data.numDimensions = 2;
  b_maxfrq_data.canFreeData = FALSE;
  rdivide(&b_maxfrq_data, 66.666666666666671, b_y);
  br = b_y->size[0] * b_y->size[1];
  for (ib = 0; ib < br; ib++) {
    dv1[0] = b_y->data[ib];
  }

  br = 0;
  if (!linpts) {
    br = 1;
  }

  b_maxfrq_size[0] = 1;
  b_maxfrq_size[1] = br;
  ib = 0;
  while (ib <= br - 1) {
    c_maxfrq_data[0] = maxfrq;
    ib = 1;
  }

  emxInit_real_T(&c_y, 2);
  d_maxfrq_data.data = (real_T *)&c_maxfrq_data;
  d_maxfrq_data.size = (int32_T *)&b_maxfrq_size;
  d_maxfrq_data.allocatedSize = 1;
  d_maxfrq_data.numDimensions = 2;
  d_maxfrq_data.canFreeData = FALSE;
  rdivide(&d_maxfrq_data, 1000.0, b_y);
  b_log(b_y);
  ib = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = b_y->size[1];
  emxEnsureCapacity((emxArray__common *)c_y, ib, (int32_T)sizeof(real_T));
  br = b_y->size[0] * b_y->size[1];
  for (ib = 0; ib < br; ib++) {
    c_y->data[ib] = b_y->data[ib];
  }

  rdivide(c_y, 0.068751777420949192, b_y);
  nm1d2 = b_y->size[1];
  br = b_y->size[0] * b_y->size[1];
  emxFree_real_T(&c_y);
  for (ib = 0; ib < br; ib++) {
    tmp_data[ib] = b_y->data[ib];
  }

  dv2[0] = dv1[0];
  for (ib = 0; ib < nm1d2; ib++) {
    dv2[0] = 14.999999999999998 + tmp_data[ib];
  }

  for (ib = 0; ib < 34; ib++) {
    y = a[ib] * dv2[0];

    /*  seems like a good idea to avoid aliasing */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*    f = mel2hz(z, htk) */
    /*    Convert 'mel scale' frequencies into Hz */
    /*    Optional htk = 1 means use the HTK formula */
    /*    else use the formula from Slaney's mfcc.m */
    /*  2005-04-19 dpwe@ee.columbia.edu */
    /*  133.33333; */
    /*  66.66667; */
    /*  starting mel value for log region */
    /*  the magic 1.0711703 which is the ratio needed to get from 1000 Hz to 6400 Hz in 27 steps, and is *almost* the ratio between 1000 Hz and the preceding linear filter center at 933.33333 Hz (actually 1000/933.33333 = 1.07142857142857 and  exp(log(6.4)/27) = 1.07117028749447) */
    b_linpts[ib] = (y < 14.999999999999998);
    binfrqs[ib] = 0.0 * y;
    d_y[ib] = y;
  }

  /*  fill in parts separately */
  eml_li_find(b_linpts, b_tmp_data, tmp_size);
  eml_li_find(b_linpts, c_tmp_data, tmp_size);
  br = tmp_size[0] * tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    b_data[ib] = d_y[c_tmp_data[ib] - 1];
  }

  br = tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    binfrqs[b_tmp_data[ib] - 1] = 66.666666666666671 * b_data[ib];
  }

  for (ib = 0; ib < 34; ib++) {
    c_linpts[ib] = !b_linpts[ib];
    d_linpts[ib] = !b_linpts[ib];
  }

  eml_li_find(c_linpts, b_tmp_data, tmp_size);
  eml_li_find(d_linpts, c_tmp_data, tmp_size);
  br = tmp_size[0] * tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    b_data[ib] = d_y[c_tmp_data[ib] - 1] - 14.999999999999998;
  }

  br = tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    b_data[ib] *= 0.068751777420949192;
  }

  br = tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    x_data[ib] = b_data[ib];
  }

  for (br = 0; br < tmp_size[1]; br++) {
    x_data[br] = exp(x_data[br]);
  }

  br = tmp_size[1];
  for (ib = 0; ib < br; ib++) {
    binfrqs[b_tmp_data[ib] - 1] = 1000.0 * x_data[ib];
  }

  emxInit_real_T(&loslope, 2);
  emxInit_real_T(&hislope, 2);
  emxInit_int32_T(&r4, 1);
  emxInit_real_T(&minval, 2);
  emxInit_real_T(&fs, 2);
  emxInit_real_T(&b_fftfrqs, 2);
  for (ar = 0; ar < 32; ar++) {
    /*   fs = mel2hz(i + [-1 0 1], htkmel); */
    /*  scale by width */
    for (ib = 0; ib < 3; ib++) {
      b_fs[ib] = binfrqs[ar + 1] + (binfrqs[ib + ar] - binfrqs[ar + 1]);
    }

    /*  lower and upper slopes for all bins */
    ib = b_fftfrqs->size[0] * b_fftfrqs->size[1];
    b_fftfrqs->size[0] = 1;
    b_fftfrqs->size[1] = fftfrqs->size[1];
    emxEnsureCapacity((emxArray__common *)b_fftfrqs, ib, (int32_T)sizeof(real_T));
    br = fftfrqs->size[0] * fftfrqs->size[1];
    for (ib = 0; ib < br; ib++) {
      b_fftfrqs->data[ib] = fftfrqs->data[ib] - b_fs[0];
    }

    rdivide(b_fftfrqs, b_fs[1] - b_fs[0], loslope);
    ib = fs->size[0] * fs->size[1];
    fs->size[0] = 1;
    fs->size[1] = fftfrqs->size[1];
    emxEnsureCapacity((emxArray__common *)fs, ib, (int32_T)sizeof(real_T));
    br = fftfrqs->size[0] * fftfrqs->size[1];
    for (ib = 0; ib < br; ib++) {
      fs->data[ib] = b_fs[2] - fftfrqs->data[ib];
    }

    rdivide(fs, b_fs[2] - b_fs[1], hislope);

    /*  .. then intersect them with each other and zero */
    /*   wts(i,:) = 2/(fs(3)-fs(1))*max(0,min(loslope, hislope)); */
    y = nfft / 2.0;
    ndbl = floor(y + 0.5);
    apnd = ndbl;
    cdiff = ndbl - y;
    if (fabs(cdiff) < 4.4408920985006262E-16 * y) {
      ndbl++;
      apnd = y;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    n = (int32_T)ndbl - 1;
    ib = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)b_y, ib, (int32_T)sizeof(real_T));
    if (n + 1 > 0) {
      b_y->data[0] = 0.0;
      if (n + 1 > 1) {
        b_y->data[n] = apnd;
        nm1d2 = n / 2;
        for (br = 1; br < nm1d2; br++) {
          b_y->data[br] = br;
          b_y->data[n - br] = apnd - (real_T)br;
        }

        if (nm1d2 << 1 == n) {
          b_y->data[nm1d2] = apnd / 2.0;
        } else {
          b_y->data[nm1d2] = nm1d2;
          b_y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
        }
      }
    }

    ib = r4->size[0];
    r4->size[0] = b_y->size[1];
    emxEnsureCapacity((emxArray__common *)r4, ib, (int32_T)sizeof(int32_T));
    br = b_y->size[1];
    for (ib = 0; ib < br; ib++) {
      r4->data[ib] = (int32_T)(1.0 + b_y->data[ib]) - 1;
    }

    for (ib = 0; ib < 2; ib++) {
      iv0[ib] = loslope->size[ib];
    }

    ib = minval->size[0] * minval->size[1];
    minval->size[0] = 1;
    minval->size[1] = iv0[1];
    emxEnsureCapacity((emxArray__common *)minval, ib, (int32_T)sizeof(real_T));
    for (br = 0; br + 1 <= iv0[1]; br++) {
      ndbl = loslope->data[br];
      y = hislope->data[br];
      if ((ndbl <= y) || rtIsNaN(y)) {
        y = ndbl;
      }

      minval->data[br] = y;
    }

    for (ib = 0; ib < 2; ib++) {
      iv0[ib] = minval->size[ib];
    }

    ib = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = iv0[1];
    emxEnsureCapacity((emxArray__common *)b_y, ib, (int32_T)sizeof(real_T));
    for (br = 0; br + 1 <= iv0[1]; br++) {
      y = minval->data[br];
      if ((0.0 >= y) || rtIsNaN(y)) {
        y = 0.0;
      }

      b_y->data[br] = y;
    }

    br = b_y->size[1];
    for (ib = 0; ib < br; ib++) {
      wts->data[ar + wts->size[0] * r4->data[ib]] = b_y->data[b_y->size[0] * ib];
    }

    /*  actual algo and weighting in feacalc (more or less) */
    /*   wts(i,:) = 0; */
    /*   ww = binbin(i+2)-binbin(i); */
    /*   usl = binbin(i+1)-binbin(i); */
    /*   wts(i,1+binbin(i)+[1:usl]) = 2/ww * [1:usl]/usl; */
    /*   dsl = binbin(i+2)-binbin(i+1); */
    /*   wts(i,1+binbin(i+1)+[1:(dsl-1)]) = 2/ww * [(dsl-1):-1:1]/dsl; */
    /*  need to disable weighting below if you use this one */
  }

  emxFree_real_T(&b_fftfrqs);
  emxFree_real_T(&fs);
  emxFree_real_T(&minval);
  emxFree_real_T(&b_y);
  emxFree_int32_T(&r4);
  emxFree_real_T(&hislope);
  emxFree_real_T(&loslope);
  emxFree_real_T(&fftfrqs);

  /*  Slaney-style mel is scaled to be approx constant E per channel */
  for (ib = 0; ib < 32; ib++) {
    z[ib] = 2.0 / (binfrqs[2 + ib] - binfrqs[ib]);
  }

  memset(&d[0], 0, sizeof(real_T) << 10);
  for (nm1d2 = 0; nm1d2 < 32; nm1d2++) {
    d[nm1d2 + (nm1d2 << 5)] = z[nm1d2];
  }

  emxInit_real_T(&b, 2);
  ib = b->size[0] * b->size[1];
  b->size[0] = 32;
  b->size[1] = wts->size[1];
  emxEnsureCapacity((emxArray__common *)b, ib, (int32_T)sizeof(real_T));
  br = wts->size[0] * wts->size[1];
  for (ib = 0; ib < br; ib++) {
    b->data[ib] = wts->data[ib];
  }

  iv0[1] = wts->size[1];
  ib = wts->size[0] * wts->size[1];
  wts->size[0] = 32;
  emxEnsureCapacity((emxArray__common *)wts, ib, (int32_T)sizeof(real_T));
  ib = wts->size[0] * wts->size[1];
  wts->size[1] = iv0[1];
  emxEnsureCapacity((emxArray__common *)wts, ib, (int32_T)sizeof(real_T));
  br = iv0[1] << 5;
  for (ib = 0; ib < br; ib++) {
    wts->data[ib] = 0.0;
  }

  if (b->size[1] == 0) {
  } else {
    nm1d2 = (b->size[1] - 1) << 5;
    for (n = 0; n <= nm1d2; n += 32) {
      for (ic = n; ic + 1 <= n + 32; ic++) {
        wts->data[ic] = 0.0;
      }
    }

    br = 0;
    for (n = 0; n <= nm1d2; n += 32) {
      ar = 0;
      for (ib = br; ib + 1 <= br + 32; ib++) {
        if (b->data[ib] != 0.0) {
          ia = ar;
          for (ic = n; ic + 1 <= n + 32; ic++) {
            ia++;
            wts->data[ic] += b->data[ib] * d[ia - 1];
          }
        }

        ar += 32;
      }

      br += 32;
    }
  }

  emxFree_real_T(&b);

  /*  Make sure 2nd half of FFT is zero */
  y = nfft / 2.0;
  if (y + 2.0 > nfft) {
    ib = 0;
    n = 0;
  } else {
    ib = (int32_T)(y + 2.0) - 1;
    n = (int32_T)nfft;
  }

  br = n - ib;
  for (n = 0; n < br; n++) {
    for (nm1d2 = 0; nm1d2 < 32; nm1d2++) {
      wts->data[nm1d2 + wts->size[0] * (ib + n)] = 0.0;
    }
  }
}

static void mean(const emxArray_real_T *x, real_T y[16])
{
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  if (x->size[1] == 0) {
    memset(&y[0], 0, sizeof(real_T) << 4);
  } else {
    iy = -1;
    ixstart = -1;
    for (j = 0; j < 16; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[1]; k++) {
        ix += 16;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }

  iy = x->size[1];
  for (ixstart = 0; ixstart < 16; ixstart++) {
    y[ixstart] /= (real_T)iy;
  }
}

static void melfcc(const emxArray_real_T *samples, real_T sr, emxArray_real_T
                   *cepstra, emxArray_real_T *aspectrum, emxArray_real_T
                   *pspectrum)
{
  emxArray_real_T *b_samples;
  real_T wintime;
  int32_T i0;
  int32_T loop_ub;
  emxArray_real_T *logE;
  emxArray_real_T *wts;
  emxArray_real_T *b_wts;
  int32_T cr;
  int32_T br;
  int32_T ar;
  uint32_T unnamed_idx_1;
  int32_T ic;
  int32_T ib;
  int32_T ia;
  real_T dctm[512];
  b_emxInit_real_T(&b_samples, 1);

  /* , varargin) */
  /* [cepstra,aspectrum,pspectrum] = melfcc(samples, sr[, opts ...]) */
  /*   Calculate Mel-frequency cepstral coefficients by: */
  /*    - take the absolute value of the STFT */
  /*    - warp to a Mel frequency scale */
  /*    - take the DCT of the log-Mel-spectrum */
  /*    - return the first <ncep> components */
  /*   This version allows a lot of options to be controlled, as optional  */
  /*   'name', value pairs from the 3rd argument on: (defaults in parens) */
  /*     'wintime' (0.025): window length in sec */
  /*     'hoptime' (0.010): step between successive windows in sec */
  /*     'numcep'     (13): number of cepstra to return */
  /*     'lifterexp' (0.6): exponent for liftering; 0 = none; < 0 = HTK sin lifter */
  /*     'sumpower'    (1): 1 = sum abs(fft)^2; 0 = sum abs(fft) */
  /*     'preemph'  (0.97): apply pre-emphasis filter [1 -preemph] (0 = none) */
  /*     'dither'      (0): 1 = add offset to spectrum as if dither noise */
  /*     'minfreq'     (0): lowest band edge of mel filters (Hz) */
  /*     'maxfreq'  (4000): highest band edge of mel filters (Hz) */
  /*     'nbands'     (40): number of warped spectral bands to use */
  /*     'bwidth'    (1.0): width of aud spec filters relative to default */
  /*     'dcttype'     (2): type of DCT used - 1 or 2 (or 3 for HTK or 4 for feac) */
  /*     'fbtype'  ('mel'): frequency warp: 'mel','bark','htkmel','fcmel' */
  /*     'usecmp'      (0): apply equal-loudness weighting and cube-root compr. */
  /*     'modelorder'  (0): if > 0, fit a PLP model of this order */
  /*     'broaden'     (0): flag to retain the (useless?) first and last bands */
  /*     'useenergy'   (0): overwrite C0 with true log energy */
  /*  The following non-default values nearly duplicate Malcolm Slaney's mfcc */
  /*  (i.e. melfcc(d,16000,opts...) =~= log(10)*2*mfcc(d*(2^17),16000) ) */
  /*        'wintime': 0.016 */
  /*      'lifterexp': 0 */
  /*        'minfreq': 133.33 */
  /*        'maxfreq': 6855.6 */
  /*       'sumpower': 0 */
  /*  The following non-default values nearly duplicate HTK's MFCC */
  /*  (i.e. melfcc(d,16000,opts...) =~= 2*htkmelfcc(:,[13,[1:12]])' */
  /*   where HTK config has PREEMCOEF = 0.97, NUMCHANS = 20, CEPLIFTER = 22,  */
  /*   NUMCEPS = 12, WINDOWSIZE = 250000.0, USEHAMMING = T, TARGETKIND = MFCC_0) */
  /*      'lifterexp': -22 */
  /*         'nbands': 20 */
  /*        'maxfreq': 8000 */
  /*       'sumpower': 0 */
  /*         'fbtype': 'htkmel' */
  /*        'dcttype': 3 */
  /*  For more detail on reproducing other programs' outputs, see */
  /*  http://www.ee.columbia.edu/~dpwe/resources/matlab/rastamat/mfccs.html */
  /*  */
  /*  2005-04-19 dpwe@ee.columbia.edu after rastaplp.m.   */
  /*  Uses Mark Paskin's process_options.m from KPMtools */
  /*  $Header: /Users/dpwe/matlab/rastamat/RCS/melfcc.m,v 1.3 2012/09/03 14:01:26 dpwe Exp dpwe $ */
  /* if nargin < 2;   sr = 16000;    end */
  /*  Parse out the optional arguments */
  /*  [wintime, hoptime, numcep, lifterexp, sumpower, preemph, dither, ... */
  /*   minfreq, maxfreq, nbands, bwidth, dcttype, fbtype, usecmp, modelorder, ... */
  /*   broaden, useenergy] = ... */
  /*      process_options(varargin, 'wintime', 0.025, 'hoptime', 0.010, ... */
  /*            'numcep', 13, 'lifterexp', 0.6, 'sumpower', 1, 'preemph', 0.97, ... */
  /*  	  'dither', 0, 'minfreq', 0, 'maxfreq', 4000, ... */
  /*  	  'nbands', 40, 'bwidth', 1.0, 'dcttype', 2, ... */
  /*  	  'fbtype', 'mel', 'usecmp', 0, 'modelorder', 0, ... */
  /*            'broaden', 0, 'useenergy', 0); */
  /*  Modifications, commented out the above function, now passing all the */
  /*  variables internally */
  /* broaden=0; */
  wintime = 512.0 / sr;

  /* usecmp=0; */
  /*  Compute FFT power spectrum */
  i0 = b_samples->size[0];
  b_samples->size[0] = samples->size[0];
  emxEnsureCapacity((emxArray__common *)b_samples, i0, (int32_T)sizeof(real_T));
  loop_ub = samples->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_samples->data[i0] = samples->data[i0];
  }

  emxInit_real_T(&logE, 2);
  emxInit_real_T(&wts, 2);
  myPowspec(b_samples, sr, wintime, wintime / 3.0, pspectrum, logE);

  /* [pspectrum1,logE1] = powspec(samples, sr, wintime, hoptime, dither); */
  /* [aspectrum,wts] = audspec(pspectrum, sr, nfilts, fbtype, minfreq, maxfreq, sumpower, bwidth) */
  /*  */
  /*  perform critical band analysis (see PLP) */
  /*  takes power spectrogram as input */
  fft2melmx(((real_T)pspectrum->size[0] - 1.0) * 2.0, sr, sr / 2.0, wts);
  emxFree_real_T(&b_samples);
  if (1 > pspectrum->size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = pspectrum->size[0];
  }

  emxInit_real_T(&b_wts, 2);
  i0 = b_wts->size[0] * b_wts->size[1];
  b_wts->size[0] = 32;
  b_wts->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_wts, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < loop_ub; i0++) {
    for (cr = 0; cr < 32; cr++) {
      b_wts->data[cr + b_wts->size[0] * i0] = wts->data[cr + wts->size[0] * i0];
    }
  }

  i0 = wts->size[0] * wts->size[1];
  wts->size[0] = 32;
  wts->size[1] = b_wts->size[1];
  emxEnsureCapacity((emxArray__common *)wts, i0, (int32_T)sizeof(real_T));
  loop_ub = b_wts->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    for (cr = 0; cr < 32; cr++) {
      wts->data[cr + wts->size[0] * i0] = b_wts->data[cr + b_wts->size[0] * i0];
    }
  }

  emxFree_real_T(&b_wts);

  /*  Integrate FFT bins into Mel bins, in abs or abs^2 domains: */
  if ((wts->size[1] == 1) || (pspectrum->size[0] == 1)) {
    i0 = aspectrum->size[0] * aspectrum->size[1];
    aspectrum->size[0] = 32;
    aspectrum->size[1] = pspectrum->size[1];
    emxEnsureCapacity((emxArray__common *)aspectrum, i0, (int32_T)sizeof(real_T));
    for (i0 = 0; i0 < 32; i0++) {
      loop_ub = pspectrum->size[1];
      for (cr = 0; cr < loop_ub; cr++) {
        aspectrum->data[i0 + aspectrum->size[0] * cr] = 0.0;
        br = wts->size[1];
        for (ar = 0; ar < br; ar++) {
          aspectrum->data[i0 + aspectrum->size[0] * cr] += wts->data[i0 +
            wts->size[0] * ar] * pspectrum->data[ar + pspectrum->size[0] * cr];
        }
      }
    }
  } else {
    unnamed_idx_1 = (uint32_T)pspectrum->size[1];
    i0 = aspectrum->size[0] * aspectrum->size[1];
    aspectrum->size[0] = 32;
    emxEnsureCapacity((emxArray__common *)aspectrum, i0, (int32_T)sizeof(real_T));
    i0 = aspectrum->size[0] * aspectrum->size[1];
    aspectrum->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)aspectrum, i0, (int32_T)sizeof(real_T));
    loop_ub = (int32_T)unnamed_idx_1 << 5;
    for (i0 = 0; i0 < loop_ub; i0++) {
      aspectrum->data[i0] = 0.0;
    }

    if (pspectrum->size[1] == 0) {
    } else {
      loop_ub = (pspectrum->size[1] - 1) << 5;
      for (cr = 0; cr <= loop_ub; cr += 32) {
        for (ic = cr; ic + 1 <= cr + 32; ic++) {
          aspectrum->data[ic] = 0.0;
        }
      }

      br = 0;
      for (cr = 0; cr <= loop_ub; cr += 32) {
        ar = 0;
        i0 = br + wts->size[1];
        for (ib = br; ib + 1 <= i0; ib++) {
          if (pspectrum->data[ib] != 0.0) {
            ia = ar;
            for (ic = cr; ic + 1 <= cr + 32; ic++) {
              ia++;
              aspectrum->data[ic] += pspectrum->data[ib] * wts->data[ia - 1];
            }
          }

          ar += 32;
        }

        br += wts->size[1];
      }
    }
  }

  /*  Modifications, commenting out below if statement */
  /*  if (usecmp) */
  /*    % PLP-like weighting/compression */
  /*    aspectrum = postaud(aspectrum, maxfreq, fbtype, broaden); */
  /*  end */
  /*  Convert to cepstra via DCT */
  /*  [cep,dctm] = spec2cep(spec, ncep, type) */
  /*      Calculate cepstra from spectral samples (in columns of spec) */
  /*      Return ncep cepstral rows (defaults to 9) */
  /*      This one does type II dct, or type I if type is specified as 1 */
  /*      dctm returns the DCT matrix that spec was multiplied by to give cep. */
  /*  2005-04-19 dpwe@ee.columbia.edu  for mfcc_dpwe */
  /*  type of DCT */
  /*  Make the DCT matrix */
  /*  this is the orthogonal one, the one you want */
  for (loop_ub = 0; loop_ub < 16; loop_ub++) {
    for (i0 = 0; i0 < 32; i0++) {
      dctm[loop_ub + (i0 << 4)] = cos((real_T)(loop_ub * (1 + 2 * i0)) / 64.0 *
        3.1415926535897931) * 0.25;
    }
  }

  i0 = wts->size[0] * wts->size[1];
  wts->size[0] = 32;
  wts->size[1] = aspectrum->size[1];
  emxEnsureCapacity((emxArray__common *)wts, i0, (int32_T)sizeof(real_T));
  loop_ub = aspectrum->size[0] * aspectrum->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    wts->data[i0] = aspectrum->data[i0];
  }

  i0 = aspectrum->size[1] << 5;
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    wts->data[(int32_T)(1.0 + (real_T)loop_ub) - 1] = log(wts->data[(int32_T)
      (1.0 + (real_T)loop_ub) - 1]);
  }

  unnamed_idx_1 = (uint32_T)wts->size[1];
  i0 = cepstra->size[0] * cepstra->size[1];
  cepstra->size[0] = 16;
  emxEnsureCapacity((emxArray__common *)cepstra, i0, (int32_T)sizeof(real_T));
  i0 = cepstra->size[0] * cepstra->size[1];
  cepstra->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)cepstra, i0, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)unnamed_idx_1 << 4;
  for (i0 = 0; i0 < loop_ub; i0++) {
    cepstra->data[i0] = 0.0;
  }

  if (wts->size[1] == 0) {
  } else {
    loop_ub = (wts->size[1] - 1) << 4;
    for (cr = 0; cr <= loop_ub; cr += 16) {
      for (ic = cr; ic + 1 <= cr + 16; ic++) {
        cepstra->data[ic] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= loop_ub; cr += 16) {
      ar = 0;
      for (ib = br; ib + 1 <= br + 32; ib++) {
        if (wts->data[ib] != 0.0) {
          ia = ar;
          for (ic = cr; ic + 1 <= cr + 16; ic++) {
            ia++;
            cepstra->data[ic] += wts->data[ib] * dctm[ia - 1];
          }
        }

        ar += 16;
      }

      br += 32;
    }
  }

  emxFree_real_T(&wts);

  /*  y = lifter(x, lift, invs) */
  /*    Apply lifter to matrix of cepstra (one per column) */
  /*    lift = exponent of x i^n liftering */
  /*    or, as a negative integer, the length of HTK-style sin-curve liftering. */
  /*    If inverse == 1 (default 0), undo the liftering. */
  /*  2005-05-19 dpwe@ee.columbia.edu */
  /*  liftering exponent */
  /*  flag to undo liftering */
  loop_ub = logE->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    cepstra->data[cepstra->size[0] * i0] = logE->data[logE->size[0] * i0];
  }

  emxFree_real_T(&logE);
}

static void myPowspec(emxArray_real_T *x, real_T sr, real_T wintime, real_T
                      steptime, emxArray_real_T *y, emxArray_real_T *e)
{
  real_T blockSize;
  real_T hopSize;
  int32_T i1;
  int32_T asub;
  int32_T numSamples;
  real_T numZerosToPad;
  int32_T csz_idx_1;
  real_T numBlocks;
  int32_T ak;
  real_T d0;
  int32_T i2;
  emxArray_real_T *a;
  emxArray_real_T *r2;
  int32_T na1;
  int32_T csz_idx_0;
  emxArray_real_T *av;
  int32_T k;
  real_T bv[512];
  static const real_T b[512] = { 0.0, 3.7796577274096244E-5,
    0.00015118059477142731, 0.00034013491038087373, 0.00060463095679685885,
    0.00094462874583833845, 0.0013600768744944647, 0.0018509125326960918,
    0.00241706151281168, 0.0030584382208665439, 0.0037749456894833888,
    0.00456647559254264, 0.0054329082615597324, 0.0063741127037773015,
    0.0073899466219696786, 0.0084802564359560684, 0.0096448773058199766,
    0.010883633156830497, 0.012196336706062738, 0.013582789490712122,
    0.015042781898099433, 0.016576093197361197, 0.018182491572821535,
    0.019861734159038968, 0.021613567077524876, 0.023437725475126125,
    0.025333933564067435, 0.02730190466364657, 0.029341341243576458,
    0.031451934968968087, 0.033633366746946, 0.035885306774891212,
    0.038207414590302524, 0.040599339122270095, 0.043060718744552196,
    0.045591181330248531, 0.048190344308060407, 0.050857814720130512,
    0.053593189281452569, 0.056396054440842724, 0.059265986443462593,
    0.062202551394885286, 0.0652053053266945, 0.06827379426360608,
    0.071407554292103159, 0.0746061116305734, 0.077868982700938449,
    0.0811956742017641, 0.084585683182840765, 0.088038497121222858,
    0.091553593998715044, 0.095130442380794267, 0.09876850149695543,
    0.10246722132246855, 0.10622604266153479, 0.11004439723182929,
    0.11392170775041788, 0.1178573880210339, 0.12185084302270349,
    0.12590146899970439, 0.13000865355284569, 0.13417177573205391,
    0.13839020613025255, 0.14266330697851953, 0.14699043224250907,
    0.15137092772012367, 0.15580413114041997, 0.16028937226373541,
    0.1648259729830191, 0.1694132474263525, 0.17405050206064371,
    0.1787370357964802, 0.183472140094124, 0.1882550990706332,
    0.19308518960809357, 0.19796168146294407, 0.20288383737637988,
    0.20785091318581578, 0.21286215793739288, 0.2179168139995134,
    0.22301411717738356, 0.22815329682854946, 0.23333357597940785,
    0.23855417144267388, 0.24381429393578813, 0.24911314820024566,
    0.25444993312182745, 0.25982384185171903, 0.26523406192849397,
    0.27067977540094745, 0.27616015895175933, 0.281674384021968,
    0.28722161693623766, 0.29280101902889821, 0.29841174677074023,
    0.3040529518965453, 0.30972378153333141, 0.31542337832929634,
    0.32115088058343716, 0.32690542237582787, 0.332686133698534,
    0.33849214058714694, 0.3443225652529146, 0.35017652621545126,
    0.35605313843600539, 0.36195151345126547, 0.36787075950768328,
    0.37380998169629476, 0.37976828208801833, 0.38574475986940937,
    0.39173851147885069, 0.3977486307431588, 0.403774209014585,
    0.40981433530819011, 0.41586809643957334, 0.42193457716293314,
    0.42801286030943975, 0.43410202692589861, 0.44020115641368346,
    0.44630932666791845, 0.45242561421688732, 0.45854909436165031,
    0.46467884131584541, 0.470813928345655, 0.476953427909915,
    0.48309641180034668, 0.48924195128188885, 0.49538911723310969,
    0.5015369802866777, 0.507684610969869, 0.513831079845091,
    0.51997545765040032, 0.526116815439995, 0.53225422472465811,
    0.53838675761213217, 0.54451348694740465, 0.55063348645288057,
    0.556745830868423, 0.56284959609123986, 0.56894385931559555,
    0.57502769917232632, 0.58110019586813921, 0.58716043132467188,
    0.59320748931729317, 0.5992404556136246, 0.60525841811175862,
    0.61126046697815717, 0.61724569478520486, 0.62321319664840047,
    0.62916207036316285, 0.6350914165412318, 0.64100033874664319,
    0.64688794363125812, 0.65275334106982486, 0.658595644294553,
    0.66441397002918134, 0.67020743862251719, 0.67597517418142694,
    0.6817163047032595, 0.68742996220768138, 0.69311528286790314,
    0.69877140714127783, 0.70439747989925294, 0.70999265055665362,
    0.715556073200279, 0.7210869067167941, 0.726584314919893, 0.73204746667672,
    0.737475536033525, 0.74286770234053645, 0.74822315037603238,
    0.7535410704695904, 0.7588206586245, 0.76406111663931409, 0.7692616522285276,
    0.77442147914235948, 0.77953981728562316, 0.78461589283566591,
    0.78964893835936034, 0.79463819292913085, 0.79958290223799344,
    0.80448231871359832, 0.80933570163125157, 0.81414231722590369,
    0.8189014388030833, 0.82361234684876461, 0.828274329138148,
    0.83288668084333761, 0.8374487046399034, 0.84195971081230514,
    0.8464190173581696, 0.85082595009139883, 0.85517984274409842,
    0.85948003706730813, 0.86372588293051966, 0.8679167384199683,
    0.87205196993568013, 0.87613095228726556, 0.8801530687884378,
    0.88411771135024786, 0.88802428057302063, 0.89187218583697359,
    0.89566084539151236, 0.89938968644318229, 0.90305814524226791,
    0.906665667168023, 0.91021170681252261, 0.913695728063121,
    0.91711720418350473, 0.92047561789332732, 0.9237704614464155,
    0.92700123670753354, 0.93016745522769417, 0.93326863831800533,
    0.9363043171220421, 0.93927403268673026, 0.9421773360317347,
    0.94501378821733839, 0.94778296041080434, 0.95048443395120952,
    0.95311780041274019, 0.95568266166644067, 0.95817862994040448,
    0.96060532787840081, 0.962962388596925, 0.96524945574066656,
    0.9674661835363858, 0.96961223684518849, 0.9716872912131963,
    0.97369103292059767, 0.97562315902907981, 0.97748337742762759,
    0.979271406876687, 0.98098697705068549, 0.9826298285789, 0.984199713084672,
    0.985696393222957, 0.98711964271620922, 0.98846924638859091,
    0.98974500019850375, 0.99094671126943834, 0.99207419791913287,
    0.99312728968704245, 0.99410582736010955, 0.995009662996835,
    0.99583865994964493, 0.99659269288554975, 0.99727164780509292,
    0.997875422059586, 0.99840392436662828, 0.99885707482390618,
    0.99923480492127492, 0.999537057551115, 0.99976378701696711,
    0.99991495904043992, 0.99999055076639343, 0.99999055076639343,
    0.99991495904043992, 0.99976378701696711, 0.999537057551115,
    0.99923480492127492, 0.99885707482390618, 0.99840392436662828,
    0.997875422059586, 0.99727164780509292, 0.99659269288554975,
    0.99583865994964493, 0.995009662996835, 0.99410582736010955,
    0.99312728968704245, 0.99207419791913287, 0.99094671126943834,
    0.98974500019850375, 0.98846924638859091, 0.98711964271620922,
    0.985696393222957, 0.984199713084672, 0.9826298285789, 0.98098697705068549,
    0.979271406876687, 0.97748337742762759, 0.97562315902907981,
    0.97369103292059767, 0.9716872912131963, 0.96961223684518849,
    0.9674661835363858, 0.96524945574066656, 0.962962388596925,
    0.96060532787840081, 0.95817862994040448, 0.95568266166644067,
    0.95311780041274019, 0.95048443395120952, 0.94778296041080434,
    0.94501378821733839, 0.9421773360317347, 0.93927403268673026,
    0.9363043171220421, 0.93326863831800533, 0.93016745522769417,
    0.92700123670753354, 0.9237704614464155, 0.92047561789332732,
    0.91711720418350473, 0.913695728063121, 0.91021170681252261,
    0.906665667168023, 0.90305814524226791, 0.89938968644318229,
    0.89566084539151236, 0.89187218583697359, 0.88802428057302063,
    0.88411771135024786, 0.8801530687884378, 0.87613095228726556,
    0.87205196993568013, 0.8679167384199683, 0.86372588293051966,
    0.85948003706730813, 0.85517984274409842, 0.85082595009139883,
    0.8464190173581696, 0.84195971081230514, 0.8374487046399034,
    0.83288668084333761, 0.828274329138148, 0.82361234684876461,
    0.8189014388030833, 0.81414231722590369, 0.80933570163125157,
    0.80448231871359832, 0.79958290223799344, 0.79463819292913085,
    0.78964893835936034, 0.78461589283566591, 0.77953981728562316,
    0.77442147914235948, 0.7692616522285276, 0.76406111663931409,
    0.7588206586245, 0.7535410704695904, 0.74822315037603238,
    0.74286770234053645, 0.737475536033525, 0.73204746667672, 0.726584314919893,
    0.7210869067167941, 0.715556073200279, 0.70999265055665362,
    0.70439747989925294, 0.69877140714127783, 0.69311528286790314,
    0.68742996220768138, 0.6817163047032595, 0.67597517418142694,
    0.67020743862251719, 0.66441397002918134, 0.658595644294553,
    0.65275334106982486, 0.64688794363125812, 0.64100033874664319,
    0.6350914165412318, 0.62916207036316285, 0.62321319664840047,
    0.61724569478520486, 0.61126046697815717, 0.60525841811175862,
    0.5992404556136246, 0.59320748931729317, 0.58716043132467188,
    0.58110019586813921, 0.57502769917232632, 0.56894385931559555,
    0.56284959609123986, 0.556745830868423, 0.55063348645288057,
    0.54451348694740465, 0.53838675761213217, 0.53225422472465811,
    0.526116815439995, 0.51997545765040032, 0.513831079845091, 0.507684610969869,
    0.5015369802866777, 0.49538911723310969, 0.48924195128188885,
    0.48309641180034668, 0.476953427909915, 0.470813928345655,
    0.46467884131584541, 0.45854909436165031, 0.45242561421688732,
    0.44630932666791845, 0.44020115641368346, 0.43410202692589861,
    0.42801286030943975, 0.42193457716293314, 0.41586809643957334,
    0.40981433530819011, 0.403774209014585, 0.3977486307431588,
    0.39173851147885069, 0.38574475986940937, 0.37976828208801833,
    0.37380998169629476, 0.36787075950768328, 0.36195151345126547,
    0.35605313843600539, 0.35017652621545126, 0.3443225652529146,
    0.33849214058714694, 0.332686133698534, 0.32690542237582787,
    0.32115088058343716, 0.31542337832929634, 0.30972378153333141,
    0.3040529518965453, 0.29841174677074023, 0.29280101902889821,
    0.28722161693623766, 0.281674384021968, 0.27616015895175933,
    0.27067977540094745, 0.26523406192849397, 0.25982384185171903,
    0.25444993312182745, 0.24911314820024566, 0.24381429393578813,
    0.23855417144267388, 0.23333357597940785, 0.22815329682854946,
    0.22301411717738356, 0.2179168139995134, 0.21286215793739288,
    0.20785091318581578, 0.20288383737637988, 0.19796168146294407,
    0.19308518960809357, 0.1882550990706332, 0.183472140094124,
    0.1787370357964802, 0.17405050206064371, 0.1694132474263525,
    0.1648259729830191, 0.16028937226373541, 0.15580413114041997,
    0.15137092772012367, 0.14699043224250907, 0.14266330697851953,
    0.13839020613025255, 0.13417177573205391, 0.13000865355284569,
    0.12590146899970439, 0.12185084302270349, 0.1178573880210339,
    0.11392170775041788, 0.11004439723182929, 0.10622604266153479,
    0.10246722132246855, 0.09876850149695543, 0.095130442380794267,
    0.091553593998715044, 0.088038497121222858, 0.084585683182840765,
    0.0811956742017641, 0.077868982700938449, 0.0746061116305734,
    0.071407554292103159, 0.06827379426360608, 0.0652053053266945,
    0.062202551394885286, 0.059265986443462593, 0.056396054440842724,
    0.053593189281452569, 0.050857814720130512, 0.048190344308060407,
    0.045591181330248531, 0.043060718744552196, 0.040599339122270095,
    0.038207414590302524, 0.035885306774891212, 0.033633366746946,
    0.031451934968968087, 0.029341341243576458, 0.02730190466364657,
    0.025333933564067435, 0.023437725475126125, 0.021613567077524876,
    0.019861734159038968, 0.018182491572821535, 0.016576093197361197,
    0.015042781898099433, 0.013582789490712122, 0.012196336706062738,
    0.010883633156830497, 0.0096448773058199766, 0.0084802564359560684,
    0.0073899466219696786, 0.0063741127037773015, 0.0054329082615597324,
    0.00456647559254264, 0.0037749456894833888, 0.0030584382208665439,
    0.00241706151281168, 0.0018509125326960918, 0.0013600768744944647,
    0.00094462874583833845, 0.00060463095679685885, 0.00034013491038087373,
    0.00015118059477142731, 3.7796577274096244E-5, 0.0 };

  real_T cv[512];
  emxArray_creal_T *b_x;
  int32_T sz[2];
  emxArray_real_T *r3;
  emxArray_real_T *idx;
  emxArray_boolean_T *b_b;
  emxArray_real_T *b_y;

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  blockSize = rt_roundd_snf(wintime * sr);
  hopSize = rt_roundd_snf(steptime * sr);

  /* WINDOW = hamming(winpts); */
  /* WINDOW = hanning(blockSize)'; */
  /*  hanning gives much less noisy sidelobes */
  /* NOVERLAP = blockSize - hopSize; */
  /* SAMPRATE = sr; */
  /*  Values coming out of rasta treat samples as integers,  */
  /*  not range -1..1, hence scale up here to match (approx) */
  i1 = x->size[0];
  emxEnsureCapacity((emxArray__common *)x, i1, (int32_T)sizeof(real_T));
  asub = x->size[0];
  for (i1 = 0; i1 < asub; i1++) {
    x->data[i1] *= 32768.0;
  }

  numSamples = x->size[0];
  numZerosToPad = rt_remd_snf(x->size[0], hopSize);
  csz_idx_1 = x->size[0];
  i1 = x->size[0];
  x->size[0] = csz_idx_1 + (int32_T)numZerosToPad;
  emxEnsureCapacity((emxArray__common *)x, i1, (int32_T)sizeof(real_T));
  asub = (int32_T)numZerosToPad;
  for (i1 = 0; i1 < asub; i1++) {
    x->data[csz_idx_1 + i1] = 0.0;
  }

  numBlocks = ((real_T)numSamples + numZerosToPad) / hopSize;
  numZerosToPad = floor(numBlocks);
  numBlocks = floor(numBlocks) - 2.0;
  i1 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)blockSize;
  y->size[1] = (int32_T)(numZerosToPad - 2.0);
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  asub = (int32_T)blockSize * (int32_T)(numZerosToPad - 2.0);
  for (i1 = 0; i1 < asub; i1++) {
    y->data[i1] = 0.0;
  }

  numZerosToPad = 1.0;
  for (ak = 0; ak < (int32_T)numBlocks; ak++) {
    d0 = (numZerosToPad + blockSize) - 1.0;
    if (numZerosToPad > d0) {
      i1 = 1;
      i2 = 0;
    } else {
      i1 = (int32_T)numZerosToPad;
      i2 = (int32_T)d0;
    }

    asub = i2 - i1;
    for (i2 = 0; i2 <= asub; i2++) {
      y->data[i2 + y->size[0] * ((int32_T)(1.0 + (real_T)ak) - 1)] = x->data[(i1
        + i2) - 1];
    }

    numZerosToPad += hopSize;
  }

  emxInit_real_T(&a, 2);
  i1 = a->size[0] * a->size[1];
  a->size[0] = y->size[0];
  a->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)a, i1, (int32_T)sizeof(real_T));
  asub = y->size[0] * y->size[1];
  for (i1 = 0; i1 < asub; i1++) {
    a->data[i1] = y->data[i1];
  }

  emxInit_real_T(&r2, 2);
  na1 = y->size[0];
  csz_idx_0 = y->size[0];
  csz_idx_1 = y->size[1];
  numSamples = y->size[0];
  i1 = r2->size[0] * r2->size[1];
  r2->size[0] = numSamples;
  emxEnsureCapacity((emxArray__common *)r2, i1, (int32_T)sizeof(real_T));
  numSamples = y->size[1];
  i1 = r2->size[0] * r2->size[1];
  r2->size[1] = numSamples;
  emxEnsureCapacity((emxArray__common *)r2, i1, (int32_T)sizeof(real_T));
  asub = y->size[0] * y->size[1];
  for (i1 = 0; i1 < asub; i1++) {
    r2->data[i1] = 0.0;
  }

  b_emxInit_real_T(&av, 1);
  i1 = y->size[0] * y->size[1];
  y->size[0] = csz_idx_0;
  y->size[1] = csz_idx_1;
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  i1 = av->size[0];
  av->size[0] = na1;
  emxEnsureCapacity((emxArray__common *)av, i1, (int32_T)sizeof(real_T));
  asub = 1;
  ak = -1;
  i1 = csz_idx_0 * csz_idx_1 - csz_idx_0;
  numSamples = 0;
  while ((r2->size[0] > 0) && (numSamples <= i1)) {
    for (k = 1; k <= na1; k++) {
      av->data[k - 1] = a->data[ak + k];
    }

    memcpy(&bv[0], &b[0], sizeof(real_T) << 9);
    for (i2 = 0; i2 < 512; i2++) {
      cv[i2] = av->data[i2] * bv[i2];
    }

    for (k = 0; k + 1 <= r2->size[0]; k++) {
      y->data[numSamples + k] = cv[k];
    }

    if (asub < a->size[1]) {
      ak += na1;
      asub++;
    } else {
      asub = 1;
    }

    numSamples += r2->size[0];
  }

  emxFree_real_T(&r2);
  emxFree_real_T(&av);
  emxInit_creal_T(&b_x, 2);
  fft(y, rt_powd_snf(2.0, ceil(log(blockSize) / 0.69314718055994529)), b_x);
  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = b_x->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = sz[0];
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  i1 = b_x->size[0] * b_x->size[1];
  for (k = 0; k < i1; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_hypotd_snf(b_x->data[(int32_T)
      (1.0 + (real_T)k) - 1].re, b_x->data[(int32_T)(1.0 + (real_T)k) - 1].im);
  }

  emxFree_creal_T(&b_x);
  b_emxInit_real_T(&r3, 1);
  d0 = blockSize / 2.0 + 2.0;
  i1 = y->size[0];
  i2 = r3->size[0];
  r3->size[0] = (int32_T)floor((real_T)i1 - d0) + 1;
  emxEnsureCapacity((emxArray__common *)r3, i2, (int32_T)sizeof(real_T));
  asub = (int32_T)floor((real_T)i1 - d0);
  for (i1 = 0; i1 <= asub; i1++) {
    r3->data[i1] = d0 + (real_T)i1;
  }

  emxInit_real_T(&idx, 2);
  i1 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof(real_T));
  numSamples = r3->size[0];
  i1 = idx->size[0] * idx->size[1];
  idx->size[1] = numSamples;
  emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof(real_T));
  asub = r3->size[0];
  for (i1 = 0; i1 < asub; i1++) {
    idx->data[i1] = r3->data[i1];
  }

  emxFree_real_T(&r3);
  if (idx->size[1] == 1) {
    numSamples = y->size[0];
    csz_idx_1 = y->size[0] - 1;
    i1 = y->size[1];
    for (csz_idx_0 = 0; csz_idx_0 + 1 <= i1; csz_idx_0++) {
      for (ak = (int32_T)idx->data[0]; ak < numSamples; ak++) {
        y->data[(ak + y->size[0] * csz_idx_0) - 1] = y->data[ak + y->size[0] *
          csz_idx_0];
      }
    }
  } else {
    emxInit_boolean_T(&b_b, 2);
    i1 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b_b, i1, (int32_T)sizeof(boolean_T));
    numSamples = y->size[0];
    i1 = b_b->size[0] * b_b->size[1];
    b_b->size[1] = numSamples;
    emxEnsureCapacity((emxArray__common *)b_b, i1, (int32_T)sizeof(boolean_T));
    asub = y->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      b_b->data[i1] = FALSE;
    }

    for (k = 1; k <= idx->size[1]; k++) {
      b_b->data[(int32_T)idx->data[k - 1] - 1] = TRUE;
    }

    numSamples = 0;
    for (k = 1; k <= b_b->size[1]; k++) {
      numSamples += b_b->data[k - 1];
    }

    csz_idx_1 = y->size[0] - numSamples;
    ak = 0;
    i1 = y->size[0];
    for (k = 1; k <= i1; k++) {
      if ((k > b_b->size[1]) || (!b_b->data[k - 1])) {
        i2 = y->size[1];
        for (csz_idx_0 = 0; csz_idx_0 + 1 <= i2; csz_idx_0++) {
          y->data[ak + y->size[0] * csz_idx_0] = y->data[(k + y->size[0] *
            csz_idx_0) - 1];
        }

        ak++;
      }
    }

    emxFree_boolean_T(&b_b);
  }

  emxFree_real_T(&idx);
  if (1 > csz_idx_1) {
    asub = 0;
  } else {
    asub = csz_idx_1;
  }

  emxInit_real_T(&b_y, 2);
  numSamples = y->size[1];
  i1 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = asub;
  b_y->size[1] = numSamples;
  emxEnsureCapacity((emxArray__common *)b_y, i1, (int32_T)sizeof(real_T));
  for (i1 = 0; i1 < numSamples; i1++) {
    for (i2 = 0; i2 < asub; i2++) {
      b_y->data[i2 + b_y->size[0] * i1] = y->data[i2 + y->size[0] * i1];
    }
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = b_y->size[0];
  y->size[1] = b_y->size[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  asub = b_y->size[1];
  for (i1 = 0; i1 < asub; i1++) {
    numSamples = b_y->size[0];
    for (i2 = 0; i2 < numSamples; i2++) {
      y->data[i2 + y->size[0] * i1] = b_y->data[i2 + b_y->size[0] * i1];
    }
  }

  emxFree_real_T(&b_y);
  i1 = a->size[0] * a->size[1];
  a->size[0] = y->size[0];
  a->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)a, i1, (int32_T)sizeof(real_T));
  asub = y->size[0] * y->size[1];
  for (i1 = 0; i1 < asub; i1++) {
    a->data[i1] = y->data[i1];
  }

  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = y->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = sz[0];
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof(real_T));
  i1 = sz[0] * sz[1];
  for (k = 0; k < i1; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = a->data[(int32_T)(1.0 + (real_T)k)
      - 1] * a->data[(int32_T)(1.0 + (real_T)k) - 1];
  }

  emxFree_real_T(&a);

  /* y = abs(specgram(x*32768,NFFT,SAMPRATE,WINDOW,NOVERLAP)).^2; */
  /*  imagine we had random dither that had a variance of 1 sample  */
  /*  step and a white spectrum.  That's like (in expectation, anyway) */
  /*  adding a constant value to every bin (to avoid digital zero) */
  /*  ignoring the hamming window, total power would be = #pts */
  /*  I think this doesn't quite make sense, but it's what rasta/powspec.c does */
  /*  that's all she wrote */
  /*  2012-09-03 Calculate log energy - after windowing, by parseval */
  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = y->size[i1];
  }

  i1 = e->size[0] * e->size[1];
  e->size[0] = 1;
  e->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)e, i1, (int32_T)sizeof(real_T));
  if ((y->size[0] == 0) || (y->size[1] == 0)) {
    i1 = e->size[0] * e->size[1];
    e->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)e, i1, (int32_T)sizeof(real_T));
    i1 = e->size[0] * e->size[1];
    e->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)e, i1, (int32_T)sizeof(real_T));
    asub = sz[1];
    for (i1 = 0; i1 < asub; i1++) {
      e->data[i1] = 0.0;
    }
  } else {
    csz_idx_1 = -1;
    csz_idx_0 = -1;
    for (ak = 1; ak <= y->size[1]; ak++) {
      numSamples = csz_idx_1 + 1;
      csz_idx_1++;
      numZerosToPad = y->data[numSamples];
      for (k = 2; k <= y->size[0]; k++) {
        csz_idx_1++;
        numZerosToPad += y->data[csz_idx_1];
      }

      csz_idx_0++;
      e->data[csz_idx_0] = numZerosToPad;
    }
  }

  b_log(e);
}

static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z)
{
  int32_T i3;
  int32_T loop_ub;
  i3 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i3, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    z->data[i3] = x->data[i3] / y;
  }
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

static real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T d1;
  real_T d2;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d1 = fabs(u0);
    d2 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d1 == 1.0) {
        y = rtNaN;
      } else if (d1 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d2 == 0.0) {
      y = 1.0;
    } else if (d2 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
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

void featureMFCCAndDerivative(const emxArray_real_T *denoisedSignal, real_T Fs,
  real_T featureVector1[64])
{
  emxArray_real_T *tempMFCC;
  emxArray_real_T *unusedU0;
  emxArray_real_T *unusedU1;
  emxArray_boolean_T *r0;
  int32_T ixLead;
  int32_T loop_ub;
  emxArray_int32_T *r1;
  emxArray_real_T *x;
  int32_T iyLead;
  emxArray_real_T *b_y1;
  int32_T ix;
  int32_T iy;
  real_T work;
  int32_T m;
  real_T tmp2;
  int32_T sz[2];
  emxArray_real_T *y;
  emxArray_boolean_T *zeroCols;
  real_T dv0[16];

  /* FEATUREMFCCANDDERIVATIVE Computes the MFCC and first derivative */
  /*    Removes MFCC values at zero frames */
  memset(&featureVector1[0], 0, sizeof(real_T) << 6);
  emxInit_real_T(&tempMFCC, 2);
  emxInit_real_T(&unusedU0, 2);
  emxInit_real_T(&unusedU1, 2);
  emxInit_boolean_T(&r0, 2);

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  window=512; */
  /*  val_fbtype='mel'; */
  /*  val_broaden=0; */
  /*  val_maxfreq=sr/2; */
  /*  val_minfreq=0; */
  /*  val_wintime=window/sr; */
  /*  val_hoptime=val_wintime/3; */
  /*  val_numcep=16; */
  /*  val_usecmp=0; */
  /*  val_dcttype=3; */
  /*  val_nbands=32; */
  /*  val_dither=0; */
  /*  val_lifterexp=0; */
  /*  val_sumpower=1; */
  /*  val_preemph=0; */
  /*  val_modelorder=0; */
  /*  val_bwidth=1; */
  /*  val_useenergy=1; */
  /* [cepstra,~,~] = melfcc(samples, sr,'wintime',val_wintime,'hoptime',val_hoptime,'numcep',val_numcep,'lifterexp',val_lifterexp,'sumpower',val_sumpower,'preemph',val_preemph,'dither',val_dither,'minfreq',val_minfreq,'maxfreq',val_maxfreq,'nbands',val_nbands,'bwidth',val_bwidth,'dcttype',val_dcttype,'fbtype',val_fbtype,'usecmp',val_usecmp,'modelorder',val_modelorder,'broaden',val_broaden,'useenergy',val_useenergy); */
  melfcc(denoisedSignal, Fs, tempMFCC, unusedU0, unusedU1);

  /*  Cepstra returns infinity and NaN for silent frames, make them zero */
  ixLead = r0->size[0] * r0->size[1];
  r0->size[0] = 16;
  r0->size[1] = tempMFCC->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixLead, (int32_T)sizeof(boolean_T));
  loop_ub = tempMFCC->size[0] * tempMFCC->size[1];
  emxFree_real_T(&unusedU1);
  emxFree_real_T(&unusedU0);
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    r0->data[ixLead] = rtIsNaN(tempMFCC->data[ixLead]);
  }

  emxInit_int32_T(&r1, 1);
  b_eml_li_find(r0, r1);
  loop_ub = r1->size[0];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    tempMFCC->data[r1->data[ixLead] - 1] = 0.0;
  }

  ixLead = r0->size[0] * r0->size[1];
  r0->size[0] = 16;
  r0->size[1] = tempMFCC->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixLead, (int32_T)sizeof(boolean_T));
  loop_ub = tempMFCC->size[0] * tempMFCC->size[1];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    r0->data[ixLead] = rtIsInf(tempMFCC->data[ixLead]);
  }

  b_eml_li_find(r0, r1);
  loop_ub = r1->size[0];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    tempMFCC->data[r1->data[ixLead] - 1] = 0.0;
  }

  emxInit_real_T(&x, 2);

  /* zeroCols = sum(cepstra)==0; */
  ixLead = x->size[0] * x->size[1];
  x->size[0] = 16;
  x->size[1] = 1 + tempMFCC->size[1];
  emxEnsureCapacity((emxArray__common *)x, ixLead, (int32_T)sizeof(real_T));
  for (ixLead = 0; ixLead < 16; ixLead++) {
    x->data[ixLead] = tempMFCC->data[ixLead];
  }

  loop_ub = tempMFCC->size[1];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    for (iyLead = 0; iyLead < 16; iyLead++) {
      x->data[iyLead + x->size[0] * (ixLead + 1)] = tempMFCC->data[iyLead +
        tempMFCC->size[0] * ixLead];
    }
  }

  emxInit_real_T(&b_y1, 2);
  if (1 >= x->size[1]) {
    ixLead = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 16;
    b_y1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)b_y1, ixLead, (int32_T)sizeof(real_T));
  } else {
    ixLead = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 16;
    b_y1->size[1] = x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)b_y1, ixLead, (int32_T)sizeof(real_T));
    ix = 16;
    iy = 0;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      ixLead = ix;
      iyLead = iy;
      work = x->data[ix - 16];
      for (m = 2; m <= x->size[1]; m++) {
        tmp2 = work;
        work = x->data[ixLead];
        tmp2 = x->data[ixLead] - tmp2;
        ixLead += 16;
        b_y1->data[iyLead] = tmp2;
        iyLead += 16;
      }

      ix++;
      iy++;
    }
  }

  emxFree_real_T(&x);
  for (ixLead = 0; ixLead < 2; ixLead++) {
    sz[ixLead] = tempMFCC->size[ixLead];
  }

  emxInit_real_T(&y, 2);
  ixLead = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, ixLead, (int32_T)sizeof(real_T));
  if (tempMFCC->size[1] == 0) {
    ixLead = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ixLead, (int32_T)sizeof(real_T));
    ixLead = y->size[0] * y->size[1];
    y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)y, ixLead, (int32_T)sizeof(real_T));
    loop_ub = sz[1];
    for (ixLead = 0; ixLead < loop_ub; ixLead++) {
      y->data[ixLead] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (iyLead = 1; iyLead <= tempMFCC->size[1]; iyLead++) {
      ixLead = ix + 1;
      ix++;
      tmp2 = tempMFCC->data[ixLead];
      for (loop_ub = 0; loop_ub < 15; loop_ub++) {
        ix++;
        tmp2 += tempMFCC->data[ix];
      }

      iy++;
      y->data[iy] = tmp2;
    }
  }

  emxInit_boolean_T(&zeroCols, 2);
  ixLead = zeroCols->size[0] * zeroCols->size[1];
  zeroCols->size[0] = 1;
  zeroCols->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)zeroCols, ixLead, (int32_T)sizeof
                    (boolean_T));
  loop_ub = y->size[0] * y->size[1];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    zeroCols->data[ixLead] = (y->data[ixLead] == 0.0);
  }

  emxFree_real_T(&y);

  /*  Removing mask values */
  eml_null_assignment(tempMFCC, zeroCols);
  eml_null_assignment(b_y1, zeroCols);

  /*  Double check isNan */
  ixLead = r0->size[0] * r0->size[1];
  r0->size[0] = 16;
  r0->size[1] = b_y1->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixLead, (int32_T)sizeof(boolean_T));
  loop_ub = b_y1->size[0] * b_y1->size[1];
  emxFree_boolean_T(&zeroCols);
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    r0->data[ixLead] = rtIsNaN(b_y1->data[ixLead]);
  }

  b_eml_li_find(r0, r1);
  loop_ub = r1->size[0];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    b_y1->data[r1->data[ixLead] - 1] = 0.0;
  }

  ixLead = r0->size[0] * r0->size[1];
  r0->size[0] = 16;
  r0->size[1] = b_y1->size[1];
  emxEnsureCapacity((emxArray__common *)r0, ixLead, (int32_T)sizeof(boolean_T));
  loop_ub = b_y1->size[0] * b_y1->size[1];
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    r0->data[ixLead] = rtIsInf(b_y1->data[ixLead]);
  }

  b_eml_li_find(r0, r1);
  loop_ub = r1->size[0];
  emxFree_boolean_T(&r0);
  for (ixLead = 0; ixLead < loop_ub; ixLead++) {
    b_y1->data[r1->data[ixLead] - 1] = 0.0;
  }

  emxFree_int32_T(&r1);

  /*  Storing means */
  mean(tempMFCC, dv0);
  memcpy(&featureVector1[0], &dv0[0], sizeof(real_T) << 4);
  mean(b_y1, dv0);
  memcpy(&featureVector1[16], &dv0[0], sizeof(real_T) << 4);

  /*  Storing std */
  b_std(tempMFCC, dv0);
  emxFree_real_T(&tempMFCC);
  memcpy(&featureVector1[32], &dv0[0], sizeof(real_T) << 4);
  b_std(b_y1, dv0);
  emxFree_real_T(&b_y1);
  memcpy(&featureVector1[48], &dv0[0], sizeof(real_T) << 4);
}

void featureMFCCAndDerivative_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void featureMFCCAndDerivative_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (featureMFCCAndDerivative.c) */
