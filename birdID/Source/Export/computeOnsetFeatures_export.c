/*
 * computeOnsetFeatures.c
 *
 * Code generation for function 'computeOnsetFeatures'
 *
 * C source code generated on: Fri Apr 25 23:35:45 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "computeOnsetFeatures_export.h"

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
static void ConstantPad(const emxArray_real_T *a, const real_T padSize[2],
  emxArray_real_T *b);
static void b_eml_li_find(const boolean_T x[12], int32_T y_data[12], int32_T
  y_size[1]);
static void b_eml_null_assignment(emxArray_boolean_T *x, const emxArray_real_T
  *idx);
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static real_T b_std(const real_T varargin_1[17]);
static void bsxfun(const real_T a[17], real_T b, real_T c[17]);
static void c_eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx);
static real_T c_std(const real_T varargin_1[17]);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void eml_null_assignment(emxArray_boolean_T *x);
static void eml_sort(const real_T x[17], real_T y[17], int32_T idx[17]);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static real_T featureSpectralCentroid(real_T S[17]);
static real_T featureSpectralCrest(const real_T S[17]);
static void filter(const emxArray_real_T *x, real_T zi, emxArray_real_T *y);
static void filtfilt(const emxArray_real_T *x_in, emxArray_real_T *y_out);
static void histogramFeatures(const real_T ioiHist[17], real_T features[12]);
static void ioiHistogram(emxArray_boolean_T *onsets, const emxArray_real_T *T,
  real_T ioiHist[17]);
static void onsetDetection(const emxArray_real_T *spec, emxArray_boolean_T
  *onsets, emxArray_real_T *flux);
static void onsetFlux(const emxArray_real_T *S, emxArray_real_T *flux);
static void padarray(const emxArray_real_T *varargin_1, emxArray_real_T *b);
static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z);
static real_T rt_powd_snf(real_T u0, real_T u1);

/* Function Definitions */
static void ConstantPad(const emxArray_real_T *a, const real_T padSize[2],
  emxArray_real_T *b)
{
  real_T sizeB[2];
  int32_T cdiff;
  uint32_T varargin_1[2];
  int32_T ndbl;
  emxArray_real_T *idxB;
  emxArray_int32_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  int32_T k;
  int32_T absb;
  int32_T apnd;
  int32_T i4;
  emxArray_boolean_T *x;
  real_T idxB1;
  real_T idxB2;
  int32_T b_sizeB[2];
  int32_T outsize[2];
  for (cdiff = 0; cdiff < 2; cdiff++) {
    sizeB[cdiff] = 0.0;
  }

  for (cdiff = 0; cdiff < 2; cdiff++) {
    varargin_1[cdiff] = (uint32_T)a->size[cdiff];
  }

  ndbl = (int32_T)varargin_1[0];
  if ((int32_T)varargin_1[1] > (int32_T)varargin_1[0]) {
    ndbl = (int32_T)varargin_1[1];
  }

  emxInit_real_T(&idxB, 2);
  cdiff = idxB->size[0] * idxB->size[1];
  idxB->size[0] = ndbl;
  idxB->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)idxB, cdiff, (int32_T)sizeof(real_T));
  ndbl <<= 1;
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    idxB->data[cdiff] = 0.0;
  }

  emxInit_int32_T(&r7, 1);
  emxInit_real_T(&r8, 2);
  emxInit_real_T(&r9, 2);
  for (k = 0; k < 2; k++) {
    sizeB[k] = (real_T)a->size[k] + 2.0 * padSize[k];
    if (1 > a->size[k]) {
      ndbl = 0;
    } else {
      ndbl = a->size[k];
    }

    cdiff = r7->size[0];
    r7->size[0] = ndbl;
    emxEnsureCapacity((emxArray__common *)r7, cdiff, (int32_T)sizeof(int32_T));
    for (cdiff = 0; cdiff < ndbl; cdiff++) {
      r7->data[cdiff] = cdiff;
    }

    if (a->size[k] < 1) {
      absb = -1;
      apnd = 0;
    } else {
      ndbl = (int32_T)floor(((real_T)a->size[k] - 1.0) + 0.5);
      apnd = ndbl + 1;
      cdiff = (ndbl - a->size[k]) + 1;
      absb = a->size[k];
      if (1 > absb) {
        i4 = 1;
      } else {
        i4 = absb;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * (real_T)i4) {
        ndbl++;
        apnd = a->size[k];
      } else if (cdiff > 0) {
        apnd = ndbl;
      } else {
        ndbl++;
      }

      absb = ndbl - 1;
    }

    cdiff = r8->size[0] * r8->size[1];
    r8->size[0] = 1;
    r8->size[1] = absb + 1;
    emxEnsureCapacity((emxArray__common *)r8, cdiff, (int32_T)sizeof(real_T));
    if (absb + 1 > 0) {
      r8->data[0] = 1.0;
      if (absb + 1 > 1) {
        r8->data[absb] = apnd;
        ndbl = absb / 2;
        for (cdiff = 1; cdiff < ndbl; cdiff++) {
          r8->data[cdiff] = 1.0 + (real_T)cdiff;
          r8->data[absb - cdiff] = apnd - cdiff;
        }

        if (ndbl << 1 == absb) {
          r8->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          r8->data[ndbl] = 1.0 + (real_T)ndbl;
          r8->data[ndbl + 1] = apnd - ndbl;
        }
      }
    }

    cdiff = r9->size[0] * r9->size[1];
    r9->size[0] = 1;
    r9->size[1] = r8->size[1];
    emxEnsureCapacity((emxArray__common *)r9, cdiff, (int32_T)sizeof(real_T));
    ndbl = r8->size[1];
    for (cdiff = 0; cdiff < ndbl; cdiff++) {
      r9->data[r9->size[0] * cdiff] = r8->data[r8->size[0] * cdiff] + padSize[k];
    }

    ndbl = r7->size[0];
    for (cdiff = 0; cdiff < ndbl; cdiff++) {
      idxB->data[r7->data[cdiff] + idxB->size[0] * k] = r9->data[cdiff];
    }
  }

  emxFree_real_T(&r9);
  emxFree_real_T(&r8);
  emxFree_int32_T(&r7);
  b_emxInit_boolean_T(&x, 1);
  ndbl = idxB->size[0];
  cdiff = x->size[0];
  x->size[0] = ndbl;
  emxEnsureCapacity((emxArray__common *)x, cdiff, (int32_T)sizeof(boolean_T));
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    x->data[cdiff] = (idxB->data[cdiff] != 0.0);
  }

  if (x->size[0] == 0) {
    idxB1 = 0.0;
  } else {
    idxB1 = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      idxB1 += (real_T)x->data[k - 1];
    }
  }

  ndbl = idxB->size[0];
  cdiff = x->size[0];
  x->size[0] = ndbl;
  emxEnsureCapacity((emxArray__common *)x, cdiff, (int32_T)sizeof(boolean_T));
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    x->data[cdiff] = (idxB->data[cdiff + idxB->size[0]] != 0.0);
  }

  if (x->size[0] == 0) {
    idxB2 = 0.0;
  } else {
    idxB2 = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      idxB2 += (real_T)x->data[k - 1];
    }
  }

  emxFree_boolean_T(&x);
  b_sizeB[0] = (int32_T)sizeB[0];
  b_sizeB[1] = (int32_T)sizeB[1];
  for (cdiff = 0; cdiff < 2; cdiff++) {
    outsize[cdiff] = b_sizeB[cdiff];
  }

  cdiff = b->size[0] * b->size[1];
  b->size[0] = outsize[0];
  emxEnsureCapacity((emxArray__common *)b, cdiff, (int32_T)sizeof(real_T));
  cdiff = b->size[0] * b->size[1];
  b->size[1] = outsize[1];
  emxEnsureCapacity((emxArray__common *)b, cdiff, (int32_T)sizeof(real_T));
  ndbl = outsize[0] * outsize[1];
  for (cdiff = 0; cdiff < ndbl; cdiff++) {
    b->data[cdiff] = 0.0;
  }

  for (ndbl = 0; ndbl < (int32_T)idxB1; ndbl++) {
    for (cdiff = 0; cdiff < (int32_T)idxB2; cdiff++) {
      b->data[((int32_T)idxB->data[(int32_T)(1.0 + (real_T)ndbl) - 1] + b->size
               [0] * ((int32_T)idxB->data[((int32_T)(1.0 + (real_T)cdiff) +
                 idxB->size[0]) - 1] - 1)) - 1] = a->data[((int32_T)(1.0 +
        (real_T)ndbl) + a->size[0] * ((int32_T)(1.0 + (real_T)cdiff) - 1)) - 1];
    }
  }

  emxFree_real_T(&idxB);
}

static void b_eml_li_find(const boolean_T x[12], int32_T y_data[12], int32_T
  y_size[1])
{
  int32_T k;
  int32_T i;
  k = 0;
  for (i = 0; i < 12; i++) {
    if (x[i]) {
      k++;
    }
  }

  y_size[0] = k;
  k = 0;
  for (i = 0; i < 12; i++) {
    if (x[i]) {
      y_data[k] = i + 1;
      k++;
    }
  }
}

static void b_eml_null_assignment(emxArray_boolean_T *x, const emxArray_real_T
  *idx)
{
  int32_T nxin;
  int32_T k;
  emxArray_int32_T *r13;
  emxArray_boolean_T *b_x;
  emxArray_boolean_T *c_x;
  int32_T nxout;
  int32_T i6;
  int32_T k0;
  emxArray_boolean_T *b;
  nxin = x->size[0] * x->size[1];
  if (idx->size[1] == 1) {
    for (k = (int32_T)idx->data[0]; k < nxin; k++) {
      x->data[k - 1] = x->data[k];
    }

    emxInit_int32_T(&r13, 1);
    emxInit_boolean_T(&b_x, 2);
    b_emxInit_boolean_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i6 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i6, (int32_T)sizeof(boolean_T));
      for (i6 = 0; i6 < nxout; i6++) {
        c_x->data[i6] = x->data[i6];
      }

      i6 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T));
      i6 = 0;
      while (i6 <= 0) {
        for (i6 = 0; i6 < nxout; i6++) {
          x->data[i6] = c_x->data[i6];
        }

        i6 = 1;
      }
    } else {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i6 = r13->size[0];
      r13->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r13, i6, (int32_T)sizeof(int32_T));
      for (i6 = 0; i6 < nxout; i6++) {
        r13->data[i6] = 1 + i6;
      }

      nxout = r13->size[0];
      i6 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i6, (int32_T)sizeof(boolean_T));
      for (i6 = 0; i6 < nxout; i6++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i6] = x->data[r13->data[i6] - 1];
          k = 1;
        }
      }

      i6 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T));
      nxout = b_x->size[1];
      for (i6 = 0; i6 < nxout; i6++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i6] = b_x->data[k + b_x->size[0] * i6];
        }
      }
    }

    emxFree_boolean_T(&c_x);
    emxFree_boolean_T(&b_x);
    emxFree_int32_T(&r13);
  } else {
    emxInit_boolean_T(&b, 2);
    i6 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = nxin;
    emxEnsureCapacity((emxArray__common *)b, i6, (int32_T)sizeof(boolean_T));
    for (i6 = 0; i6 < nxin; i6++) {
      b->data[i6] = FALSE;
    }

    for (k = 1; k <= idx->size[1]; k++) {
      b->data[(int32_T)idx->data[k - 1] - 1] = TRUE;
    }

    nxout = 0;
    for (k = 1; k <= b->size[1]; k++) {
      nxout += b->data[k - 1];
    }

    nxout = nxin - nxout;
    k0 = -1;
    for (k = 1; k <= nxin; k++) {
      if ((k > b->size[1]) || (!b->data[k - 1])) {
        k0++;
        x->data[k0] = x->data[k - 1];
      }
    }

    emxFree_boolean_T(&b);
    emxInit_int32_T(&r13, 1);
    emxInit_boolean_T(&b_x, 2);
    b_emxInit_boolean_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxout) {
        nxout = 0;
      }

      i6 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i6, (int32_T)sizeof(boolean_T));
      for (i6 = 0; i6 < nxout; i6++) {
        c_x->data[i6] = x->data[i6];
      }

      i6 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T));
      i6 = 0;
      while (i6 <= 0) {
        for (i6 = 0; i6 < nxout; i6++) {
          x->data[i6] = c_x->data[i6];
        }

        i6 = 1;
      }
    } else {
      if (1 > nxout) {
        nxout = 0;
      }

      i6 = r13->size[0];
      r13->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r13, i6, (int32_T)sizeof(int32_T));
      for (i6 = 0; i6 < nxout; i6++) {
        r13->data[i6] = 1 + i6;
      }

      nxout = r13->size[0];
      i6 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i6, (int32_T)sizeof(boolean_T));
      for (i6 = 0; i6 < nxout; i6++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i6] = x->data[r13->data[i6] - 1];
          k = 1;
        }
      }

      i6 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T));
      nxout = b_x->size[1];
      for (i6 = 0; i6 < nxout; i6++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i6] = b_x->data[k + b_x->size[0] * i6];
        }
      }
    }

    emxFree_boolean_T(&c_x);
    emxFree_boolean_T(&b_x);
    emxFree_int32_T(&r13);
  }
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

static real_T b_std(const real_T varargin_1[17])
{
  real_T y;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 16; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 17.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  y = r * r;
  for (k = 0; k < 16; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    y += r * r;
  }

  y /= 16.0;
  return sqrt(y);
}

static void bsxfun(const real_T a[17], real_T b, real_T c[17])
{
  int32_T k;
  for (k = 0; k < 17; k++) {
    c[k] = a[k] - b;
  }
}

static void c_eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx)
{
  int32_T nxin;
  int32_T k;
  emxArray_int32_T *r14;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  int32_T nxout;
  int32_T i7;
  int32_T k0;
  emxArray_boolean_T *b;
  nxin = x->size[0] * x->size[1];
  if (idx->size[1] == 1) {
    for (k = (int32_T)idx->data[0]; k < nxin; k++) {
      x->data[k - 1] = x->data[k];
    }

    emxInit_int32_T(&r14, 1);
    emxInit_real_T(&b_x, 2);
    b_emxInit_real_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i7 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i7, (int32_T)sizeof(real_T));
      for (i7 = 0; i7 < nxout; i7++) {
        c_x->data[i7] = x->data[i7];
      }

      i7 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i7, (int32_T)sizeof(real_T));
      i7 = 0;
      while (i7 <= 0) {
        for (i7 = 0; i7 < nxout; i7++) {
          x->data[i7] = c_x->data[i7];
        }

        i7 = 1;
      }
    } else {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i7 = r14->size[0];
      r14->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r14, i7, (int32_T)sizeof(int32_T));
      for (i7 = 0; i7 < nxout; i7++) {
        r14->data[i7] = 1 + i7;
      }

      nxout = r14->size[0];
      i7 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i7, (int32_T)sizeof(real_T));
      for (i7 = 0; i7 < nxout; i7++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i7] = x->data[r14->data[i7] - 1];
          k = 1;
        }
      }

      i7 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i7, (int32_T)sizeof(real_T));
      nxout = b_x->size[1];
      for (i7 = 0; i7 < nxout; i7++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i7] = b_x->data[k + b_x->size[0] * i7];
        }
      }
    }

    emxFree_real_T(&c_x);
    emxFree_real_T(&b_x);
    emxFree_int32_T(&r14);
  } else {
    emxInit_boolean_T(&b, 2);
    i7 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = nxin;
    emxEnsureCapacity((emxArray__common *)b, i7, (int32_T)sizeof(boolean_T));
    for (i7 = 0; i7 < nxin; i7++) {
      b->data[i7] = FALSE;
    }

    for (k = 1; k <= idx->size[1]; k++) {
      b->data[(int32_T)idx->data[k - 1] - 1] = TRUE;
    }

    nxout = 0;
    for (k = 1; k <= b->size[1]; k++) {
      nxout += b->data[k - 1];
    }

    nxout = nxin - nxout;
    k0 = -1;
    for (k = 1; k <= nxin; k++) {
      if ((k > b->size[1]) || (!b->data[k - 1])) {
        k0++;
        x->data[k0] = x->data[k - 1];
      }
    }

    emxFree_boolean_T(&b);
    emxInit_int32_T(&r14, 1);
    emxInit_real_T(&b_x, 2);
    b_emxInit_real_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxout) {
        nxout = 0;
      }

      i7 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i7, (int32_T)sizeof(real_T));
      for (i7 = 0; i7 < nxout; i7++) {
        c_x->data[i7] = x->data[i7];
      }

      i7 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i7, (int32_T)sizeof(real_T));
      i7 = 0;
      while (i7 <= 0) {
        for (i7 = 0; i7 < nxout; i7++) {
          x->data[i7] = c_x->data[i7];
        }

        i7 = 1;
      }
    } else {
      if (1 > nxout) {
        nxout = 0;
      }

      i7 = r14->size[0];
      r14->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r14, i7, (int32_T)sizeof(int32_T));
      for (i7 = 0; i7 < nxout; i7++) {
        r14->data[i7] = 1 + i7;
      }

      nxout = r14->size[0];
      i7 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i7, (int32_T)sizeof(real_T));
      for (i7 = 0; i7 < nxout; i7++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i7] = x->data[r14->data[i7] - 1];
          k = 1;
        }
      }

      i7 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i7, (int32_T)sizeof(real_T));
      nxout = b_x->size[1];
      for (i7 = 0; i7 < nxout; i7++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i7] = b_x->data[k + b_x->size[0] * i7];
        }
      }
    }

    emxFree_real_T(&c_x);
    emxFree_real_T(&b_x);
    emxFree_int32_T(&r14);
  }
}

static real_T c_std(const real_T varargin_1[17])
{
  real_T y;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 16; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 17.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  y = r * r;
  for (k = 0; k < 16; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    y += r * r;
  }

  y /= 17.0;
  return sqrt(y);
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

static void eml_null_assignment(emxArray_boolean_T *x)
{
  emxArray_boolean_T *b;
  int32_T nxin;
  int32_T i5;
  int32_T k;
  int32_T nxout;
  int32_T k0;
  emxArray_int32_T *r12;
  emxArray_boolean_T *b_x;
  emxArray_boolean_T *c_x;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0] * x->size[1];
  i5 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = nxin;
  emxEnsureCapacity((emxArray__common *)b, i5, (int32_T)sizeof(boolean_T));
  for (i5 = 0; i5 < nxin; i5++) {
    b->data[i5] = FALSE;
  }

  for (k = 0; k < 2; k++) {
    b->data[k] = TRUE;
  }

  nxout = 0;
  for (k = 1; k <= b->size[1]; k++) {
    nxout += b->data[k - 1];
  }

  nxout = nxin - nxout;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > b->size[1]) || (!b->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  emxFree_boolean_T(&b);
  emxInit_int32_T(&r12, 1);
  emxInit_boolean_T(&b_x, 2);
  b_emxInit_boolean_T(&c_x, 1);
  if ((x->size[0] != 1) && (x->size[1] == 1)) {
    if (1 > nxout) {
      nxout = 0;
    }

    i5 = c_x->size[0];
    c_x->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)c_x, i5, (int32_T)sizeof(boolean_T));
    for (i5 = 0; i5 < nxout; i5++) {
      c_x->data[i5] = x->data[i5];
    }

    i5 = x->size[0] * x->size[1];
    x->size[0] = nxout;
    x->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)x, i5, (int32_T)sizeof(boolean_T));
    i5 = 0;
    while (i5 <= 0) {
      for (i5 = 0; i5 < nxout; i5++) {
        x->data[i5] = c_x->data[i5];
      }

      i5 = 1;
    }
  } else {
    if (1 > nxout) {
      nxout = 0;
    }

    i5 = r12->size[0];
    r12->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)r12, i5, (int32_T)sizeof(int32_T));
    for (i5 = 0; i5 < nxout; i5++) {
      r12->data[i5] = 1 + i5;
    }

    nxout = r12->size[0];
    i5 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = nxout;
    emxEnsureCapacity((emxArray__common *)b_x, i5, (int32_T)sizeof(boolean_T));
    for (i5 = 0; i5 < nxout; i5++) {
      k = 0;
      while (k <= 0) {
        b_x->data[b_x->size[0] * i5] = x->data[r12->data[i5] - 1];
        k = 1;
      }
    }

    i5 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity((emxArray__common *)x, i5, (int32_T)sizeof(boolean_T));
    nxout = b_x->size[1];
    for (i5 = 0; i5 < nxout; i5++) {
      k0 = b_x->size[0];
      for (k = 0; k < k0; k++) {
        x->data[k + x->size[0] * i5] = b_x->data[k + b_x->size[0] * i5];
      }
    }
  }

  emxFree_boolean_T(&c_x);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&r12);
}

static void eml_sort(const real_T x[17], real_T y[17], int32_T idx[17])
{
  int32_T k;
  boolean_T p;
  int8_T idx0[17];
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  for (k = 0; k < 17; k++) {
    idx[k] = k + 1;
  }

  for (k = 0; k < 15; k += 2) {
    if ((x[k] <= x[k + 1]) || rtIsNaN(x[k + 1])) {
      p = TRUE;
    } else {
      p = FALSE;
    }

    if (p) {
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  for (i = 0; i < 17; i++) {
    idx0[i] = 1;
  }

  i = 2;
  while (i < 17) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 18; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > 18) {
        qEnd = 18;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x[idx[b_p - 1] - 1] <= x[idx[q] - 1]) || rtIsNaN(x[idx[q] - 1])) {
          p = TRUE;
        } else {
          p = FALSE;
        }

        if (p) {
          idx0[k] = (int8_T)idx[b_p - 1];
          b_p++;
          if (b_p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              idx0[k] = (int8_T)idx[q];
              q++;
            }
          }
        } else {
          idx0[k] = (int8_T)idx[q];
          q++;
          if (q + 1 == qEnd) {
            while (b_p < pEnd) {
              k++;
              idx0[k] = (int8_T)idx[b_p - 1];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = idx0[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  for (k = 0; k < 17; k++) {
    y[k] = x[idx[k] - 1];
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

static real_T featureSpectralCentroid(real_T S[17])
{
  real_T y;
  int32_T i;
  real_T b_y;

  /* FEATURESPECTRALCENTROID Computes spectral centroid feature */
  /*  It is the mass center of the spectrum */
  /* [r,c] = size(S); */
  /* feature = sum(repmat((1:r)',1,c).* S)./sum(S); */
  y = 0.0;
  for (i = 0; i < 17; i++) {
    b_y = S[i] * S[i];
    y += (((real_T)i + 1.0) - 1.0) * b_y;
    S[i] = b_y;
  }

  b_y = S[0];
  for (i = 0; i < 16; i++) {
    b_y += S[i + 1];
  }

  return y / b_y;
}

static real_T featureSpectralCrest(const real_T S[17])
{
  int32_T ixstart;
  real_T mtmp;
  int32_T ix;
  boolean_T exitg1;
  real_T y;

  /* FEATURESPECTRALCREST Computes spectral crest */
  /*  It is a rough measure of tonality */
  ixstart = 1;
  mtmp = S[0];
  if (rtIsNaN(S[0])) {
    ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (ix < 18)) {
      ixstart = ix;
      if (!rtIsNaN(S[ix - 1])) {
        mtmp = S[ix - 1];
        exitg1 = TRUE;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 17) {
    while (ixstart + 1 < 18) {
      if (S[ixstart] > mtmp) {
        mtmp = S[ixstart];
      }

      ixstart++;
    }
  }

  y = S[0];
  for (ixstart = 0; ixstart < 16; ixstart++) {
    y += S[ixstart + 1];
  }

  return mtmp / y;
}

static void filter(const emxArray_real_T *x, real_T zi, emxArray_real_T *y)
{
  uint32_T unnamed_idx_0;
  int32_T j;
  real_T dbuffer[2];
  int32_T k;
  real_T b_dbuffer;
  unnamed_idx_0 = (uint32_T)x->size[0];
  j = y->size[0];
  y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(real_T));
  dbuffer[1] = zi;
  for (j = 0; j + 1 <= x->size[0]; j++) {
    dbuffer[0] = dbuffer[1];
    dbuffer[1] = 0.0;
    for (k = 0; k < 2; k++) {
      b_dbuffer = dbuffer[k] + x->data[j] * 0.33333333333333331;
      dbuffer[k] = b_dbuffer;
    }

    y->data[j] = dbuffer[0];
  }
}

static void filtfilt(const emxArray_real_T *x_in, emxArray_real_T *y_out)
{
  emxArray_real_T *x;
  int32_T i2;
  int32_T loop_ub;
  emxArray_real_T *y;
  real_T xtmp;
  real_T b_y;
  int32_T md2;
  emxArray_real_T *c_y;
  int32_T m;
  emxArray_real_T *d_y;
  emxArray_int32_T *r6;
  b_emxInit_real_T(&x, 1);
  if (x_in->size[0] == 1) {
    i2 = x->size[0];
    x->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)x, i2, (int32_T)sizeof(real_T));
    x->data[0] = x_in->data[0];
  } else {
    i2 = x->size[0];
    x->size[0] = x_in->size[0];
    emxEnsureCapacity((emxArray__common *)x, i2, (int32_T)sizeof(real_T));
    loop_ub = x_in->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = x_in->data[i2];
    }
  }

  if (x->size[0] == 0) {
    i2 = y_out->size[0] * y_out->size[1];
    y_out->size[0] = 0;
    y_out->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)y_out, i2, (int32_T)sizeof(real_T));
  } else {
    b_emxInit_real_T(&y, 1);
    xtmp = 2.0 * x->data[0];
    b_y = 2.0 * x->data[x->size[0] - 1];
    md2 = x->size[0] - 1;
    i2 = y->size[0];
    y->size[0] = 6 + x->size[0];
    emxEnsureCapacity((emxArray__common *)y, i2, (int32_T)sizeof(real_T));
    for (i2 = 0; i2 < 3; i2++) {
      y->data[i2] = xtmp - x->data[3 - i2];
    }

    loop_ub = x->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      y->data[i2 + 3] = x->data[i2];
    }

    for (i2 = 0; i2 < 3; i2++) {
      y->data[(i2 + x->size[0]) + 3] = b_y - x->data[(md2 - i2) - 1];
    }

    b_emxInit_real_T(&c_y, 1);
    i2 = c_y->size[0];
    c_y->size[0] = y->size[0];
    emxEnsureCapacity((emxArray__common *)c_y, i2, (int32_T)sizeof(real_T));
    loop_ub = y->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      c_y->data[i2] = y->data[i2];
    }

    xtmp = y->data[0];
    filter(c_y, 0.33333333333333331 * xtmp, y);
    m = y->size[0];
    i2 = y->size[0];
    md2 = i2 / 2;
    loop_ub = 1;
    emxFree_real_T(&c_y);
    while (loop_ub <= md2) {
      xtmp = y->data[loop_ub - 1];
      y->data[loop_ub - 1] = y->data[m - loop_ub];
      y->data[m - loop_ub] = xtmp;
      loop_ub++;
    }

    b_emxInit_real_T(&d_y, 1);
    i2 = d_y->size[0];
    d_y->size[0] = y->size[0];
    emxEnsureCapacity((emxArray__common *)d_y, i2, (int32_T)sizeof(real_T));
    loop_ub = y->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      d_y->data[i2] = y->data[i2];
    }

    xtmp = y->data[0];
    filter(d_y, 0.33333333333333331 * xtmp, y);
    m = y->size[0];
    i2 = y->size[0];
    md2 = i2 / 2;
    loop_ub = 1;
    emxFree_real_T(&d_y);
    while (loop_ub <= md2) {
      xtmp = y->data[loop_ub - 1];
      y->data[loop_ub - 1] = y->data[m - loop_ub];
      y->data[m - loop_ub] = xtmp;
      loop_ub++;
    }

    if (x_in->size[0] == 1) {
      emxInit_int32_T(&r6, 1);
      loop_ub = (int32_T)((real_T)x->size[0] + 3.0) - 4;
      i2 = r6->size[0];
      r6->size[0] = loop_ub + 1;
      emxEnsureCapacity((emxArray__common *)r6, i2, (int32_T)sizeof(int32_T));
      for (i2 = 0; i2 <= loop_ub; i2++) {
        r6->data[i2] = 4 + i2;
      }

      i2 = y_out->size[0] * y_out->size[1];
      y_out->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)y_out, i2, (int32_T)sizeof(real_T));
      md2 = r6->size[0];
      i2 = y_out->size[0] * y_out->size[1];
      y_out->size[1] = md2;
      emxEnsureCapacity((emxArray__common *)y_out, i2, (int32_T)sizeof(real_T));
      loop_ub = r6->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        y_out->data[i2] = y->data[r6->data[i2] - 1];
      }

      emxFree_int32_T(&r6);
    } else {
      emxInit_int32_T(&r6, 1);
      loop_ub = (int32_T)((real_T)x->size[0] + 3.0) - 3;
      i2 = y_out->size[0] * y_out->size[1];
      y_out->size[0] = loop_ub;
      y_out->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)y_out, i2, (int32_T)sizeof(real_T));
      md2 = (int32_T)((real_T)x->size[0] + 3.0) - 4;
      i2 = r6->size[0];
      r6->size[0] = md2 + 1;
      emxEnsureCapacity((emxArray__common *)r6, i2, (int32_T)sizeof(int32_T));
      for (i2 = 0; i2 <= md2; i2++) {
        r6->data[i2] = 4 + i2;
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        y_out->data[i2] = y->data[r6->data[i2] - 1];
      }

      emxFree_int32_T(&r6);
    }

    emxFree_real_T(&y);
  }

  emxFree_real_T(&x);
}

static void histogramFeatures(const real_T ioiHist[17], real_T features[12])
{
  int32_T iidx[17];
  real_T k[17];
  int32_T ind[17];
  boolean_T S[17];
  int32_T cindx;
  real_T xlast;
  int32_T b_k;
  real_T b_ioiHist[17];
  real_T sigma;
  real_T b_S[17];
  real_T b[17];
  int32_T ix;
  boolean_T x;
  int8_T S_size[2];
  int8_T outsz[2];
  int32_T loop_ub;
  int32_T iindx_data[1];
  int32_T b_ix;
  int32_T indx_data[1];

  /* UNTITLED Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* features(1) = mean(ioiHist); */
  features[0] = b_std(ioiHist);
  eml_sort(ioiHist, k, iidx);
  features[1] = k[16] / k[15];
  for (cindx = 0; cindx < 17; cindx++) {
    ind[cindx] = iidx[cindx];
    S[cindx] = (ioiHist[cindx] == 0.0);
  }

  features[2] = (real_T)ind[16] / (real_T)ind[15];
  xlast = S[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += (real_T)S[b_k + 1];
  }

  features[3] = xlast / 17.0;
  for (cindx = 0; cindx < 17; cindx++) {
    b_ioiHist[cindx] = ioiHist[cindx];

    /* FEATURESPECTRALDECREASE Computes the Spectral Decrease */
    /*   A measure of steepness of spectral envelope over frequency */
    k[cindx] = cindx;
  }

  features[4] = featureSpectralCentroid(b_ioiHist);
  features[5] = featureSpectralCrest(ioiHist);
  k[0] = 1.0;
  xlast = 0.0;
  for (cindx = 0; cindx < 17; cindx++) {
    /*  compute slope */
    xlast += 1.0 / k[cindx] * (ioiHist[cindx] - ioiHist[0]);
  }

  sigma = ioiHist[1];
  for (b_k = 0; b_k < 15; b_k++) {
    sigma += ioiHist[b_k + 2];
  }

  features[6] = xlast / sigma;

  /* FEATURESPECTRALKURTOSIS Computes the Spectral Kurtosis */
  /*    It is a measure of gaussianity of a spectrum */
  sigma = c_std(ioiHist);

  /*  Subtracting means */
  xlast = ioiHist[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += ioiHist[b_k + 1];
  }

  bsxfun(ioiHist, xlast / 17.0, b_S);
  for (b_k = 0; b_k < 17; b_k++) {
    k[b_k] = rt_powd_snf(b_S[b_k], 4.0) / (rt_powd_snf(sigma, 4.0) * 17.0);
  }

  sigma = k[0];
  for (b_k = 0; b_k < 16; b_k++) {
    sigma += k[b_k + 1];
  }

  features[7] = sigma;

  /* FEATURESPECTRALROLLOFF Computes Spectral Rolloff */
  /*     Finds frequency bin where cumsum reaches 0.85 of magnitude */
  /* compute rolloff */
  xlast = ioiHist[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += ioiHist[b_k + 1];
  }

  sigma = 0.85 * xlast;

  /*  Find indices where cumulative sum is greater */
  memcpy(&b[0], &ioiHist[0], 17U * sizeof(real_T));
  ix = 0;
  xlast = ioiHist[0];
  for (b_k = 0; b_k < 16; b_k++) {
    ix++;
    xlast += b[ix];
    b[ix] = xlast;
  }

  for (b_k = 0; b_k < 17; b_k++) {
    S[b_k] = (b[b_k] >= sigma);
  }

  /*  Find the maximum value */
  xlast = S[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += (real_T)S[b_k + 1];
  }

  x = (xlast > 0.0);
  b_k = 0;
  if (x) {
    b_k = 1;
  }

  S_size[0] = 17;
  S_size[1] = (int8_T)b_k;
  for (cindx = 0; cindx < 2; cindx++) {
    outsz[cindx] = S_size[cindx];
  }

  loop_ub = outsz[1];
  for (cindx = 0; cindx < loop_ub; cindx++) {
    iindx_data[cindx] = 1;
  }

  ix = -16;
  cindx = 1;
  while (cindx <= b_k) {
    ix += 17;
    x = S[(ix - 1) % 17];
    loop_ub = 1;
    cindx = 1;
    if (ix < ix + 16) {
      for (b_ix = ix; b_ix + 1 <= ix + 16; b_ix++) {
        cindx++;
        if (S[b_ix % 17] > x) {
          x = S[b_ix % 17];
          loop_ub = cindx;
        }
      }
    }

    iindx_data[0] = loop_ub;
    cindx = 2;
  }

  loop_ub = outsz[1];
  for (cindx = 0; cindx < loop_ub; cindx++) {
    indx_data[cindx] = iindx_data[cindx];
  }

  features[8] = indx_data[0];

  /* FEATURESPECTRALSKEWNESS Compute spectral skewness */
  /*    A measure of symmettricity of pdf */
  sigma = c_std(ioiHist);

  /*  Subtracting means */
  xlast = ioiHist[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += ioiHist[b_k + 1];
  }

  bsxfun(ioiHist, xlast / 17.0, b_S);
  for (b_k = 0; b_k < 17; b_k++) {
    k[b_k] = rt_powd_snf(b_S[b_k], 3.0) / (rt_powd_snf(sigma, 3.0) * 17.0);
  }

  sigma = k[0];
  for (b_k = 0; b_k < 16; b_k++) {
    sigma += k[b_k + 1];
  }

  features[9] = sigma;

  /* FUNCTIONSPECTRALSLOPE Computes the spectral slope */
  /*  */
  /*  compute index vector */
  /*  compute slope */
  xlast = ioiHist[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += ioiHist[b_k + 1];
  }

  bsxfun(ioiHist, xlast / 17.0, b_S);
  xlast = 0.0;
  sigma = 0.0;
  for (b_k = 0; b_k < 17; b_k++) {
    xlast += (-8.5 + (((real_T)b_k + 1.0) - 1.0)) * b_S[b_k];
    sigma += (-8.5 + (((real_T)b_k + 1.0) - 1.0)) * (-8.5 + (((real_T)b_k + 1.0)
      - 1.0));
    b_ioiHist[b_k] = ioiHist[b_k];
    k[b_k] = b_k;
    b_S[b_k] = ioiHist[b_k] * ioiHist[b_k];
  }

  features[10] = xlast / sigma;

  /*  FEATURESPECTRALSPREAD Computes spectral spread */
  /*    Concentration of energy around spectral centroid */
  bsxfun(k, featureSpectralCentroid(b_ioiHist), b);
  for (b_k = 0; b_k < 17; b_k++) {
    k[b_k] = b[b_k] * b[b_k] * b_S[b_k];
  }

  xlast = k[0];
  sigma = b_S[0];
  for (b_k = 0; b_k < 16; b_k++) {
    xlast += k[b_k + 1];
    sigma += b_S[b_k + 1];
  }

  features[11] = sqrt(xlast / sigma);
}

static void ioiHistogram(emxArray_boolean_T *onsets, const emxArray_real_T *T,
  real_T ioiHist[17])
{
  emxArray_real_T *tOnset;
  emxArray_int32_T *r10;
  int32_T high_i;
  int32_T ixLead;
  emxArray_real_T *ioi;
  emxArray_real_T *b_y1;
  int32_T iyLead;
  real_T work_data_idx_0;
  real_T tmp1;
  real_T tmp2;
  int32_T sz[2];
  real_T meanIOI_data[1];
  int32_T meanIOI_size[2];
  int32_T k;
  emxArray_real_T *r11;
  emxArray_real_T b_meanIOI_data;
  int32_T d;
  real_T stdIOI_data[1];
  boolean_T goodInd_data[1];
  real_T histEdges[17];
  int32_T exitg1;
  b_emxInit_real_T(&tOnset, 1);
  emxInit_int32_T(&r10, 1);

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Setting the first one as true */
  onsets->data[0] = TRUE;

  /* onsetInd = onsets; */
  eml_li_find(onsets, r10);
  high_i = tOnset->size[0];
  tOnset->size[0] = r10->size[0];
  emxEnsureCapacity((emxArray__common *)tOnset, high_i, (int32_T)sizeof(real_T));
  ixLead = r10->size[0];
  for (high_i = 0; high_i < ixLead; high_i++) {
    tOnset->data[high_i] = T->data[r10->data[high_i] - 1];
  }

  emxFree_int32_T(&r10);
  emxInit_real_T(&ioi, 2);
  if (tOnset->size[0] == 0) {
    high_i = ioi->size[0] * ioi->size[1];
    ioi->size[0] = 0;
    ioi->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)ioi, high_i, (int32_T)sizeof(real_T));
  } else {
    ixLead = tOnset->size[0] - 1;
    if (ixLead <= 1) {
    } else {
      ixLead = 1;
    }

    if (ixLead < 1) {
      high_i = ioi->size[0] * ioi->size[1];
      ioi->size[0] = 0;
      ioi->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)ioi, high_i, (int32_T)sizeof(real_T));
    } else {
      b_emxInit_real_T(&b_y1, 1);
      high_i = b_y1->size[0];
      b_y1->size[0] = tOnset->size[0] - 1;
      emxEnsureCapacity((emxArray__common *)b_y1, high_i, (int32_T)sizeof(real_T));
      ixLead = 1;
      iyLead = 0;
      work_data_idx_0 = tOnset->data[0];
      for (high_i = 2; high_i <= tOnset->size[0]; high_i++) {
        tmp1 = tOnset->data[ixLead];
        tmp2 = work_data_idx_0;
        work_data_idx_0 = tmp1;
        tmp1 -= tmp2;
        ixLead++;
        b_y1->data[iyLead] = tmp1;
        iyLead++;
      }

      ixLead = b_y1->size[0];
      high_i = ioi->size[0] * ioi->size[1];
      ioi->size[0] = ixLead;
      emxEnsureCapacity((emxArray__common *)ioi, high_i, (int32_T)sizeof(real_T));
      high_i = ioi->size[0] * ioi->size[1];
      ioi->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)ioi, high_i, (int32_T)sizeof(real_T));
      ixLead = b_y1->size[0];
      for (high_i = 0; high_i < ixLead; high_i++) {
        ioi->data[high_i] = b_y1->data[high_i];
      }

      emxFree_real_T(&b_y1);
    }
  }

  emxFree_real_T(&tOnset);
  for (high_i = 0; high_i < 2; high_i++) {
    sz[high_i] = ioi->size[high_i];
  }

  meanIOI_size[0] = 1;
  meanIOI_size[1] = sz[1];
  if ((ioi->size[0] == 0) || (ioi->size[1] == 0)) {
    meanIOI_size[0] = 1;
    meanIOI_size[1] = sz[1];
    ixLead = sz[1];
    for (high_i = 0; high_i < ixLead; high_i++) {
      meanIOI_data[high_i] = 0.0;
    }
  } else {
    iyLead = -1;
    work_data_idx_0 = ioi->data[0];
    for (k = 2; k <= ioi->size[0]; k++) {
      iyLead++;
      work_data_idx_0 += ioi->data[iyLead + 1];
    }

    meanIOI_data[0] = work_data_idx_0;
  }

  emxInit_real_T(&r11, 2);
  b_meanIOI_data.data = (real_T *)&meanIOI_data;
  b_meanIOI_data.size = (int32_T *)&meanIOI_size;
  b_meanIOI_data.allocatedSize = 1;
  b_meanIOI_data.numDimensions = 2;
  b_meanIOI_data.canFreeData = FALSE;
  rdivide(&b_meanIOI_data, ioi->size[0], r11);
  meanIOI_size[0] = 1;
  meanIOI_size[1] = r11->size[1];
  ixLead = r11->size[0] * r11->size[1];
  for (high_i = 0; high_i < ixLead; high_i++) {
    meanIOI_data[high_i] = r11->data[high_i];
  }

  emxFree_real_T(&r11);
  if (ioi->size[0] > 1) {
    d = ioi->size[0] - 1;
  } else {
    d = ioi->size[0];
  }

  for (high_i = 0; high_i < 2; high_i++) {
    sz[high_i] = ioi->size[high_i];
  }

  iyLead = 0;
  ixLead = 1;
  while (ixLead <= ioi->size[1]) {
    if ((ioi->size[0] == 0) || (ioi->size[1] == 0)) {
      work_data_idx_0 = rtNaN;
    } else {
      ixLead = iyLead;
      tmp1 = ioi->data[iyLead];
      for (k = 0; k <= ioi->size[0] - 2; k++) {
        ixLead++;
        tmp1 += ioi->data[ixLead];
      }

      tmp1 /= (real_T)ioi->size[0];
      ixLead = iyLead;
      tmp2 = ioi->data[iyLead] - tmp1;
      work_data_idx_0 = tmp2 * tmp2;
      for (k = 0; k <= ioi->size[0] - 2; k++) {
        ixLead++;
        tmp2 = ioi->data[ixLead] - tmp1;
        work_data_idx_0 += tmp2 * tmp2;
      }

      work_data_idx_0 /= (real_T)d;
    }

    stdIOI_data[0] = work_data_idx_0;
    iyLead += ioi->size[0];
    ixLead = 2;
  }

  k = 0;
  while (k <= sz[1] - 1) {
    stdIOI_data[0] = sqrt(stdIOI_data[0]);
    k = 1;
  }

  iyLead = ioi->size[1];
  ixLead = ioi->size[0] * ioi->size[1];
  for (high_i = 0; high_i < ixLead; high_i++) {
    goodInd_data[high_i] = ((ioi->data[high_i] > meanIOI_data[high_i] - 2.0 *
      stdIOI_data[high_i]) && (ioi->data[high_i] < meanIOI_data[high_i] + 2.0 *
      stdIOI_data[high_i]));
  }

  k = 0;
  ixLead = 1;
  while (ixLead <= iyLead) {
    if (goodInd_data[0]) {
      k++;
    }

    ixLead = 2;
  }

  /*  Avoiding code export bug */
  /* ioi(ioi>upperThresh) = []; */
  /* ioi(ioi<lowerThresh) = []; */
  /* nBins = 16; */
  for (high_i = 0; high_i < 17; high_i++) {
    histEdges[high_i] = 0.125 * (real_T)high_i;
    ioiHist[high_i] = 0.0;
  }

  histEdges[16] = rtInf;
  high_i = 0;
  do {
    exitg1 = 0;
    if (high_i < 16) {
      if (histEdges[1 + high_i] < histEdges[high_i]) {
        for (high_i = 0; high_i < 17; high_i++) {
          ioiHist[high_i] = rtNaN;
        }

        exitg1 = 1;
      } else {
        high_i++;
      }
    } else {
      ixLead = 0;
      while (ixLead <= k - 1) {
        ixLead = 0;
        if (!rtIsNaN(ioi->data[0])) {
          if ((ioi->data[0] >= 0.0) && (ioi->data[0] < rtInf)) {
            ixLead = 1;
            iyLead = 2;
            high_i = 17;
            while (high_i > iyLead) {
              d = (ixLead + high_i) >> 1;
              if (ioi->data[0] >= histEdges[d - 1]) {
                ixLead = d;
                iyLead = d + 1;
              } else {
                high_i = d;
              }
            }
          }

          if (ioi->data[0] == rtInf) {
            ixLead = 17;
          }
        }

        if (ixLead > 0) {
          ioiHist[ixLead - 1]++;
        }

        ixLead = 1;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&ioi);
  work_data_idx_0 = ioiHist[0];
  for (k = 0; k < 16; k++) {
    work_data_idx_0 += ioiHist[k + 1];
  }

  for (high_i = 0; high_i < 17; high_i++) {
    ioiHist[high_i] /= work_data_idx_0;
  }
}

static void onsetDetection(const emxArray_real_T *spec, emxArray_boolean_T
  *onsets, emxArray_real_T *flux)
{
  emxArray_real_T *b_flux;
  int32_T ixstart;
  real_T mtmp;
  int32_T k0;
  boolean_T exitg1;
  int32_T i0;
  emxArray_real_T *flux1;
  int32_T varargin_1[2];
  int32_T i;
  boolean_T x[7];
  int32_T k;
  emxArray_real_T *r0;
  int32_T nxin;
  emxArray_real_T *r1;
  emxArray_real_T *mask2;
  emxArray_boolean_T *b;
  emxArray_int32_T *r2;
  emxArray_real_T *b_mask2;
  emxArray_real_T *c_mask2;
  emxArray_real_T *r3;
  int32_T vstride;
  int32_T npages;
  int32_T dim;
  int32_T j;
  int32_T ia;
  b_emxInit_real_T(&b_flux, 1);

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  onsetFlux(spec, b_flux);

  /*  Normalizing */
  ixstart = 1;
  mtmp = b_flux->data[0];
  if (b_flux->size[0] > 1) {
    if (rtIsNaN(b_flux->data[0])) {
      k0 = 2;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (k0 <= b_flux->size[0])) {
        ixstart = k0;
        if (!rtIsNaN(b_flux->data[k0 - 1])) {
          mtmp = b_flux->data[k0 - 1];
          exitg1 = TRUE;
        } else {
          k0++;
        }
      }
    }

    if (ixstart < b_flux->size[0]) {
      while (ixstart + 1 <= b_flux->size[0]) {
        if (b_flux->data[ixstart] > mtmp) {
          mtmp = b_flux->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  i0 = b_flux->size[0];
  emxEnsureCapacity((emxArray__common *)b_flux, i0, (int32_T)sizeof(real_T));
  ixstart = b_flux->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    b_flux->data[i0] /= mtmp;
  }

  emxInit_real_T(&flux1, 2);

  /*  Smoothing */
  /* h=fdesign.lowpass('N,F3dB',12,0.15); */
  /* d1 = design(h,'elliptic'); */
  /* flux = filtfilt(d1.sosMatrix,d1.ScaleValues,flux); */
  filtfilt(b_flux, flux);

  /* h = 1/4*ones(4,1); */
  /* flux = filter(h,1,flux); */
  /*  Peak picking  */
  /* w = 2; % Size of window to find local maxima */
  padarray(flux, flux1);
  emxFree_real_T(&b_flux);
  for (i0 = 0; i0 < 2; i0++) {
    varargin_1[i0] = flux1->size[i0];
  }

  i0 = onsets->size[0] * onsets->size[1];
  onsets->size[0] = varargin_1[0];
  emxEnsureCapacity((emxArray__common *)onsets, i0, (int32_T)sizeof(boolean_T));
  i0 = onsets->size[0] * onsets->size[1];
  onsets->size[1] = varargin_1[1];
  emxEnsureCapacity((emxArray__common *)onsets, i0, (int32_T)sizeof(boolean_T));
  ixstart = varargin_1[0] * varargin_1[1];
  for (i0 = 0; i0 < ixstart; i0++) {
    onsets->data[i0] = FALSE;
  }

  if ((0 == flux1->size[0]) || (0 == flux1->size[1])) {
    ixstart = 0;
  } else if (flux1->size[0] > flux1->size[1]) {
    ixstart = flux1->size[0];
  } else {
    ixstart = flux1->size[1];
  }

  for (i = 3; i - 3 <= ixstart - 7; i++) {
    mtmp = flux1->data[i];
    for (i0 = 0; i0 < 7; i0++) {
      x[i0] = (mtmp >= flux1->data[(i0 + i) - 3]);
    }

    mtmp = x[0];
    for (k = 0; k < 6; k++) {
      mtmp += (real_T)x[k + 1];
    }

    if (mtmp == 7.0) {
      onsets->data[i] = TRUE;
    }
  }

  b_emxInit_real_T(&r0, 1);

  /*  Remove m elements at the start and end */
  eml_null_assignment(onsets);
  mtmp = (real_T)(onsets->size[0] * onsets->size[1]) - 3.0;
  i0 = onsets->size[0] * onsets->size[1];
  nxin = r0->size[0];
  r0->size[0] = (int32_T)((real_T)i0 - mtmp) + 1;
  emxEnsureCapacity((emxArray__common *)r0, nxin, (int32_T)sizeof(real_T));
  ixstart = (int32_T)((real_T)i0 - mtmp);
  for (i0 = 0; i0 <= ixstart; i0++) {
    r0->data[i0] = mtmp + (real_T)i0;
  }

  emxInit_real_T(&r1, 2);
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  ixstart = r0->size[0];
  i0 = r1->size[0] * r1->size[1];
  r1->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  ixstart = r0->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    r1->data[i0] = r0->data[i0];
  }

  emxFree_real_T(&r0);
  b_eml_null_assignment(onsets, r1);

  /*  Perform second thresholding operation */
  /* m = 1; % Multiplier so mean is calculated over a larger range before peak */
  /* delta = 0.01; % Threshold above local mean */
  padarray(flux, flux1);
  for (i0 = 0; i0 < 2; i0++) {
    varargin_1[i0] = flux1->size[i0];
  }

  emxInit_real_T(&mask2, 2);
  i0 = mask2->size[0] * mask2->size[1];
  mask2->size[0] = varargin_1[0];
  emxEnsureCapacity((emxArray__common *)mask2, i0, (int32_T)sizeof(real_T));
  i0 = mask2->size[0] * mask2->size[1];
  mask2->size[1] = varargin_1[1];
  emxEnsureCapacity((emxArray__common *)mask2, i0, (int32_T)sizeof(real_T));
  ixstart = varargin_1[0] * varargin_1[1];
  for (i0 = 0; i0 < ixstart; i0++) {
    mask2->data[i0] = 0.0;
  }

  if ((0 == flux1->size[0]) || (0 == flux1->size[1])) {
    ixstart = 0;
  } else if (flux1->size[0] > flux1->size[1]) {
    ixstart = flux1->size[0];
  } else {
    ixstart = flux1->size[1];
  }

  for (i = 3; i - 3 <= ixstart - 7; i++) {
    /* flux = onsetDetection(denoisedSpec); */
    mtmp = flux1->data[-3 + i];
    for (k = 0; k < 6; k++) {
      mtmp += flux1->data[(k + i) - 2];
    }

    if (flux1->data[i] >= mtmp / 7.0 + 0.01) {
      mask2->data[i] = 1.0;
    }
  }

  emxFree_real_T(&flux1);
  emxInit_boolean_T(&b, 2);

  /*  Remove mw elements at the start and end */
  nxin = mask2->size[0] * mask2->size[1];
  i0 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = nxin;
  emxEnsureCapacity((emxArray__common *)b, i0, (int32_T)sizeof(boolean_T));
  for (i0 = 0; i0 < nxin; i0++) {
    b->data[i0] = FALSE;
  }

  for (k = 0; k < 2; k++) {
    b->data[k] = TRUE;
  }

  ixstart = 0;
  for (k = 1; k <= b->size[1]; k++) {
    ixstart += b->data[k - 1];
  }

  ixstart = nxin - ixstart;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > b->size[1]) || (!b->data[k - 1])) {
      k0++;
      mask2->data[k0] = mask2->data[k - 1];
    }
  }

  emxInit_int32_T(&r2, 1);
  emxInit_real_T(&b_mask2, 2);
  b_emxInit_real_T(&c_mask2, 1);
  if ((mask2->size[0] != 1) && (mask2->size[1] == 1)) {
    if (1 > ixstart) {
      ixstart = 0;
    }

    i0 = c_mask2->size[0];
    c_mask2->size[0] = ixstart;
    emxEnsureCapacity((emxArray__common *)c_mask2, i0, (int32_T)sizeof(real_T));
    for (i0 = 0; i0 < ixstart; i0++) {
      c_mask2->data[i0] = mask2->data[i0];
    }

    i0 = mask2->size[0] * mask2->size[1];
    mask2->size[0] = ixstart;
    mask2->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)mask2, i0, (int32_T)sizeof(real_T));
    i0 = 0;
    while (i0 <= 0) {
      for (i0 = 0; i0 < ixstart; i0++) {
        mask2->data[i0] = c_mask2->data[i0];
      }

      i0 = 1;
    }
  } else {
    if (1 > ixstart) {
      ixstart = 0;
    }

    i0 = r2->size[0];
    r2->size[0] = ixstart;
    emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(int32_T));
    for (i0 = 0; i0 < ixstart; i0++) {
      r2->data[i0] = 1 + i0;
    }

    ixstart = r2->size[0];
    i0 = b_mask2->size[0] * b_mask2->size[1];
    b_mask2->size[0] = 1;
    b_mask2->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)b_mask2, i0, (int32_T)sizeof(real_T));
    for (i0 = 0; i0 < ixstart; i0++) {
      nxin = 0;
      while (nxin <= 0) {
        b_mask2->data[b_mask2->size[0] * i0] = mask2->data[r2->data[i0] - 1];
        nxin = 1;
      }
    }

    i0 = mask2->size[0] * mask2->size[1];
    mask2->size[0] = b_mask2->size[0];
    mask2->size[1] = b_mask2->size[1];
    emxEnsureCapacity((emxArray__common *)mask2, i0, (int32_T)sizeof(real_T));
    ixstart = b_mask2->size[1];
    for (i0 = 0; i0 < ixstart; i0++) {
      k0 = b_mask2->size[0];
      for (nxin = 0; nxin < k0; nxin++) {
        mask2->data[nxin + mask2->size[0] * i0] = b_mask2->data[nxin +
          b_mask2->size[0] * i0];
      }
    }
  }

  emxFree_real_T(&c_mask2);
  emxFree_real_T(&b_mask2);
  emxFree_int32_T(&r2);
  b_emxInit_real_T(&r3, 1);
  mtmp = (real_T)(mask2->size[0] * mask2->size[1]) - 3.0;
  i0 = mask2->size[0] * mask2->size[1];
  nxin = r3->size[0];
  r3->size[0] = (int32_T)((real_T)i0 - mtmp) + 1;
  emxEnsureCapacity((emxArray__common *)r3, nxin, (int32_T)sizeof(real_T));
  ixstart = (int32_T)((real_T)i0 - mtmp);
  for (i0 = 0; i0 <= ixstart; i0++) {
    r3->data[i0] = mtmp + (real_T)i0;
  }

  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  ixstart = r3->size[0];
  i0 = r1->size[0] * r1->size[1];
  r1->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  ixstart = r3->size[0];
  for (i0 = 0; i0 < ixstart; i0++) {
    r1->data[i0] = r3->data[i0];
  }

  emxFree_real_T(&r3);
  c_eml_null_assignment(mask2, r1);
  i0 = onsets->size[0] * onsets->size[1];
  emxEnsureCapacity((emxArray__common *)onsets, i0, (int32_T)sizeof(boolean_T));
  ixstart = onsets->size[0];
  k0 = onsets->size[1];
  ixstart *= k0;
  emxFree_real_T(&r1);
  for (i0 = 0; i0 < ixstart; i0++) {
    onsets->data[i0] = (onsets->data[i0] && (mask2->data[i0] != 0.0));
  }

  emxFree_real_T(&mask2);
  onsets->data[0] = FALSE;
  if ((onsets->size[0] == 0) || (onsets->size[1] == 0) || ((onsets->size[0] == 1)
       && (onsets->size[1] == 1))) {
  } else {
    for (i0 = 0; i0 < 2; i0++) {
      varargin_1[i0] = onsets->size[i0];
    }

    ixstart = varargin_1[0];
    if (varargin_1[1] > varargin_1[0]) {
      ixstart = varargin_1[1];
    }

    i0 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)b, i0, (int32_T)sizeof(boolean_T));
    vstride = 1;
    npages = onsets->size[0] * onsets->size[1];
    for (dim = 0; dim < 2; dim++) {
      i0 = onsets->size[dim];
      npages = div_s32(npages, onsets->size[dim]);
      if (onsets->size[dim] > 1) {
        ixstart = (int32_T)fabs(-1.0 + (((real_T)dim + 1.0) - 1.0));
        if (ixstart - div_s32(ixstart, onsets->size[dim]) * onsets->size[dim] >
            0) {
          ixstart = (onsets->size[dim] - 1) * vstride;
          k0 = 0;
          for (i = 1; i <= npages; i++) {
            nxin = k0;
            k0 += ixstart;
            for (j = 1; j <= vstride; j++) {
              nxin++;
              k0++;
              ia = nxin;
              for (k = 1; k <= i0; k++) {
                b->data[k - 1] = onsets->data[ia - 1];
                ia += vstride;
              }

              ia = nxin - 1;
              for (k = 2; k <= i0; k++) {
                onsets->data[ia] = b->data[k - 1];
                ia += vstride;
              }

              onsets->data[ia] = b->data[0];
            }
          }
        }
      }

      vstride *= i0;
    }
  }

  emxFree_boolean_T(&b);

  /*  Some post processing to remove sequences of onsets */
  /*  Changing to non vectorized versions for export */
  if ((0 == onsets->size[0]) || (0 == onsets->size[1])) {
    ixstart = 0;
  } else if (onsets->size[0] > onsets->size[1]) {
    ixstart = onsets->size[0];
  } else {
    ixstart = onsets->size[1];
  }

  for (i = 0; i <= ixstart - 3; i++) {
    if ((onsets->data[i] == 1) && (onsets->data[i + 1] == 1)) {
      if (onsets->data[i + 2] == 1) {
        onsets->data[i + 2] = FALSE;
      }

      onsets->data[i + 1] = FALSE;
    }
  }

  /*  tripleInd = strfind(onsets',[1,1,1]); */
  /*   onsets(tripleInd+1) = 0; */
  /*   onsets(tripleInd+2) = 0; */
  /*    */
  /*   doubleInd = strfind(onsets',[1,1]); */
  /*   onsets(doubleInd+1) = 0; */
  /* onsets(1) = 0; */
  /* flux(1) = 0; */
  /* onsets(end+1) = 0; */
  /* flux(end+1) = 0; */
  /*  xmin = 1; */
  /*  xmax = length(flux); */
  /*   */
  /*  figure */
  /*  subplot(4,1,1) */
  /*  stem(mask1); */
  /*  axis([xmin xmax 0 1]); */
  /*  subplot(4,1,2) */
  /*  stem(mask2); */
  /*  axis([xmin xmax 0 1]); */
  /*  subplot(4,1,3) */
  /*  stem(mask1&mask2); */
  /*  axis([xmin xmax 0 1]); */
  /*  subplot(4,1,4); */
  /*  imagesc(denoisedSpec); */
  /*  axis([xmin xmax 0 512]); */
  /*  axis('xy'); */
  /*  colormap(hot); */
}

static void onsetFlux(const emxArray_real_T *S, emxArray_real_T *flux)
{
  emxArray_real_T *b_S;
  int32_T iyLead;
  int32_T loop_ub;
  int32_T ixLead;
  int32_T iy;
  emxArray_real_T *x;
  int32_T d;
  emxArray_real_T *b_y1;
  uint32_T ySize[2];
  int32_T ix;
  real_T work;
  real_T tmp2;
  emxArray_real_T *r4;
  emxArray_real_T *b_flux;
  real_T y;
  real_T r;
  emxArray_real_T *c_flux;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *r5;
  b_emxInit_real_T(&b_S, 1);

  /* ONSETFLUX Computes new spectral flux */
  /*    Detailed explanation goes here */
  /*  Just to be sure */
  /* S = abs(S); */
  iyLead = S->size[0];
  loop_ub = S->size[0];
  ixLead = S->size[1];
  iy = b_S->size[0];
  b_S->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_S, iy, (int32_T)sizeof(real_T));
  for (iy = 0; iy < loop_ub; iy++) {
    b_S->data[iy] = S->data[iy + S->size[0] * (ixLead - 1)];
  }

  emxInit_real_T(&x, 2);
  iy = x->size[0] * x->size[1];
  x->size[0] = S->size[0];
  x->size[1] = S->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)x, iy, (int32_T)sizeof(real_T));
  loop_ub = S->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    d = S->size[0];
    for (ixLead = 0; ixLead < d; ixLead++) {
      x->data[ixLead + x->size[0] * iy] = S->data[ixLead + S->size[0] * iy];
    }
  }

  iy = 0;
  while (iy <= 0) {
    for (iy = 0; iy < iyLead; iy++) {
      x->data[iy + x->size[0] * S->size[1]] = b_S->data[iy];
    }

    iy = 1;
  }

  emxFree_real_T(&b_S);
  emxInit_real_T(&b_y1, 2);
  if (1 >= x->size[1]) {
    for (iy = 0; iy < 2; iy++) {
      ySize[iy] = (uint32_T)x->size[iy];
    }

    iy = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = (int32_T)ySize[0];
    emxEnsureCapacity((emxArray__common *)b_y1, iy, (int32_T)sizeof(real_T));
    iy = b_y1->size[0] * b_y1->size[1];
    b_y1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)b_y1, iy, (int32_T)sizeof(real_T));
  } else {
    for (iy = 0; iy < 2; iy++) {
      ySize[iy] = (uint32_T)x->size[iy];
    }

    iy = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = (int32_T)ySize[0];
    b_y1->size[1] = x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)b_y1, iy, (int32_T)sizeof(real_T));
    ix = 0;
    iy = 1;
    for (d = 1; d <= x->size[0]; d++) {
      ixLead = ix + x->size[0];
      iyLead = iy;
      work = x->data[ix];
      for (loop_ub = 2; loop_ub <= x->size[1]; loop_ub++) {
        tmp2 = work;
        work = x->data[ixLead];
        tmp2 = x->data[ixLead] - tmp2;
        ixLead += x->size[0];
        b_y1->data[iyLead - 1] = tmp2;
        iyLead += x->size[0];
      }

      ix++;
      iy++;
    }
  }

  emxFree_real_T(&x);

  /*  Half wave rectification */
  for (iy = 0; iy < 2; iy++) {
    ySize[iy] = (uint32_T)b_y1->size[iy];
  }

  emxInit_real_T(&r4, 2);
  iy = r4->size[0] * r4->size[1];
  r4->size[0] = (int32_T)ySize[0];
  r4->size[1] = (int32_T)ySize[1];
  emxEnsureCapacity((emxArray__common *)r4, iy, (int32_T)sizeof(real_T));
  iy = b_y1->size[0] * b_y1->size[1];
  for (loop_ub = 0; loop_ub < iy; loop_ub++) {
    r4->data[(int32_T)(1.0 + (real_T)loop_ub) - 1] = fabs(b_y1->data[(int32_T)
      (1.0 + (real_T)loop_ub) - 1]);
  }

  iy = b_y1->size[0] * b_y1->size[1];
  emxEnsureCapacity((emxArray__common *)b_y1, iy, (int32_T)sizeof(real_T));
  ixLead = b_y1->size[0];
  d = b_y1->size[1];
  iyLead = ixLead * d;
  for (iy = 0; iy < iyLead; iy++) {
    b_y1->data[iy] = (b_y1->data[iy] + r4->data[iy]) / 2.0;
  }

  emxFree_real_T(&r4);

  /*  Summed across all bins */
  for (iy = 0; iy < 2; iy++) {
    ySize[iy] = (uint32_T)b_y1->size[iy];
  }

  emxInit_real_T(&b_flux, 2);
  iy = b_flux->size[0] * b_flux->size[1];
  b_flux->size[0] = 1;
  b_flux->size[1] = (int32_T)ySize[1];
  emxEnsureCapacity((emxArray__common *)b_flux, iy, (int32_T)sizeof(real_T));
  if ((b_y1->size[0] == 0) || (b_y1->size[1] == 0)) {
    iy = b_flux->size[0] * b_flux->size[1];
    b_flux->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b_flux, iy, (int32_T)sizeof(real_T));
    iy = b_flux->size[0] * b_flux->size[1];
    b_flux->size[1] = (int32_T)ySize[1];
    emxEnsureCapacity((emxArray__common *)b_flux, iy, (int32_T)sizeof(real_T));
    iyLead = (int32_T)ySize[1];
    for (iy = 0; iy < iyLead; iy++) {
      b_flux->data[iy] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (d = 1; d <= b_y1->size[1]; d++) {
      ixLead = ix + 1;
      ix++;
      tmp2 = b_y1->data[ixLead];
      for (loop_ub = 2; loop_ub <= b_y1->size[0]; loop_ub++) {
        ix++;
        tmp2 += b_y1->data[ix];
      }

      iy++;
      b_flux->data[iy] = tmp2;
    }
  }

  emxFree_real_T(&b_y1);
  if (b_flux->size[1] == 0) {
    tmp2 = 0.0;
  } else {
    tmp2 = b_flux->data[0];
    for (loop_ub = 2; loop_ub <= b_flux->size[1]; loop_ub++) {
      tmp2 += b_flux->data[loop_ub - 1];
    }
  }

  tmp2 /= (real_T)b_flux->size[1];
  if (b_flux->size[1] > 1) {
    d = b_flux->size[1] - 1;
  } else {
    d = b_flux->size[1];
  }

  if (b_flux->size[1] == 0) {
    y = rtNaN;
  } else {
    ix = 0;
    work = b_flux->data[0];
    for (loop_ub = 0; loop_ub <= b_flux->size[1] - 2; loop_ub++) {
      ix++;
      work += b_flux->data[ix];
    }

    work /= (real_T)b_flux->size[1];
    ix = 0;
    r = b_flux->data[0] - work;
    y = r * r;
    for (loop_ub = 0; loop_ub <= b_flux->size[1] - 2; loop_ub++) {
      ix++;
      r = b_flux->data[ix] - work;
      y += r * r;
    }

    y /= (real_T)d;
  }

  emxInit_real_T(&c_flux, 2);
  iy = c_flux->size[0] * c_flux->size[1];
  c_flux->size[0] = 1;
  c_flux->size[1] = b_flux->size[1];
  emxEnsureCapacity((emxArray__common *)c_flux, iy, (int32_T)sizeof(real_T));
  iyLead = b_flux->size[0] * b_flux->size[1];
  for (iy = 0; iy < iyLead; iy++) {
    c_flux->data[iy] = b_flux->data[iy] - tmp2;
  }

  rdivide(c_flux, y, b_flux);
  iy = flux->size[0];
  flux->size[0] = b_flux->size[1];
  emxEnsureCapacity((emxArray__common *)flux, iy, (int32_T)sizeof(real_T));
  iyLead = b_flux->size[1];
  emxFree_real_T(&c_flux);
  for (iy = 0; iy < iyLead; iy++) {
    flux->data[iy] = b_flux->data[iy];
  }

  emxFree_real_T(&b_flux);
  b_emxInit_boolean_T(&b_x, 1);
  iy = b_x->size[0];
  b_x->size[0] = flux->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, iy, (int32_T)sizeof(boolean_T));
  iyLead = flux->size[0];
  for (iy = 0; iy < iyLead; iy++) {
    b_x->data[iy] = (flux->data[iy] < 0.0);
  }

  loop_ub = 0;
  for (d = 1; d <= b_x->size[0]; d++) {
    if (b_x->data[d - 1]) {
      loop_ub++;
    }
  }

  emxInit_int32_T(&r5, 1);
  iy = r5->size[0];
  r5->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r5, iy, (int32_T)sizeof(int32_T));
  ixLead = 0;
  for (d = 1; d <= b_x->size[0]; d++) {
    if (b_x->data[d - 1]) {
      r5->data[ixLead] = d;
      ixLead++;
    }
  }

  emxFree_boolean_T(&b_x);
  iyLead = r5->size[0];
  for (iy = 0; iy < iyLead; iy++) {
    flux->data[r5->data[iy] - 1] = 0.0;
  }

  emxFree_int32_T(&r5);
}

static void padarray(const emxArray_real_T *varargin_1, emxArray_real_T *b)
{
  real_T sizeB[2];
  int32_T i3;
  real_T b_sizeB;
  int32_T c_sizeB[2];
  int32_T outsize[2];
  int32_T loop_ub;
  for (i3 = 0; i3 < 2; i3++) {
    sizeB[i3] = 0.0;
  }

  sizeB[0] = 3.0;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    for (i3 = 0; i3 < 2; i3++) {
      b_sizeB = (real_T)varargin_1->size[i3] + 2.0 * sizeB[i3];
      sizeB[i3] = b_sizeB;
    }

    c_sizeB[0] = (int32_T)sizeB[0];
    c_sizeB[1] = (int32_T)sizeB[1];
    for (i3 = 0; i3 < 2; i3++) {
      outsize[i3] = c_sizeB[i3];
    }

    i3 = b->size[0] * b->size[1];
    b->size[0] = outsize[0];
    emxEnsureCapacity((emxArray__common *)b, i3, (int32_T)sizeof(real_T));
    i3 = b->size[0] * b->size[1];
    b->size[1] = outsize[1];
    emxEnsureCapacity((emxArray__common *)b, i3, (int32_T)sizeof(real_T));
    loop_ub = outsize[0] * outsize[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      b->data[i3] = 0.0;
    }
  } else {
    ConstantPad(varargin_1, sizeB, b);
  }
}

static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z)
{
  int32_T i1;
  int32_T loop_ub;
  i1 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i1, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    z->data[i1] = x->data[i1] / y;
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

void computeOnsetFeatures(const emxArray_real_T *denoisedSpectrum, const
  emxArray_real_T *T, real_T ioiFeatures[12], emxArray_boolean_T *onsets)
{
  emxArray_real_T *unusedU0;
  emxArray_boolean_T *b_onsets;
  int32_T i;
  int32_T loop_ub;
  real_T ioiHist[17];
  boolean_T bv0[12];
  int32_T tmp_size[1];
  int32_T tmp_data[12];
  emxInit_real_T(&unusedU0, 2);
  emxInit_boolean_T(&b_onsets, 2);

  /* COMPUTEONSETFEATURES Computes onset features */
  onsetDetection(denoisedSpectrum, onsets, unusedU0);

  /*  Collecting number of onsets per 2 second window */
  /* onsetFeatures1 = onsetFeatures(onsets,T); */
  /*  Collect IOI histogram */
  i = b_onsets->size[0] * b_onsets->size[1];
  b_onsets->size[0] = onsets->size[0];
  b_onsets->size[1] = onsets->size[1];
  emxEnsureCapacity((emxArray__common *)b_onsets, i, (int32_T)sizeof(boolean_T));
  loop_ub = onsets->size[0] * onsets->size[1];
  emxFree_real_T(&unusedU0);
  for (i = 0; i < loop_ub; i++) {
    b_onsets->data[i] = onsets->data[i];
  }

  ioiHistogram(b_onsets, T, ioiHist);
  histogramFeatures(ioiHist, ioiFeatures);

  /* ioiFeatures = vertcat(ioiFeatures,onsetFeatures1); */
  emxFree_boolean_T(&b_onsets);
  for (i = 0; i < 12; i++) {
    bv0[i] = rtIsNaN(ioiFeatures[i]);
  }

  b_eml_li_find(bv0, tmp_data, tmp_size);
  loop_ub = tmp_size[0];
  for (i = 0; i < loop_ub; i++) {
    ioiFeatures[tmp_data[i] - 1] = 0.0;
  }

  for (i = 0; i < 12; i++) {
    bv0[i] = rtIsInf(ioiFeatures[i]);
  }

  b_eml_li_find(bv0, tmp_data, tmp_size);
  loop_ub = tmp_size[0];
  for (i = 0; i < loop_ub; i++) {
    ioiFeatures[tmp_data[i] - 1] = 0.0;
  }
}

void computeOnsetFeatures_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void computeOnsetFeatures_terminate(void)
{
  /* (no terminate code required) */
}

emxArray_boolean_T *emxCreateND_boolean_T(int32_T numDimensions, int32_T *size)
{
  emxArray_boolean_T *emx;
  int32_T numEl;
  int32_T i;
  emxInit_boolean_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (boolean_T *)calloc((uint32_T)numEl, sizeof(boolean_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

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

emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int32_T
  numDimensions, int32_T *size)
{
  emxArray_boolean_T *emx;
  int32_T numEl;
  int32_T i;
  emxInit_boolean_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = FALSE;
  return emx;
}

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

emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int32_T rows,
  int32_T cols)
{
  emxArray_boolean_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_boolean_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = FALSE;
  return emx;
}

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

emxArray_boolean_T *emxCreate_boolean_T(int32_T rows, int32_T cols)
{
  emxArray_boolean_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_boolean_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (boolean_T *)calloc((uint32_T)numEl, sizeof(boolean_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

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

void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray)
{
  emxFree_boolean_T(&emxArray);
}

//void emxDestroyArray_real_T(emxArray_real_T *emxArray)
//{
//  emxFree_real_T(&emxArray);
//}

/* End of code generation (computeOnsetFeatures.c) */
