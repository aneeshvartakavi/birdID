/*
 * computeSpectralFeatures.c
 *
 * Code generation for function 'computeSpectralFeatures'
 *
 * C source code generated on: Sat Apr 05 23:58:53 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "computeSpectralFeatures.h"

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
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void b_power(const emxArray_real_T *a, emxArray_real_T *y);
static void b_rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z);
static void b_sqrt(emxArray_real_T *x);
static void b_std(const emxArray_real_T *varargin_1, emxArray_real_T *y);
static void b_sum(const emxArray_real_T *x, emxArray_real_T *y);
static void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                   emxArray_real_T *c);
static void c_power(const emxArray_real_T *a, emxArray_real_T *y);
static void c_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                      emxArray_real_T *z);
static void c_std(const emxArray_real_T *varargin_1, real_T y[10]);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void featureSpectralCentroid(const emxArray_real_T *S, emxArray_real_T
  *feature);
static void featureSpectralCrest(const emxArray_real_T *S, emxArray_real_T
  *feature);
static void featureSpectralDecrease(const emxArray_real_T *S, emxArray_real_T
  *feature);
static void featureSpectralFlux(const emxArray_real_T *S, emxArray_real_T
  *feature);
static void featureSpectralRolloff(const emxArray_real_T *S, emxArray_real_T
  *feature);
static void featureSpectralSlope(emxArray_real_T *S, emxArray_real_T *feature);
static void mean(const emxArray_real_T *x, real_T y[10]);
static void power(const emxArray_real_T *a, emxArray_real_T *y);
static void rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                    emxArray_real_T *z);
static void repmat(const emxArray_real_T *a, real_T m, emxArray_real_T *b);
static real_T rt_powd_snf(real_T u0, real_T u1);
static void sum(const emxArray_real_T *x, emxArray_real_T *y);

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

static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions)
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

static void b_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv1[2];
  int32_T i7;
  int32_T k;
  for (i7 = 0; i7 < 2; i7++) {
    uv1[i7] = (uint32_T)a->size[i7];
  }

  i7 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv1[0];
  y->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity((emxArray__common *)y, i7, (int32_T)sizeof(real_T));
  i7 = (int32_T)uv1[0] * (int32_T)uv1[1];
  for (k = 0; k < i7; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_powd_snf(a->data[(int32_T)(1.0
      + (real_T)k) - 1], 4.0);
  }
}

static void b_rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z)
{
  int32_T i5;
  int32_T loop_ub;
  i5 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i5, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    z->data[i5] = x->data[i5] / y;
  }
}

static void b_sqrt(emxArray_real_T *x)
{
  int32_T i12;
  int32_T k;
  i12 = x->size[1];
  for (k = 0; k < i12; k++) {
    x->data[(int32_T)(1.0 + (real_T)k) - 1] = sqrt(x->data[(int32_T)(1.0 +
      (real_T)k) - 1]);
  }
}

static void b_std(const emxArray_real_T *varargin_1, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T ix;
  int32_T iy;
  int32_T i;
  real_T b_y;
  int32_T b_ix;
  real_T xbar;
  int32_T k;
  real_T r;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (uint32_T)varargin_1->size[ix];
  }

  ix = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)y, ix, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= varargin_1->size[1]; i++) {
    iy++;
    if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix];
      for (k = 0; k <= varargin_1->size[0] - 2; k++) {
        b_ix++;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)varargin_1->size[0];
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      for (k = 0; k <= varargin_1->size[0] - 2; k++) {
        b_ix++;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)varargin_1->size[0];
    }

    y->data[iy] = b_y;
    ix += varargin_1->size[0];
  }

  b_sqrt(y);
}

static void b_sum(const emxArray_real_T *x, emxArray_real_T *y)
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
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

static void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                   emxArray_real_T *c)
{
  emxArray_real_T *av;
  int32_T k;
  int32_T unnamed_idx_0;
  int32_T asub;
  int32_T bsub;
  int32_T ak;
  int32_T bk;
  int32_T a_idx_0;
  int32_T a_idx_1;
  int32_T b_a_idx_0;
  int32_T ck;
  emxArray_real_T *cv;
  int32_T exitg1;
  real_T b_b;
  int32_T exitg2;
  b_emxInit_real_T(&av, 1);
  k = c->size[0] * c->size[1];
  c->size[0] = a->size[0];
  c->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)c, k, (int32_T)sizeof(real_T));
  unnamed_idx_0 = a->size[0];
  k = av->size[0];
  av->size[0] = unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)av, k, (int32_T)sizeof(real_T));
  asub = 1;
  bsub = 1;
  ak = -1;
  bk = 0;
  a_idx_0 = a->size[0];
  a_idx_1 = a->size[1];
  b_a_idx_0 = a->size[0];
  ck = 0;
  b_emxInit_real_T(&cv, 1);
  do {
    exitg1 = 0;
    unnamed_idx_0 = a->size[0];
    if ((unnamed_idx_0 > 0) && (ck <= a_idx_0 * a_idx_1 - b_a_idx_0)) {
      for (k = 1; k <= a->size[0]; k++) {
        av->data[k - 1] = a->data[ak + k];
      }

      b_b = b->data[bk];
      k = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, k, (int32_T)sizeof(real_T));
      unnamed_idx_0 = av->size[0];
      for (k = 0; k < unnamed_idx_0; k++) {
        cv->data[k] = av->data[k] - b_b;
      }

      k = 1;
      do {
        exitg2 = 0;
        unnamed_idx_0 = a->size[0];
        if (k <= unnamed_idx_0) {
          c->data[(ck + k) - 1] = cv->data[k - 1];
          k++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (asub < a->size[1]) {
        ak += a->size[0];
        bk++;
        bsub++;
        asub++;
      } else if (bsub < b->size[1]) {
        bk++;
        bsub++;
      } else {
        asub = 1;
        bsub = 1;
      }

      unnamed_idx_0 = a->size[0];
      ck += unnamed_idx_0;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&cv);
  emxFree_real_T(&av);
}

static void c_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv2[2];
  int32_T i10;
  int32_T k;
  for (i10 = 0; i10 < 2; i10++) {
    uv2[i10] = (uint32_T)a->size[i10];
  }

  i10 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv2[0];
  y->size[1] = (int32_T)uv2[1];
  emxEnsureCapacity((emxArray__common *)y, i10, (int32_T)sizeof(real_T));
  i10 = (int32_T)uv2[0] * (int32_T)uv2[1];
  for (k = 0; k < i10; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_powd_snf(a->data[(int32_T)(1.0
      + (real_T)k) - 1], 3.0);
  }
}

static void c_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                      emxArray_real_T *z)
{
  int32_T i8;
  int32_T loop_ub;
  i8 = z->size[0] * z->size[1];
  z->size[0] = x->size[0];
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i8, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    z->data[i8] = x->data[i8] / y->data[i8];
  }
}

static void c_std(const emxArray_real_T *varargin_1, real_T y[10])
{
  int32_T d;
  int32_T ix;
  int32_T iy;
  int32_T j;
  real_T b_y;
  int32_T b_ix;
  real_T xbar;
  int32_T k;
  real_T r;
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  ix = -1;
  iy = -1;
  for (j = 0; j < 10; j++) {
    ix++;
    iy++;
    if (varargin_1->size[1] == 0) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix];
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 10;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)varargin_1->size[1];
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 10;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)d;
    }

    y[iy] = b_y;
  }

  for (k = 0; k < 10; k++) {
    y[k] = sqrt(y[k]);
  }
}

static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  int32_T i;
  int32_T j;
  n = 10 * x->size[1];
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
  int32_T ncols;
  int32_T k;
  int32_T j;
  int32_T i13;
  int32_T i;
  emxArray_real_T *b_x;
  ncols = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    ncols += idx->data[k - 1];
  }

  ncols = x->size[1] - ncols;
  j = 0;
  i13 = x->size[1];
  for (k = 1; k <= i13; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      for (i = 0; i < 10; i++) {
        x->data[i + x->size[0] * j] = x->data[i + x->size[0] * (k - 1)];
      }

      j++;
    }
  }

  if (1 > ncols) {
    ncols = 0;
  }

  emxInit_real_T(&b_x, 2);
  i13 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 10;
  b_x->size[1] = ncols;
  emxEnsureCapacity((emxArray__common *)b_x, i13, (int32_T)sizeof(real_T));
  for (i13 = 0; i13 < ncols; i13++) {
    for (j = 0; j < 10; j++) {
      b_x->data[j + b_x->size[0] * i13] = x->data[j + x->size[0] * i13];
    }
  }

  i13 = x->size[0] * x->size[1];
  x->size[0] = 10;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, i13, (int32_T)sizeof(real_T));
  ncols = b_x->size[1];
  for (i13 = 0; i13 < ncols; i13++) {
    for (j = 0; j < 10; j++) {
      x->data[j + x->size[0] * i13] = b_x->data[j + b_x->size[0] * i13];
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

static void featureSpectralCentroid(const emxArray_real_T *S, emxArray_real_T
  *feature)
{
  int32_T absb;
  int32_T apnd;
  int32_T ndbl;
  int32_T cdiff;
  emxArray_real_T *y;
  int32_T k;
  emxArray_real_T *a;
  int32_T mv[2];
  int32_T b_a[2];
  int32_T outsize[2];
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *r4;

  /* FEATURESPECTRALCENTROID Computes spectral centroid feature */
  /*  It is the mass center of the spectrum */
  if (S->size[0] < 1) {
    absb = -1;
    apnd = 0;
  } else {
    ndbl = (int32_T)floor(((real_T)S->size[0] - 1.0) + 0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - S->size[0]) + 1;
    absb = S->size[0];
    if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
      ndbl++;
      apnd = S->size[0];
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    absb = ndbl - 1;
  }

  emxInit_real_T(&y, 2);
  cdiff = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = absb + 1;
  emxEnsureCapacity((emxArray__common *)y, cdiff, (int32_T)sizeof(real_T));
  if (absb + 1 > 0) {
    y->data[0] = 1.0;
    if (absb + 1 > 1) {
      y->data[absb] = apnd;
      ndbl = absb / 2;
      for (k = 1; k < ndbl; k++) {
        y->data[k] = 1.0 + (real_T)k;
        y->data[absb - k] = apnd - k;
      }

      if (ndbl << 1 == absb) {
        y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ndbl] = 1.0 + (real_T)ndbl;
        y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  b_emxInit_real_T(&a, 1);
  cdiff = a->size[0];
  a->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)a, cdiff, (int32_T)sizeof(real_T));
  ndbl = y->size[1];
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    a->data[cdiff] = y->data[cdiff];
  }

  mv[0] = 1;
  mv[1] = S->size[1];
  b_a[0] = a->size[0];
  b_a[1] = 1;
  for (cdiff = 0; cdiff < 2; cdiff++) {
    outsize[cdiff] = b_a[cdiff] * mv[cdiff];
  }

  emxInit_real_T(&r2, 2);
  cdiff = r2->size[0] * r2->size[1];
  r2->size[0] = outsize[0];
  r2->size[1] = outsize[1];
  emxEnsureCapacity((emxArray__common *)r2, cdiff, (int32_T)sizeof(real_T));
  if ((outsize[0] == 0) || (outsize[1] == 0)) {
  } else {
    ndbl = 0;
    for (cdiff = 1; cdiff <= mv[1]; cdiff++) {
      absb = 0;
      for (k = 1; k <= a->size[0]; k++) {
        r2->data[ndbl] = a->data[absb];
        absb++;
        ndbl++;
      }
    }
  }

  emxFree_real_T(&a);
  emxInit_real_T(&r3, 2);
  cdiff = r3->size[0] * r3->size[1];
  r3->size[0] = r2->size[0];
  r3->size[1] = r2->size[1];
  emxEnsureCapacity((emxArray__common *)r3, cdiff, (int32_T)sizeof(real_T));
  ndbl = r2->size[0] * r2->size[1];
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    r3->data[cdiff] = r2->data[cdiff] * S->data[cdiff];
  }

  emxFree_real_T(&r2);
  emxInit_real_T(&r4, 2);
  sum(r3, y);
  sum(S, r4);
  rdivide(y, r4, feature);
  emxFree_real_T(&r3);
  emxFree_real_T(&r4);
  emxFree_real_T(&y);
}

static void featureSpectralCrest(const emxArray_real_T *S, emxArray_real_T
  *feature)
{
  uint32_T outsz[2];
  int32_T ix;
  emxArray_real_T *maxval;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  int32_T ixstop;
  real_T mtmp;
  int32_T b_ix;
  boolean_T exitg1;
  emxArray_real_T *r5;

  /* FEATURESPECTRALCREST Computes spectral crest */
  /*  It is a rough measure of tonality */
  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = (uint32_T)S->size[ix];
  }

  emxInit_real_T(&maxval, 2);
  ix = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity((emxArray__common *)maxval, ix, (int32_T)sizeof(real_T));
  ix = 0;
  iy = -1;
  for (i = 1; i <= S->size[1]; i++) {
    ixstart = ix;
    ixstop = ix + S->size[0];
    mtmp = S->data[ix];
    if (S->size[0] > 1) {
      if (rtIsNaN(S->data[ix])) {
        b_ix = ix + 1;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (b_ix + 1 <= ixstop)) {
          ixstart = b_ix;
          if (!rtIsNaN(S->data[b_ix])) {
            mtmp = S->data[b_ix];
            exitg1 = TRUE;
          } else {
            b_ix++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        for (b_ix = ixstart + 1; b_ix + 1 <= ixstop; b_ix++) {
          if (S->data[b_ix] > mtmp) {
            mtmp = S->data[b_ix];
          }
        }
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += S->size[0];
  }

  emxInit_real_T(&r5, 2);
  b_sum(S, r5);
  rdivide(maxval, r5, feature);
  emxFree_real_T(&r5);
  emxFree_real_T(&maxval);
}

static void featureSpectralDecrease(const emxArray_real_T *S, emxArray_real_T
  *feature)
{
  int32_T cdiff;
  int32_T apnd;
  int32_T ndbl;
  emxArray_real_T *k;
  int32_T i2;
  int32_T ar;
  emxArray_real_T *b_S;
  emxArray_real_T *b;
  int32_T i3;
  int32_T i4;
  emxArray_real_T *y;
  uint32_T unnamed_idx_1;
  int32_T ic;
  int32_T ia;
  emxArray_real_T *c_S;

  /* FEATURESPECTRALDECREASE Computes the Spectral Decrease */
  /*   A measure of steepness of spectral envelope over frequency */
  if (S->size[0] - 1 < 0) {
    cdiff = -1;
    apnd = -1;
  } else {
    ndbl = (int32_T)floor(((real_T)S->size[0] - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = (ndbl - S->size[0]) + 1;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((real_T)S->size[0] - 1.0)) {
      ndbl++;
      apnd = S->size[0] - 1;
    } else if (cdiff > 0) {
      apnd = ndbl - 1;
    } else {
      ndbl++;
    }

    cdiff = ndbl - 1;
  }

  emxInit_real_T(&k, 2);
  i2 = k->size[0] * k->size[1];
  k->size[0] = 1;
  k->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)k, i2, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    k->data[0] = 0.0;
    if (cdiff + 1 > 1) {
      k->data[cdiff] = apnd;
      ndbl = cdiff / 2;
      for (ar = 1; ar < ndbl; ar++) {
        k->data[ar] = ar;
        k->data[cdiff - ar] = apnd - ar;
      }

      if (ndbl << 1 == cdiff) {
        k->data[ndbl] = (real_T)apnd / 2.0;
      } else {
        k->data[ndbl] = ndbl;
        k->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  k->data[0] = 1.0;
  i2 = k->size[0] * k->size[1];
  k->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)k, i2, (int32_T)sizeof(real_T));
  ar = k->size[0];
  ndbl = k->size[1];
  ndbl *= ar;
  for (i2 = 0; i2 < ndbl; i2++) {
    k->data[i2] = 1.0 / k->data[i2];
  }

  emxInit_real_T(&b_S, 2);

  /*  compute slope */
  ndbl = S->size[1];
  i2 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = 1;
  b_S->size[1] = ndbl;
  emxEnsureCapacity((emxArray__common *)b_S, i2, (int32_T)sizeof(real_T));
  for (i2 = 0; i2 < ndbl; i2++) {
    b_S->data[b_S->size[0] * i2] = S->data[S->size[0] * i2];
  }

  emxInit_real_T(&b, 2);
  repmat(b_S, S->size[0], b);
  emxFree_real_T(&b_S);
  if (2 > S->size[0]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 1;
    i3 = S->size[0];
  }

  i4 = b->size[0] * b->size[1];
  b->size[0] = S->size[0];
  b->size[1] = S->size[1];
  emxEnsureCapacity((emxArray__common *)b, i4, (int32_T)sizeof(real_T));
  ndbl = S->size[0] * S->size[1];
  for (i4 = 0; i4 < ndbl; i4++) {
    b->data[i4] = S->data[i4] - b->data[i4];
  }

  emxInit_real_T(&y, 2);
  if ((k->size[1] == 1) || (b->size[0] == 1)) {
    i4 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b->size[1];
    emxEnsureCapacity((emxArray__common *)y, i4, (int32_T)sizeof(real_T));
    ndbl = b->size[1];
    for (i4 = 0; i4 < ndbl; i4++) {
      y->data[y->size[0] * i4] = 0.0;
      cdiff = k->size[1];
      for (ar = 0; ar < cdiff; ar++) {
        y->data[y->size[0] * i4] += k->data[k->size[0] * ar] * b->data[ar +
          b->size[0] * i4];
      }
    }
  } else {
    unnamed_idx_1 = (uint32_T)b->size[1];
    i4 = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, i4, (int32_T)sizeof(real_T));
    i4 = y->size[0] * y->size[1];
    y->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)y, i4, (int32_T)sizeof(real_T));
    ndbl = (int32_T)unnamed_idx_1;
    for (i4 = 0; i4 < ndbl; i4++) {
      y->data[i4] = 0.0;
    }

    if (b->size[1] == 0) {
    } else {
      for (ndbl = 1; ndbl - 1 < b->size[1]; ndbl++) {
        for (ic = ndbl; ic <= ndbl; ic++) {
          y->data[ic - 1] = 0.0;
        }
      }

      cdiff = 0;
      for (ndbl = 0; ndbl < b->size[1]; ndbl++) {
        ar = 0;
        i4 = cdiff + k->size[1];
        for (apnd = cdiff; apnd + 1 <= i4; apnd++) {
          if (b->data[apnd] != 0.0) {
            ia = ar;
            for (ic = ndbl; ic + 1 <= ndbl + 1; ic++) {
              ia++;
              y->data[ic] += b->data[apnd] * k->data[ia - 1];
            }
          }

          ar++;
        }

        cdiff += k->size[1];
      }
    }
  }

  emxFree_real_T(&b);
  emxInit_real_T(&c_S, 2);
  ndbl = S->size[1];
  i4 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = i3 - i2;
  c_S->size[1] = ndbl;
  emxEnsureCapacity((emxArray__common *)c_S, i4, (int32_T)sizeof(real_T));
  for (i4 = 0; i4 < ndbl; i4++) {
    cdiff = i3 - i2;
    for (ar = 0; ar < cdiff; ar++) {
      c_S->data[ar + c_S->size[0] * i4] = S->data[(i2 + ar) + S->size[0] * i4];
    }
  }

  b_sum(c_S, k);
  rdivide(y, k, feature);
  emxFree_real_T(&c_S);
  emxFree_real_T(&y);
  emxFree_real_T(&k);
}

static void featureSpectralFlux(const emxArray_real_T *S, emxArray_real_T
  *feature)
{
  emxArray_real_T *b_S;
  int32_T ix;
  int32_T iy;
  int32_T s;
  emxArray_real_T *x;
  int32_T ixLead;
  emxArray_real_T *b_y1;
  uint32_T ySize[2];
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  emxArray_real_T *A;
  b_emxInit_real_T(&b_S, 1);

  /* FEATURESPECTRALFLUX Computes the Spectral Flux */
  /*    It is a measure of change spectral shape */
  ix = S->size[0];
  iy = S->size[0];
  s = b_S->size[0];
  b_S->size[0] = iy;
  emxEnsureCapacity((emxArray__common *)b_S, s, (int32_T)sizeof(real_T));
  for (s = 0; s < iy; s++) {
    b_S->data[s] = S->data[s];
  }

  emxInit_real_T(&x, 2);
  s = x->size[0] * x->size[1];
  x->size[0] = ix;
  x->size[1] = 1 + S->size[1];
  emxEnsureCapacity((emxArray__common *)x, s, (int32_T)sizeof(real_T));
  s = 0;
  while (s <= 0) {
    for (s = 0; s < ix; s++) {
      x->data[s] = b_S->data[s];
    }

    s = 1;
  }

  emxFree_real_T(&b_S);
  ix = S->size[1];
  for (s = 0; s < ix; s++) {
    iy = S->size[0];
    for (ixLead = 0; ixLead < iy; ixLead++) {
      x->data[ixLead + x->size[0] * (s + 1)] = S->data[ixLead + S->size[0] * s];
    }
  }

  emxInit_real_T(&b_y1, 2);
  if (1 >= x->size[1]) {
    for (s = 0; s < 2; s++) {
      ySize[s] = (uint32_T)x->size[s];
    }

    s = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = (int32_T)ySize[0];
    emxEnsureCapacity((emxArray__common *)b_y1, s, (int32_T)sizeof(real_T));
    s = b_y1->size[0] * b_y1->size[1];
    b_y1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)b_y1, s, (int32_T)sizeof(real_T));
  } else {
    for (s = 0; s < 2; s++) {
      ySize[s] = (uint32_T)x->size[s];
    }

    s = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = (int32_T)ySize[0];
    b_y1->size[1] = x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)b_y1, s, (int32_T)sizeof(real_T));
    ix = 0;
    iy = 0;
    for (s = 1; s <= x->size[0]; s++) {
      ixLead = ix + x->size[0];
      iyLead = iy;
      work = x->data[ix];
      for (m = 2; m <= x->size[1]; m++) {
        tmp2 = work;
        work = x->data[ixLead];
        tmp2 = x->data[ixLead] - tmp2;
        ixLead += x->size[0];
        b_y1->data[iyLead] = tmp2;
        iyLead += x->size[0];
      }

      ix++;
      iy++;
    }
  }

  emxInit_real_T(&A, 2);
  power(b_y1, x);
  sum(x, A);
  b_sqrt(A);
  b_rdivide(A, S->size[0], feature);
  emxFree_real_T(&b_y1);
  emxFree_real_T(&A);
  emxFree_real_T(&x);
}

static void featureSpectralRolloff(const emxArray_real_T *S, emxArray_real_T
  *feature)
{
  emxArray_real_T *mag;
  int32_T i9;
  int32_T vstride;
  int32_T npages;
  int32_T loop_ub;
  int32_T dim;
  emxArray_real_T *x;
  int32_T ix;
  int32_T i;
  int32_T ak;
  int32_T bsub;
  real_T s;
  emxArray_boolean_T *b_S;
  emxArray_real_T *av;
  int32_T iy;
  int32_T ck;
  emxArray_boolean_T *cv;
  int32_T exitg2;
  int32_T exitg3;
  uint32_T sz[2];
  emxArray_boolean_T *b_x;
  emxArray_int32_T *y;
  emxArray_boolean_T *c_S;
  emxArray_int32_T *iindx;
  uint32_T b_sz;
  emxArray_int32_T *r6;
  int32_T exitg1;
  boolean_T mtmp;
  boolean_T a;
  emxInit_real_T(&mag, 2);

  /* FEATURESPECTRALROLLOFF Computes Spectral Rolloff */
  /*     Finds frequency bin where cumsum reaches 0.85 of magnitude */
  /* compute rolloff */
  b_sum(S, mag);
  i9 = mag->size[0] * mag->size[1];
  mag->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)mag, i9, (int32_T)sizeof(real_T));
  vstride = mag->size[0];
  npages = mag->size[1];
  loop_ub = vstride * npages;
  for (i9 = 0; i9 < loop_ub; i9++) {
    mag->data[i9] *= 0.85;
  }

  /*  Find indices where cumulative sum is greater */
  dim = 1;
  if (S->size[0] != 1) {
    dim = 0;
  }

  emxInit_real_T(&x, 2);
  i9 = x->size[0] * x->size[1];
  x->size[0] = S->size[0];
  x->size[1] = S->size[1];
  emxEnsureCapacity((emxArray__common *)x, i9, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  for (i9 = 0; i9 < loop_ub; i9++) {
    x->data[i9] = S->data[i9];
  }

  if ((!((S->size[0] == 0) || (S->size[1] == 0))) && (S->size[dim] > 1)) {
    vstride = 1;
    loop_ub = 1;
    while (loop_ub <= dim) {
      vstride *= S->size[0];
      loop_ub = 2;
    }

    npages = 1;
    loop_ub = dim + 2;
    while (loop_ub < 3) {
      npages *= S->size[1];
      loop_ub = 3;
    }

    ix = -1;
    for (i = 1; i <= npages; i++) {
      ak = ix;
      for (bsub = 1; bsub <= vstride; bsub++) {
        ak++;
        ix = ak;
        s = x->data[ak];
        for (loop_ub = 0; loop_ub <= S->size[dim] - 2; loop_ub++) {
          ix += vstride;
          s += x->data[ix];
          x->data[ix] = s;
        }
      }
    }
  }

  emxInit_boolean_T(&b_S, 2);
  b_emxInit_real_T(&av, 1);
  i9 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = x->size[0];
  b_S->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_S, i9, (int32_T)sizeof(boolean_T));
  vstride = x->size[0];
  i9 = av->size[0];
  av->size[0] = vstride;
  emxEnsureCapacity((emxArray__common *)av, i9, (int32_T)sizeof(real_T));
  npages = 1;
  bsub = 1;
  ak = -1;
  dim = 0;
  iy = x->size[0];
  ix = x->size[1];
  i = x->size[0];
  ck = 0;
  b_emxInit_boolean_T(&cv, 1);
  do {
    exitg2 = 0;
    vstride = x->size[0];
    if ((vstride > 0) && (ck <= iy * ix - i)) {
      for (loop_ub = 1; loop_ub <= x->size[0]; loop_ub++) {
        av->data[loop_ub - 1] = x->data[ak + loop_ub];
      }

      s = mag->data[dim];
      i9 = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, i9, (int32_T)sizeof(boolean_T));
      loop_ub = av->size[0];
      for (i9 = 0; i9 < loop_ub; i9++) {
        cv->data[i9] = (av->data[i9] >= s);
      }

      loop_ub = 1;
      do {
        exitg3 = 0;
        vstride = x->size[0];
        if (loop_ub <= vstride) {
          b_S->data[(ck + loop_ub) - 1] = cv->data[loop_ub - 1];
          loop_ub++;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      if (npages < x->size[1]) {
        ak += x->size[0];
        dim++;
        bsub++;
        npages++;
      } else if (bsub < mag->size[1]) {
        dim++;
        bsub++;
      } else {
        npages = 1;
        bsub = 1;
      }

      vstride = x->size[0];
      ck += vstride;
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_boolean_T(&cv);
  emxFree_real_T(&av);
  emxFree_real_T(&x);

  /*  Find the maximum value */
  for (i9 = 0; i9 < 2; i9++) {
    sz[i9] = (uint32_T)b_S->size[i9];
  }

  i9 = mag->size[0] * mag->size[1];
  mag->size[0] = 1;
  mag->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)mag, i9, (int32_T)sizeof(real_T));
  if ((b_S->size[0] == 0) || (b_S->size[1] == 0)) {
    i9 = mag->size[0] * mag->size[1];
    mag->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)mag, i9, (int32_T)sizeof(real_T));
    i9 = mag->size[0] * mag->size[1];
    mag->size[1] = (int32_T)sz[1];
    emxEnsureCapacity((emxArray__common *)mag, i9, (int32_T)sizeof(real_T));
    loop_ub = (int32_T)sz[1];
    for (i9 = 0; i9 < loop_ub; i9++) {
      mag->data[i9] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= b_S->size[1]; i++) {
      ak = ix + 1;
      ix++;
      s = b_S->data[ak];
      for (loop_ub = 2; loop_ub <= b_S->size[0]; loop_ub++) {
        ix++;
        s += (real_T)b_S->data[ix];
      }

      iy++;
      mag->data[iy] = s;
    }
  }

  emxInit_boolean_T(&b_x, 2);
  i9 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = mag->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, i9, (int32_T)sizeof(boolean_T));
  loop_ub = mag->size[0] * mag->size[1];
  for (i9 = 0; i9 < loop_ub; i9++) {
    b_x->data[i9] = (mag->data[i9] > 0.0);
  }

  emxFree_real_T(&mag);
  loop_ub = 0;
  for (i = 1; i <= b_x->size[1]; i++) {
    if (b_x->data[i - 1]) {
      loop_ub++;
    }
  }

  b_emxInit_int32_T(&y, 2);
  i9 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)y, i9, (int32_T)sizeof(int32_T));
  bsub = 0;
  for (i = 1; i <= b_x->size[1]; i++) {
    if (b_x->data[i - 1]) {
      y->data[bsub] = i;
      bsub++;
    }
  }

  emxFree_boolean_T(&b_x);
  emxInit_boolean_T(&c_S, 2);
  loop_ub = b_S->size[0];
  vstride = y->size[1];
  i9 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = loop_ub;
  c_S->size[1] = vstride;
  emxEnsureCapacity((emxArray__common *)c_S, i9, (int32_T)sizeof(boolean_T));
  for (i9 = 0; i9 < vstride; i9++) {
    for (dim = 0; dim < loop_ub; dim++) {
      c_S->data[dim + c_S->size[0] * i9] = b_S->data[dim + b_S->size[0] *
        (y->data[i9] - 1)];
    }
  }

  for (i9 = 0; i9 < 2; i9++) {
    sz[i9] = (uint32_T)c_S->size[i9];
  }

  emxFree_boolean_T(&c_S);
  b_emxInit_int32_T(&iindx, 2);
  b_sz = sz[1];
  sz[1] = sz[1];
  i9 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)iindx, i9, (int32_T)sizeof(int32_T));
  i9 = iindx->size[0] * iindx->size[1];
  iindx->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)iindx, i9, (int32_T)sizeof(int32_T));
  loop_ub = (int32_T)b_sz;
  for (i9 = 0; i9 < loop_ub; i9++) {
    iindx->data[i9] = 1;
  }

  ix = 1;
  iy = -1;
  i = 1;
  emxInit_int32_T(&r6, 1);
  do {
    exitg1 = 0;
    vstride = y->size[1];
    if (i <= vstride) {
      i9 = b_S->size[0] - 1;
      vstride = ix + i9;
      i9 = b_S->size[0];
      dim = r6->size[0];
      r6->size[0] = y->size[1];
      emxEnsureCapacity((emxArray__common *)r6, dim, (int32_T)sizeof(int32_T));
      loop_ub = y->size[1];
      for (dim = 0; dim < loop_ub; dim++) {
        r6->data[dim] = y->data[dim];
      }

      mtmp = b_S->data[(ix - 1) % i9 + b_S->size[0] * (r6->data[(ix - 1) / i9] -
        1)];
      npages = 1;
      i9 = b_S->size[0];
      if (i9 > 1) {
        bsub = 1;
        if (ix < vstride) {
          for (ak = ix; ak + 1 <= vstride; ak++) {
            bsub++;
            i9 = b_S->size[0];
            dim = r6->size[0];
            r6->size[0] = y->size[1];
            emxEnsureCapacity((emxArray__common *)r6, dim, (int32_T)sizeof
                              (int32_T));
            loop_ub = y->size[1];
            for (dim = 0; dim < loop_ub; dim++) {
              r6->data[dim] = y->data[dim];
            }

            a = b_S->data[ak % i9 + b_S->size[0] * (r6->data[ak / i9] - 1)];
            if (a > mtmp) {
              i9 = b_S->size[0];
              dim = r6->size[0];
              r6->size[0] = y->size[1];
              emxEnsureCapacity((emxArray__common *)r6, dim, (int32_T)sizeof
                                (int32_T));
              loop_ub = y->size[1];
              for (dim = 0; dim < loop_ub; dim++) {
                r6->data[dim] = y->data[dim];
              }

              mtmp = b_S->data[ak % i9 + b_S->size[0] * (r6->data[ak / i9] - 1)];
              npages = bsub;
            }
          }
        }
      }

      iy++;
      iindx->data[iy] = npages;
      i9 = b_S->size[0];
      ix += i9;
      i++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_int32_T(&r6);
  emxFree_int32_T(&y);
  emxFree_boolean_T(&b_S);
  i9 = feature->size[0] * feature->size[1];
  feature->size[0] = 1;
  feature->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)feature, i9, (int32_T)sizeof(real_T));
  loop_ub = iindx->size[0] * iindx->size[1];
  for (i9 = 0; i9 < loop_ub; i9++) {
    feature->data[i9] = iindx->data[i9];
  }

  emxFree_int32_T(&iindx);
}

static void featureSpectralSlope(emxArray_real_T *S, emxArray_real_T *feature)
{
  int32_T ar;
  int32_T apnd;
  int32_T ndbl;
  int32_T cdiff;
  emxArray_real_T *kmu;
  int32_T i11;
  real_T y;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *b_S;
  uint32_T unnamed_idx_1;
  int32_T ic;
  int32_T ia;
  emxArray_real_T *b;

  /* FUNCTIONSPECTRALSLOPE Computes the spectral slope */
  /*  */
  /*  compute index vector */
  if (S->size[0] - 1 < 0) {
    ar = -1;
    apnd = -1;
  } else {
    ndbl = (int32_T)floor(((real_T)S->size[0] - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = (ndbl - S->size[0]) + 1;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((real_T)S->size[0] - 1.0)) {
      ndbl++;
      apnd = S->size[0] - 1;
    } else if (cdiff > 0) {
      apnd = ndbl - 1;
    } else {
      ndbl++;
    }

    ar = ndbl - 1;
  }

  emxInit_real_T(&kmu, 2);
  i11 = kmu->size[0] * kmu->size[1];
  kmu->size[0] = 1;
  kmu->size[1] = ar + 1;
  emxEnsureCapacity((emxArray__common *)kmu, i11, (int32_T)sizeof(real_T));
  if (ar + 1 > 0) {
    kmu->data[0] = 0.0;
    if (ar + 1 > 1) {
      kmu->data[ar] = apnd;
      ndbl = ar / 2;
      for (cdiff = 1; cdiff < ndbl; cdiff++) {
        kmu->data[cdiff] = cdiff;
        kmu->data[ar - cdiff] = apnd - cdiff;
      }

      if (ndbl << 1 == ar) {
        kmu->data[ndbl] = (real_T)apnd / 2.0;
      } else {
        kmu->data[ndbl] = ndbl;
        kmu->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  y = (real_T)S->size[0] / 2.0;
  i11 = kmu->size[0] * kmu->size[1];
  kmu->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)kmu, i11, (int32_T)sizeof(real_T));
  ndbl = kmu->size[0];
  cdiff = kmu->size[1];
  ndbl *= cdiff;
  for (i11 = 0; i11 < ndbl; i11++) {
    kmu->data[i11] -= y;
  }

  emxInit_real_T(&b_y, 2);
  emxInit_real_T(&c_y, 2);

  /*  compute slope */
  b_sum(S, b_y);
  i11 = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = b_y->size[1];
  emxEnsureCapacity((emxArray__common *)c_y, i11, (int32_T)sizeof(real_T));
  ndbl = b_y->size[0] * b_y->size[1];
  for (i11 = 0; i11 < ndbl; i11++) {
    c_y->data[i11] = b_y->data[i11];
  }

  emxInit_real_T(&b_S, 2);
  b_rdivide(c_y, S->size[0], b_y);
  i11 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = S->size[0];
  b_S->size[1] = S->size[1];
  emxEnsureCapacity((emxArray__common *)b_S, i11, (int32_T)sizeof(real_T));
  ndbl = S->size[0] * S->size[1];
  emxFree_real_T(&c_y);
  for (i11 = 0; i11 < ndbl; i11++) {
    b_S->data[i11] = S->data[i11];
  }

  bsxfun(b_S, b_y, S);
  emxFree_real_T(&b_S);
  if ((kmu->size[1] == 1) || (S->size[0] == 1)) {
    i11 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = S->size[1];
    emxEnsureCapacity((emxArray__common *)b_y, i11, (int32_T)sizeof(real_T));
    ndbl = S->size[1];
    for (i11 = 0; i11 < ndbl; i11++) {
      b_y->data[b_y->size[0] * i11] = 0.0;
      cdiff = kmu->size[1];
      for (ar = 0; ar < cdiff; ar++) {
        b_y->data[b_y->size[0] * i11] += kmu->data[kmu->size[0] * ar] * S->
          data[ar + S->size[0] * i11];
      }
    }
  } else {
    unnamed_idx_1 = (uint32_T)S->size[1];
    i11 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b_y, i11, (int32_T)sizeof(real_T));
    i11 = b_y->size[0] * b_y->size[1];
    b_y->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)b_y, i11, (int32_T)sizeof(real_T));
    ndbl = (int32_T)unnamed_idx_1;
    for (i11 = 0; i11 < ndbl; i11++) {
      b_y->data[i11] = 0.0;
    }

    if (S->size[1] == 0) {
    } else {
      for (ndbl = 1; ndbl - 1 < S->size[1]; ndbl++) {
        for (ic = ndbl; ic <= ndbl; ic++) {
          b_y->data[ic - 1] = 0.0;
        }
      }

      cdiff = 0;
      for (ndbl = 0; ndbl < S->size[1]; ndbl++) {
        ar = 0;
        i11 = cdiff + kmu->size[1];
        for (apnd = cdiff; apnd + 1 <= i11; apnd++) {
          if (S->data[apnd] != 0.0) {
            ia = ar;
            for (ic = ndbl; ic + 1 <= ndbl + 1; ic++) {
              ia++;
              b_y->data[ic] += S->data[apnd] * kmu->data[ia - 1];
            }
          }

          ar++;
        }

        cdiff += kmu->size[1];
      }
    }
  }

  b_emxInit_real_T(&b, 1);
  i11 = b->size[0];
  b->size[0] = kmu->size[1];
  emxEnsureCapacity((emxArray__common *)b, i11, (int32_T)sizeof(real_T));
  ndbl = kmu->size[1];
  for (i11 = 0; i11 < ndbl; i11++) {
    b->data[i11] = kmu->data[i11];
  }

  if ((kmu->size[1] == 1) || (b->size[0] == 1)) {
    y = 0.0;
    for (i11 = 0; i11 < kmu->size[1]; i11++) {
      y += kmu->data[kmu->size[0] * i11] * b->data[i11];
    }
  } else {
    y = 0.0;
    if (kmu->size[1] < 1) {
    } else {
      for (cdiff = 0; cdiff + 1 <= kmu->size[1]; cdiff++) {
        y += kmu->data[cdiff] * b->data[cdiff];
      }
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&kmu);
  b_rdivide(b_y, y, feature);
  emxFree_real_T(&b_y);
}

static void mean(const emxArray_real_T *x, real_T y[10])
{
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  if (x->size[1] == 0) {
    memset(&y[0], 0, 10U * sizeof(real_T));
  } else {
    iy = -1;
    ixstart = -1;
    for (j = 0; j < 10; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[1]; k++) {
        ix += 10;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }

  iy = x->size[1];
  for (ixstart = 0; ixstart < 10; ixstart++) {
    y[ixstart] /= (real_T)iy;
  }
}

static void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv0[2];
  int32_T i6;
  int32_T k;
  for (i6 = 0; i6 < 2; i6++) {
    uv0[i6] = (uint32_T)a->size[i6];
  }

  i6 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv0[0];
  y->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i6, (int32_T)sizeof(real_T));
  i6 = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (k = 0; k < i6; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = a->data[(int32_T)(1.0 + (real_T)k)
      - 1] * a->data[(int32_T)(1.0 + (real_T)k) - 1];
  }
}

static void rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                    emxArray_real_T *z)
{
  int32_T i1;
  int32_T loop_ub;
  i1 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i1, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    z->data[i1] = x->data[i1] / y->data[i1];
  }
}

static void repmat(const emxArray_real_T *a, real_T m, emxArray_real_T *b)
{
  int32_T mv[2];
  int32_T outsize[2];
  int32_T ia;
  int32_T ib;
  int32_T iacol;
  int32_T jcol;
  int32_T itilerow;
  mv[0] = (int32_T)m;
  mv[1] = 1;
  for (ia = 0; ia < 2; ia++) {
    outsize[ia] = a->size[ia] * mv[ia];
  }

  ia = b->size[0] * b->size[1];
  b->size[0] = outsize[0];
  b->size[1] = outsize[1];
  emxEnsureCapacity((emxArray__common *)b, ia, (int32_T)sizeof(real_T));
  if ((outsize[0] == 0) || (outsize[1] == 0)) {
  } else {
    ia = 1;
    ib = 0;
    iacol = 1;
    for (jcol = 1; jcol <= a->size[1]; jcol++) {
      for (itilerow = 1; itilerow <= (int32_T)m; itilerow++) {
        b->data[ib] = a->data[iacol - 1];
        ia = iacol + 1;
        ib++;
      }

      iacol = ia;
    }
  }
}

static real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T d0;
  real_T d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = rtNaN;
      } else if (d0 > 1.0) {
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
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
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

static void sum(const emxArray_real_T *x, emxArray_real_T *y)
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
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

void computeSpectralFeatures(const emxArray_real_T *denoisedSpectrum, real_T
  features[40])
{
  emxArray_real_T *features1;
  int32_T i0;
  int32_T nm1d2;
  int32_T ixLead;
  emxArray_real_T *y;
  emxArray_real_T *x;
  emxArray_real_T *b_y;
  emxArray_real_T *sigma;
  emxArray_real_T *c_y;
  emxArray_real_T *d_y;
  emxArray_real_T *e_y;
  emxArray_real_T *S;
  emxArray_real_T *a;
  emxArray_real_T *b_a;
  emxArray_real_T *b_x;
  emxArray_real_T *f_y;
  emxArray_real_T *c_a;
  emxArray_real_T *c_x;
  emxArray_real_T *b_denoisedSpectrum;
  int32_T bsub;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *d_a;
  emxArray_real_T *av;
  int32_T bk;
  int32_T a_idx_0;
  int32_T iy;
  int32_T b_a_idx_0;
  int32_T ck;
  emxArray_real_T *cv;
  int32_T exitg2;
  int32_T exitg3;
  emxArray_real_T *d_x;
  emxArray_real_T *e_x;
  emxArray_real_T *g_y;
  emxArray_boolean_T *r0;
  emxArray_int32_T *r1;
  emxArray_real_T *f_x;
  emxArray_real_T *b_y1;
  uint32_T outsize[2];
  emxArray_boolean_T *colsToRemove;
  boolean_T exitg1;
  boolean_T b0;
  real_T dv0[10];

  /* COMPUTESPECTRALFEATURES Computes spectral features */
  /*    Detailed explanation goes here */
  /*  Preallocate */
  memset(&features[0], 0, 40U * sizeof(real_T));
  emxInit_real_T(&features1, 2);
  i0 = features1->size[0] * features1->size[1];
  features1->size[0] = 10;
  emxEnsureCapacity((emxArray__common *)features1, i0, (int32_T)sizeof(real_T));
  nm1d2 = denoisedSpectrum->size[1];
  i0 = features1->size[0] * features1->size[1];
  features1->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)features1, i0, (int32_T)sizeof(real_T));
  ixLead = 10 * denoisedSpectrum->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[i0] = 0.0;
  }

  emxInit_real_T(&y, 2);

  /*  Compute features */
  featureSpectralCentroid(denoisedSpectrum, y);
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  featureSpectralCrest(denoisedSpectrum, y);
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[1 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  featureSpectralDecrease(denoisedSpectrum, y);
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[2 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  emxInit_real_T(&x, 2);

  /* FEATURESPECTRALFLATNESS Computes Spectral Flatness */
  /*    It is a measure of noisiness */
  i0 = x->size[0] * x->size[1];
  x->size[0] = denoisedSpectrum->size[0];
  x->size[1] = denoisedSpectrum->size[1];
  emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T));
  ixLead = denoisedSpectrum->size[0] * denoisedSpectrum->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    x->data[i0] = denoisedSpectrum->data[i0] + 1.0E-20;
  }

  i0 = x->size[0] * x->size[1];
  for (ixLead = 0; ixLead < i0; ixLead++) {
    x->data[(int32_T)(1.0 + (real_T)ixLead) - 1] = log(x->data[(int32_T)(1.0 +
      (real_T)ixLead) - 1]);
  }

  emxInit_real_T(&b_y, 2);
  b_sum(x, y);
  i0 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    b_y->data[i0] = y->data[i0];
  }

  emxInit_real_T(&sigma, 2);
  b_rdivide(b_y, x->size[0], y);
  i0 = sigma->size[0] * sigma->size[1];
  sigma->size[0] = 1;
  sigma->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)sigma, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  emxFree_real_T(&b_y);
  for (i0 = 0; i0 < ixLead; i0++) {
    sigma->data[i0] = y->data[i0];
  }

  for (ixLead = 0; ixLead < y->size[1]; ixLead++) {
    sigma->data[(int32_T)(1.0 + (real_T)ixLead) - 1] = exp(sigma->data[(int32_T)
      (1.0 + (real_T)ixLead) - 1]);
  }

  emxInit_real_T(&c_y, 2);
  b_sum(denoisedSpectrum, y);
  i0 = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)c_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    c_y->data[i0] = y->data[i0];
  }

  emxInit_real_T(&d_y, 2);
  b_rdivide(c_y, denoisedSpectrum->size[0], y);
  i0 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = 1;
  d_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)d_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  emxFree_real_T(&c_y);
  for (i0 = 0; i0 < ixLead; i0++) {
    d_y->data[i0] = y->data[i0];
  }

  rdivide(sigma, d_y, y);
  ixLead = y->size[1];
  emxFree_real_T(&d_y);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[3 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  featureSpectralFlux(denoisedSpectrum, y);
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[4 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  emxInit_real_T(&e_y, 2);

  /* FEATURESPECTRALKURTOSIS Computes the Spectral Kurtosis */
  /*    It is a measure of gaussianity of a spectrum */
  b_std(denoisedSpectrum, sigma);

  /*  Subtracting means */
  b_sum(denoisedSpectrum, y);
  i0 = e_y->size[0] * e_y->size[1];
  e_y->size[0] = 1;
  e_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    e_y->data[i0] = y->data[i0];
  }

  emxInit_real_T(&S, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&b_a, 2);
  b_rdivide(e_y, denoisedSpectrum->size[0], y);
  bsxfun(denoisedSpectrum, y, S);
  repmat(sigma, S->size[0], x);
  b_power(x, a);
  b_power(S, x);
  i0 = b_a->size[0] * b_a->size[1];
  b_a->size[0] = a->size[0];
  b_a->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)b_a, i0, (int32_T)sizeof(real_T));
  nm1d2 = S->size[0];
  ixLead = a->size[0] * a->size[1];
  emxFree_real_T(&e_y);
  for (i0 = 0; i0 < ixLead; i0++) {
    b_a->data[i0] = a->data[i0] * (real_T)nm1d2;
  }

  emxInit_real_T(&b_x, 2);
  i0 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, i0, (int32_T)sizeof(real_T));
  ixLead = x->size[0] * x->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    b_x->data[i0] = x->data[i0];
  }

  c_rdivide(b_x, b_a, x);
  sum(x, y);
  ixLead = y->size[1];
  emxFree_real_T(&b_x);
  emxFree_real_T(&b_a);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[5 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  featureSpectralRolloff(denoisedSpectrum, y);
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[6 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  emxInit_real_T(&f_y, 2);

  /* FEATURESPECTRALSKEWNESS Compute spectral skewness */
  /*    A measure of symmettricity of pdf */
  b_std(denoisedSpectrum, sigma);

  /*  Subtracting means */
  b_sum(denoisedSpectrum, y);
  i0 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 1;
  f_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    f_y->data[i0] = y->data[i0];
  }

  emxInit_real_T(&c_a, 2);
  b_rdivide(f_y, denoisedSpectrum->size[0], y);
  bsxfun(denoisedSpectrum, y, S);
  repmat(sigma, S->size[0], x);
  c_power(x, a);
  c_power(S, x);
  i0 = c_a->size[0] * c_a->size[1];
  c_a->size[0] = a->size[0];
  c_a->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)c_a, i0, (int32_T)sizeof(real_T));
  nm1d2 = S->size[0];
  ixLead = a->size[0] * a->size[1];
  emxFree_real_T(&f_y);
  for (i0 = 0; i0 < ixLead; i0++) {
    c_a->data[i0] = a->data[i0] * (real_T)nm1d2;
  }

  emxFree_real_T(&a);
  emxInit_real_T(&c_x, 2);
  i0 = c_x->size[0] * c_x->size[1];
  c_x->size[0] = x->size[0];
  c_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)c_x, i0, (int32_T)sizeof(real_T));
  ixLead = x->size[0] * x->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    c_x->data[i0] = x->data[i0];
  }

  c_rdivide(c_x, c_a, x);
  sum(x, y);
  ixLead = y->size[1];
  emxFree_real_T(&c_x);
  emxFree_real_T(&c_a);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[7 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  emxInit_real_T(&b_denoisedSpectrum, 2);
  i0 = b_denoisedSpectrum->size[0] * b_denoisedSpectrum->size[1];
  b_denoisedSpectrum->size[0] = denoisedSpectrum->size[0];
  b_denoisedSpectrum->size[1] = denoisedSpectrum->size[1];
  emxEnsureCapacity((emxArray__common *)b_denoisedSpectrum, i0, (int32_T)sizeof
                    (real_T));
  ixLead = denoisedSpectrum->size[0] * denoisedSpectrum->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    b_denoisedSpectrum->data[i0] = denoisedSpectrum->data[i0];
  }

  featureSpectralSlope(b_denoisedSpectrum, y);
  ixLead = y->size[1];
  emxFree_real_T(&b_denoisedSpectrum);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[8 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  /*  FEATURESPECTRALSPREAD Computes spectral spread */
  /*    Concentration of energy around spectral centroid */
  featureSpectralCentroid(denoisedSpectrum, sigma);
  power(denoisedSpectrum, S);
  if ((real_T)S->size[0] - 1.0 < 0.0) {
    bsub = -1;
    apnd = -1.0;
  } else {
    ndbl = floor(((real_T)S->size[0] - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - ((real_T)S->size[0] - 1.0);
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((real_T)S->size[0] - 1.0)) {
      ndbl++;
      apnd = (real_T)S->size[0] - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    bsub = (int32_T)ndbl - 1;
  }

  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = bsub + 1;
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T));
  if (bsub + 1 > 0) {
    y->data[0] = 0.0;
    if (bsub + 1 > 1) {
      y->data[bsub] = apnd;
      nm1d2 = bsub / 2;
      for (ixLead = 1; ixLead < nm1d2; ixLead++) {
        y->data[ixLead] = ixLead;
        y->data[bsub - ixLead] = apnd - (real_T)ixLead;
      }

      if (nm1d2 << 1 == bsub) {
        y->data[nm1d2] = apnd / 2.0;
      } else {
        y->data[nm1d2] = nm1d2;
        y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  b_emxInit_real_T(&d_a, 1);
  i0 = d_a->size[0];
  d_a->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)d_a, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    d_a->data[i0] = y->data[i0];
  }

  b_emxInit_real_T(&av, 1);
  i0 = x->size[0] * x->size[1];
  x->size[0] = d_a->size[0];
  x->size[1] = sigma->size[1];
  emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T));
  nm1d2 = d_a->size[0];
  i0 = av->size[0];
  av->size[0] = nm1d2;
  emxEnsureCapacity((emxArray__common *)av, i0, (int32_T)sizeof(real_T));
  bsub = 1;
  bk = 0;
  a_idx_0 = d_a->size[0];
  iy = sigma->size[1];
  b_a_idx_0 = d_a->size[0];
  ck = 0;
  b_emxInit_real_T(&cv, 1);
  do {
    exitg2 = 0;
    nm1d2 = d_a->size[0];
    if ((nm1d2 > 0) && (ck <= a_idx_0 * iy - b_a_idx_0)) {
      for (ixLead = 0; ixLead + 1 <= d_a->size[0]; ixLead++) {
        av->data[ixLead] = d_a->data[ixLead];
      }

      ndbl = sigma->data[bk];
      i0 = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, i0, (int32_T)sizeof(real_T));
      ixLead = av->size[0];
      for (i0 = 0; i0 < ixLead; i0++) {
        cv->data[i0] = av->data[i0] - ndbl;
      }

      ixLead = 0;
      do {
        exitg3 = 0;
        nm1d2 = d_a->size[0];
        if (ixLead + 1 <= nm1d2) {
          x->data[ck + ixLead] = cv->data[ixLead];
          ixLead++;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      if (bsub < sigma->size[1]) {
        bk++;
        bsub++;
      } else {
        bsub = 1;
      }

      nm1d2 = d_a->size[0];
      ck += nm1d2;
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&cv);
  emxFree_real_T(&av);
  emxFree_real_T(&d_a);
  emxInit_real_T(&d_x, 2);
  i0 = d_x->size[0] * d_x->size[1];
  d_x->size[0] = x->size[0];
  d_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)d_x, i0, (int32_T)sizeof(real_T));
  ixLead = x->size[0] * x->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    d_x->data[i0] = x->data[i0];
  }

  emxInit_real_T(&e_x, 2);
  power(d_x, x);
  i0 = e_x->size[0] * e_x->size[1];
  e_x->size[0] = x->size[0];
  e_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)e_x, i0, (int32_T)sizeof(real_T));
  ixLead = x->size[0] * x->size[1];
  emxFree_real_T(&d_x);
  for (i0 = 0; i0 < ixLead; i0++) {
    e_x->data[i0] = x->data[i0] * S->data[i0];
  }

  emxFree_real_T(&x);
  emxInit_real_T(&g_y, 2);
  sum(e_x, y);
  sum(S, sigma);
  i0 = g_y->size[0] * g_y->size[1];
  g_y->size[0] = 1;
  g_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)g_y, i0, (int32_T)sizeof(real_T));
  ixLead = y->size[0] * y->size[1];
  emxFree_real_T(&e_x);
  emxFree_real_T(&S);
  for (i0 = 0; i0 < ixLead; i0++) {
    g_y->data[i0] = y->data[i0];
  }

  rdivide(g_y, sigma, y);
  b_sqrt(y);
  ixLead = y->size[1];
  emxFree_real_T(&g_y);
  emxFree_real_T(&sigma);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[9 + features1->size[0] * i0] = y->data[y->size[0] * i0];
  }

  emxFree_real_T(&y);
  emxInit_boolean_T(&r0, 2);

  /*  Remove undefined results */
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 10;
  r0->size[1] = features1->size[1];
  emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(boolean_T));
  ixLead = features1->size[0] * features1->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    r0->data[i0] = rtIsNaN(features1->data[i0]);
  }

  emxInit_int32_T(&r1, 1);
  eml_li_find(r0, r1);
  ixLead = r1->size[0];
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[r1->data[i0] - 1] = 0.0;
  }

  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 10;
  r0->size[1] = features1->size[1];
  emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(boolean_T));
  ixLead = features1->size[0] * features1->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    r0->data[i0] = rtIsInf(features1->data[i0]);
  }

  eml_li_find(r0, r1);
  ixLead = r1->size[0];
  emxFree_boolean_T(&r0);
  for (i0 = 0; i0 < ixLead; i0++) {
    features1->data[r1->data[i0] - 1] = 0.0;
  }

  emxFree_int32_T(&r1);
  emxInit_real_T(&f_x, 2);

  /*  Compute first derivative of features */
  i0 = f_x->size[0] * f_x->size[1];
  f_x->size[0] = 10;
  f_x->size[1] = 1 + features1->size[1];
  emxEnsureCapacity((emxArray__common *)f_x, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < 10; i0++) {
    f_x->data[i0] = features1->data[i0];
  }

  ixLead = features1->size[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    for (bsub = 0; bsub < 10; bsub++) {
      f_x->data[bsub + f_x->size[0] * (i0 + 1)] = features1->data[bsub +
        features1->size[0] * i0];
    }
  }

  emxInit_real_T(&b_y1, 2);
  if (1 >= f_x->size[1]) {
    i0 = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 10;
    b_y1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)b_y1, i0, (int32_T)sizeof(real_T));
  } else {
    i0 = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 10;
    b_y1->size[1] = f_x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)b_y1, i0, (int32_T)sizeof(real_T));
    nm1d2 = 10;
    iy = 1;
    for (bsub = 0; bsub < 10; bsub++) {
      ixLead = nm1d2;
      bk = iy;
      apnd = f_x->data[nm1d2 - 10];
      for (a_idx_0 = 2; a_idx_0 <= f_x->size[1]; a_idx_0++) {
        ndbl = apnd;
        apnd = f_x->data[ixLead];
        ndbl = f_x->data[ixLead] - ndbl;
        ixLead += 10;
        b_y1->data[bk - 1] = ndbl;
        bk += 10;
      }

      nm1d2++;
      iy++;
    }
  }

  emxFree_real_T(&f_x);

  /*  Remove columns for silent frames */
  for (i0 = 0; i0 < 2; i0++) {
    outsize[i0] = (uint32_T)denoisedSpectrum->size[i0];
  }

  emxInit_boolean_T(&colsToRemove, 2);
  i0 = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)colsToRemove, i0, (int32_T)sizeof
                    (boolean_T));
  i0 = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity((emxArray__common *)colsToRemove, i0, (int32_T)sizeof
                    (boolean_T));
  ixLead = (int32_T)outsize[1];
  for (i0 = 0; i0 < ixLead; i0++) {
    colsToRemove->data[i0] = FALSE;
  }

  nm1d2 = 0;
  iy = -1;
  for (bsub = 1; bsub <= denoisedSpectrum->size[1]; bsub++) {
    ixLead = nm1d2;
    nm1d2 += denoisedSpectrum->size[0];
    iy++;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (ixLead + 1 <= nm1d2)) {
      if ((denoisedSpectrum->data[ixLead] == 0.0) || rtIsNaN
          (denoisedSpectrum->data[ixLead])) {
        b0 = TRUE;
      } else {
        b0 = FALSE;
      }

      if (!b0) {
        colsToRemove->data[iy] = TRUE;
        exitg1 = TRUE;
      } else {
        ixLead++;
      }
    }
  }

  i0 = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)colsToRemove, i0, (int32_T)sizeof
                    (boolean_T));
  nm1d2 = colsToRemove->size[0];
  bsub = colsToRemove->size[1];
  ixLead = nm1d2 * bsub;
  for (i0 = 0; i0 < ixLead; i0++) {
    colsToRemove->data[i0] = !colsToRemove->data[i0];
  }

  eml_null_assignment(features1, colsToRemove);
  eml_null_assignment(b_y1, colsToRemove);

  /*  Extract mean and std sub features */
  mean(features1, dv0);
  emxFree_boolean_T(&colsToRemove);
  memcpy(&features[0], &dv0[0], 10U * sizeof(real_T));
  c_std(features1, dv0);
  emxFree_real_T(&features1);
  memcpy(&features[10], &dv0[0], 10U * sizeof(real_T));
  mean(b_y1, dv0);
  memcpy(&features[20], &dv0[0], 10U * sizeof(real_T));
  c_std(b_y1, dv0);
  emxFree_real_T(&b_y1);
  memcpy(&features[30], &dv0[0], 10U * sizeof(real_T));
}

void computeSpectralFeatures_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void computeSpectralFeatures_terminate(void)
{
  /* (no terminate code required) */
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

/* End of code generation (computeSpectralFeatures.c) */
