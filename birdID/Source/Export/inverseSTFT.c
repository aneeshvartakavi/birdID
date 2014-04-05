/*
 * inverseSTFT.c
 *
 * Code generation for function 'inverseSTFT'
 *
 * C source code generated on: Sat Apr 05 16:03:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "inverseSTFT.h"

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
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void b_exp(emxArray_creal_T *x);
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_creal_T(emxArray_creal_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void flipud(emxArray_real_T *x);
static void ifft(const emxArray_creal_T *x, emxArray_creal_T *y);

/* Function Definitions */
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

static void b_exp(emxArray_creal_T *x)
{
  int32_T i2;
  int32_T k;
  real_T r;
  real_T x_im;
  real_T b_x_im;
  i2 = x->size[0] * x->size[1];
  for (k = 0; k < i2; k++) {
    r = exp(x->data[(int32_T)(1.0 + (real_T)k) - 1].re / 2.0);
    x_im = x->data[(int32_T)(1.0 + (real_T)k) - 1].im;
    b_x_im = x->data[(int32_T)(1.0 + (real_T)k) - 1].im;
    x->data[(int32_T)(1.0 + (real_T)k) - 1].re = r * (r * cos(x_im));
    x->data[(int32_T)(1.0 + (real_T)k) - 1].im = r * (r * sin(b_x_im));
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

static void flipud(emxArray_real_T *x)
{
  int32_T m;
  int32_T n;
  int32_T md2;
  int32_T j;
  int32_T i;
  real_T xtmp;
  m = x->size[0];
  n = x->size[1];
  md2 = x->size[0];
  md2 /= 2;
  for (j = 0; j + 1 <= n; j++) {
    for (i = 1; i <= md2; i++) {
      xtmp = x->data[(i + x->size[0] * j) - 1];
      x->data[(i + x->size[0] * j) - 1] = x->data[(m - i) + x->size[0] * j];
      x->data[(m - i) + x->size[0] * j] = xtmp;
    }
  }
}

static void ifft(const emxArray_creal_T *x, emxArray_creal_T *y)
{
  uint32_T sz[2];
  int32_T ju;
  int32_T minval;
  emxArray_real_T *costab1q;
  int32_T nd2;
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
    sz[ju] = (uint32_T)x->size[ju];
  }

  ju = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
  } else {
    minval = x->size[0];
    emxInit_real_T(&costab1q, 2);
    nd2 = (x->size[0] - minval) + 1;
    if (1 >= nd2) {
      ixDelta = 1;
    } else {
      ixDelta = nd2;
    }

    ju = x->size[0];
    nRowsD2 = ju / 2;
    nRowsD4 = nRowsD2 / 2;
    lastChan = x->size[0] * (div_s32(x->size[0] * x->size[1], x->size[0]) - 1);
    e = 6.2831853071795862 / (real_T)x->size[0];
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
      sintab->data[k] = costab1q->data[(costab1q->size[1] - k) - 1];
    }

    for (k = costab1q->size[1]; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = costab1q->data[(k - costab1q->size[1]) + 1];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    for (chanStart = 0; chanStart <= lastChan; chanStart += x->size[0]) {
      ju = 0;
      nd2 = chanStart;
      for (i = 1; i < minval; i++) {
        y->data[nd2] = x->data[ix];
        nd2 = x->size[0];
        tst = TRUE;
        while (tst) {
          nd2 >>= 1;
          ju ^= nd2;
          tst = ((ju & nd2) == 0);
        }

        nd2 = chanStart + ju;
        ix++;
      }

      y->data[nd2] = x->data[ix];
      ix += ixDelta;
      ju = (chanStart + x->size[0]) - 2;
      if (x->size[0] > 1) {
        for (i = chanStart; i <= ju; i += 2) {
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
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
    if (y->size[0] > 1) {
      e = 1.0 / (real_T)y->size[0];
      ju = y->size[0] * y->size[1];
      emxEnsureCapacity((emxArray__common *)y, ju, (int32_T)sizeof(creal_T));
      nd2 = y->size[0];
      ju = y->size[1];
      nd2 *= ju;
      for (ju = 0; ju < nd2; ju++) {
        y->data[ju].re *= e;
        y->data[ju].im *= e;
      }
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

void inverseSTFT(const emxArray_real_T *magSpec, const emxArray_real_T
                 *phaseSpec, real_T blockSize, real_T hopSize, emxArray_real_T
                 *audioData)
{
  emxArray_real_T *magSpec1;
  int32_T i0;
  int32_T ixstart;
  int32_T loop_ub;
  emxArray_real_T *phaseSpec1;
  emxArray_int32_T *r0;
  real_T L;
  int32_T asub;
  int32_T i1;
  emxArray_real_T *r1;
  int32_T nm1d2;
  int32_T csz_idx_1;
  emxArray_real_T *spec;
  emxArray_creal_T *r2;
  emxArray_creal_T *b_magSpec1;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *t1;
  emxArray_real_T *x;
  emxArray_real_T *W;
  int32_T na1;
  emxArray_real_T *av;
  emxArray_real_T *bv;
  int32_T ak;
  emxArray_real_T *cv;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *b_spec;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_int32_T *r7;
  emxArray_real_T *b_audioData;
  uint32_T unnamed_idx_0;
  boolean_T exitg1;
  emxInit_real_T(&magSpec1, 2);

  /* INVERSESTFT Computes inverse STFT using overlap add */
  /*  */
  /*  Expects the dimensions of magSpec and phaseSpec to be equal, with number */
  /*  of rows equal to (blockSize/2 + 1) */
  /*   */
  /*  Inputs -  */
  /*  magSpec (double) - Magnitude spectrum */
  /*   */
  /*  phaseSpec (double) - Phase spectrum */
  /*  */
  /*  blockSize (double) - Block size (should be the same as used for STFT) */
  /*  */
  /*  hopSize (double) - Hop size (should be the same as used for STFT) */
  /*  */
  /*  Outputs -  */
  /*  audioData - Reconstructed audio data */
  /*  */
  /*  Author - Aneesh Vartakavi */
  /*  assert(isequal(size(magSpec),size(phaseSpec)),'Size of magSpec not equal to size of phaseSpec'); */
  /*   */
  /*  assert(blockSize == 2*(size(magSpec,1)-1),'Number of rows in input spectrum incorrect, see help for details'); */
  i0 = magSpec1->size[0] * magSpec1->size[1];
  magSpec1->size[0] = (int32_T)blockSize;
  emxEnsureCapacity((emxArray__common *)magSpec1, i0, (int32_T)sizeof(real_T));
  ixstart = magSpec->size[1];
  i0 = magSpec1->size[0] * magSpec1->size[1];
  magSpec1->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)magSpec1, i0, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)blockSize * magSpec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    magSpec1->data[i0] = 0.0;
  }

  emxInit_real_T(&phaseSpec1, 2);
  i0 = phaseSpec1->size[0] * phaseSpec1->size[1];
  phaseSpec1->size[0] = (int32_T)blockSize;
  emxEnsureCapacity((emxArray__common *)phaseSpec1, i0, (int32_T)sizeof(real_T));
  ixstart = magSpec->size[1];
  i0 = phaseSpec1->size[0] * phaseSpec1->size[1];
  phaseSpec1->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)phaseSpec1, i0, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)blockSize * magSpec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    phaseSpec1->data[i0] = 0.0;
  }

  emxInit_int32_T(&r0, 1);
  L = blockSize / 2.0;
  i0 = r0->size[0];
  r0->size[0] = (int32_T)floor(L) + 1;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(int32_T));
  loop_ub = (int32_T)floor(L);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    r0->data[i0] = (int32_T)(1.0 + (real_T)i0) - 1;
  }

  loop_ub = magSpec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    asub = magSpec->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      magSpec1->data[r0->data[i1] + magSpec1->size[0] * i0] = magSpec->data[i1 +
        magSpec->size[0] * i0];
    }
  }

  L = blockSize / 2.0;
  if (2.0 > L) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = 1;
    i1 = (int32_T)L;
  }

  L = blockSize / 2.0;
  if (L + 2.0 > blockSize) {
    ixstart = 0;
  } else {
    ixstart = (int32_T)(L + 2.0) - 1;
  }

  emxInit_real_T(&r1, 2);
  loop_ub = magSpec->size[1];
  nm1d2 = r1->size[0] * r1->size[1];
  r1->size[0] = i1 - i0;
  r1->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r1, nm1d2, (int32_T)sizeof(real_T));
  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    asub = i1 - i0;
    for (csz_idx_1 = 0; csz_idx_1 < asub; csz_idx_1++) {
      r1->data[csz_idx_1 + r1->size[0] * nm1d2] = magSpec->data[(i0 + csz_idx_1)
        + magSpec->size[0] * nm1d2];
    }
  }

  flipud(r1);
  loop_ub = r1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    asub = r1->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      magSpec1->data[(ixstart + i1) + magSpec1->size[0] * i0] = r1->data[i1 +
        r1->size[0] * i0];
    }
  }

  L = blockSize / 2.0;
  i0 = r0->size[0];
  r0->size[0] = (int32_T)floor(L) + 1;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(int32_T));
  loop_ub = (int32_T)floor(L);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    r0->data[i0] = (int32_T)(1.0 + (real_T)i0) - 1;
  }

  loop_ub = magSpec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    asub = magSpec->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      phaseSpec1->data[r0->data[i1] + phaseSpec1->size[0] * i0] = magSpec->
        data[i1 + magSpec->size[0] * i0];
    }
  }

  emxFree_int32_T(&r0);
  L = blockSize / 2.0;
  if (2.0 > L) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = 1;
    i1 = (int32_T)L;
  }

  L = blockSize / 2.0;
  if (L + 2.0 > blockSize) {
    ixstart = 0;
  } else {
    ixstart = (int32_T)(L + 2.0) - 1;
  }

  emxInit_real_T(&spec, 2);
  loop_ub = phaseSpec->size[1];
  nm1d2 = spec->size[0] * spec->size[1];
  spec->size[0] = i1 - i0;
  spec->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)spec, nm1d2, (int32_T)sizeof(real_T));
  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    asub = i1 - i0;
    for (csz_idx_1 = 0; csz_idx_1 < asub; csz_idx_1++) {
      spec->data[csz_idx_1 + spec->size[0] * nm1d2] = phaseSpec->data[(i0 +
        csz_idx_1) + phaseSpec->size[0] * nm1d2];
    }
  }

  flipud(spec);
  loop_ub = spec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    asub = spec->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      phaseSpec1->data[(ixstart + i1) + phaseSpec1->size[0] * i0] = -spec->
        data[i1 + spec->size[0] * i0];
    }
  }

  emxInit_creal_T(&r2, 2);
  i0 = r2->size[0] * r2->size[1];
  r2->size[0] = phaseSpec1->size[0];
  r2->size[1] = phaseSpec1->size[1];
  emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(creal_T));
  loop_ub = phaseSpec1->size[0] * phaseSpec1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r2->data[i0].re = phaseSpec1->data[i0] * 0.0;
    r2->data[i0].im = phaseSpec1->data[i0];
  }

  emxFree_real_T(&phaseSpec1);
  emxInit_creal_T(&b_magSpec1, 2);
  b_exp(r2);
  i0 = b_magSpec1->size[0] * b_magSpec1->size[1];
  b_magSpec1->size[0] = magSpec1->size[0];
  b_magSpec1->size[1] = magSpec1->size[1];
  emxEnsureCapacity((emxArray__common *)b_magSpec1, i0, (int32_T)sizeof(creal_T));
  loop_ub = magSpec1->size[0] * magSpec1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_magSpec1->data[i0].re = magSpec1->data[i0] * r2->data[i0].re;
    b_magSpec1->data[i0].im = magSpec1->data[i0] * r2->data[i0].im;
  }

  ifft(b_magSpec1, r2);
  i0 = spec->size[0] * spec->size[1];
  spec->size[0] = r2->size[0];
  spec->size[1] = r2->size[1];
  emxEnsureCapacity((emxArray__common *)spec, i0, (int32_T)sizeof(real_T));
  loop_ub = r2->size[0] * r2->size[1];
  emxFree_creal_T(&b_magSpec1);
  for (i0 = 0; i0 < loop_ub; i0++) {
    spec->data[i0] = r2->data[i0].re;
  }

  emxFree_creal_T(&r2);
  if (blockSize - 1.0 < 0.0) {
    ixstart = -1;
    L = 0.0;
    apnd = -1.0;
  } else if (rtIsInf(blockSize - 1.0)) {
    ixstart = 0;
    L = rtNaN;
    apnd = blockSize - 1.0;
  } else {
    L = 0.0;
    ndbl = floor((blockSize - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - (blockSize - 1.0);
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs(blockSize - 1.0)) {
      ndbl++;
      apnd = blockSize - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    ixstart = (int32_T)ndbl - 1;
  }

  emxInit_real_T(&t1, 2);
  i0 = t1->size[0] * t1->size[1];
  t1->size[0] = 1;
  t1->size[1] = ixstart + 1;
  emxEnsureCapacity((emxArray__common *)t1, i0, (int32_T)sizeof(real_T));
  if (ixstart + 1 > 0) {
    t1->data[0] = L;
    if (ixstart + 1 > 1) {
      t1->data[ixstart] = apnd;
      nm1d2 = ixstart / 2;
      for (csz_idx_1 = 1; csz_idx_1 < nm1d2; csz_idx_1++) {
        t1->data[csz_idx_1] = L + (real_T)csz_idx_1;
        t1->data[ixstart - csz_idx_1] = apnd - (real_T)csz_idx_1;
      }

      if (nm1d2 << 1 == ixstart) {
        t1->data[nm1d2] = (L + apnd) / 2.0;
      } else {
        t1->data[nm1d2] = L + (real_T)nm1d2;
        t1->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  L = 6.2831853071795862 * (1.0 / (2.0 * (blockSize - 1.0)));
  i0 = t1->size[0] * t1->size[1];
  t1->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)t1, i0, (int32_T)sizeof(real_T));
  ixstart = t1->size[0];
  nm1d2 = t1->size[1];
  loop_ub = ixstart * nm1d2;
  for (i0 = 0; i0 < loop_ub; i0++) {
    t1->data[i0] *= L;
  }

  emxInit_real_T(&x, 2);
  i0 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = t1->size[1];
  emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T));
  loop_ub = t1->size[0] * t1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    x->data[i0] = t1->data[i0];
  }

  for (csz_idx_1 = 0; csz_idx_1 < t1->size[1]; csz_idx_1++) {
    x->data[csz_idx_1] = sin(x->data[csz_idx_1]);
  }

  emxFree_real_T(&t1);
  b_emxInit_real_T(&W, 1);
  i0 = W->size[0];
  W->size[0] = x->size[1];
  emxEnsureCapacity((emxArray__common *)W, i0, (int32_T)sizeof(real_T));
  loop_ub = x->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    W->data[i0] = x->data[i0];
  }

  emxFree_real_T(&x);

  /* W = diag(sparse(sineWindow)); */
  i0 = magSpec1->size[0] * magSpec1->size[1];
  magSpec1->size[0] = spec->size[0];
  magSpec1->size[1] = spec->size[1];
  emxEnsureCapacity((emxArray__common *)magSpec1, i0, (int32_T)sizeof(real_T));
  loop_ub = spec->size[0] * spec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    magSpec1->data[i0] = spec->data[i0];
  }

  na1 = spec->size[0];
  nm1d2 = spec->size[0];
  csz_idx_1 = spec->size[1];
  ixstart = spec->size[0];
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  ixstart = spec->size[1];
  i0 = r1->size[0] * r1->size[1];
  r1->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T));
  loop_ub = spec->size[0] * spec->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = 0.0;
  }

  b_emxInit_real_T(&av, 1);
  b_emxInit_real_T(&bv, 1);
  i0 = spec->size[0] * spec->size[1];
  spec->size[0] = nm1d2;
  spec->size[1] = csz_idx_1;
  emxEnsureCapacity((emxArray__common *)spec, i0, (int32_T)sizeof(real_T));
  i0 = av->size[0];
  av->size[0] = na1;
  emxEnsureCapacity((emxArray__common *)av, i0, (int32_T)sizeof(real_T));
  ixstart = W->size[0];
  i0 = bv->size[0];
  bv->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)bv, i0, (int32_T)sizeof(real_T));
  asub = 1;
  ak = -1;
  i0 = nm1d2 * csz_idx_1 - nm1d2;
  ixstart = 0;
  b_emxInit_real_T(&cv, 1);
  while ((r1->size[0] > 0) && (ixstart <= i0)) {
    for (csz_idx_1 = 1; csz_idx_1 <= na1; csz_idx_1++) {
      av->data[csz_idx_1 - 1] = magSpec1->data[ak + csz_idx_1];
    }

    for (csz_idx_1 = 0; csz_idx_1 + 1 <= W->size[0]; csz_idx_1++) {
      bv->data[csz_idx_1] = W->data[csz_idx_1];
    }

    i1 = cv->size[0];
    cv->size[0] = av->size[0];
    emxEnsureCapacity((emxArray__common *)cv, i1, (int32_T)sizeof(real_T));
    loop_ub = av->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      cv->data[i1] = av->data[i1] * bv->data[i1];
    }

    for (csz_idx_1 = 0; csz_idx_1 + 1 <= r1->size[0]; csz_idx_1++) {
      spec->data[ixstart + csz_idx_1] = cv->data[csz_idx_1];
    }

    if (asub < magSpec1->size[1]) {
      ak += na1;
      asub++;
    } else {
      asub = 1;
    }

    ixstart += r1->size[0];
  }

  emxFree_real_T(&cv);
  emxFree_real_T(&bv);
  emxFree_real_T(&av);
  emxFree_real_T(&r1);
  emxFree_real_T(&magSpec1);

  /* spec = W * spec; */
  L = ((real_T)spec->size[1] - 1.0) * hopSize + blockSize;
  i0 = audioData->size[0];
  audioData->size[0] = (int32_T)L;
  emxEnsureCapacity((emxArray__common *)audioData, i0, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)L;
  for (i0 = 0; i0 < loop_ub; i0++) {
    audioData->data[i0] = 0.0;
  }

  if (1.0 > blockSize) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)blockSize;
  }

  emxInit_int32_T(&r3, 1);
  i0 = r3->size[0];
  r3->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r3, i0, (int32_T)sizeof(int32_T));
  for (i0 = 0; i0 < loop_ub; i0++) {
    r3->data[i0] = 1 + i0;
  }

  b_emxInit_int32_T(&r4, 2);
  i0 = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(int32_T));
  ixstart = r3->size[0];
  i0 = r4->size[0] * r4->size[1];
  r4->size[1] = ixstart;
  emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(int32_T));
  loop_ub = r3->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r4->data[i0] = r3->data[i0] - 1;
  }

  emxFree_int32_T(&r3);
  b_emxInit_real_T(&b_spec, 1);
  loop_ub = spec->size[0];
  i0 = b_spec->size[0];
  b_spec->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_spec, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_spec->data[i0] = spec->data[i0];
  }

  loop_ub = r4->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    asub = r4->size[0];
    for (i1 = 0; i1 < asub; i1++) {
      audioData->data[r4->data[i1 + r4->size[0] * i0]] = b_spec->data[i1 +
        (*(int32_T (*)[2])r4->size)[0] * i0];
    }
  }

  emxFree_real_T(&b_spec);
  nm1d2 = 0;
  b_emxInit_real_T(&r5, 1);
  b_emxInit_real_T(&r6, 1);
  b_emxInit_int32_T(&r7, 2);
  b_emxInit_real_T(&b_audioData, 1);
  while (nm1d2 <= spec->size[1] - 2) {
    L = hopSize * (1.0 + (real_T)nm1d2);
    ndbl = hopSize * (1.0 + (real_T)nm1d2);
    i0 = r5->size[0];
    r5->size[0] = (int32_T)floor(blockSize - 1.0) + 1;
    emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T));
    loop_ub = (int32_T)floor(blockSize - 1.0);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      r5->data[i0] = 1.0 + (real_T)i0;
    }

    i0 = r4->size[0] * r4->size[1];
    r4->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(int32_T));
    ixstart = r5->size[0];
    i0 = r4->size[0] * r4->size[1];
    r4->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(int32_T));
    loop_ub = r5->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r4->data[i0] = (int32_T)(ndbl + r5->data[i0]);
    }

    i0 = r6->size[0];
    r6->size[0] = (int32_T)floor(blockSize - 1.0) + 1;
    emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T));
    loop_ub = (int32_T)floor(blockSize - 1.0);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      r6->data[i0] = 1.0 + (real_T)i0;
    }

    i0 = r7->size[0] * r7->size[1];
    r7->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T));
    ixstart = r6->size[0];
    i0 = r7->size[0] * r7->size[1];
    r7->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T));
    loop_ub = r6->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r7->data[i0] = (int32_T)(L + r6->data[i0]);
    }

    ixstart = r7->size[1];
    i0 = b_audioData->size[0];
    b_audioData->size[0] = ixstart;
    emxEnsureCapacity((emxArray__common *)b_audioData, i0, (int32_T)sizeof
                      (real_T));
    for (i0 = 0; i0 < ixstart; i0++) {
      b_audioData->data[i0] = audioData->data[r7->data[i0] - 1] + spec->data[i0
        + spec->size[0] * (nm1d2 + 1)];
    }

    loop_ub = r4->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      asub = r4->size[0];
      for (i1 = 0; i1 < asub; i1++) {
        audioData->data[r4->data[i1 + r4->size[0] * i0] - 1] = b_audioData->
          data[i1 + (*(int32_T (*)[2])r4->size)[0] * i0];
      }
    }

    nm1d2++;
  }

  emxFree_real_T(&b_audioData);
  emxFree_int32_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_int32_T(&r4);
  emxFree_real_T(&spec);
  unnamed_idx_0 = (uint32_T)audioData->size[0];
  i0 = W->size[0];
  W->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)W, i0, (int32_T)sizeof(real_T));
  for (csz_idx_1 = 0; csz_idx_1 < audioData->size[0]; csz_idx_1++) {
    W->data[csz_idx_1] = fabs(audioData->data[csz_idx_1]);
  }

  ixstart = 1;
  L = W->data[0];
  if (W->size[0] > 1) {
    if (rtIsNaN(W->data[0])) {
      nm1d2 = 2;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (nm1d2 <= W->size[0])) {
        ixstart = nm1d2;
        if (!rtIsNaN(W->data[nm1d2 - 1])) {
          L = W->data[nm1d2 - 1];
          exitg1 = TRUE;
        } else {
          nm1d2++;
        }
      }
    }

    if (ixstart < W->size[0]) {
      while (ixstart + 1 <= W->size[0]) {
        if (W->data[ixstart] > L) {
          L = W->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  emxFree_real_T(&W);
  i0 = audioData->size[0];
  emxEnsureCapacity((emxArray__common *)audioData, i0, (int32_T)sizeof(real_T));
  loop_ub = audioData->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    audioData->data[i0] /= L;
  }
}

void inverseSTFT_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void inverseSTFT_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (inverseSTFT.c) */
