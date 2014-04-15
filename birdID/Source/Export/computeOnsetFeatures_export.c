/*
 * computeOnsetFeatures.c
 *
 * Code generation for function 'computeOnsetFeatures'
 *
 * C source code generated on: Mon Apr 14 23:15:23 2014
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
static void b_eml_null_assignment(emxArray_boolean_T *x, const emxArray_real_T
  *idx);
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void b_power(const emxArray_real_T *a, emxArray_real_T *y);
static void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                      emxArray_real_T *z);
static void b_sqrt(emxArray_real_T *x);
static void b_std(const emxArray_real_T *varargin_1, emxArray_real_T *y);
static void b_sum(const emxArray_real_T *x, real_T y[17]);
static void bsxfun(const emxArray_real_T *a, const real_T b[17], emxArray_real_T
                   *c);
static void c_eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx);
static void c_power(const emxArray_real_T *a, emxArray_real_T *y);
static void c_std(const emxArray_real_T *varargin_1, real_T y[17]);
static void c_sum(const emxArray_real_T *x, real_T y[17]);
static void d_eml_null_assignment(emxArray_real_T *x, const boolean_T idx_data[1],
  const int32_T idx_size[2]);
static void diff(const emxArray_real_T *x, emxArray_real_T *y);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_li_find(const boolean_T x[12], int32_T y_data[12], int32_T
  y_size[1]);
static void eml_null_assignment(emxArray_boolean_T *x);
static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B, real_T Y
  [17]);
static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y,
                     emxArray_int32_T *idx);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void featureSpectralCentroid(emxArray_real_T *S, real_T feature[17]);
static void featureSpectralCrest(const emxArray_real_T *S, real_T feature[17]);
static void featureSpectralDecrease(const emxArray_real_T *S, real_T feature[17]);
static void featureSpectralKurtosis(emxArray_real_T *S, real_T feature[17]);
static void featureSpectralRolloff(const emxArray_real_T *S, real_T
  feature_data[17], int32_T feature_size[2]);
static void filter(const emxArray_real_T *x, real_T zi, emxArray_real_T *y);
static void filtfilt(const emxArray_real_T *x_in, emxArray_real_T *y_out);
static void histogramFeatures(const emxArray_real_T *ioiHist, real_T features[12]);
static void ioiHistogram(emxArray_boolean_T *onsets, const emxArray_real_T *T,
  emxArray_real_T *ioiHist);
static void onsetDetection(const emxArray_real_T *spec, emxArray_boolean_T
  *onsets, emxArray_real_T *flux);
static void onsetFlux(const emxArray_real_T *S, emxArray_real_T *flux);
static void padarray(const emxArray_real_T *varargin_1, emxArray_real_T *b);
static void power(const emxArray_real_T *a, emxArray_real_T *y);
static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z);
static void repmat(const real_T a[17], real_T m, emxArray_real_T *b);
static real_T rt_hypotd_snf(real_T u0, real_T u1);
static real_T rt_powd_snf(real_T u0, real_T u1);
static void sum(const emxArray_boolean_T *x, emxArray_real_T *y);

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

static void b_eml_null_assignment(emxArray_boolean_T *x, const emxArray_real_T
  *idx)
{
  int32_T nxin;
  int32_T k;
  emxArray_int32_T *r14;
  emxArray_boolean_T *b_x;
  emxArray_boolean_T *c_x;
  int32_T nxout;
  int32_T i17;
  int32_T k0;
  emxArray_boolean_T *b;
  nxin = x->size[0] * x->size[1];
  if (idx->size[1] == 1) {
    for (k = (int32_T)idx->data[0]; k < nxin; k++) {
      x->data[k - 1] = x->data[k];
    }

    emxInit_int32_T(&r14, 1);
    emxInit_boolean_T(&b_x, 2);
    b_emxInit_boolean_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i17 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i17, (int32_T)sizeof(boolean_T));
      for (i17 = 0; i17 < nxout; i17++) {
        c_x->data[i17] = x->data[i17];
      }

      i17 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i17, (int32_T)sizeof(boolean_T));
      i17 = 0;
      while (i17 <= 0) {
        for (i17 = 0; i17 < nxout; i17++) {
          x->data[i17] = c_x->data[i17];
        }

        i17 = 1;
      }
    } else {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i17 = r14->size[0];
      r14->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r14, i17, (int32_T)sizeof(int32_T));
      for (i17 = 0; i17 < nxout; i17++) {
        r14->data[i17] = 1 + i17;
      }

      nxout = r14->size[0];
      i17 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i17, (int32_T)sizeof(boolean_T));
      for (i17 = 0; i17 < nxout; i17++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i17] = x->data[r14->data[i17] - 1];
          k = 1;
        }
      }

      i17 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i17, (int32_T)sizeof(boolean_T));
      nxout = b_x->size[1];
      for (i17 = 0; i17 < nxout; i17++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i17] = b_x->data[k + b_x->size[0] * i17];
        }
      }
    }

    emxFree_boolean_T(&c_x);
    emxFree_boolean_T(&b_x);
    emxFree_int32_T(&r14);
  } else {
    emxInit_boolean_T(&b, 2);
    i17 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = nxin;
    emxEnsureCapacity((emxArray__common *)b, i17, (int32_T)sizeof(boolean_T));
    for (i17 = 0; i17 < nxin; i17++) {
      b->data[i17] = FALSE;
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
    emxInit_boolean_T(&b_x, 2);
    b_emxInit_boolean_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxout) {
        nxout = 0;
      }

      i17 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i17, (int32_T)sizeof(boolean_T));
      for (i17 = 0; i17 < nxout; i17++) {
        c_x->data[i17] = x->data[i17];
      }

      i17 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i17, (int32_T)sizeof(boolean_T));
      i17 = 0;
      while (i17 <= 0) {
        for (i17 = 0; i17 < nxout; i17++) {
          x->data[i17] = c_x->data[i17];
        }

        i17 = 1;
      }
    } else {
      if (1 > nxout) {
        nxout = 0;
      }

      i17 = r14->size[0];
      r14->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r14, i17, (int32_T)sizeof(int32_T));
      for (i17 = 0; i17 < nxout; i17++) {
        r14->data[i17] = 1 + i17;
      }

      nxout = r14->size[0];
      i17 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i17, (int32_T)sizeof(boolean_T));
      for (i17 = 0; i17 < nxout; i17++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i17] = x->data[r14->data[i17] - 1];
          k = 1;
        }
      }

      i17 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i17, (int32_T)sizeof(boolean_T));
      nxout = b_x->size[1];
      for (i17 = 0; i17 < nxout; i17++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i17] = b_x->data[k + b_x->size[0] * i17];
        }
      }
    }

    emxFree_boolean_T(&c_x);
    emxFree_boolean_T(&b_x);
    emxFree_int32_T(&r14);
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
  uint32_T uv2[2];
  int32_T i12;
  int32_T k;
  for (i12 = 0; i12 < 2; i12++) {
    uv2[i12] = (uint32_T)a->size[i12];
  }

  i12 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv2[0];
  y->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)y, i12, (int32_T)sizeof(real_T));
  i12 = (int32_T)uv2[0] * 17;
  for (k = 0; k < i12; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_powd_snf(a->data[(int32_T)(1.0
      + (real_T)k) - 1], 4.0);
  }
}

static void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                      emxArray_real_T *z)
{
  int32_T i13;
  int32_T loop_ub;
  i13 = z->size[0] * z->size[1];
  z->size[0] = x->size[0];
  z->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)z, i13, (int32_T)sizeof(real_T));
  loop_ub = x->size[0] * x->size[1];
  for (i13 = 0; i13 < loop_ub; i13++) {
    z->data[i13] = x->data[i13] / y->data[i13];
  }
}

static void b_sqrt(emxArray_real_T *x)
{
  int32_T i19;
  int32_T k;
  i19 = x->size[1];
  for (k = 0; k < i19; k++) {
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
  ix = -16;
  iy = -1;
  for (i = 1; i <= varargin_1->size[1]; i++) {
    ix += 17;
    iy++;
    if (varargin_1->size[1] == 0) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix - 1];
      for (k = 0; k < 16; k++) {
        b_ix++;
        xbar += varargin_1->data[b_ix - 1];
      }

      xbar /= 17.0;
      b_ix = ix;
      r = varargin_1->data[ix - 1] - xbar;
      b_y = r * r;
      for (k = 0; k < 16; k++) {
        b_ix++;
        r = varargin_1->data[b_ix - 1] - xbar;
        b_y += r * r;
      }

      b_y /= 16.0;
    }

    y->data[iy] = b_y;
  }

  b_sqrt(y);
}

static void b_sum(const emxArray_real_T *x, real_T y[17])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  if (x->size[0] == 0) {
    memset(&y[0], 0, 17U * sizeof(real_T));
  } else {
    ix = -1;
    iy = -1;
    for (i = 0; i < 17; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (ixstart = 2; ixstart <= x->size[0]; ixstart++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }
}

static void bsxfun(const emxArray_real_T *a, const real_T b[17], emxArray_real_T
                   *c)
{
  emxArray_real_T *av;
  int32_T k;
  int32_T unnamed_idx_0;
  int32_T ak;
  int32_T bk;
  int32_T a_idx_0;
  int32_T b_a_idx_0;
  int32_T ck;
  emxArray_real_T *cv;
  int32_T exitg1;
  int32_T exitg2;
  b_emxInit_real_T(&av, 1);
  k = c->size[0] * c->size[1];
  c->size[0] = a->size[0];
  c->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c, k, (int32_T)sizeof(real_T));
  unnamed_idx_0 = a->size[0];
  k = av->size[0];
  av->size[0] = unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)av, k, (int32_T)sizeof(real_T));
  ak = -1;
  bk = 0;
  a_idx_0 = a->size[0];
  b_a_idx_0 = a->size[0];
  ck = 0;
  b_emxInit_real_T(&cv, 1);
  do {
    exitg1 = 0;
    unnamed_idx_0 = a->size[0];
    if ((unnamed_idx_0 > 0) && (ck <= a_idx_0 * 17 - b_a_idx_0)) {
      for (k = 1; k <= a->size[0]; k++) {
        av->data[k - 1] = a->data[ak + k];
      }

      k = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, k, (int32_T)sizeof(real_T));
      unnamed_idx_0 = av->size[0];
      for (k = 0; k < unnamed_idx_0; k++) {
        cv->data[k] = av->data[k] - b[bk];
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

      ak += a->size[0];
      bk++;
      unnamed_idx_0 = a->size[0];
      ck += unnamed_idx_0;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&cv);
  emxFree_real_T(&av);
}

static void c_eml_null_assignment(emxArray_real_T *x, const emxArray_real_T *idx)
{
  int32_T nxin;
  int32_T k;
  emxArray_int32_T *r15;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  int32_T nxout;
  int32_T i18;
  int32_T k0;
  emxArray_boolean_T *b;
  nxin = x->size[0] * x->size[1];
  if (idx->size[1] == 1) {
    for (k = (int32_T)idx->data[0]; k < nxin; k++) {
      x->data[k - 1] = x->data[k];
    }

    emxInit_int32_T(&r15, 1);
    emxInit_real_T(&b_x, 2);
    b_emxInit_real_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i18 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i18, (int32_T)sizeof(real_T));
      for (i18 = 0; i18 < nxout; i18++) {
        c_x->data[i18] = x->data[i18];
      }

      i18 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i18, (int32_T)sizeof(real_T));
      i18 = 0;
      while (i18 <= 0) {
        for (i18 = 0; i18 < nxout; i18++) {
          x->data[i18] = c_x->data[i18];
        }

        i18 = 1;
      }
    } else {
      if (1 > nxin - 1) {
        nxout = 0;
      } else {
        nxout = nxin - 1;
      }

      i18 = r15->size[0];
      r15->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r15, i18, (int32_T)sizeof(int32_T));
      for (i18 = 0; i18 < nxout; i18++) {
        r15->data[i18] = 1 + i18;
      }

      nxout = r15->size[0];
      i18 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i18, (int32_T)sizeof(real_T));
      for (i18 = 0; i18 < nxout; i18++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i18] = x->data[r15->data[i18] - 1];
          k = 1;
        }
      }

      i18 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i18, (int32_T)sizeof(real_T));
      nxout = b_x->size[1];
      for (i18 = 0; i18 < nxout; i18++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i18] = b_x->data[k + b_x->size[0] * i18];
        }
      }
    }

    emxFree_real_T(&c_x);
    emxFree_real_T(&b_x);
    emxFree_int32_T(&r15);
  } else {
    emxInit_boolean_T(&b, 2);
    i18 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = nxin;
    emxEnsureCapacity((emxArray__common *)b, i18, (int32_T)sizeof(boolean_T));
    for (i18 = 0; i18 < nxin; i18++) {
      b->data[i18] = FALSE;
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
    emxInit_int32_T(&r15, 1);
    emxInit_real_T(&b_x, 2);
    b_emxInit_real_T(&c_x, 1);
    if ((x->size[0] != 1) && (x->size[1] == 1)) {
      if (1 > nxout) {
        nxout = 0;
      }

      i18 = c_x->size[0];
      c_x->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)c_x, i18, (int32_T)sizeof(real_T));
      for (i18 = 0; i18 < nxout; i18++) {
        c_x->data[i18] = x->data[i18];
      }

      i18 = x->size[0] * x->size[1];
      x->size[0] = nxout;
      x->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)x, i18, (int32_T)sizeof(real_T));
      i18 = 0;
      while (i18 <= 0) {
        for (i18 = 0; i18 < nxout; i18++) {
          x->data[i18] = c_x->data[i18];
        }

        i18 = 1;
      }
    } else {
      if (1 > nxout) {
        nxout = 0;
      }

      i18 = r15->size[0];
      r15->size[0] = nxout;
      emxEnsureCapacity((emxArray__common *)r15, i18, (int32_T)sizeof(int32_T));
      for (i18 = 0; i18 < nxout; i18++) {
        r15->data[i18] = 1 + i18;
      }

      nxout = r15->size[0];
      i18 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = nxout;
      emxEnsureCapacity((emxArray__common *)b_x, i18, (int32_T)sizeof(real_T));
      for (i18 = 0; i18 < nxout; i18++) {
        k = 0;
        while (k <= 0) {
          b_x->data[b_x->size[0] * i18] = x->data[r15->data[i18] - 1];
          k = 1;
        }
      }

      i18 = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = b_x->size[1];
      emxEnsureCapacity((emxArray__common *)x, i18, (int32_T)sizeof(real_T));
      nxout = b_x->size[1];
      for (i18 = 0; i18 < nxout; i18++) {
        k0 = b_x->size[0];
        for (k = 0; k < k0; k++) {
          x->data[k + x->size[0] * i18] = b_x->data[k + b_x->size[0] * i18];
        }
      }
    }

    emxFree_real_T(&c_x);
    emxFree_real_T(&b_x);
    emxFree_int32_T(&r15);
  }
}

static void c_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv3[2];
  int32_T i15;
  int32_T k;
  for (i15 = 0; i15 < 2; i15++) {
    uv3[i15] = (uint32_T)a->size[i15];
  }

  i15 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv3[0];
  y->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)y, i15, (int32_T)sizeof(real_T));
  i15 = (int32_T)uv3[0] * 17;
  for (k = 0; k < i15; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = rt_powd_snf(a->data[(int32_T)(1.0
      + (real_T)k) - 1], 3.0);
  }
}

static void c_std(const emxArray_real_T *varargin_1, real_T y[17])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  real_T b_y;
  int32_T b_ix;
  real_T xbar;
  int32_T k;
  real_T r;
  ix = 0;
  iy = -1;
  for (i = 0; i < 17; i++) {
    iy++;
    if (varargin_1->size[0] == 0) {
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

    y[iy] = b_y;
    ix += varargin_1->size[0];
  }

  for (k = 0; k < 17; k++) {
    y[k] = sqrt(y[k]);
  }
}

static void c_sum(const emxArray_real_T *x, real_T y[17])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  if (x->size[0] == 0) {
    memset(&y[0], 0, 17U * sizeof(real_T));
  } else {
    ix = -1;
    iy = -1;
    for (i = 0; i < 17; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (ixstart = 2; ixstart <= x->size[0]; ixstart++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }
}

static void d_eml_null_assignment(emxArray_real_T *x, const boolean_T idx_data[1],
  const int32_T idx_size[2])
{
  int32_T nxin;
  int32_T nxout;
  int32_T k;
  int32_T k0;
  emxArray_int32_T *r16;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  nxin = x->size[0] * x->size[1];
  nxout = 0;
  k = 1;
  while (k <= idx_size[1]) {
    nxout += idx_data[0];
    k = 2;
  }

  nxout = nxin - nxout;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx_size[1]) || (!idx_data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  emxInit_int32_T(&r16, 1);
  emxInit_real_T(&b_x, 2);
  b_emxInit_real_T(&c_x, 1);
  if ((x->size[0] != 1) && (x->size[1] == 1)) {
    if (1 > nxout) {
      nxout = 0;
    }

    nxin = c_x->size[0];
    c_x->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)c_x, nxin, (int32_T)sizeof(real_T));
    for (nxin = 0; nxin < nxout; nxin++) {
      c_x->data[nxin] = x->data[nxin];
    }

    nxin = x->size[0] * x->size[1];
    x->size[0] = nxout;
    x->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)x, nxin, (int32_T)sizeof(real_T));
    nxin = 0;
    while (nxin <= 0) {
      for (nxin = 0; nxin < nxout; nxin++) {
        x->data[nxin] = c_x->data[nxin];
      }

      nxin = 1;
    }
  } else {
    if (1 > nxout) {
      nxout = 0;
    }

    nxin = r16->size[0];
    r16->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)r16, nxin, (int32_T)sizeof(int32_T));
    for (nxin = 0; nxin < nxout; nxin++) {
      r16->data[nxin] = 1 + nxin;
    }

    nxout = r16->size[0];
    nxin = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = nxout;
    emxEnsureCapacity((emxArray__common *)b_x, nxin, (int32_T)sizeof(real_T));
    for (nxin = 0; nxin < nxout; nxin++) {
      k = 0;
      while (k <= 0) {
        b_x->data[b_x->size[0] * nxin] = x->data[r16->data[nxin] - 1];
        k = 1;
      }
    }

    nxin = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity((emxArray__common *)x, nxin, (int32_T)sizeof(real_T));
    nxout = b_x->size[1];
    for (nxin = 0; nxin < nxout; nxin++) {
      k0 = b_x->size[0];
      for (k = 0; k < k0; k++) {
        x->data[k + x->size[0] * nxin] = b_x->data[k + b_x->size[0] * nxin];
      }
    }
  }

  emxFree_real_T(&c_x);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&r16);
}

static void diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T iyLead;
  int32_T ixLead;
  emxArray_real_T *b_y1;
  real_T work_data_idx_0;
  int32_T m;
  real_T tmp1;
  real_T tmp2;
  if (x->size[0] == 0) {
    iyLead = y->size[0] * y->size[1];
    y->size[0] = 0;
    y->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)y, iyLead, (int32_T)sizeof(real_T));
  } else {
    ixLead = x->size[0] - 1;
    if (ixLead <= 1) {
    } else {
      ixLead = 1;
    }

    if (ixLead < 1) {
      iyLead = y->size[0] * y->size[1];
      y->size[0] = 0;
      y->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)y, iyLead, (int32_T)sizeof(real_T));
    } else {
      b_emxInit_real_T(&b_y1, 1);
      iyLead = b_y1->size[0];
      b_y1->size[0] = x->size[0] - 1;
      emxEnsureCapacity((emxArray__common *)b_y1, iyLead, (int32_T)sizeof(real_T));
      ixLead = 1;
      iyLead = 0;
      work_data_idx_0 = x->data[0];
      for (m = 2; m <= x->size[0]; m++) {
        tmp1 = x->data[ixLead];
        tmp2 = work_data_idx_0;
        work_data_idx_0 = tmp1;
        tmp1 -= tmp2;
        ixLead++;
        b_y1->data[iyLead] = tmp1;
        iyLead++;
      }

      ixLead = b_y1->size[0];
      iyLead = y->size[0] * y->size[1];
      y->size[0] = ixLead;
      emxEnsureCapacity((emxArray__common *)y, iyLead, (int32_T)sizeof(real_T));
      iyLead = y->size[0] * y->size[1];
      y->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)y, iyLead, (int32_T)sizeof(real_T));
      ixLead = b_y1->size[0];
      for (iyLead = 0; iyLead < ixLead; iyLead++) {
        y->data[iyLead] = b_y1->data[iyLead];
      }

      emxFree_real_T(&b_y1);
    }
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

static void eml_li_find(const boolean_T x[12], int32_T y_data[12], int32_T
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

static void eml_null_assignment(emxArray_boolean_T *x)
{
  emxArray_boolean_T *b;
  int32_T nxin;
  int32_T i16;
  int32_T k;
  int32_T nxout;
  int32_T k0;
  emxArray_int32_T *r13;
  emxArray_boolean_T *b_x;
  emxArray_boolean_T *c_x;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0] * x->size[1];
  i16 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = nxin;
  emxEnsureCapacity((emxArray__common *)b, i16, (int32_T)sizeof(boolean_T));
  for (i16 = 0; i16 < nxin; i16++) {
    b->data[i16] = FALSE;
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
  emxInit_int32_T(&r13, 1);
  emxInit_boolean_T(&b_x, 2);
  b_emxInit_boolean_T(&c_x, 1);
  if ((x->size[0] != 1) && (x->size[1] == 1)) {
    if (1 > nxout) {
      nxout = 0;
    }

    i16 = c_x->size[0];
    c_x->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)c_x, i16, (int32_T)sizeof(boolean_T));
    for (i16 = 0; i16 < nxout; i16++) {
      c_x->data[i16] = x->data[i16];
    }

    i16 = x->size[0] * x->size[1];
    x->size[0] = nxout;
    x->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)x, i16, (int32_T)sizeof(boolean_T));
    i16 = 0;
    while (i16 <= 0) {
      for (i16 = 0; i16 < nxout; i16++) {
        x->data[i16] = c_x->data[i16];
      }

      i16 = 1;
    }
  } else {
    if (1 > nxout) {
      nxout = 0;
    }

    i16 = r13->size[0];
    r13->size[0] = nxout;
    emxEnsureCapacity((emxArray__common *)r13, i16, (int32_T)sizeof(int32_T));
    for (i16 = 0; i16 < nxout; i16++) {
      r13->data[i16] = 1 + i16;
    }

    nxout = r13->size[0];
    i16 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = nxout;
    emxEnsureCapacity((emxArray__common *)b_x, i16, (int32_T)sizeof(boolean_T));
    for (i16 = 0; i16 < nxout; i16++) {
      k = 0;
      while (k <= 0) {
        b_x->data[b_x->size[0] * i16] = x->data[r13->data[i16] - 1];
        k = 1;
      }
    }

    i16 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity((emxArray__common *)x, i16, (int32_T)sizeof(boolean_T));
    nxout = b_x->size[1];
    for (i16 = 0; i16 < nxout; i16++) {
      k0 = b_x->size[0];
      for (k = 0; k < k0; k++) {
        x->data[k + x->size[0] * i16] = b_x->data[k + b_x->size[0] * i16];
      }
    }
  }

  emxFree_boolean_T(&c_x);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&r13);
}

static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B, real_T Y
  [17])
{
  emxArray_real_T *b_A;
  int32_T knt;
  int32_T loop_ub;
  real_T wj;
  real_T d0;
  real_T xnorm;
  real_T beta1;
  int32_T k;
  b_emxInit_real_T(&b_A, 1);
  knt = b_A->size[0];
  b_A->size[0] = A->size[0];
  emxEnsureCapacity((emxArray__common *)b_A, knt, (int32_T)sizeof(real_T));
  loop_ub = A->size[0];
  for (knt = 0; knt < loop_ub; knt++) {
    b_A->data[knt] = A->data[knt];
  }

  wj = b_A->data[0];
  d0 = 0.0;
  xnorm = eml_xnrm2(A->size[0] - 1, b_A, 2);
  if (xnorm != 0.0) {
    beta1 = rt_hypotd_snf(b_A->data[0], xnorm);
    if (b_A->data[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        eml_xscal(A->size[0] - 1, 9.9792015476736E+291, b_A);
        beta1 *= 9.9792015476736E+291;
        wj *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      xnorm = eml_xnrm2(A->size[0] - 1, b_A, 2);
      beta1 = rt_hypotd_snf(wj, xnorm);
      if (wj >= 0.0) {
        beta1 = -beta1;
      }

      d0 = (beta1 - wj) / beta1;
      eml_xscal(A->size[0] - 1, 1.0 / (wj - beta1), b_A);
      for (k = 1; k <= knt; k++) {
        beta1 *= 1.0020841800044864E-292;
      }

      wj = beta1;
    } else {
      d0 = (beta1 - b_A->data[0]) / beta1;
      xnorm = 1.0 / (b_A->data[0] - beta1);
      eml_xscal(A->size[0] - 1, xnorm, b_A);
      wj = beta1;
    }
  }

  b_A->data[0] = wj;
  xnorm = 0.0;
  k = 0;
  while ((k <= 0) && (!(fabs(b_A->data[0]) <= (real_T)A->size[0] * fabs
                        (b_A->data[0]) * 2.2204460492503131E-16))) {
    xnorm++;
    k = 1;
  }

  memset(&Y[0], 0, 17U * sizeof(real_T));
  if (d0 != 0.0) {
    for (k = 0; k < 17; k++) {
      wj = B->data[B->size[0] * k];
      for (loop_ub = 1; loop_ub - 1 <= A->size[0] - 2; loop_ub++) {
        wj += b_A->data[loop_ub] * B->data[loop_ub + B->size[0] * k];
      }

      wj *= d0;
      if (wj != 0.0) {
        B->data[B->size[0] * k] -= wj;
        for (loop_ub = 1; loop_ub - 1 <= A->size[0] - 2; loop_ub++) {
          B->data[loop_ub + B->size[0] * k] -= b_A->data[loop_ub] * wj;
        }
      }
    }
  }

  for (k = 0; k < 17; k++) {
    for (loop_ub = 0; loop_ub < (int32_T)xnorm; loop_ub++) {
      Y[k] = B->data[B->size[0] * k];
    }

    for (loop_ub = 0; loop_ub < (int32_T)-(1.0 + (-1.0 - xnorm)); loop_ub++) {
      Y[k] /= b_A->data[0];
    }
  }

  emxFree_real_T(&b_A);
}

static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y,
                     emxArray_int32_T *idx)
{
  int32_T ix;
  int32_T i;
  uint32_T uv0[2];
  int32_T i2;
  int32_T b_i;
  int32_T i1;
  real_T vwork[17];
  int32_T k;
  int8_T iidx[17];
  boolean_T p;
  int8_T idx0[17];
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  for (ix = 0; ix < 2; ix++) {
    i = y->size[0] * y->size[1];
    y->size[ix] = x->size[ix];
    emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(real_T));
  }

  for (ix = 0; ix < 2; ix++) {
    uv0[ix] = (uint32_T)x->size[ix];
  }

  ix = idx->size[0] * idx->size[1];
  idx->size[0] = 17;
  idx->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)idx, ix, (int32_T)sizeof(int32_T));
  i2 = 1;
  for (b_i = 1; b_i <= x->size[1]; b_i++) {
    i1 = i2 - 1;
    i2 += 17;
    ix = i1;
    for (k = 0; k < 17; k++) {
      vwork[k] = x->data[ix];
      ix++;
    }

    for (k = 0; k < 17; k++) {
      iidx[k] = (int8_T)(k + 1);
    }

    for (k = 0; k < 15; k += 2) {
      if ((vwork[k] <= vwork[k + 1]) || rtIsNaN(vwork[k + 1])) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      if (p) {
      } else {
        iidx[k] = (int8_T)(k + 2);
        iidx[k + 1] = (int8_T)(k + 1);
      }
    }

    for (i = 0; i < 17; i++) {
      idx0[i] = 1;
    }

    i = 2;
    while (i < 17) {
      ix = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < 18; pEnd = qEnd + i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + ix;
        if (qEnd > 18) {
          qEnd = 18;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((vwork[iidx[b_p - 1] - 1] <= vwork[iidx[q] - 1]) || rtIsNaN
              (vwork[iidx[q] - 1])) {
            p = TRUE;
          } else {
            p = FALSE;
          }

          if (p) {
            idx0[k] = iidx[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                idx0[k] = iidx[q];
                q++;
              }
            }
          } else {
            idx0[k] = iidx[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                k++;
                idx0[k] = iidx[b_p - 1];
                b_p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          iidx[(j + k) - 1] = idx0[k];
        }

        j = qEnd;
      }

      i = ix;
    }

    ix = i1;
    for (k = 0; k < 17; k++) {
      y->data[ix] = vwork[iidx[k] - 1];
      idx->data[ix] = iidx[k];
      ix++;
    }
  }
}

static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  if (n == 1) {
    y = fabs(x->data[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x->data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x)
{
  int32_T k;
  for (k = 1; k + 1 <= n + 1; k++) {
    x->data[k] *= a;
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

static void featureSpectralCentroid(emxArray_real_T *S, real_T feature[17])
{
  emxArray_real_T *b_S;
  int32_T i6;
  int32_T nm1d2;
  int32_T ar;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *y;
  int32_T br;
  int32_T ic;
  int32_T ib;
  int32_T ia;
  real_T b_y[17];
  emxInit_real_T(&b_S, 2);

  /* FEATURESPECTRALCENTROID Computes spectral centroid feature */
  /*  It is the mass center of the spectrum */
  /* [r,c] = size(S); */
  /* feature = sum(repmat((1:r)',1,c).* S)./sum(S); */
  i6 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = S->size[0];
  b_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_S, i6, (int32_T)sizeof(real_T));
  nm1d2 = S->size[0] * S->size[1];
  for (i6 = 0; i6 < nm1d2; i6++) {
    b_S->data[i6] = S->data[i6];
  }

  power(b_S, S);
  emxFree_real_T(&b_S);
  if ((real_T)S->size[0] - 1.0 < 0.0) {
    ar = -1;
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

    ar = (int32_T)ndbl - 1;
  }

  emxInit_real_T(&y, 2);
  i6 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ar + 1;
  emxEnsureCapacity((emxArray__common *)y, i6, (int32_T)sizeof(real_T));
  if (ar + 1 > 0) {
    y->data[0] = 0.0;
    if (ar + 1 > 1) {
      y->data[ar] = apnd;
      nm1d2 = ar / 2;
      for (br = 1; br < nm1d2; br++) {
        y->data[br] = br;
        y->data[ar - br] = apnd - (real_T)br;
      }

      if (nm1d2 << 1 == ar) {
        y->data[nm1d2] = apnd / 2.0;
      } else {
        y->data[nm1d2] = nm1d2;
        y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  if ((y->size[1] == 1) || (S->size[0] == 1)) {
    for (i6 = 0; i6 < 17; i6++) {
      feature[i6] = 0.0;
      nm1d2 = y->size[1];
      for (br = 0; br < nm1d2; br++) {
        ndbl = feature[i6] + y->data[y->size[0] * br] * S->data[br + S->size[0] *
          i6];
        feature[i6] = ndbl;
      }
    }
  } else {
    memset(&feature[0], 0, 17U * sizeof(real_T));
    for (nm1d2 = 0; nm1d2 < 17; nm1d2++) {
      for (ic = nm1d2; ic + 1 <= nm1d2 + 1; ic++) {
        feature[ic] = 0.0;
      }
    }

    br = 0;
    for (nm1d2 = 0; nm1d2 < 17; nm1d2++) {
      ar = 0;
      i6 = br + y->size[1];
      for (ib = br; ib + 1 <= i6; ib++) {
        if (S->data[ib] != 0.0) {
          ia = ar;
          for (ic = nm1d2; ic + 1 <= nm1d2 + 1; ic++) {
            ia++;
            feature[ic] += S->data[ib] * y->data[ia - 1];
          }
        }

        ar++;
      }

      br += y->size[1];
    }
  }

  emxFree_real_T(&y);
  b_sum(S, b_y);
  for (i6 = 0; i6 < 17; i6++) {
    feature[i6] /= b_y[i6];
  }
}

static void featureSpectralCrest(const emxArray_real_T *S, real_T feature[17])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  int32_T ixstop;
  real_T mtmp;
  int32_T b_ix;
  boolean_T exitg1;
  real_T y[17];

  /* FEATURESPECTRALCREST Computes spectral crest */
  /*  It is a rough measure of tonality */
  ix = 0;
  iy = -1;
  for (i = 0; i < 17; i++) {
    ixstart = ix + 1;
    ixstop = ix + S->size[0];
    mtmp = S->data[ix];
    if (S->size[0] > 1) {
      if (rtIsNaN(S->data[ix])) {
        b_ix = ix + 1;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (b_ix + 1 <= ixstop)) {
          ixstart = b_ix + 1;
          if (!rtIsNaN(S->data[b_ix])) {
            mtmp = S->data[b_ix];
            exitg1 = TRUE;
          } else {
            b_ix++;
          }
        }
      }

      if (ixstart < ixstop) {
        while (ixstart + 1 <= ixstop) {
          if (S->data[ixstart] > mtmp) {
            mtmp = S->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    iy++;
    feature[iy] = mtmp;
    ix += S->size[0];
  }

  b_sum(S, y);
  for (ix = 0; ix < 17; ix++) {
    feature[ix] /= y[ix];
  }
}

static void featureSpectralDecrease(const emxArray_real_T *S, real_T feature[17])
{
  int32_T cdiff;
  int32_T apnd;
  int32_T ndbl;
  emxArray_real_T *k;
  int32_T i8;
  int32_T ar;
  real_T b_S[17];
  emxArray_real_T *b;
  int32_T i9;
  int32_T i10;
  real_T b_feature;
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
  i8 = k->size[0] * k->size[1];
  k->size[0] = 1;
  k->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)k, i8, (int32_T)sizeof(real_T));
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
  i8 = k->size[0] * k->size[1];
  k->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)k, i8, (int32_T)sizeof(real_T));
  ar = k->size[0];
  ndbl = k->size[1];
  ndbl *= ar;
  for (i8 = 0; i8 < ndbl; i8++) {
    k->data[i8] = 1.0 / k->data[i8];
  }

  /*  compute slope */
  for (i8 = 0; i8 < 17; i8++) {
    b_S[i8] = S->data[S->size[0] * i8];
  }

  emxInit_real_T(&b, 2);
  repmat(b_S, S->size[0], b);
  if (2 > S->size[0]) {
    i8 = 0;
    i9 = 0;
  } else {
    i8 = 1;
    i9 = S->size[0];
  }

  i10 = b->size[0] * b->size[1];
  b->size[0] = S->size[0];
  b->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b, i10, (int32_T)sizeof(real_T));
  ndbl = S->size[0] * S->size[1];
  for (i10 = 0; i10 < ndbl; i10++) {
    b->data[i10] = S->data[i10] - b->data[i10];
  }

  if ((k->size[1] == 1) || (b->size[0] == 1)) {
    for (i10 = 0; i10 < 17; i10++) {
      feature[i10] = 0.0;
      ndbl = k->size[1];
      for (cdiff = 0; cdiff < ndbl; cdiff++) {
        b_feature = feature[i10] + k->data[k->size[0] * cdiff] * b->data[cdiff +
          b->size[0] * i10];
        feature[i10] = b_feature;
      }
    }
  } else {
    memset(&feature[0], 0, 17U * sizeof(real_T));
    for (ndbl = 0; ndbl < 17; ndbl++) {
      for (ic = ndbl; ic + 1 <= ndbl + 1; ic++) {
        feature[ic] = 0.0;
      }
    }

    cdiff = 0;
    for (ndbl = 0; ndbl < 17; ndbl++) {
      ar = 0;
      i10 = cdiff + k->size[1];
      for (apnd = cdiff; apnd + 1 <= i10; apnd++) {
        if (b->data[apnd] != 0.0) {
          ia = ar;
          for (ic = ndbl; ic + 1 <= ndbl + 1; ic++) {
            ia++;
            feature[ic] += b->data[apnd] * k->data[ia - 1];
          }
        }

        ar++;
      }

      cdiff += k->size[1];
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&k);
  emxInit_real_T(&c_S, 2);
  i10 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = i9 - i8;
  c_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c_S, i10, (int32_T)sizeof(real_T));
  for (i10 = 0; i10 < 17; i10++) {
    ndbl = i9 - i8;
    for (cdiff = 0; cdiff < ndbl; cdiff++) {
      c_S->data[cdiff + c_S->size[0] * i10] = S->data[(i8 + cdiff) + S->size[0] *
        i10];
    }
  }

  b_sum(c_S, b_S);
  emxFree_real_T(&c_S);
  for (i8 = 0; i8 < 17; i8++) {
    feature[i8] /= b_S[i8];
  }
}

static void featureSpectralKurtosis(emxArray_real_T *S, real_T feature[17])
{
  real_T sigma[17];
  real_T x[17];
  int32_T b_S;
  real_T b_x[17];
  int32_T i11;
  emxArray_real_T *c_S;
  int32_T loop_ub;
  emxArray_real_T *a;
  emxArray_real_T *r11;
  emxArray_real_T *b_a;
  emxArray_real_T *r12;

  /* FEATURESPECTRALKURTOSIS Computes the Spectral Kurtosis */
  /*    It is a measure of gaussianity of a spectrum */
  c_std(S, sigma);

  /*  Subtracting means */
  b_sum(S, x);
  b_S = S->size[0];
  for (i11 = 0; i11 < 17; i11++) {
    b_x[i11] = x[i11] / (real_T)b_S;
  }

  emxInit_real_T(&c_S, 2);
  i11 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = S->size[0];
  c_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c_S, i11, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    c_S->data[i11] = S->data[i11];
  }

  emxInit_real_T(&a, 2);
  emxInit_real_T(&r11, 2);
  emxInit_real_T(&b_a, 2);
  bsxfun(c_S, b_x, S);
  repmat(sigma, S->size[0], r11);
  b_power(r11, a);
  b_power(S, r11);
  i11 = b_a->size[0] * b_a->size[1];
  b_a->size[0] = a->size[0];
  b_a->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_a, i11, (int32_T)sizeof(real_T));
  b_S = S->size[0];
  loop_ub = a->size[0] * a->size[1];
  emxFree_real_T(&c_S);
  for (i11 = 0; i11 < loop_ub; i11++) {
    b_a->data[i11] = a->data[i11] * (real_T)b_S;
  }

  emxFree_real_T(&a);
  emxInit_real_T(&r12, 2);
  i11 = r12->size[0] * r12->size[1];
  r12->size[0] = r11->size[0];
  r12->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)r12, i11, (int32_T)sizeof(real_T));
  loop_ub = r11->size[0] * r11->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    r12->data[i11] = r11->data[i11];
  }

  b_rdivide(r12, b_a, r11);
  c_sum(r11, feature);
  emxFree_real_T(&r12);
  emxFree_real_T(&b_a);
  emxFree_real_T(&r11);
}

static void featureSpectralRolloff(const emxArray_real_T *S, real_T
  feature_data[17], int32_T feature_size[2])
{
  real_T mag[17];
  int32_T i14;
  int32_T dim;
  emxArray_real_T *x;
  int32_T vstride;
  int32_T k;
  int32_T npages;
  int32_T ix;
  int32_T i;
  int32_T ixstart;
  int32_T bk;
  real_T s;
  emxArray_boolean_T *b_S;
  emxArray_real_T *av;
  int32_T ck;
  emxArray_boolean_T *cv;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T mtmp;
  boolean_T b_x[17];
  int8_T y_data[17];
  emxArray_boolean_T *c_S;
  uint32_T outsz[2];
  int32_T iindx_data[17];
  int8_T tmp_data[17];
  boolean_T a;

  /* FEATURESPECTRALROLLOFF Computes Spectral Rolloff */
  /*     Finds frequency bin where cumsum reaches 0.85 of magnitude */
  /* compute rolloff */
  b_sum(S, mag);
  for (i14 = 0; i14 < 17; i14++) {
    mag[i14] *= 0.85;
  }

  /*  Find indices where cumulative sum is greater */
  if (S->size[0] != 1) {
    dim = 0;
  } else {
    dim = 1;
  }

  emxInit_real_T(&x, 2);
  i14 = x->size[0] * x->size[1];
  x->size[0] = S->size[0];
  x->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)x, i14, (int32_T)sizeof(real_T));
  vstride = S->size[0] * S->size[1];
  for (i14 = 0; i14 < vstride; i14++) {
    x->data[i14] = S->data[i14];
  }

  if ((!(S->size[0] == 0)) && (S->size[dim] > 1)) {
    vstride = 1;
    k = 1;
    while (k <= dim) {
      vstride *= S->size[0];
      k = 2;
    }

    npages = 1;
    k = dim + 2;
    while (k < 3) {
      npages *= 17;
      k = 3;
    }

    ix = -1;
    for (i = 1; i <= npages; i++) {
      ixstart = ix;
      for (bk = 1; bk <= vstride; bk++) {
        ixstart++;
        ix = ixstart;
        s = x->data[ixstart];
        for (k = 0; k <= S->size[dim] - 2; k++) {
          ix += vstride;
          s += x->data[ix];
          x->data[ix] = s;
        }
      }
    }
  }

  emxInit_boolean_T(&b_S, 2);
  b_emxInit_real_T(&av, 1);
  i14 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = x->size[0];
  b_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_S, i14, (int32_T)sizeof(boolean_T));
  vstride = x->size[0];
  i14 = av->size[0];
  av->size[0] = vstride;
  emxEnsureCapacity((emxArray__common *)av, i14, (int32_T)sizeof(real_T));
  npages = -1;
  bk = 0;
  ixstart = x->size[0];
  dim = x->size[0];
  ck = 0;
  b_emxInit_boolean_T(&cv, 1);
  do {
    exitg1 = 0;
    vstride = x->size[0];
    if ((vstride > 0) && (ck <= ixstart * 17 - dim)) {
      for (k = 1; k <= x->size[0]; k++) {
        av->data[k - 1] = x->data[npages + k];
      }

      i14 = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, i14, (int32_T)sizeof(boolean_T));
      vstride = av->size[0];
      for (i14 = 0; i14 < vstride; i14++) {
        cv->data[i14] = (av->data[i14] >= mag[bk]);
      }

      k = 1;
      do {
        exitg2 = 0;
        vstride = x->size[0];
        if (k <= vstride) {
          b_S->data[(ck + k) - 1] = cv->data[k - 1];
          k++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      npages += x->size[0];
      bk++;
      vstride = x->size[0];
      ck += vstride;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_boolean_T(&cv);
  emxFree_real_T(&av);
  emxFree_real_T(&x);

  /*  Find the maximum value */
  if (b_S->size[0] == 0) {
    memset(&mag[0], 0, 17U * sizeof(real_T));
  } else {
    ix = -1;
    dim = -1;
    for (i = 0; i < 17; i++) {
      ixstart = ix + 1;
      ix++;
      s = b_S->data[ixstart];
      for (k = 2; k <= b_S->size[0]; k++) {
        ix++;
        s += (real_T)b_S->data[ix];
      }

      dim++;
      mag[dim] = s;
    }
  }

  k = 0;
  for (i14 = 0; i14 < 17; i14++) {
    mtmp = (mag[i14] > 0.0);
    if (mtmp) {
      k++;
    }

    b_x[i14] = mtmp;
  }

  bk = 0;
  for (i = 0; i < 17; i++) {
    if (b_x[i]) {
      y_data[bk] = (int8_T)(i + 1);
      bk++;
    }
  }

  emxInit_boolean_T(&c_S, 2);
  vstride = b_S->size[0];
  i14 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = vstride;
  c_S->size[1] = k;
  emxEnsureCapacity((emxArray__common *)c_S, i14, (int32_T)sizeof(boolean_T));
  for (i14 = 0; i14 < k; i14++) {
    for (ixstart = 0; ixstart < vstride; ixstart++) {
      c_S->data[ixstart + c_S->size[0] * i14] = b_S->data[ixstart + b_S->size[0]
        * (y_data[i14] - 1)];
    }
  }

  for (i14 = 0; i14 < 2; i14++) {
    outsz[i14] = (uint32_T)c_S->size[i14];
  }

  emxFree_boolean_T(&c_S);
  vstride = (int32_T)outsz[1];
  for (i14 = 0; i14 < vstride; i14++) {
    iindx_data[i14] = 1;
  }

  ix = 1;
  dim = -1;
  for (i = 1; i <= k; i++) {
    i14 = b_S->size[0] - 1;
    vstride = ix + i14;
    i14 = b_S->size[0];
    for (ixstart = 0; ixstart < k; ixstart++) {
      tmp_data[ixstart] = y_data[ixstart];
    }

    mtmp = b_S->data[(ix - 1) % i14 + b_S->size[0] * (tmp_data[(ix - 1) / i14] -
      1)];
    npages = 1;
    i14 = b_S->size[0];
    if (i14 > 1) {
      bk = 1;
      if (ix < vstride) {
        for (ck = ix; ck + 1 <= vstride; ck++) {
          bk++;
          i14 = b_S->size[0];
          for (ixstart = 0; ixstart < k; ixstart++) {
            tmp_data[ixstart] = y_data[ixstart];
          }

          a = b_S->data[ck % i14 + b_S->size[0] * (tmp_data[ck / i14] - 1)];
          if (a > mtmp) {
            i14 = b_S->size[0];
            for (ixstart = 0; ixstart < k; ixstart++) {
              tmp_data[ixstart] = y_data[ixstart];
            }

            mtmp = b_S->data[ck % i14 + b_S->size[0] * (tmp_data[ck / i14] - 1)];
            npages = bk;
          }
        }
      }
    }

    dim++;
    iindx_data[dim] = npages;
    i14 = b_S->size[0];
    ix += i14;
  }

  emxFree_boolean_T(&b_S);
  feature_size[0] = 1;
  feature_size[1] = (int32_T)outsz[1];
  vstride = (int32_T)outsz[1];
  for (i14 = 0; i14 < vstride; i14++) {
    feature_data[i14] = iindx_data[i14];
  }
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

static void histogramFeatures(const emxArray_real_T *ioiHist, real_T features[12])
{
  emxArray_real_T *tempHist;
  emxArray_real_T *ind;
  emxArray_int32_T *iidx;
  emxArray_real_T *kmu;
  int32_T i5;
  int32_T loop_ub;
  int32_T cdiff;
  emxArray_boolean_T *b_ioiHist;
  emxArray_real_T *b_kmu;
  emxArray_real_T *c_ioiHist;
  int32_T ndbl;
  emxArray_real_T *d_ioiHist;
  real_T temp[17];
  emxArray_real_T *e_ioiHist;
  emxArray_real_T *f_ioiHist;
  emxArray_real_T *g_ioiHist;
  emxArray_real_T *S;
  int32_T temp_size[2];
  real_T x[17];
  real_T b_x[17];
  emxArray_real_T *b_S;
  emxArray_real_T *a;
  emxArray_real_T *c;
  emxArray_real_T *b_a;
  emxArray_real_T *b_c;
  int32_T apnd;
  real_T b_ndbl;
  emxArray_real_T *c_S;
  int32_T ib;
  int32_T ia;
  emxArray_real_T *b;
  emxArray_real_T *d_S;
  emxArray_real_T *e_S;
  real_T b_apnd;
  real_T b_cdiff;
  emxArray_real_T *av;
  emxArray_real_T *cv;
  int32_T exitg1;
  int32_T exitg2;
  emxArray_real_T *c_c;
  emxArray_real_T *d_c;
  emxInit_real_T(&tempHist, 2);
  emxInit_real_T(&ind, 2);
  b_emxInit_int32_T(&iidx, 2);
  emxInit_real_T(&kmu, 2);

  /* UNTITLED Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* features(1) = mean(ioiHist); */
  b_std(ioiHist, kmu);
  features[0] = kmu->data[0];
  eml_sort(ioiHist, tempHist, iidx);
  i5 = ind->size[0] * ind->size[1];
  ind->size[0] = 17;
  ind->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)ind, i5, (int32_T)sizeof(real_T));
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    ind->data[i5] = iidx->data[i5];
  }

  emxFree_int32_T(&iidx);
  features[1] = tempHist->data[17 * tempHist->size[1] - 1] / tempHist->data
    [(int32_T)((real_T)(17 * tempHist->size[1]) - 1.0) - 1];
  features[2] = ind->data[17 * ind->size[1] - 1] / ind->data[(int32_T)((real_T)
    (17 * ind->size[1]) - 1.0) - 1];
  emxFree_real_T(&ind);
  emxFree_real_T(&tempHist);
  if (0 == ioiHist->size[1]) {
    cdiff = 0;
  } else if (17 > ioiHist->size[1]) {
    cdiff = 17;
  } else {
    cdiff = ioiHist->size[1];
  }

  emxInit_boolean_T(&b_ioiHist, 2);
  i5 = b_ioiHist->size[0] * b_ioiHist->size[1];
  b_ioiHist->size[0] = 17;
  b_ioiHist->size[1] = ioiHist->size[1];
  emxEnsureCapacity((emxArray__common *)b_ioiHist, i5, (int32_T)sizeof(boolean_T));
  loop_ub = ioiHist->size[0] * ioiHist->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_ioiHist->data[i5] = (ioiHist->data[i5] == 0.0);
  }

  emxInit_real_T(&b_kmu, 2);
  sum(b_ioiHist, kmu);
  i5 = b_kmu->size[0] * b_kmu->size[1];
  b_kmu->size[0] = 1;
  b_kmu->size[1] = kmu->size[1];
  emxEnsureCapacity((emxArray__common *)b_kmu, i5, (int32_T)sizeof(real_T));
  loop_ub = kmu->size[0] * kmu->size[1];
  emxFree_boolean_T(&b_ioiHist);
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_kmu->data[i5] = kmu->data[i5];
  }

  emxInit_real_T(&c_ioiHist, 2);
  rdivide(b_kmu, cdiff, kmu);
  features[3] = kmu->data[0];
  i5 = c_ioiHist->size[0] * c_ioiHist->size[1];
  c_ioiHist->size[0] = ioiHist->size[1];
  c_ioiHist->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c_ioiHist, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&b_kmu);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      c_ioiHist->data[ndbl + c_ioiHist->size[0] * i5] = ioiHist->data[i5 +
        ioiHist->size[0] * ndbl];
    }
  }

  emxInit_real_T(&d_ioiHist, 2);
  featureSpectralCentroid(c_ioiHist, temp);
  features[4] = temp[0];
  i5 = d_ioiHist->size[0] * d_ioiHist->size[1];
  d_ioiHist->size[0] = ioiHist->size[1];
  d_ioiHist->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)d_ioiHist, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&c_ioiHist);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      d_ioiHist->data[ndbl + d_ioiHist->size[0] * i5] = ioiHist->data[i5 +
        ioiHist->size[0] * ndbl];
    }
  }

  emxInit_real_T(&e_ioiHist, 2);
  featureSpectralCrest(d_ioiHist, temp);
  features[5] = temp[0];
  i5 = e_ioiHist->size[0] * e_ioiHist->size[1];
  e_ioiHist->size[0] = ioiHist->size[1];
  e_ioiHist->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)e_ioiHist, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&d_ioiHist);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      e_ioiHist->data[ndbl + e_ioiHist->size[0] * i5] = ioiHist->data[i5 +
        ioiHist->size[0] * ndbl];
    }
  }

  emxInit_real_T(&f_ioiHist, 2);
  featureSpectralDecrease(e_ioiHist, temp);
  features[6] = temp[0];
  i5 = f_ioiHist->size[0] * f_ioiHist->size[1];
  f_ioiHist->size[0] = ioiHist->size[1];
  f_ioiHist->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)f_ioiHist, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&e_ioiHist);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      f_ioiHist->data[ndbl + f_ioiHist->size[0] * i5] = ioiHist->data[i5 +
        ioiHist->size[0] * ndbl];
    }
  }

  emxInit_real_T(&g_ioiHist, 2);
  featureSpectralKurtosis(f_ioiHist, temp);
  features[7] = temp[0];
  i5 = g_ioiHist->size[0] * g_ioiHist->size[1];
  g_ioiHist->size[0] = ioiHist->size[1];
  g_ioiHist->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)g_ioiHist, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&f_ioiHist);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      g_ioiHist->data[ndbl + g_ioiHist->size[0] * i5] = ioiHist->data[i5 +
        ioiHist->size[0] * ndbl];
    }
  }

  emxInit_real_T(&S, 2);
  featureSpectralRolloff(g_ioiHist, temp, temp_size);
  features[8] = temp[0];
  i5 = S->size[0] * S->size[1];
  S->size[0] = ioiHist->size[1];
  S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)S, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&g_ioiHist);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      S->data[ndbl + S->size[0] * i5] = ioiHist->data[i5 + ioiHist->size[0] *
        ndbl];
    }
  }

  /* FEATURESPECTRALSKEWNESS Compute spectral skewness */
  /*    A measure of symmettricity of pdf */
  c_std(S, temp);

  /*  Subtracting means */
  b_sum(S, x);
  cdiff = S->size[0];
  for (i5 = 0; i5 < 17; i5++) {
    b_x[i5] = x[i5] / (real_T)cdiff;
  }

  emxInit_real_T(&b_S, 2);
  i5 = b_S->size[0] * b_S->size[1];
  b_S->size[0] = S->size[0];
  b_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_S, i5, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_S->data[i5] = S->data[i5];
  }

  emxInit_real_T(&a, 2);
  emxInit_real_T(&c, 2);
  emxInit_real_T(&b_a, 2);
  bsxfun(b_S, b_x, S);
  repmat(temp, S->size[0], c);
  c_power(c, a);
  c_power(S, c);
  i5 = b_a->size[0] * b_a->size[1];
  b_a->size[0] = a->size[0];
  b_a->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_a, i5, (int32_T)sizeof(real_T));
  cdiff = S->size[0];
  loop_ub = a->size[0] * a->size[1];
  emxFree_real_T(&b_S);
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_a->data[i5] = a->data[i5] * (real_T)cdiff;
  }

  emxFree_real_T(&a);
  emxInit_real_T(&b_c, 2);
  i5 = b_c->size[0] * b_c->size[1];
  b_c->size[0] = c->size[0];
  b_c->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b_c, i5, (int32_T)sizeof(real_T));
  loop_ub = c->size[0] * c->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_c->data[i5] = c->data[i5];
  }

  b_rdivide(b_c, b_a, c);
  c_sum(c, temp);
  features[9] = temp[0];
  i5 = S->size[0] * S->size[1];
  S->size[0] = ioiHist->size[1];
  S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)S, i5, (int32_T)sizeof(real_T));
  emxFree_real_T(&b_c);
  emxFree_real_T(&b_a);
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      S->data[ndbl + S->size[0] * i5] = ioiHist->data[i5 + ioiHist->size[0] *
        ndbl];
    }
  }

  /* FUNCTIONSPECTRALSLOPE Computes the spectral slope */
  /*  */
  /*  compute index vector */
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

  i5 = kmu->size[0] * kmu->size[1];
  kmu->size[0] = 1;
  kmu->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)kmu, i5, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    kmu->data[0] = 0.0;
    if (cdiff + 1 > 1) {
      kmu->data[cdiff] = apnd;
      ndbl = cdiff / 2;
      for (loop_ub = 1; loop_ub < ndbl; loop_ub++) {
        kmu->data[loop_ub] = loop_ub;
        kmu->data[cdiff - loop_ub] = apnd - loop_ub;
      }

      if (ndbl << 1 == cdiff) {
        kmu->data[ndbl] = (real_T)apnd / 2.0;
      } else {
        kmu->data[ndbl] = ndbl;
        kmu->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  b_ndbl = (real_T)S->size[0] / 2.0;
  i5 = kmu->size[0] * kmu->size[1];
  kmu->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)kmu, i5, (int32_T)sizeof(real_T));
  cdiff = kmu->size[0];
  ndbl = kmu->size[1];
  loop_ub = cdiff * ndbl;
  for (i5 = 0; i5 < loop_ub; i5++) {
    kmu->data[i5] -= b_ndbl;
  }

  /*  compute slope */
  b_sum(S, x);
  cdiff = S->size[0];
  for (i5 = 0; i5 < 17; i5++) {
    b_x[i5] = x[i5] / (real_T)cdiff;
  }

  emxInit_real_T(&c_S, 2);
  i5 = c_S->size[0] * c_S->size[1];
  c_S->size[0] = S->size[0];
  c_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c_S, i5, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    c_S->data[i5] = S->data[i5];
  }

  bsxfun(c_S, b_x, S);
  emxFree_real_T(&c_S);
  if ((kmu->size[1] == 1) || (S->size[0] == 1)) {
    for (i5 = 0; i5 < 17; i5++) {
      x[i5] = 0.0;
      loop_ub = kmu->size[1];
      for (ndbl = 0; ndbl < loop_ub; ndbl++) {
        b_ndbl = x[i5] + kmu->data[kmu->size[0] * ndbl] * S->data[ndbl + S->
          size[0] * i5];
        x[i5] = b_ndbl;
      }
    }
  } else {
    memset(&x[0], 0, 17U * sizeof(real_T));
    for (ndbl = 0; ndbl < 17; ndbl++) {
      for (loop_ub = ndbl; loop_ub + 1 <= ndbl + 1; loop_ub++) {
        x[loop_ub] = 0.0;
      }
    }

    cdiff = 0;
    for (ndbl = 0; ndbl < 17; ndbl++) {
      apnd = 0;
      i5 = cdiff + kmu->size[1];
      for (ib = cdiff; ib + 1 <= i5; ib++) {
        if (S->data[ib] != 0.0) {
          ia = apnd;
          for (loop_ub = ndbl; loop_ub + 1 <= ndbl + 1; loop_ub++) {
            ia++;
            x[loop_ub] += S->data[ib] * kmu->data[ia - 1];
          }
        }

        apnd++;
      }

      cdiff += kmu->size[1];
    }
  }

  b_emxInit_real_T(&b, 1);
  i5 = b->size[0];
  b->size[0] = kmu->size[1];
  emxEnsureCapacity((emxArray__common *)b, i5, (int32_T)sizeof(real_T));
  loop_ub = kmu->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b->data[i5] = kmu->data[i5];
  }

  if ((kmu->size[1] == 1) || (b->size[0] == 1)) {
    b_ndbl = 0.0;
    for (i5 = 0; i5 < kmu->size[1]; i5++) {
      b_ndbl += kmu->data[kmu->size[0] * i5] * b->data[i5];
    }
  } else {
    b_ndbl = 0.0;
    if (kmu->size[1] < 1) {
    } else {
      for (loop_ub = 0; loop_ub + 1 <= kmu->size[1]; loop_ub++) {
        b_ndbl += kmu->data[loop_ub] * b->data[loop_ub];
      }
    }
  }

  features[10] = x[0] / b_ndbl;
  i5 = S->size[0] * S->size[1];
  S->size[0] = ioiHist->size[1];
  S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)S, i5, (int32_T)sizeof(real_T));
  for (i5 = 0; i5 < 17; i5++) {
    loop_ub = ioiHist->size[1];
    for (ndbl = 0; ndbl < loop_ub; ndbl++) {
      S->data[ndbl + S->size[0] * i5] = ioiHist->data[i5 + ioiHist->size[0] *
        ndbl];
    }
  }

  emxInit_real_T(&d_S, 2);

  /*  FEATURESPECTRALSPREAD Computes spectral spread */
  /*    Concentration of energy around spectral centroid */
  i5 = d_S->size[0] * d_S->size[1];
  d_S->size[0] = S->size[0];
  d_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)d_S, i5, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    d_S->data[i5] = S->data[i5];
  }

  emxInit_real_T(&e_S, 2);
  featureSpectralCentroid(d_S, temp);
  i5 = e_S->size[0] * e_S->size[1];
  e_S->size[0] = S->size[0];
  e_S->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)e_S, i5, (int32_T)sizeof(real_T));
  loop_ub = S->size[0] * S->size[1];
  emxFree_real_T(&d_S);
  for (i5 = 0; i5 < loop_ub; i5++) {
    e_S->data[i5] = S->data[i5];
  }

  power(e_S, S);
  emxFree_real_T(&e_S);
  if ((real_T)S->size[0] - 1.0 < 0.0) {
    cdiff = -1;
    b_apnd = -1.0;
  } else {
    b_ndbl = floor(((real_T)S->size[0] - 1.0) + 0.5);
    b_apnd = b_ndbl;
    b_cdiff = b_ndbl - ((real_T)S->size[0] - 1.0);
    if (fabs(b_cdiff) < 4.4408920985006262E-16 * fabs((real_T)S->size[0] - 1.0))
    {
      b_ndbl++;
      b_apnd = (real_T)S->size[0] - 1.0;
    } else if (b_cdiff > 0.0) {
      b_apnd = b_ndbl - 1.0;
    } else {
      b_ndbl++;
    }

    cdiff = (int32_T)b_ndbl - 1;
  }

  i5 = kmu->size[0] * kmu->size[1];
  kmu->size[0] = 1;
  kmu->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)kmu, i5, (int32_T)sizeof(real_T));
  if (cdiff + 1 > 0) {
    kmu->data[0] = 0.0;
    if (cdiff + 1 > 1) {
      kmu->data[cdiff] = b_apnd;
      ndbl = cdiff / 2;
      for (loop_ub = 1; loop_ub < ndbl; loop_ub++) {
        kmu->data[loop_ub] = loop_ub;
        kmu->data[cdiff - loop_ub] = b_apnd - (real_T)loop_ub;
      }

      if (ndbl << 1 == cdiff) {
        kmu->data[ndbl] = b_apnd / 2.0;
      } else {
        kmu->data[ndbl] = ndbl;
        kmu->data[ndbl + 1] = b_apnd - (real_T)ndbl;
      }
    }
  }

  i5 = b->size[0];
  b->size[0] = kmu->size[1];
  emxEnsureCapacity((emxArray__common *)b, i5, (int32_T)sizeof(real_T));
  loop_ub = kmu->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b->data[i5] = kmu->data[i5];
  }

  emxFree_real_T(&kmu);
  b_emxInit_real_T(&av, 1);
  i5 = c->size[0] * c->size[1];
  c->size[0] = b->size[0];
  c->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c, i5, (int32_T)sizeof(real_T));
  cdiff = b->size[0];
  i5 = av->size[0];
  av->size[0] = cdiff;
  emxEnsureCapacity((emxArray__common *)av, i5, (int32_T)sizeof(real_T));
  cdiff = 0;
  apnd = b->size[0];
  ib = b->size[0];
  ia = 0;
  b_emxInit_real_T(&cv, 1);
  do {
    exitg1 = 0;
    ndbl = b->size[0];
    if ((ndbl > 0) && (ia <= apnd * 17 - ib)) {
      for (loop_ub = 0; loop_ub + 1 <= b->size[0]; loop_ub++) {
        av->data[loop_ub] = b->data[loop_ub];
      }

      i5 = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, i5, (int32_T)sizeof(real_T));
      loop_ub = av->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        cv->data[i5] = av->data[i5] - temp[cdiff];
      }

      loop_ub = 0;
      do {
        exitg2 = 0;
        ndbl = b->size[0];
        if (loop_ub + 1 <= ndbl) {
          c->data[ia + loop_ub] = cv->data[loop_ub];
          loop_ub++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      cdiff++;
      ndbl = b->size[0];
      ia += ndbl;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&cv);
  emxFree_real_T(&av);
  emxFree_real_T(&b);
  emxInit_real_T(&c_c, 2);
  i5 = c_c->size[0] * c_c->size[1];
  c_c->size[0] = c->size[0];
  c_c->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)c_c, i5, (int32_T)sizeof(real_T));
  loop_ub = c->size[0] * c->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    c_c->data[i5] = c->data[i5];
  }

  emxInit_real_T(&d_c, 2);
  power(c_c, c);
  i5 = d_c->size[0] * d_c->size[1];
  d_c->size[0] = c->size[0];
  d_c->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)d_c, i5, (int32_T)sizeof(real_T));
  loop_ub = c->size[0] * c->size[1];
  emxFree_real_T(&c_c);
  for (i5 = 0; i5 < loop_ub; i5++) {
    d_c->data[i5] = c->data[i5] * S->data[i5];
  }

  emxFree_real_T(&c);
  c_sum(d_c, temp);
  c_sum(S, x);
  emxFree_real_T(&d_c);
  emxFree_real_T(&S);
  for (i5 = 0; i5 < 17; i5++) {
    temp[i5] = sqrt(temp[i5] / x[i5]);
  }

  features[11] = temp[0];
}

static void ioiHistogram(emxArray_boolean_T *onsets, const emxArray_real_T *T,
  emxArray_real_T *ioiHist)
{
  int32_T n;
  int32_T k;
  int32_T mid_i;
  emxArray_int32_T *y;
  int32_T ix;
  int32_T j;
  emxArray_real_T *b_T;
  int32_T ixstart;
  emxArray_real_T *ioi;
  emxArray_real_T *r10;
  int32_T sz[2];
  real_T stdIOI_data[1];
  int32_T stdIOI_size[2];
  real_T s;
  emxArray_real_T *b_y;
  emxArray_real_T b_stdIOI_data;
  real_T meanIOI_data[1];
  real_T c_y;
  real_T r;
  int32_T tmp_size[2];
  boolean_T tmp_data[1];
  real_T histEdges[17];
  int32_T exitg1;
  int32_T xind;
  int32_T yind;
  emxArray_real_T *A;
  emxArray_real_T *B;

  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Setting the first one as true */
  onsets->data[0] = TRUE;

  /* onsetInd = onsets; */
  n = onsets->size[0] * onsets->size[1];
  k = 0;
  for (mid_i = 1; mid_i <= n; mid_i++) {
    if (onsets->data[mid_i - 1]) {
      k++;
    }
  }

  emxInit_int32_T(&y, 1);
  ix = y->size[0];
  y->size[0] = k;
  emxEnsureCapacity((emxArray__common *)y, ix, (int32_T)sizeof(int32_T));
  j = 0;
  for (mid_i = 1; mid_i <= n; mid_i++) {
    if (onsets->data[mid_i - 1]) {
      y->data[j] = mid_i;
      j++;
    }
  }

  b_emxInit_real_T(&b_T, 1);
  ix = b_T->size[0];
  b_T->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)b_T, ix, (int32_T)sizeof(real_T));
  ixstart = y->size[0];
  for (ix = 0; ix < ixstart; ix++) {
    b_T->data[ix] = T->data[y->data[ix] - 1];
  }

  emxFree_int32_T(&y);
  emxInit_real_T(&ioi, 2);
  emxInit_real_T(&r10, 2);
  diff(b_T, r10);
  ix = ioi->size[0] * ioi->size[1];
  ioi->size[0] = r10->size[0];
  ioi->size[1] = r10->size[1];
  emxEnsureCapacity((emxArray__common *)ioi, ix, (int32_T)sizeof(real_T));
  ixstart = r10->size[0] * r10->size[1];
  emxFree_real_T(&b_T);
  for (ix = 0; ix < ixstart; ix++) {
    ioi->data[ix] = r10->data[ix];
  }

  emxFree_real_T(&r10);
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = ioi->size[ix];
  }

  stdIOI_size[0] = 1;
  stdIOI_size[1] = sz[1];
  if ((ioi->size[0] == 0) || (ioi->size[1] == 0)) {
    stdIOI_size[0] = 1;
    stdIOI_size[1] = sz[1];
    ixstart = sz[1];
    for (ix = 0; ix < ixstart; ix++) {
      stdIOI_data[ix] = 0.0;
    }
  } else {
    ix = -1;
    for (mid_i = 1; mid_i <= ioi->size[1]; mid_i++) {
      ixstart = ix + 1;
      ix++;
      s = ioi->data[ixstart];
      for (k = 2; k <= ioi->size[0]; k++) {
        ix++;
        s += ioi->data[ix];
      }

      stdIOI_data[0] = s;
    }
  }

  emxInit_real_T(&b_y, 2);
  b_stdIOI_data.data = (real_T *)&stdIOI_data;
  b_stdIOI_data.size = (int32_T *)&stdIOI_size;
  b_stdIOI_data.allocatedSize = 1;
  b_stdIOI_data.numDimensions = 2;
  b_stdIOI_data.canFreeData = FALSE;
  rdivide(&b_stdIOI_data, ioi->size[0], b_y);
  ixstart = b_y->size[0] * b_y->size[1];
  for (ix = 0; ix < ixstart; ix++) {
    meanIOI_data[ix] = b_y->data[ix];
  }

  if (ioi->size[0] > 1) {
    n = ioi->size[0] - 1;
  } else {
    n = ioi->size[0];
  }

  for (ix = 0; ix < 2; ix++) {
    sz[ix] = ioi->size[ix];
  }

  stdIOI_size[0] = 1;
  stdIOI_size[1] = sz[1];
  ix = 0;
  for (mid_i = 1; mid_i <= ioi->size[1]; mid_i++) {
    if ((ioi->size[0] == 0) || (ioi->size[1] == 0)) {
      c_y = rtNaN;
    } else {
      ixstart = ix;
      s = ioi->data[ix];
      for (k = 0; k <= ioi->size[0] - 2; k++) {
        ixstart++;
        s += ioi->data[ixstart];
      }

      s /= (real_T)ioi->size[0];
      ixstart = ix;
      r = ioi->data[ix] - s;
      c_y = r * r;
      for (k = 0; k <= ioi->size[0] - 2; k++) {
        ixstart++;
        r = ioi->data[ixstart] - s;
        c_y += r * r;
      }

      c_y /= (real_T)n;
    }

    stdIOI_data[0] = c_y;
    ix += ioi->size[0];
  }

  ix = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = stdIOI_size[1];
  emxEnsureCapacity((emxArray__common *)b_y, ix, (int32_T)sizeof(real_T));
  ixstart = stdIOI_size[0] * stdIOI_size[1];
  for (ix = 0; ix < ixstart; ix++) {
    b_y->data[ix] = stdIOI_data[ix];
  }

  b_sqrt(b_y);
  stdIOI_size[0] = 1;
  stdIOI_size[1] = b_y->size[1];
  ixstart = b_y->size[0] * b_y->size[1];
  for (ix = 0; ix < ixstart; ix++) {
    stdIOI_data[ix] = b_y->data[ix];
  }

  tmp_size[0] = ioi->size[0];
  tmp_size[1] = ioi->size[1];
  ixstart = ioi->size[0] * ioi->size[1];
  for (ix = 0; ix < ixstart; ix++) {
    tmp_data[ix] = (ioi->data[ix] > meanIOI_data[ix] + 2.0 * stdIOI_data[ix]);
  }

  d_eml_null_assignment(ioi, tmp_data, tmp_size);
  tmp_size[0] = ioi->size[0];
  tmp_size[1] = ioi->size[1];
  ixstart = ioi->size[0] * ioi->size[1];
  for (ix = 0; ix < ixstart; ix++) {
    tmp_data[ix] = (ioi->data[ix] < meanIOI_data[ix] - 2.0 * stdIOI_data[ix]);
  }

  d_eml_null_assignment(ioi, tmp_data, tmp_size);

  /* nBins = 16; */
  for (ix = 0; ix < 17; ix++) {
    histEdges[ix] = 0.125 * (real_T)ix;
  }

  histEdges[16] = rtInf;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = ioi->size[ix];
  }

  ix = ioiHist->size[0] * ioiHist->size[1];
  ioiHist->size[0] = 17;
  emxEnsureCapacity((emxArray__common *)ioiHist, ix, (int32_T)sizeof(real_T));
  ix = ioiHist->size[0] * ioiHist->size[1];
  ioiHist->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)ioiHist, ix, (int32_T)sizeof(real_T));
  ixstart = 17 * sz[1];
  for (ix = 0; ix < ixstart; ix++) {
    ioiHist->data[ix] = 0.0;
  }

  ixstart = 0;
  do {
    exitg1 = 0;
    if (ixstart < 16) {
      if (histEdges[1 + ixstart] < histEdges[ixstart]) {
        ix = ioiHist->size[0] * ioiHist->size[1];
        ioiHist->size[0] = 17;
        emxEnsureCapacity((emxArray__common *)ioiHist, ix, (int32_T)sizeof
                          (real_T));
        ix = ioiHist->size[0] * ioiHist->size[1];
        ioiHist->size[1] = sz[1];
        emxEnsureCapacity((emxArray__common *)ioiHist, ix, (int32_T)sizeof
                          (real_T));
        ixstart = 17 * sz[1];
        for (ix = 0; ix < ixstart; ix++) {
          ioiHist->data[ix] = rtNaN;
        }

        exitg1 = 1;
      } else {
        ixstart++;
      }
    } else {
      xind = 0;
      yind = -1;
      for (j = 1; j <= ioi->size[1]; j++) {
        for (k = 0; k < ioi->size[0]; k++) {
          ixstart = 0;
          if (!rtIsNaN(ioi->data[xind])) {
            if ((ioi->data[xind] >= 0.0) && (ioi->data[xind] < rtInf)) {
              ixstart = 1;
              n = 2;
              ix = 17;
              while (ix > n) {
                mid_i = (ixstart + ix) >> 1;
                if (ioi->data[xind] >= histEdges[mid_i - 1]) {
                  ixstart = mid_i;
                  n = mid_i + 1;
                } else {
                  ix = mid_i;
                }
              }
            }

            if (ioi->data[xind] == rtInf) {
              ixstart = 17;
            }
          }

          if (ixstart > 0) {
            ixstart += yind;
            ioiHist->data[ixstart]++;
          }

          xind++;
        }

        yind += 17;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&ioi);
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = ioiHist->size[ix];
  }

  ix = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)b_y, ix, (int32_T)sizeof(real_T));
  if (ioiHist->size[1] == 0) {
    ix = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b_y, ix, (int32_T)sizeof(real_T));
    ix = b_y->size[0] * b_y->size[1];
    b_y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)b_y, ix, (int32_T)sizeof(real_T));
    ixstart = sz[1];
    for (ix = 0; ix < ixstart; ix++) {
      b_y->data[ix] = 0.0;
    }
  } else {
    ix = -1;
    n = -1;
    for (mid_i = 1; mid_i <= ioiHist->size[1]; mid_i++) {
      ixstart = ix + 1;
      ix++;
      s = ioiHist->data[ixstart];
      for (k = 0; k < 16; k++) {
        ix++;
        s += ioiHist->data[ix];
      }

      n++;
      b_y->data[n] = s;
    }
  }

  b_emxInit_real_T(&A, 1);
  ix = A->size[0];
  A->size[0] = b_y->size[1];
  emxEnsureCapacity((emxArray__common *)A, ix, (int32_T)sizeof(real_T));
  ixstart = b_y->size[1];
  for (ix = 0; ix < ixstart; ix++) {
    A->data[ix] = b_y->data[ix];
  }

  emxFree_real_T(&b_y);
  emxInit_real_T(&B, 2);
  ix = B->size[0] * B->size[1];
  B->size[0] = ioiHist->size[1];
  B->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)B, ix, (int32_T)sizeof(real_T));
  for (ix = 0; ix < 17; ix++) {
    ixstart = ioiHist->size[1];
    for (n = 0; n < ixstart; n++) {
      B->data[n + B->size[0] * ix] = ioiHist->data[ix + ioiHist->size[0] * n];
    }
  }

  if ((A->size[0] == 0) || (B->size[0] == 0)) {
    ix = B->size[0] * B->size[1];
    B->size[0] = 1;
    B->size[1] = 17;
    emxEnsureCapacity((emxArray__common *)B, ix, (int32_T)sizeof(real_T));
    for (ix = 0; ix < 17; ix++) {
      B->data[ix] = 0.0;
    }
  } else if (A->size[0] == 1) {
    for (j = 0; j < 17; j++) {
      if (B->data[j] != 0.0) {
        B->data[j] /= A->data[0];
      }
    }
  } else {
    eml_qrsolve(A, B, histEdges);
    ix = B->size[0] * B->size[1];
    B->size[0] = 1;
    B->size[1] = 17;
    emxEnsureCapacity((emxArray__common *)B, ix, (int32_T)sizeof(real_T));
    for (ix = 0; ix < 17; ix++) {
      B->data[ix] = histEdges[ix];
    }
  }

  emxFree_real_T(&A);
  ix = ioiHist->size[0] * ioiHist->size[1];
  ioiHist->size[0] = 17;
  ioiHist->size[1] = B->size[0];
  emxEnsureCapacity((emxArray__common *)ioiHist, ix, (int32_T)sizeof(real_T));
  ixstart = B->size[0];
  for (ix = 0; ix < ixstart; ix++) {
    for (n = 0; n < 17; n++) {
      ioiHist->data[n + ioiHist->size[0] * ix] = B->data[ix + B->size[0] * n];
    }
  }

  emxFree_real_T(&B);
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

static void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv1[2];
  int32_T i7;
  int32_T k;
  for (i7 = 0; i7 < 2; i7++) {
    uv1[i7] = (uint32_T)a->size[i7];
  }

  i7 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv1[0];
  y->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)y, i7, (int32_T)sizeof(real_T));
  i7 = (int32_T)uv1[0] * 17;
  for (k = 0; k < i7; k++) {
    y->data[(int32_T)(1.0 + (real_T)k) - 1] = a->data[(int32_T)(1.0 + (real_T)k)
      - 1] * a->data[(int32_T)(1.0 + (real_T)k) - 1];
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

static void repmat(const real_T a[17], real_T m, emxArray_real_T *b)
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
    outsize[ia] = (1 + (ia << 4)) * mv[ia];
  }

  ia = b->size[0] * b->size[1];
  b->size[0] = outsize[0];
  b->size[1] = 17;
  emxEnsureCapacity((emxArray__common *)b, ia, (int32_T)sizeof(real_T));
  if (outsize[0] == 0) {
  } else {
    ia = 1;
    ib = 0;
    iacol = 1;
    for (jcol = 0; jcol < 17; jcol++) {
      for (itilerow = 1; itilerow <= (int32_T)m; itilerow++) {
        b->data[ib] = a[iacol - 1];
        ia = iacol + 1;
        ib++;
      }

      iacol = ia;
    }
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
  if (x->size[1] == 0) {
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
      for (k = 0; k < 16; k++) {
        ix++;
        s += (real_T)x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

void computeOnsetFeatures(const emxArray_real_T *denoisedSpectrum, const
  emxArray_real_T *T, real_T ioiFeatures[12], emxArray_boolean_T *onsets)
{
  emxArray_real_T *unusedU0;
  emxArray_boolean_T *b_onsets;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *ioiHist;
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

  emxInit_real_T(&ioiHist, 2);
  ioiHistogram(b_onsets, T, ioiHist);
  histogramFeatures(ioiHist, ioiFeatures);

  /* ioiFeatures = vertcat(ioiFeatures,onsetFeatures1); */
  emxFree_boolean_T(&b_onsets);
  emxFree_real_T(&ioiHist);
  for (i = 0; i < 12; i++) {
    bv0[i] = rtIsNaN(ioiFeatures[i]);
  }

  eml_li_find(bv0, tmp_data, tmp_size);
  loop_ub = tmp_size[0];
  for (i = 0; i < loop_ub; i++) {
    ioiFeatures[tmp_data[i] - 1] = 0.0;
  }

  for (i = 0; i < 12; i++) {
    bv0[i] = rtIsInf(ioiFeatures[i]);
  }

  eml_li_find(bv0, tmp_data, tmp_size);
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
