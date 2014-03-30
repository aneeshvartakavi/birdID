/*
 * denoiseSpectrogram.c
 *
 * Code generation for function 'denoiseSpectrogram'
 *
 * C source code generated on: Sat Mar 29 23:46:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "denoiseSpectrogram.h"

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

/* Variable Definitions */
static uint32_T method;
static uint32_T state;
static uint32_T b_state[2];
static uint32_T c_state[625];
static boolean_T state_not_empty;

/* Function Declarations */
static void b_eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static real_T b_rand(void);
static void b_sqrt(emxArray_real_T *x);
static void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                   emxArray_real_T *c);
static void dot(const emxArray_real_T *a, const emxArray_real_T *b,
                emxArray_real_T *c);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static real_T eml_rand_mt19937ar(uint32_T d_state[625]);
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
static void kMeans(const emxArray_real_T *X, emxArray_real_T *L);
static void median(const emxArray_real_T *x, emxArray_real_T *y);
static void power(const emxArray_real_T *a, emxArray_real_T *y);
static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z);
static real_T rt_roundd_snf(real_T u);
static void sum(const emxArray_real_T *x, emxArray_real_T *y);
static void twister_state_vector(uint32_T mt[625], real_T seed);

/* Function Definitions */
static void b_eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T k;
  int32_T i;
  int32_T j;
  k = 0;
  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = k;
  emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(int32_T));
  j = 0;
  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
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

static real_T b_rand(void)
{
  real_T r;
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  if (method == 4U) {
    hi = (int32_T)(state / 127773U);
    test1 = 16807U * (state - hi * 127773U);
    test2 = 2836U * hi;
    if (test1 < test2) {
      state = (test1 - test2) + 2147483647U;
    } else {
      state = test1 - test2;
    }

    r = (real_T)state * 4.6566128752457969E-10;
  } else if (method == 5U) {
    test1 = 69069U * b_state[0] + 1234567U;
    test2 = b_state[1] ^ b_state[1] << 13U;
    test2 ^= test2 >> 17U;
    test2 ^= test2 << 5U;
    b_state[0] = test1;
    b_state[1] = test2;
    r = (real_T)(test1 + test2) * 2.328306436538696E-10;
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(uint32_T));
      twister_state_vector(c_state, 5489.0);
      state_not_empty = TRUE;
    }

    r = eml_rand_mt19937ar(c_state);
  }

  return r;
}

static void b_sqrt(emxArray_real_T *x)
{
  int32_T i4;
  int32_T k;
  i4 = x->size[1];
  for (k = 0; k < i4; k++) {
    x->data[k] = sqrt(x->data[k]);
  }
}

static void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                   emxArray_real_T *c)
{
  emxArray_real_T *av;
  emxArray_real_T *bv;
  int32_T k;
  int32_T csz_idx_0;
  int32_T asub;
  int32_T ak;
  int32_T a_idx_0;
  int32_T a_idx_1;
  int32_T b_a_idx_0;
  int32_T ck;
  emxArray_real_T *cv;
  int32_T exitg1;
  int32_T exitg2;
  b_emxInit_real_T(&av, 1);
  b_emxInit_real_T(&bv, 1);
  k = c->size[0] * c->size[1];
  c->size[0] = a->size[0];
  c->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)c, k, (int32_T)sizeof(real_T));
  csz_idx_0 = a->size[0];
  k = av->size[0];
  av->size[0] = csz_idx_0;
  emxEnsureCapacity((emxArray__common *)av, k, (int32_T)sizeof(real_T));
  csz_idx_0 = b->size[0];
  k = bv->size[0];
  bv->size[0] = csz_idx_0;
  emxEnsureCapacity((emxArray__common *)bv, k, (int32_T)sizeof(real_T));
  asub = 1;
  ak = 0;
  a_idx_0 = a->size[0];
  a_idx_1 = a->size[1];
  b_a_idx_0 = a->size[0];
  ck = 0;
  b_emxInit_real_T(&cv, 1);
  do {
    exitg1 = 0;
    csz_idx_0 = a->size[0];
    if ((csz_idx_0 > 0) && (ck <= a_idx_0 * a_idx_1 - b_a_idx_0)) {
      for (k = 0; k + 1 <= a->size[0]; k++) {
        av->data[k] = a->data[ak + k];
      }

      for (k = 0; k + 1 <= b->size[0]; k++) {
        bv->data[k] = b->data[k];
      }

      k = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, k, (int32_T)sizeof(real_T));
      csz_idx_0 = av->size[0];
      for (k = 0; k < csz_idx_0; k++) {
        cv->data[k] = av->data[k] - bv->data[k];
      }

      k = 0;
      do {
        exitg2 = 0;
        csz_idx_0 = a->size[0];
        if (k + 1 <= csz_idx_0) {
          c->data[ck + k] = cv->data[k];
          k++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (asub < a->size[1]) {
        ak += a->size[0];
        asub++;
      } else {
        asub = 1;
      }

      csz_idx_0 = a->size[0];
      ck += csz_idx_0;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&cv);
  emxFree_real_T(&bv);
  emxFree_real_T(&av);
}

static void dot(const emxArray_real_T *a, const emxArray_real_T *b,
                emxArray_real_T *c)
{
  uint32_T sz[2];
  int32_T i2;
  int32_T ic;
  int32_T i;
  int32_T i1;
  real_T b_c;
  int32_T iy;
  int32_T k;
  if (a->size[0] == 1) {
    for (i2 = 0; i2 < 2; i2++) {
      sz[i2] = (uint32_T)a->size[i2];
    }

    i2 = c->size[0] * c->size[1];
    c->size[0] = 1;
    c->size[1] = (int32_T)sz[1];
    emxEnsureCapacity((emxArray__common *)c, i2, (int32_T)sizeof(real_T));
    for (i2 = 0; i2 + 1 <= (int32_T)sz[1]; i2++) {
      c->data[i2] = a->data[i2] * b->data[i2];
    }
  } else {
    for (i2 = 0; i2 < 2; i2++) {
      sz[i2] = (uint32_T)a->size[i2];
    }

    i2 = c->size[0] * c->size[1];
    c->size[0] = 1;
    c->size[1] = (int32_T)sz[1];
    emxEnsureCapacity((emxArray__common *)c, i2, (int32_T)sizeof(real_T));
    i2 = 1;
    ic = -1;
    for (i = 1; i <= a->size[1]; i++) {
      i1 = i2;
      i2 += a->size[0];
      ic++;
      b_c = 0.0;
      if (a->size[0] < 1) {
      } else {
        iy = i1;
        for (k = 1; k <= a->size[0]; k++) {
          b_c += a->data[i1 - 1] * b->data[iy - 1];
          i1++;
          iy++;
        }
      }

      c->data[ic] = b_c;
    }
  }
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

static real_T eml_rand_mt19937ar(uint32_T d_state[625])
{
  real_T r;
  int32_T exitg1;
  uint32_T u[2];
  int32_T i;
  uint32_T mti;
  int32_T kk;
  uint32_T y;
  uint32_T b_y;
  uint32_T c_y;
  uint32_T d_y;
  boolean_T isvalid;
  boolean_T exitg2;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg1 = 0;
    for (i = 0; i < 2; i++) {
      u[i] = 0U;
    }

    for (i = 0; i < 2; i++) {
      mti = d_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (d_state[kk] & 2147483648U) | (d_state[1 + kk] & 2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            b_y = y >> 1U;
          } else {
            b_y = y >> 1U ^ 2567483615U;
          }

          d_state[kk] = d_state[397 + kk] ^ b_y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (d_state[227 + kk] & 2147483648U) | (d_state[228 + kk] &
            2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            c_y = y >> 1U;
          } else {
            c_y = y >> 1U ^ 2567483615U;
          }

          d_state[227 + kk] = d_state[kk] ^ c_y;
        }

        y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          d_y = y >> 1U;
        } else {
          d_y = y >> 1U ^ 2567483615U;
        }

        d_state[623] = d_state[396] ^ d_y;
        mti = 1U;
      }

      y = d_state[(int32_T)mti - 1];
      d_state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[i] = y;
    }

    r = 1.1102230246251565E-16 * ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)
                                  (u[1] >> 6U));
    if (r == 0.0) {
      if ((d_state[624] >= 1U) && (d_state[624] < 625U)) {
        isvalid = TRUE;
      } else {
        isvalid = FALSE;
      }

      if (isvalid) {
        isvalid = FALSE;
        i = 1;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (i < 625)) {
          if (d_state[i - 1] == 0U) {
            i++;
          } else {
            isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!isvalid) {
        twister_state_vector(d_state, 5489.0);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_real_T *vwork;
  int32_T vlen;
  int32_T ix;
  int32_T k;
  emxArray_int32_T *iidx;
  b_emxInit_real_T(&vwork, 1);
  vlen = x->size[1] - 1;
  ix = vwork->size[0];
  vwork->size[0] = vlen + 1;
  emxEnsureCapacity((emxArray__common *)vwork, ix, (int32_T)sizeof(real_T));
  for (ix = 0; ix < 2; ix++) {
    k = y->size[0] * y->size[1];
    y->size[ix] = x->size[ix];
    emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T));
  }

  emxInit_int32_T(&iidx, 1);
  ix = 1;
  for (k = 0; k <= vlen; k++) {
    vwork->data[k] = x->data[ix - 1];
    ix++;
  }

  eml_sort_idx(vwork, iidx);
  ix = 1;
  for (k = 0; k <= vlen; k++) {
    y->data[ix - 1] = vwork->data[iidx->data[k] - 1];
    ix++;
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

static void kMeans(const emxArray_real_T *X, emxArray_real_T *L)
{
  int32_T i1;
  int32_T i2;
  int32_T q;
  emxArray_real_T *L1;
  emxArray_real_T *D;
  emxArray_real_T *temp;
  emxArray_boolean_T *l;
  emxArray_real_T *C;
  emxArray_real_T *y;
  emxArray_real_T *A;
  emxArray_int32_T *idx;
  emxArray_int32_T *idx0;
  emxArray_real_T *r2;
  emxArray_real_T *b_temp;
  emxArray_real_T *r3;
  emxArray_real_T *b_X;
  emxArray_real_T *r4;
  emxArray_real_T *c_temp;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_real_T *d_temp;
  emxArray_real_T *c_X;
  emxArray_int32_T *b_idx;
  emxArray_real_T *d_X;
  emxArray_real_T *b_C;
  int32_T exitg2;
  int32_T outsz[2];
  int32_T k;
  boolean_T p;
  int32_T i;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T qEnd;
  int32_T kEnd;
  real_T x;
  int32_T exitg8;
  real_T xlast;
  int32_T exponent;
  int32_T ix;
  int32_T exitg1;
  boolean_T exitg4;
  boolean_T exitg3;
  int32_T exitg5;
  boolean_T exitg7;
  boolean_T b0;
  boolean_T exitg6;

  /* KMEANS Cluster multivariate data using the k-means++ algorithm. */
  /*    [L,C] = kmeans(X,k) produces a 1-by-size(X,2) vector L with one class */
  /*    label per column in X and a size(X,1)-by-k matrix C containing the */
  /*    centers corresponding to each class. */
  /*    Version: 2013-02-08 */
  /*    Authors: Laurent Sorber (Laurent.Sorber@cs.kuleuven.be) */
  /*  */
  /*    References: */
  /*    [1] J. B. MacQueen, "Some Methods for Classification and Analysis of  */
  /*        MultiVariate Observations", in Proc. of the fifth Berkeley */
  /*        Symposium on Mathematical Statistics and Probability, L. M. L. Cam */
  /*        and J. Neyman, eds., vol. 1, UC Press, 1967, pp. 281-297. */
  /*    [2] D. Arthur and S. Vassilvitskii, "k-means++: The Advantages of */
  /*        Careful Seeding", Technical Report 2006-13, Stanford InfoLab, 2006. */
  i1 = L->size[0] * L->size[1];
  L->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof(real_T));
  i2 = X->size[1];
  i1 = L->size[0] * L->size[1];
  L->size[1] = i2;
  emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof(real_T));
  q = X->size[1];
  for (i1 = 0; i1 < q; i1++) {
    L->data[i1] = 0.0;
  }

  emxInit_real_T(&L1, 2);
  i1 = L1->size[0] * L1->size[1];
  L1->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)L1, i1, (int32_T)sizeof(real_T));
  i2 = X->size[1];
  i1 = L1->size[0] * L1->size[1];
  L1->size[1] = i2;
  emxEnsureCapacity((emxArray__common *)L1, i1, (int32_T)sizeof(real_T));
  q = X->size[1];
  for (i1 = 0; i1 < q; i1++) {
    L1->data[i1] = 0.0;
  }

  emxInit_real_T(&D, 2);
  emxInit_real_T(&temp, 2);
  emxInit_boolean_T(&l, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&y, 2);
  b_emxInit_real_T(&A, 1);
  b_emxInit_int32_T(&idx, 2);
  emxInit_int32_T(&idx0, 1);
  emxInit_real_T(&r2, 2);
  b_emxInit_real_T(&b_temp, 1);
  b_emxInit_real_T(&r3, 1);
  emxInit_real_T(&b_X, 2);
  emxInit_real_T(&r4, 2);
  b_emxInit_real_T(&c_temp, 1);
  emxInit_int32_T(&r5, 1);
  emxInit_int32_T(&r6, 1);
  emxInit_real_T(&d_temp, 2);
  b_emxInit_real_T(&c_X, 1);
  b_emxInit_int32_T(&b_idx, 2);
  b_emxInit_real_T(&d_X, 1);
  emxInit_real_T(&b_C, 2);
  do {
    exitg2 = 0;
    for (i1 = 0; i1 < 2; i1++) {
      outsz[i1] = L->size[i1];
    }

    i1 = idx->size[0] * idx->size[1];
    idx->size[0] = 1;
    idx->size[1] = outsz[1];
    emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof(int32_T));
    if (L->size[1] == 0) {
    } else {
      for (k = 1; k <= L->size[1]; k++) {
        idx->data[k - 1] = k;
      }

      for (k = 1; k <= L->size[1] - 1; k += 2) {
        p = (L->data[k - 1] <= L->data[k]);
        if (p) {
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      i1 = idx0->size[0];
      idx0->size[0] = L->size[1];
      emxEnsureCapacity((emxArray__common *)idx0, i1, (int32_T)sizeof(int32_T));
      q = L->size[1];
      for (i1 = 0; i1 < q; i1++) {
        idx0->data[i1] = 1;
      }

      i = 2;
      while (i < L->size[1]) {
        i2 = i << 1;
        j = 1;
        for (pEnd = 1 + i; pEnd < L->size[1] + 1; pEnd = qEnd + i) {
          b_p = j;
          q = pEnd;
          qEnd = j + i2;
          if (qEnd > L->size[1] + 1) {
            qEnd = L->size[1] + 1;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            p = (L->data[idx->data[b_p - 1] - 1] <= L->data[idx->data[q - 1] - 1]);
            if (p) {
              idx0->data[k] = idx->data[b_p - 1];
              b_p++;
              if (b_p == pEnd) {
                while (q < qEnd) {
                  k++;
                  idx0->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              idx0->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
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
    }

    for (i1 = 0; i1 < 2; i1++) {
      outsz[i1] = L->size[i1];
    }

    i1 = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = outsz[1];
    emxEnsureCapacity((emxArray__common *)temp, i1, (int32_T)sizeof(real_T));
    for (k = 0; k + 1 <= L->size[1]; k++) {
      temp->data[k] = L->data[idx->data[k] - 1];
    }

    k = 0;
    while ((k + 1 <= L->size[1]) && rtIsInf(temp->data[k]) && (temp->data[k] <
            0.0)) {
      k++;
    }

    qEnd = k;
    k = L->size[1];
    b_p = L->size[1] - k;
    while ((k >= 1) && rtIsInf(temp->data[k - 1]) && (temp->data[k - 1] > 0.0))
    {
      k--;
    }

    pEnd = (L->size[1] - k) - b_p;
    q = -1;
    if (qEnd > 0) {
      q = 0;
    }

    i2 = (qEnd + k) - qEnd;
    while (qEnd + 1 <= i2) {
      x = temp->data[qEnd];
      do {
        exitg8 = 0;
        qEnd++;
        if (qEnd + 1 > i2) {
          exitg8 = 1;
        } else {
          xlast = fabs(x / 2.0);
          if (!rtIsInf(xlast)) {
            if (xlast <= 2.2250738585072014E-308) {
              xlast = 4.94065645841247E-324;
            } else {
              frexp(xlast, &exponent);
              xlast = ldexp(1.0, exponent - 53);
            }
          } else {
            xlast = rtNaN;
          }

          if ((fabs(x - temp->data[qEnd]) < xlast) || (rtIsInf(temp->data[qEnd])
               && rtIsInf(x) && ((temp->data[qEnd] > 0.0) == (x > 0.0)))) {
            p = TRUE;
          } else {
            p = FALSE;
          }

          if (!p) {
            exitg8 = 1;
          }
        }
      } while (exitg8 == 0);

      q++;
      temp->data[q] = x;
    }

    if (pEnd > 0) {
      q++;
      temp->data[q] = temp->data[i2];
    }

    qEnd = i2 + pEnd;
    for (j = 1; j <= b_p; j++) {
      q++;
      temp->data[q] = temp->data[(qEnd + j) - 1];
    }

    if (1 > q + 1) {
      q = -1;
    }

    i1 = r5->size[0];
    r5->size[0] = q + 1;
    emxEnsureCapacity((emxArray__common *)r5, i1, (int32_T)sizeof(int32_T));
    for (i1 = 0; i1 <= q; i1++) {
      r5->data[i1] = 1 + i1;
    }

    i2 = r5->size[0];
    i1 = d_temp->size[0] * d_temp->size[1];
    d_temp->size[0] = 1;
    d_temp->size[1] = i2;
    emxEnsureCapacity((emxArray__common *)d_temp, i1, (int32_T)sizeof(real_T));
    for (i1 = 0; i1 < i2; i1++) {
      ix = 0;
      while (ix <= 0) {
        d_temp->data[d_temp->size[0] * i1] = temp->data[r5->data[i1] - 1];
        ix = 1;
      }
    }

    i1 = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = d_temp->size[1];
    emxEnsureCapacity((emxArray__common *)temp, i1, (int32_T)sizeof(real_T));
    q = d_temp->size[1];
    for (i1 = 0; i1 < q; i1++) {
      temp->data[temp->size[0] * i1] = d_temp->data[d_temp->size[0] * i1];
    }

    if (temp->size[1] != 3) {
      /*  The k-means++ initialization. */
      xlast = b_rand();
      xlast *= (real_T)X->size[1] - 1.0;
      x = rt_roundd_snf(xlast);
      q = X->size[0];
      b_p = X->size[0];
      i1 = c_X->size[0];
      c_X->size[0] = b_p;
      emxEnsureCapacity((emxArray__common *)c_X, i1, (int32_T)sizeof(real_T));
      for (i1 = 0; i1 < b_p; i1++) {
        c_X->data[i1] = X->data[i1 + X->size[0] * ((int32_T)(1.0 + x) - 1)];
      }

      i1 = C->size[0] * C->size[1];
      C->size[0] = q;
      C->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)C, i1, (int32_T)sizeof(real_T));
      i1 = 0;
      while (i1 <= 0) {
        for (i1 = 0; i1 < q; i1++) {
          C->data[i1] = c_X->data[i1];
        }

        i1 = 1;
      }

      i1 = L->size[0] * L->size[1];
      L->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof(real_T));
      i2 = X->size[1];
      i1 = L->size[0] * L->size[1];
      L->size[1] = i2;
      emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof(real_T));
      q = X->size[1];
      for (i1 = 0; i1 < q; i1++) {
        L->data[i1] = 1.0;
      }

      i = 0;
      do {
        exitg1 = 0;
        if (i < 2) {
          i1 = D->size[0] * D->size[1];
          D->size[0] = X->size[0];
          D->size[1] = X->size[1];
          emxEnsureCapacity((emxArray__common *)D, i1, (int32_T)sizeof(real_T));
          q = X->size[1];
          for (i1 = 0; i1 < q; i1++) {
            b_p = X->size[0];
            for (ix = 0; ix < b_p; ix++) {
              D->data[ix + D->size[0] * i1] = X->data[ix + X->size[0] * i1] -
                C->data[ix + C->size[0] * ((int32_T)L->data[i1] - 1)];
            }
          }

          /*  Why is this cumsum?? Can it be just sum? */
          dot(D, D, temp);
          b_sqrt(temp);
          i2 = temp->size[1];
          if ((!(temp->size[1] == 0)) && (i2 > 1)) {
            ix = 0;
            xlast = temp->data[0];
            for (k = 0; k <= i2 - 2; k++) {
              ix++;
              xlast += temp->data[ix];
              temp->data[ix] = xlast;
            }
          }

          if (temp->data[temp->size[1] - 1] == 0.0) {
            /*  Can potentially replace this with a for loop */
            /*  for tw = i:k */
            /*     C(:,tw) = X(:,tw-1); */
            /* C(:,i:k) = X(:,ones(1,k-i+1));  */
            /*  end */
            exitg1 = 1;
          } else {
            i1 = l->size[0] * l->size[1];
            l->size[0] = 1;
            l->size[1] = temp->size[1];
            emxEnsureCapacity((emxArray__common *)l, i1, (int32_T)sizeof
                              (boolean_T));
            xlast = b_rand();
            x = temp->data[temp->size[1] - 1];
            q = temp->size[0] * temp->size[1];
            for (i1 = 0; i1 < q; i1++) {
              l->data[i1] = (xlast < temp->data[i1] / x);
            }

            i2 = l->size[1];
            if (1 <= i2) {
              k = 1;
            } else {
              k = i2;
            }

            pEnd = 0;
            i1 = idx->size[0] * idx->size[1];
            idx->size[0] = 1;
            idx->size[1] = k;
            emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                              (int32_T));
            i2 = 1;
            exitg4 = FALSE;
            while ((exitg4 == FALSE) && (i2 <= l->size[1])) {
              if (l->data[i2 - 1]) {
                pEnd = 1;
                idx->data[0] = i2;
                exitg4 = TRUE;
              } else {
                i2++;
              }
            }

            if (k == 1) {
              if (pEnd == 0) {
                i1 = idx->size[0] * idx->size[1];
                idx->size[0] = 1;
                idx->size[1] = 0;
                emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                                  (int32_T));
              }
            } else {
              if (1 > pEnd) {
                q = -1;
              } else {
                q = 0;
              }

              i1 = r6->size[0];
              r6->size[0] = q + 1;
              emxEnsureCapacity((emxArray__common *)r6, i1, (int32_T)sizeof
                                (int32_T));
              i1 = 0;
              while (i1 <= q) {
                r6->data[0] = 1;
                i1 = 1;
              }

              i2 = r6->size[0];
              i1 = b_idx->size[0] * b_idx->size[1];
              b_idx->size[0] = 1;
              b_idx->size[1] = i2;
              emxEnsureCapacity((emxArray__common *)b_idx, i1, (int32_T)sizeof
                                (int32_T));
              for (i1 = 0; i1 < i2; i1++) {
                ix = 0;
                while (ix <= 0) {
                  b_idx->data[b_idx->size[0] * i1] = idx->data[r6->data[i1] - 1];
                  ix = 1;
                }
              }

              i1 = idx->size[0] * idx->size[1];
              idx->size[0] = 1;
              idx->size[1] = b_idx->size[1];
              emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                                (int32_T));
              q = b_idx->size[1];
              for (i1 = 0; i1 < q; i1++) {
                idx->data[idx->size[0] * i1] = b_idx->data[b_idx->size[0] * i1];
              }
            }

            i1 = temp->size[0] * temp->size[1];
            temp->size[0] = 1;
            temp->size[1] = idx->size[1];
            emxEnsureCapacity((emxArray__common *)temp, i1, (int32_T)sizeof
                              (real_T));
            q = idx->size[0] * idx->size[1];
            for (i1 = 0; i1 < q; i1++) {
              temp->data[i1] = idx->data[i1];
            }

            q = X->size[0];
            b_p = X->size[0];
            i2 = (int32_T)temp->data[0];
            i1 = d_X->size[0];
            d_X->size[0] = b_p;
            emxEnsureCapacity((emxArray__common *)d_X, i1, (int32_T)sizeof
                              (real_T));
            for (i1 = 0; i1 < b_p; i1++) {
              d_X->data[i1] = X->data[i1 + X->size[0] * (i2 - 1)];
            }

            i1 = b_C->size[0] * b_C->size[1];
            b_C->size[0] = C->size[0];
            b_C->size[1] = C->size[1] + 1;
            emxEnsureCapacity((emxArray__common *)b_C, i1, (int32_T)sizeof
                              (real_T));
            b_p = C->size[1];
            for (i1 = 0; i1 < b_p; i1++) {
              i2 = C->size[0];
              for (ix = 0; ix < i2; ix++) {
                b_C->data[ix + b_C->size[0] * i1] = C->data[ix + C->size[0] * i1];
              }
            }

            i1 = 0;
            while (i1 <= 0) {
              for (i1 = 0; i1 < q; i1++) {
                b_C->data[i1 + b_C->size[0] * C->size[1]] = d_X->data[i1];
              }

              i1 = 1;
            }

            i1 = C->size[0] * C->size[1];
            C->size[0] = b_C->size[0];
            C->size[1] = b_C->size[1];
            emxEnsureCapacity((emxArray__common *)C, i1, (int32_T)sizeof(real_T));
            q = b_C->size[1];
            for (i1 = 0; i1 < q; i1++) {
              b_p = b_C->size[0];
              for (ix = 0; ix < b_p; ix++) {
                C->data[ix + C->size[0] * i1] = b_C->data[ix + b_C->size[0] * i1];
              }
            }

            /* C(:,i) = X(:,temp(1)); */
            i1 = D->size[0] * D->size[1];
            D->size[0] = C->size[1];
            D->size[1] = C->size[0];
            emxEnsureCapacity((emxArray__common *)D, i1, (int32_T)sizeof(real_T));
            q = C->size[0];
            for (i1 = 0; i1 < q; i1++) {
              b_p = C->size[1];
              for (ix = 0; ix < b_p; ix++) {
                D->data[ix + D->size[0] * i1] = C->data[i1 + C->size[0] * ix];
              }
            }

            if ((D->size[1] == 1) || (X->size[0] == 1)) {
              i1 = y->size[0] * y->size[1];
              y->size[0] = D->size[0];
              y->size[1] = X->size[1];
              emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                (real_T));
              q = D->size[0];
              for (i1 = 0; i1 < q; i1++) {
                b_p = X->size[1];
                for (ix = 0; ix < b_p; ix++) {
                  y->data[i1 + y->size[0] * ix] = 0.0;
                  i2 = D->size[1];
                  for (pEnd = 0; pEnd < i2; pEnd++) {
                    y->data[i1 + y->size[0] * ix] += D->data[i1 + D->size[0] *
                      pEnd] * X->data[pEnd + X->size[0] * ix];
                  }
                }
              }
            } else {
              outsz[0] = D->size[0];
              outsz[1] = X->size[1];
              i1 = y->size[0] * y->size[1];
              y->size[0] = outsz[0];
              emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                (real_T));
              i1 = y->size[0] * y->size[1];
              y->size[1] = outsz[1];
              emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                (real_T));
              q = outsz[0] * outsz[1];
              for (i1 = 0; i1 < q; i1++) {
                y->data[i1] = 0.0;
              }

              if (X->size[1] == 0) {
              } else {
                i2 = D->size[0] * (X->size[1] - 1);
                for (pEnd = 0; pEnd <= i2; pEnd += D->size[0]) {
                  i1 = pEnd + D->size[0];
                  for (j = pEnd; j + 1 <= i1; j++) {
                    y->data[j] = 0.0;
                  }
                }

                b_p = 0;
                for (pEnd = 0; pEnd <= i2; pEnd += D->size[0]) {
                  q = 0;
                  i1 = b_p + D->size[1];
                  for (qEnd = b_p; qEnd + 1 <= i1; qEnd++) {
                    if (X->data[qEnd] != 0.0) {
                      kEnd = q;
                      ix = pEnd + D->size[0];
                      for (j = pEnd; j + 1 <= ix; j++) {
                        kEnd++;
                        y->data[j] += X->data[qEnd] * D->data[kEnd - 1];
                      }
                    }

                    q += D->size[0];
                  }

                  b_p += D->size[1];
                }
              }
            }

            dot(C, C, temp);
            i1 = r4->size[0] * r4->size[1];
            r4->size[0] = y->size[0];
            r4->size[1] = y->size[1];
            emxEnsureCapacity((emxArray__common *)r4, i1, (int32_T)sizeof(real_T));
            q = y->size[0] * y->size[1];
            for (i1 = 0; i1 < q; i1++) {
              r4->data[i1] = 2.0 * y->data[i1];
            }

            i1 = c_temp->size[0];
            c_temp->size[0] = temp->size[1];
            emxEnsureCapacity((emxArray__common *)c_temp, i1, (int32_T)sizeof
                              (real_T));
            q = temp->size[1];
            for (i1 = 0; i1 < q; i1++) {
              c_temp->data[i1] = temp->data[i1];
            }

            bsxfun(r4, c_temp, D);
            for (i1 = 0; i1 < 2; i1++) {
              outsz[i1] = D->size[i1];
            }

            i2 = outsz[1];
            i1 = idx->size[0] * idx->size[1];
            idx->size[0] = 1;
            emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                              (int32_T));
            i1 = idx->size[0] * idx->size[1];
            idx->size[1] = outsz[1];
            emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                              (int32_T));
            for (i1 = 0; i1 < i2; i1++) {
              idx->data[i1] = 1;
            }

            ix = 0;
            i2 = -1;
            for (j = 1; j <= D->size[1]; j++) {
              pEnd = ix;
              b_p = ix + D->size[0];
              xlast = D->data[ix];
              q = 1;
              if (D->size[0] > 1) {
                qEnd = 1;
                if (rtIsNaN(D->data[ix])) {
                  kEnd = ix + 1;
                  exitg3 = FALSE;
                  while ((exitg3 == FALSE) && (kEnd + 1 <= b_p)) {
                    qEnd++;
                    pEnd = kEnd;
                    if (!rtIsNaN(D->data[kEnd])) {
                      xlast = D->data[kEnd];
                      q = qEnd;
                      exitg3 = TRUE;
                    } else {
                      kEnd++;
                    }
                  }
                }

                if (pEnd + 1 < b_p) {
                  for (kEnd = pEnd + 1; kEnd + 1 <= b_p; kEnd++) {
                    qEnd++;
                    if (D->data[kEnd] > xlast) {
                      xlast = D->data[kEnd];
                      q = qEnd;
                    }
                  }
                }
              }

              i2++;
              idx->data[i2] = q;
              ix += D->size[0];
            }

            i1 = L->size[0] * L->size[1];
            L->size[0] = 1;
            L->size[1] = idx->size[1];
            emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof(real_T));
            q = idx->size[0] * idx->size[1];
            for (i1 = 0; i1 < q; i1++) {
              L->data[i1] = idx->data[i1];
            }

            i++;
          }
        } else {
          /*  The k-means algorithm. */
          do {
            exitg5 = 0;
            i1 = l->size[0] * l->size[1];
            l->size[0] = 1;
            l->size[1] = L->size[1];
            emxEnsureCapacity((emxArray__common *)l, i1, (int32_T)sizeof
                              (boolean_T));
            q = L->size[0] * L->size[1];
            for (i1 = 0; i1 < q; i1++) {
              l->data[i1] = (L->data[i1] != L1->data[i1]);
            }

            p = FALSE;
            ix = 1;
            exitg7 = FALSE;
            while ((exitg7 == FALSE) && (ix <= l->size[1])) {
              b0 = (l->data[ix - 1] == 0);
              if (!b0) {
                p = TRUE;
                exitg7 = TRUE;
              } else {
                ix++;
              }
            }

            if (p) {
              i1 = L1->size[0] * L1->size[1];
              L1->size[0] = 1;
              L1->size[1] = L->size[1];
              emxEnsureCapacity((emxArray__common *)L1, i1, (int32_T)sizeof
                                (real_T));
              q = L->size[0] * L->size[1];
              for (i1 = 0; i1 < q; i1++) {
                L1->data[i1] = L->data[i1];
              }

              for (i = 0; i < 3; i++) {
                i1 = l->size[0] * l->size[1];
                l->size[0] = 1;
                l->size[1] = L->size[1];
                emxEnsureCapacity((emxArray__common *)l, i1, (int32_T)sizeof
                                  (boolean_T));
                q = L->size[0] * L->size[1];
                for (i1 = 0; i1 < q; i1++) {
                  l->data[i1] = (L->data[i1] == 1.0 + (real_T)i);
                }

                if (l->size[1] == 0) {
                  xlast = 0.0;
                } else {
                  xlast = l->data[0];
                  for (k = 2; k <= l->size[1]; k++) {
                    xlast += (real_T)l->data[k - 1];
                  }
                }

                b_eml_li_find(l, idx);
                q = X->size[0];
                i2 = idx->size[1];
                i1 = b_X->size[0] * b_X->size[1];
                b_X->size[0] = q;
                b_X->size[1] = i2;
                emxEnsureCapacity((emxArray__common *)b_X, i1, (int32_T)sizeof
                                  (real_T));
                for (i1 = 0; i1 < i2; i1++) {
                  for (ix = 0; ix < q; ix++) {
                    b_X->data[ix + b_X->size[0] * i1] = X->data[ix + X->size[0] *
                      (idx->data[i1] - 1)];
                  }
                }

                sum(b_X, A);
                rdivide(A, xlast, r3);
                q = r3->size[0];
                for (i1 = 0; i1 < q; i1++) {
                  C->data[i1 + C->size[0] * i] = r3->data[i1];
                }
              }

              i1 = D->size[0] * D->size[1];
              D->size[0] = C->size[1];
              D->size[1] = C->size[0];
              emxEnsureCapacity((emxArray__common *)D, i1, (int32_T)sizeof
                                (real_T));
              q = C->size[0];
              for (i1 = 0; i1 < q; i1++) {
                b_p = C->size[1];
                for (ix = 0; ix < b_p; ix++) {
                  D->data[ix + D->size[0] * i1] = C->data[i1 + C->size[0] * ix];
                }
              }

              if ((D->size[1] == 1) || (X->size[0] == 1)) {
                i1 = y->size[0] * y->size[1];
                y->size[0] = D->size[0];
                y->size[1] = X->size[1];
                emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                  (real_T));
                q = D->size[0];
                for (i1 = 0; i1 < q; i1++) {
                  b_p = X->size[1];
                  for (ix = 0; ix < b_p; ix++) {
                    y->data[i1 + y->size[0] * ix] = 0.0;
                    i2 = D->size[1];
                    for (pEnd = 0; pEnd < i2; pEnd++) {
                      y->data[i1 + y->size[0] * ix] += D->data[i1 + D->size[0] *
                        pEnd] * X->data[pEnd + X->size[0] * ix];
                    }
                  }
                }
              } else {
                outsz[0] = D->size[0];
                outsz[1] = X->size[1];
                i1 = y->size[0] * y->size[1];
                y->size[0] = outsz[0];
                emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                  (real_T));
                i1 = y->size[0] * y->size[1];
                y->size[1] = outsz[1];
                emxEnsureCapacity((emxArray__common *)y, i1, (int32_T)sizeof
                                  (real_T));
                q = outsz[0] * outsz[1];
                for (i1 = 0; i1 < q; i1++) {
                  y->data[i1] = 0.0;
                }

                if (X->size[1] == 0) {
                } else {
                  i2 = D->size[0] * (X->size[1] - 1);
                  for (pEnd = 0; pEnd <= i2; pEnd += D->size[0]) {
                    i1 = pEnd + D->size[0];
                    for (j = pEnd; j + 1 <= i1; j++) {
                      y->data[j] = 0.0;
                    }
                  }

                  b_p = 0;
                  for (pEnd = 0; pEnd <= i2; pEnd += D->size[0]) {
                    q = 0;
                    i1 = b_p + D->size[1];
                    for (qEnd = b_p; qEnd + 1 <= i1; qEnd++) {
                      if (X->data[qEnd] != 0.0) {
                        kEnd = q;
                        ix = pEnd + D->size[0];
                        for (j = pEnd; j + 1 <= ix; j++) {
                          kEnd++;
                          y->data[j] += X->data[qEnd] * D->data[kEnd - 1];
                        }
                      }

                      q += D->size[0];
                    }

                    b_p += D->size[1];
                  }
                }
              }

              dot(C, C, temp);
              i1 = r2->size[0] * r2->size[1];
              r2->size[0] = y->size[0];
              r2->size[1] = y->size[1];
              emxEnsureCapacity((emxArray__common *)r2, i1, (int32_T)sizeof
                                (real_T));
              q = y->size[0] * y->size[1];
              for (i1 = 0; i1 < q; i1++) {
                r2->data[i1] = 2.0 * y->data[i1];
              }

              i1 = b_temp->size[0];
              b_temp->size[0] = temp->size[1];
              emxEnsureCapacity((emxArray__common *)b_temp, i1, (int32_T)sizeof
                                (real_T));
              q = temp->size[1];
              for (i1 = 0; i1 < q; i1++) {
                b_temp->data[i1] = temp->data[i1];
              }

              bsxfun(r2, b_temp, D);
              for (i1 = 0; i1 < 2; i1++) {
                outsz[i1] = D->size[i1];
              }

              i2 = outsz[1];
              i1 = idx->size[0] * idx->size[1];
              idx->size[0] = 1;
              emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                                (int32_T));
              i1 = idx->size[0] * idx->size[1];
              idx->size[1] = outsz[1];
              emxEnsureCapacity((emxArray__common *)idx, i1, (int32_T)sizeof
                                (int32_T));
              for (i1 = 0; i1 < i2; i1++) {
                idx->data[i1] = 1;
              }

              ix = 0;
              i2 = -1;
              for (i = 1; i <= D->size[1]; i++) {
                pEnd = ix;
                b_p = ix + D->size[0];
                xlast = D->data[ix];
                q = 1;
                if (D->size[0] > 1) {
                  qEnd = 1;
                  if (rtIsNaN(D->data[ix])) {
                    kEnd = ix + 1;
                    exitg6 = FALSE;
                    while ((exitg6 == FALSE) && (kEnd + 1 <= b_p)) {
                      qEnd++;
                      pEnd = kEnd;
                      if (!rtIsNaN(D->data[kEnd])) {
                        xlast = D->data[kEnd];
                        q = qEnd;
                        exitg6 = TRUE;
                      } else {
                        kEnd++;
                      }
                    }
                  }

                  if (pEnd + 1 < b_p) {
                    for (kEnd = pEnd + 1; kEnd + 1 <= b_p; kEnd++) {
                      qEnd++;
                      if (D->data[kEnd] > xlast) {
                        xlast = D->data[kEnd];
                        q = qEnd;
                      }
                    }
                  }
                }

                i2++;
                idx->data[i2] = q;
                ix += D->size[0];
              }

              i1 = L->size[0] * L->size[1];
              L->size[0] = 1;
              L->size[1] = idx->size[1];
              emxEnsureCapacity((emxArray__common *)L, i1, (int32_T)sizeof
                                (real_T));
              q = idx->size[0] * idx->size[1];
              for (i1 = 0; i1 < q; i1++) {
                L->data[i1] = idx->data[i1];
              }
            } else {
              exitg5 = 1;
            }
          } while (exitg5 == 0);

          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = 1;
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_C);
  emxFree_real_T(&d_X);
  emxFree_int32_T(&b_idx);
  emxFree_real_T(&c_X);
  emxFree_real_T(&d_temp);
  emxFree_int32_T(&r6);
  emxFree_int32_T(&r5);
  emxFree_real_T(&c_temp);
  emxFree_real_T(&r4);
  emxFree_real_T(&b_X);
  emxFree_real_T(&r3);
  emxFree_real_T(&b_temp);
  emxFree_real_T(&r2);
  emxFree_int32_T(&idx0);
  emxFree_int32_T(&idx);
  emxFree_real_T(&A);
  emxFree_real_T(&y);
  emxFree_real_T(&C);
  emxFree_boolean_T(&l);
  emxFree_real_T(&temp);
  emxFree_real_T(&D);
  emxFree_real_T(&L1);
}

static void median(const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T k;
  int32_T ix;
  emxArray_real_T *vwork;
  int32_T iy;
  int32_T i1;
  int32_T j;
  emxArray_int32_T *idx;
  real_T m;
  for (k = 0; k < 2; k++) {
    sz[k] = (uint32_T)x->size[k];
  }

  k = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    k = y->size[0];
    y->size[0] = (int32_T)sz[0];
    emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T));
    ix = (int32_T)sz[0];
    for (k = 0; k < ix; k++) {
      y->data[k] = rtNaN;
    }
  } else {
    b_emxInit_real_T(&vwork, 1);
    sz[0] = (uint32_T)x->size[1];
    k = vwork->size[0];
    vwork->size[0] = (int32_T)sz[0];
    emxEnsureCapacity((emxArray__common *)vwork, k, (int32_T)sizeof(real_T));
    iy = -1;
    i1 = 0;
    j = 1;
    emxInit_int32_T(&idx, 1);
    while (j <= x->size[0]) {
      i1++;
      ix = i1;
      for (k = 0; k < x->size[1]; k++) {
        vwork->data[k] = x->data[ix - 1];
        ix += x->size[0];
      }

      iy++;
      k = vwork->size[0];
      ix = k / 2;
      eml_sort_idx(vwork, idx);
      if (rtIsNaN(vwork->data[idx->data[idx->size[0] - 1] - 1])) {
        m = vwork->data[idx->data[idx->size[0] - 1] - 1];
      } else if (ix << 1 == vwork->size[0]) {
        if (((vwork->data[idx->data[ix - 1] - 1] < 0.0) && (vwork->data
              [idx->data[ix] - 1] >= 0.0)) || rtIsInf(vwork->data[idx->data[ix -
             1] - 1]) || rtIsInf(vwork->data[idx->data[ix] - 1])) {
          m = (vwork->data[idx->data[ix - 1] - 1] + vwork->data[idx->data[ix] -
               1]) / 2.0;
        } else {
          m = vwork->data[idx->data[ix - 1] - 1] + (vwork->data[idx->data[ix] -
            1] - vwork->data[idx->data[ix - 1] - 1]) / 2.0;
        }
      } else {
        m = vwork->data[idx->data[ix] - 1];
      }

      y->data[iy] = m;
      j++;
    }

    emxFree_int32_T(&idx);
    emxFree_real_T(&vwork);
  }
}

static void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T uv0[2];
  int32_T i3;
  int32_T k;
  for (i3 = 0; i3 < 2; i3++) {
    uv0[i3] = (uint32_T)a->size[i3];
  }

  i3 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv0[0];
  y->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i3, (int32_T)sizeof(real_T));
  i3 = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (k = 0; k < i3; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

static void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z)
{
  int32_T i2;
  int32_T loop_ub;
  i2 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i2, (int32_T)sizeof(real_T));
  loop_ub = x->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    z->data[i2] = x->data[i2] / y;
  }
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

static void sum(const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  for (iy = 0; iy < 2; iy++) {
    sz[iy] = (uint32_T)x->size[iy];
  }

  iy = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    iy = y->size[0];
    y->size[0] = (int32_T)sz[0];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
    ixstart = (int32_T)sz[0];
    for (iy = 0; iy < ixstart; iy++) {
      y->data[iy] = 0.0;
    }
  } else {
    iy = -1;
    ixstart = -1;
    for (j = 1; j <= x->size[0]; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[1]; k++) {
        ix += x->size[0];
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

static void twister_state_vector(uint32_T mt[625], real_T seed)
{
  uint32_T r;
  int32_T mti;
  if (seed < 4.294967296E+9) {
    if (seed >= 0.0) {
      r = (uint32_T)seed;
    } else {
      r = 0U;
    }
  } else if (seed >= 4.294967296E+9) {
    r = MAX_uint32_T;
  } else {
    r = 0U;
  }

  mt[0] = r;
  for (mti = 0; mti < 623; mti++) {
    r = (r ^ r >> 30U) * 1812433253U + (1 + mti);
    mt[1 + mti] = r;
  }

  mt[624] = 624U;
}

void denoiseSpectrogram(emxArray_real_T *spec, emxArray_real_T *denoisedSpec)
{
  emxArray_real_T *noiseEst;
  emxArray_real_T *b_spec;
  int32_T ixstart;
  int32_T iy;
  emxArray_boolean_T *c_spec;
  emxArray_int32_T *r0;
  emxArray_real_T *clusters;
  real_T M;
  emxArray_real_T *v;
  real_T mtmp;
  int32_T ftmp;
  int32_T k;
  emxArray_boolean_T *b_clusters;
  emxArray_real_T *x;
  emxArray_int32_T *indx;
  emxArray_real_T *b_noiseEst;
  emxArray_boolean_T *b_denoisedSpec;
  int32_T outsz[2];
  int32_T ixstop;
  int32_T ix;
  boolean_T exitg4;
  boolean_T exitg3;
  emxArray_boolean_T *c_denoisedSpec;
  boolean_T exitg2;
  boolean_T exitg1;
  emxArray_boolean_T *r1;
  b_emxInit_real_T(&noiseEst, 1);
  emxInit_real_T(&b_spec, 2);

  /* DENOISESPEC Performs the custom denoising routine */
  /*   Aneesh Vartakavi */
  /*  Spectral Subtraction */
  median(spec, noiseEst);
  ixstart = b_spec->size[0] * b_spec->size[1];
  b_spec->size[0] = spec->size[0];
  b_spec->size[1] = spec->size[1];
  emxEnsureCapacity((emxArray__common *)b_spec, ixstart, (int32_T)sizeof(real_T));
  iy = spec->size[0] * spec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    b_spec->data[ixstart] = spec->data[ixstart];
  }

  emxInit_boolean_T(&c_spec, 2);
  bsxfun(b_spec, noiseEst, spec);
  ixstart = c_spec->size[0] * c_spec->size[1];
  c_spec->size[0] = spec->size[0];
  c_spec->size[1] = spec->size[1];
  emxEnsureCapacity((emxArray__common *)c_spec, ixstart, (int32_T)sizeof
                    (boolean_T));
  iy = spec->size[0] * spec->size[1];
  emxFree_real_T(&b_spec);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    c_spec->data[ixstart] = (spec->data[ixstart] < 0.0);
  }

  emxInit_int32_T(&r0, 1);
  eml_li_find(c_spec, r0);
  iy = r0->size[0];
  emxFree_boolean_T(&c_spec);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    spec->data[r0->data[ixstart] - 1] = 0.0;
  }

  emxInit_real_T(&clusters, 2);

  /*  kMeans to estimate noiss */
  kMeans(spec, clusters);
  if (clusters->size[1] == 0) {
    M = rtNaN;
  } else {
    emxInit_real_T(&v, 2);
    eml_sort(clusters, v);
    M = v->data[0];
    iy = 1;
    mtmp = v->data[0];
    ftmp = 1;
    for (k = 0; k < (int32_T)((real_T)v->size[1] + -1.0); k++) {
      if (v->data[(int32_T)(2.0 + (real_T)k) - 1] == mtmp) {
        ftmp++;
      } else {
        if (ftmp > iy) {
          M = mtmp;
          iy = ftmp;
        }

        mtmp = v->data[(int32_T)(2.0 + (real_T)k) - 1];
        ftmp = 1;
      }
    }

    emxFree_real_T(&v);
    if (ftmp > iy) {
      M = mtmp;
    }
  }

  emxInit_boolean_T(&b_clusters, 2);

  /*  Index of noisy frames */
  ixstart = b_clusters->size[0] * b_clusters->size[1];
  b_clusters->size[0] = 1;
  b_clusters->size[1] = clusters->size[1];
  emxEnsureCapacity((emxArray__common *)b_clusters, ixstart, (int32_T)sizeof
                    (boolean_T));
  iy = clusters->size[0] * clusters->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    b_clusters->data[ixstart] = (clusters->data[ixstart] == M);
  }

  emxInit_real_T(&x, 2);
  b_emxInit_int32_T(&indx, 2);
  b_eml_li_find(b_clusters, indx);
  iy = spec->size[0];
  ftmp = indx->size[1];
  ixstart = x->size[0] * x->size[1];
  x->size[0] = iy;
  x->size[1] = ftmp;
  emxEnsureCapacity((emxArray__common *)x, ixstart, (int32_T)sizeof(real_T));
  emxFree_boolean_T(&b_clusters);
  for (ixstart = 0; ixstart < ftmp; ixstart++) {
    for (k = 0; k < iy; k++) {
      x->data[k + x->size[0] * ixstart] = spec->data[k + spec->size[0] *
        (indx->data[ixstart] - 1)];
    }
  }

  emxFree_int32_T(&indx);
  b_emxInit_real_T(&b_noiseEst, 1);
  sum(x, noiseEst);
  ixstart = b_noiseEst->size[0];
  b_noiseEst->size[0] = noiseEst->size[0];
  emxEnsureCapacity((emxArray__common *)b_noiseEst, ixstart, (int32_T)sizeof
                    (real_T));
  iy = noiseEst->size[0];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    b_noiseEst->data[ixstart] = noiseEst->data[ixstart];
  }

  rdivide(b_noiseEst, x->size[1], noiseEst);

  /*  Wiener filter with kMeans as noise estimate */
  power(spec, x);
  bsxfun(x, noiseEst, denoisedSpec);
  power(spec, x);
  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = denoisedSpec->size[0];
  ftmp = denoisedSpec->size[1];
  iy *= ftmp;
  emxFree_real_T(&b_noiseEst);
  emxFree_real_T(&noiseEst);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] /= x->data[ixstart];
  }

  emxFree_real_T(&x);
  emxInit_boolean_T(&b_denoisedSpec, 2);
  ixstart = b_denoisedSpec->size[0] * b_denoisedSpec->size[1];
  b_denoisedSpec->size[0] = denoisedSpec->size[0];
  b_denoisedSpec->size[1] = denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)b_denoisedSpec, ixstart, (int32_T)sizeof
                    (boolean_T));
  iy = denoisedSpec->size[0] * denoisedSpec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    b_denoisedSpec->data[ixstart] = (denoisedSpec->data[ixstart] < 0.0);
  }

  eml_li_find(b_denoisedSpec, r0);
  iy = r0->size[0];
  emxFree_boolean_T(&b_denoisedSpec);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[r0->data[ixstart] - 1] = 0.0;
  }

  /*  Scaling */
  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  denoisedSpec->size[0] = spec->size[0];
  denoisedSpec->size[1] = spec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = spec->size[0] * spec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] = spec->data[ixstart] * denoisedSpec->
      data[ixstart] + 1.0E-10;
  }

  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  for (k = 0; k < ixstart; k++) {
    denoisedSpec->data[k] = log10(denoisedSpec->data[k]);
  }

  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = denoisedSpec->size[0];
  ftmp = denoisedSpec->size[1];
  iy *= ftmp;
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] *= 20.0;
  }

  /*  Setting the max value to 0 db. */
  for (ixstart = 0; ixstart < 2; ixstart++) {
    outsz[ixstart] = denoisedSpec->size[ixstart];
  }

  ixstart = clusters->size[0] * clusters->size[1];
  clusters->size[0] = 1;
  clusters->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)clusters, ixstart, (int32_T)sizeof
                    (real_T));
  ftmp = 0;
  iy = -1;
  for (k = 1; k <= denoisedSpec->size[1]; k++) {
    ixstart = ftmp;
    ixstop = ftmp + denoisedSpec->size[0];
    mtmp = denoisedSpec->data[ftmp];
    if (denoisedSpec->size[0] > 1) {
      if (rtIsNaN(denoisedSpec->data[ftmp])) {
        ix = ftmp + 1;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (ix + 1 <= ixstop)) {
          ixstart = ix;
          if (!rtIsNaN(denoisedSpec->data[ix])) {
            mtmp = denoisedSpec->data[ix];
            exitg4 = TRUE;
          } else {
            ix++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        for (ix = ixstart + 1; ix + 1 <= ixstop; ix++) {
          if (denoisedSpec->data[ix] > mtmp) {
            mtmp = denoisedSpec->data[ix];
          }
        }
      }
    }

    iy++;
    clusters->data[iy] = mtmp;
    ftmp += denoisedSpec->size[0];
  }

  ixstart = 1;
  mtmp = clusters->data[0];
  if (clusters->size[1] > 1) {
    if (rtIsNaN(clusters->data[0])) {
      ftmp = 2;
      exitg3 = FALSE;
      while ((exitg3 == FALSE) && (ftmp <= clusters->size[1])) {
        ixstart = ftmp;
        if (!rtIsNaN(clusters->data[ftmp - 1])) {
          mtmp = clusters->data[ftmp - 1];
          exitg3 = TRUE;
        } else {
          ftmp++;
        }
      }
    }

    if (ixstart < clusters->size[1]) {
      while (ixstart + 1 <= clusters->size[1]) {
        if (clusters->data[ixstart] > mtmp) {
          mtmp = clusters->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = denoisedSpec->size[0];
  ftmp = denoisedSpec->size[1];
  iy *= ftmp;
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] -= mtmp;
  }

  emxInit_boolean_T(&c_denoisedSpec, 2);

  /*  Thresholding 40db below maximum */
  ixstart = c_denoisedSpec->size[0] * c_denoisedSpec->size[1];
  c_denoisedSpec->size[0] = denoisedSpec->size[0];
  c_denoisedSpec->size[1] = denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)c_denoisedSpec, ixstart, (int32_T)sizeof
                    (boolean_T));
  iy = denoisedSpec->size[0] * denoisedSpec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    c_denoisedSpec->data[ixstart] = (denoisedSpec->data[ixstart] <= -40.0);
  }

  eml_li_find(c_denoisedSpec, r0);
  iy = r0->size[0];
  emxFree_boolean_T(&c_denoisedSpec);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[r0->data[ixstart] - 1] = -40.0;
  }

  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = denoisedSpec->size[0];
  ftmp = denoisedSpec->size[1];
  iy *= ftmp;
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] += 40.0;
  }

  /*  Normalizing 0-1. */
  for (ixstart = 0; ixstart < 2; ixstart++) {
    outsz[ixstart] = denoisedSpec->size[ixstart];
  }

  ixstart = clusters->size[0] * clusters->size[1];
  clusters->size[0] = 1;
  clusters->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)clusters, ixstart, (int32_T)sizeof
                    (real_T));
  ftmp = 0;
  iy = -1;
  for (k = 1; k <= denoisedSpec->size[1]; k++) {
    ixstart = ftmp;
    ixstop = ftmp + denoisedSpec->size[0];
    mtmp = denoisedSpec->data[ftmp];
    if (denoisedSpec->size[0] > 1) {
      if (rtIsNaN(denoisedSpec->data[ftmp])) {
        ix = ftmp + 1;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (ix + 1 <= ixstop)) {
          ixstart = ix;
          if (!rtIsNaN(denoisedSpec->data[ix])) {
            mtmp = denoisedSpec->data[ix];
            exitg2 = TRUE;
          } else {
            ix++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        for (ix = ixstart + 1; ix + 1 <= ixstop; ix++) {
          if (denoisedSpec->data[ix] > mtmp) {
            mtmp = denoisedSpec->data[ix];
          }
        }
      }
    }

    iy++;
    clusters->data[iy] = mtmp;
    ftmp += denoisedSpec->size[0];
  }

  ixstart = 1;
  mtmp = clusters->data[0];
  if (clusters->size[1] > 1) {
    if (rtIsNaN(clusters->data[0])) {
      ftmp = 2;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (ftmp <= clusters->size[1])) {
        ixstart = ftmp;
        if (!rtIsNaN(clusters->data[ftmp - 1])) {
          mtmp = clusters->data[ftmp - 1];
          exitg1 = TRUE;
        } else {
          ftmp++;
        }
      }
    }

    if (ixstart < clusters->size[1]) {
      while (ixstart + 1 <= clusters->size[1]) {
        if (clusters->data[ixstart] > mtmp) {
          mtmp = clusters->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  emxFree_real_T(&clusters);
  ixstart = denoisedSpec->size[0] * denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)denoisedSpec, ixstart, (int32_T)sizeof
                    (real_T));
  iy = denoisedSpec->size[0];
  ftmp = denoisedSpec->size[1];
  iy *= ftmp;
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[ixstart] /= mtmp;
  }

  emxInit_boolean_T(&r1, 2);
  ixstart = r1->size[0] * r1->size[1];
  r1->size[0] = denoisedSpec->size[0];
  r1->size[1] = denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)r1, ixstart, (int32_T)sizeof(boolean_T));
  iy = denoisedSpec->size[0] * denoisedSpec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    r1->data[ixstart] = rtIsNaN(denoisedSpec->data[ixstart]);
  }

  eml_li_find(r1, r0);
  iy = r0->size[0];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[r0->data[ixstart] - 1] = 0.0;
  }

  ixstart = r1->size[0] * r1->size[1];
  r1->size[0] = denoisedSpec->size[0];
  r1->size[1] = denoisedSpec->size[1];
  emxEnsureCapacity((emxArray__common *)r1, ixstart, (int32_T)sizeof(boolean_T));
  iy = denoisedSpec->size[0] * denoisedSpec->size[1];
  for (ixstart = 0; ixstart < iy; ixstart++) {
    r1->data[ixstart] = rtIsInf(denoisedSpec->data[ixstart]);
  }

  eml_li_find(r1, r0);
  iy = r0->size[0];
  emxFree_boolean_T(&r1);
  for (ixstart = 0; ixstart < iy; ixstart++) {
    denoisedSpec->data[r0->data[ixstart] - 1] = 0.0;
  }

  emxFree_int32_T(&r0);
}

void denoiseSpectrogram_initialize(void)
{
  int32_T i0;
  rt_InitInfAndNaN(8U);
  state_not_empty = FALSE;
  state = 1144108930U;
  for (i0 = 0; i0 < 2; i0++) {
    b_state[i0] = 362436069U + 158852560U * i0;
  }

  method = 7U;
}

void denoiseSpectrogram_terminate(void)
{
  /* (no terminate code required) */
}

emxArray_real_T *emxCreateND_real_T(int32_T numDimensions, int32_T *size)
{
  emxArray_real_T *emx;
  int32_T numEl;
  int32_T i;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (real_T *)calloc((uint32_T)numEl, sizeof(real_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_real_T *emxCreateWrapperND_real_T(real_T *data, int32_T numDimensions,
  int32_T *size)
{
  emxArray_real_T *emx;
  int32_T numEl;
  int32_T i;
  emxInit_real_T(&emx, numDimensions);
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

emxArray_real_T *emxCreateWrapper_real_T(real_T *data, int32_T rows, int32_T
  cols)
{
  emxArray_real_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_real_T(&emx, 2);
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

emxArray_real_T *emxCreate_real_T(int32_T rows, int32_T cols)
{
  emxArray_real_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_real_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (real_T *)calloc((uint32_T)numEl, sizeof(real_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

/* End of code generation (denoiseSpectrogram.c) */
