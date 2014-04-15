/*
 * computeBWFeatures.c
 *
 * Code generation for function 'computeBWFeatures'
 *
 * C source code generated on: Sat Apr 05 23:02:21 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "computeBWFeatures_export.h"

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
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_std(const emxArray_real_T *varargin_1, real_T y[2]);
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
static void mean(const emxArray_real_T *x, real_T y[2]);

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

static void b_std(const emxArray_real_T *varargin_1, real_T y[2])
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
  for (j = 0; j < 2; j++) {
    ix++;
    iy++;
    if (varargin_1->size[1] == 0) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix];
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 2;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)varargin_1->size[1];
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 2;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)d;
    }

    y[iy] = b_y;
  }

  for (k = 0; k < 2; k++) {
    y[k] = sqrt(y[k]);
  }
}

static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx)
{
  int32_T ncols;
  int32_T k;
  int32_T j;
  int32_T i0;
  int32_T i;
  emxArray_real_T *b_x;
  ncols = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    ncols += idx->data[k - 1];
  }

  ncols = x->size[1] - ncols;
  j = 0;
  i0 = x->size[1];
  for (k = 1; k <= i0; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      for (i = 0; i < 2; i++) {
        x->data[i + x->size[0] * j] = x->data[i + x->size[0] * (k - 1)];
      }

      j++;
    }
  }

  if (1 > ncols) {
    ncols = 0;
  }

  emxInit_real_T(&b_x, 2);
  i0 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 2;
  b_x->size[1] = ncols;
  emxEnsureCapacity((emxArray__common *)b_x, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < ncols; i0++) {
    for (j = 0; j < 2; j++) {
      b_x->data[j + b_x->size[0] * i0] = x->data[j + x->size[0] * i0];
    }
  }

  i0 = x->size[0] * x->size[1];
  x->size[0] = 2;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T));
  ncols = b_x->size[1];
  for (i0 = 0; i0 < ncols; i0++) {
    for (j = 0; j < 2; j++) {
      x->data[j + x->size[0] * i0] = b_x->data[j + b_x->size[0] * i0];
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

static void mean(const emxArray_real_T *x, real_T y[2])
{
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  if (x->size[1] == 0) {
    for (iy = 0; iy < 2; iy++) {
      y[iy] = 0.0;
    }
  } else {
    iy = -1;
    ixstart = -1;
    for (j = 0; j < 2; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[1]; k++) {
        ix += 2;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }

  iy = x->size[1];
  for (ixstart = 0; ixstart < 2; ixstart++) {
    y[ixstart] /= (real_T)iy;
  }
}

void computeBWFeatures(const emxArray_real_T *denoisedSpectrum, real_T features
  [8])
{
  emxArray_real_T *features1;
  int32_T i2;
  int32_T iyLead;
  emxArray_boolean_T *mask;
  int32_T i;
  emxArray_real_T *temp;
  emxArray_boolean_T *colsToRemove;
  emxArray_boolean_T *x;
  emxArray_real_T *b_x;
  emxArray_int32_T *ii;
  emxArray_real_T *b_y1;
  emxArray_int32_T *r0;
  emxArray_int32_T *b_ii;
  int32_T ixLead;
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  real_T work;
  int32_T m;
  real_T tmp1;
  real_T tmp2;
  int32_T ix;
  int32_T iindx_data[1];
  int32_T indx_data[1];
  emxArray_real_T *b_features1;
  emxArray_real_T *c_x;
  emxArray_real_T *c_y1;
  int32_T iy;
  uint32_T outsize[2];
  boolean_T exitg1;
  boolean_T b0;
  real_T dv0[2];
  emxInit_real_T(&features1, 2);

  /* UNTITLED12 Summary of this function goes here */
  /*    Detailed explanation goes here */
  i2 = denoisedSpectrum->size[1];
  iyLead = features1->size[0] * features1->size[1];
  features1->size[0] = i2;
  features1->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)features1, iyLead, (int32_T)sizeof
                    (real_T));
  i2 = denoisedSpectrum->size[1] << 1;
  for (iyLead = 0; iyLead < i2; iyLead++) {
    features1->data[iyLead] = 0.0;
  }

  memset(&features[0], 0, sizeof(real_T) << 3);
  emxInit_boolean_T(&mask, 2);
  iyLead = mask->size[0] * mask->size[1];
  mask->size[0] = denoisedSpectrum->size[0];
  mask->size[1] = denoisedSpectrum->size[1];
  emxEnsureCapacity((emxArray__common *)mask, iyLead, (int32_T)sizeof(boolean_T));
  i2 = denoisedSpectrum->size[0] * denoisedSpectrum->size[1];
  for (iyLead = 0; iyLead < i2; iyLead++) {
    mask->data[iyLead] = (denoisedSpectrum->data[iyLead] != 0.0);
  }

  i = 0;
  emxInit_real_T(&temp, 2);
  emxInit_boolean_T(&colsToRemove, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_real_T(&b_x, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_real_T(&b_y1, 2);
  b_emxInit_int32_T(&r0, 1);
  emxInit_int32_T(&b_ii, 2);
  while (i <= denoisedSpectrum->size[1] - 1) {
    i2 = mask->size[0];
    iyLead = colsToRemove->size[0] * colsToRemove->size[1];
    colsToRemove->size[0] = 1;
    colsToRemove->size[1] = i2;
    emxEnsureCapacity((emxArray__common *)colsToRemove, iyLead, (int32_T)sizeof
                      (boolean_T));
    for (iyLead = 0; iyLead < i2; iyLead++) {
      colsToRemove->data[colsToRemove->size[0] * iyLead] = mask->data[iyLead +
        mask->size[0] * i];
    }

    iyLead = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = colsToRemove->size[1];
    emxEnsureCapacity((emxArray__common *)x, iyLead, (int32_T)sizeof(boolean_T));
    i2 = colsToRemove->size[0] * colsToRemove->size[1];
    for (iyLead = 0; iyLead < i2; iyLead++) {
      x->data[iyLead] = !(colsToRemove->data[iyLead] > 0);
    }

    ixLead = 0;
    iyLead = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)ii, iyLead, (int32_T)sizeof(int32_T));
    i2 = 1;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (i2 <= x->size[1])) {
      guard1 = FALSE;
      if (x->data[i2 - 1]) {
        ixLead++;
        ii->data[ixLead - 1] = i2;
        if (ixLead >= x->size[1]) {
          exitg2 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        i2++;
      }
    }

    if (x->size[1] == 1) {
      if (ixLead == 0) {
        iyLead = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)ii, iyLead, (int32_T)sizeof
                          (int32_T));
      }
    } else {
      if (1 > ixLead) {
        i2 = 0;
      } else {
        i2 = ixLead;
      }

      iyLead = r0->size[0];
      r0->size[0] = i2;
      emxEnsureCapacity((emxArray__common *)r0, iyLead, (int32_T)sizeof(int32_T));
      for (iyLead = 0; iyLead < i2; iyLead++) {
        r0->data[iyLead] = 1 + iyLead;
      }

      i2 = r0->size[0];
      iyLead = b_ii->size[0] * b_ii->size[1];
      b_ii->size[0] = 1;
      b_ii->size[1] = i2;
      emxEnsureCapacity((emxArray__common *)b_ii, iyLead, (int32_T)sizeof
                        (int32_T));
      for (iyLead = 0; iyLead < i2; iyLead++) {
        ixLead = 0;
        while (ixLead <= 0) {
          b_ii->data[b_ii->size[0] * iyLead] = ii->data[r0->data[iyLead] - 1];
          ixLead = 1;
        }
      }

      iyLead = ii->size[0] * ii->size[1];
      ii->size[0] = 1;
      ii->size[1] = b_ii->size[1];
      emxEnsureCapacity((emxArray__common *)ii, iyLead, (int32_T)sizeof(int32_T));
      i2 = b_ii->size[1];
      for (iyLead = 0; iyLead < i2; iyLead++) {
        ii->data[ii->size[0] * iyLead] = b_ii->data[b_ii->size[0] * iyLead];
      }
    }

    iyLead = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = 2 + ii->size[1];
    emxEnsureCapacity((emxArray__common *)b_x, iyLead, (int32_T)sizeof(real_T));
    b_x->data[0] = 0.0;
    i2 = ii->size[1];
    for (iyLead = 0; iyLead < i2; iyLead++) {
      b_x->data[b_x->size[0] * (iyLead + 1)] = ii->data[ii->size[0] * iyLead];
    }

    b_x->data[b_x->size[0] * (1 + ii->size[1])] = (real_T)colsToRemove->size[1]
      + 1.0;
    iyLead = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 1;
    b_y1->size[1] = b_x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)b_y1, iyLead, (int32_T)sizeof(real_T));
    ixLead = 1;
    iyLead = 0;
    work = b_x->data[0];
    for (m = 2; m <= b_x->size[1]; m++) {
      tmp1 = b_x->data[ixLead];
      tmp2 = work;
      work = tmp1;
      tmp1 -= tmp2;
      ixLead++;
      b_y1->data[iyLead] = tmp1;
      iyLead++;
    }

    iyLead = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = b_y1->size[1];
    emxEnsureCapacity((emxArray__common *)temp, iyLead, (int32_T)sizeof(real_T));
    i2 = b_y1->size[0] * b_y1->size[1];
    for (iyLead = 0; iyLead < i2; iyLead++) {
      temp->data[iyLead] = b_y1->data[iyLead] - 1.0;
    }

    i2 = temp->size[1];
    work = temp->data[0];
    ixLead = 1;
    if (temp->size[1] > 1) {
      iyLead = 1;
      if (1 < i2) {
        for (ix = 1; ix + 1 <= i2; ix++) {
          iyLead++;
          if (temp->data[ix] > work) {
            work = temp->data[ix];
            ixLead = iyLead;
          }
        }
      }
    }

    iindx_data[0] = ixLead;
    iyLead = 0;
    while (iyLead <= 0) {
      indx_data[0] = iindx_data[0];
      iyLead = 1;
    }

    features1->data[i] = work;
    features1->data[i + features1->size[0]] = indx_data[0];

    /* features1(i,2) = find(temp1==features1(i,1),1,'first'); */
    i++;
  }

  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&r0);
  emxFree_real_T(&b_y1);
  emxFree_int32_T(&ii);
  emxFree_real_T(&b_x);
  emxFree_boolean_T(&x);
  emxFree_real_T(&temp);
  emxFree_boolean_T(&mask);
  emxInit_real_T(&b_features1, 2);
  iyLead = b_features1->size[0] * b_features1->size[1];
  b_features1->size[0] = 2;
  b_features1->size[1] = features1->size[0];
  emxEnsureCapacity((emxArray__common *)b_features1, iyLead, (int32_T)sizeof
                    (real_T));
  i2 = features1->size[0];
  for (iyLead = 0; iyLead < i2; iyLead++) {
    for (ixLead = 0; ixLead < 2; ixLead++) {
      b_features1->data[ixLead + b_features1->size[0] * iyLead] =
        features1->data[iyLead + features1->size[0] * ixLead];
    }
  }

  emxFree_real_T(&features1);
  emxInit_real_T(&c_x, 2);

  /*  Compute derivative features */
  iyLead = c_x->size[0] * c_x->size[1];
  c_x->size[0] = 2;
  c_x->size[1] = 1 + b_features1->size[1];
  emxEnsureCapacity((emxArray__common *)c_x, iyLead, (int32_T)sizeof(real_T));
  for (iyLead = 0; iyLead < 2; iyLead++) {
    c_x->data[iyLead] = b_features1->data[iyLead];
  }

  i2 = b_features1->size[1];
  for (iyLead = 0; iyLead < i2; iyLead++) {
    for (ixLead = 0; ixLead < 2; ixLead++) {
      c_x->data[ixLead + c_x->size[0] * (iyLead + 1)] = b_features1->data[ixLead
        + b_features1->size[0] * iyLead];
    }
  }

  emxInit_real_T(&c_y1, 2);
  if (1 >= c_x->size[1]) {
    iyLead = c_y1->size[0] * c_y1->size[1];
    c_y1->size[0] = 2;
    c_y1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)c_y1, iyLead, (int32_T)sizeof(real_T));
  } else {
    iyLead = c_y1->size[0] * c_y1->size[1];
    c_y1->size[0] = 2;
    c_y1->size[1] = c_x->size[1] - 1;
    emxEnsureCapacity((emxArray__common *)c_y1, iyLead, (int32_T)sizeof(real_T));
    ix = 2;
    iy = 1;
    for (i2 = 0; i2 < 2; i2++) {
      ixLead = ix;
      iyLead = iy;
      work = c_x->data[ix - 2];
      for (m = 2; m <= c_x->size[1]; m++) {
        tmp2 = work;
        work = c_x->data[ixLead];
        tmp1 = c_x->data[ixLead] - tmp2;
        ixLead += 2;
        c_y1->data[iyLead - 1] = tmp1;
        iyLead += 2;
      }

      ix++;
      iy++;
    }
  }

  emxFree_real_T(&c_x);

  /*  Remove columns for silent frames */
  for (iyLead = 0; iyLead < 2; iyLead++) {
    outsize[iyLead] = (uint32_T)denoisedSpectrum->size[iyLead];
  }

  iyLead = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)colsToRemove, iyLead, (int32_T)sizeof
                    (boolean_T));
  iyLead = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity((emxArray__common *)colsToRemove, iyLead, (int32_T)sizeof
                    (boolean_T));
  i2 = (int32_T)outsize[1];
  for (iyLead = 0; iyLead < i2; iyLead++) {
    colsToRemove->data[iyLead] = FALSE;
  }

  i2 = 0;
  iy = -1;
  for (i = 1; i <= denoisedSpectrum->size[1]; i++) {
    ixLead = i2;
    i2 += denoisedSpectrum->size[0];
    iy++;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (ixLead + 1 <= i2)) {
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

  iyLead = colsToRemove->size[0] * colsToRemove->size[1];
  colsToRemove->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)colsToRemove, iyLead, (int32_T)sizeof
                    (boolean_T));
  i2 = colsToRemove->size[0];
  ixLead = colsToRemove->size[1];
  i2 *= ixLead;
  for (iyLead = 0; iyLead < i2; iyLead++) {
    colsToRemove->data[iyLead] = !colsToRemove->data[iyLead];
  }

  eml_null_assignment(b_features1, colsToRemove);
  eml_null_assignment(c_y1, colsToRemove);

  /*  Extract mean and std sub features */
  mean(b_features1, dv0);
  emxFree_boolean_T(&colsToRemove);
  for (i = 0; i < 2; i++) {
    features[i] = dv0[i];
  }

  b_std(b_features1, dv0);
  emxFree_real_T(&b_features1);
  for (i = 0; i < 2; i++) {
    features[i + 2] = dv0[i];
  }

  mean(c_y1, dv0);
  for (i = 0; i < 2; i++) {
    features[i + 4] = dv0[i];
  }

  b_std(c_y1, dv0);
  emxFree_real_T(&c_y1);
  for (i = 0; i < 2; i++) {
    features[i + 6] = dv0[i];
  }
}

void computeBWFeatures_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void computeBWFeatures_terminate(void)
{
  /* (no terminate code required) */
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

/* End of code generation (computeBWFeatures.c) */
