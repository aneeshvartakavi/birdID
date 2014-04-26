/*
 * computePitchFeatures_exp.c
 *
 * Code generation for function 'computePitchFeatures_exp'
 *
 * C source code generated on: Sat Apr 26 01:29:18 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "computePitchFeatures_exp.h"

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
static void applySegmentationMask(emxArray_real_T *pitch, const emxArray_real_T *
  t_pitch, const emxArray_boolean_T *mask, const emxArray_real_T *t_mask,
  emxArray_real_T *onsetTimes);
static void b_eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);
static void b_emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void b_std(const emxArray_real_T *varargin_1, real_T y[4]);
static real_T c_std(const emxArray_real_T *varargin_1);
static void do_vectors(const emxArray_real_T *a, const real_T b_data[2], const
  int32_T b_size[2], emxArray_real_T *c, emxArray_int32_T *ia, int32_T ib_data[2],
  int32_T ib_size[1]);
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
static void mean(const emxArray_real_T *x, real_T y[4]);
static real_T rt_powd_snf(real_T u0, real_T u1);
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x);

/* Function Definitions */
static void applySegmentationMask(emxArray_real_T *pitch, const emxArray_real_T *
  t_pitch, const emxArray_boolean_T *mask, const emxArray_real_T *t_mask,
  emxArray_real_T *onsetTimes)
{
  real_T y;
  int32_T k;
  int8_T x[3];
  int32_T b_y1[2];
  int32_T ixLead;
  int32_T iyLead;
  int32_T work;
  int32_T m;
  int32_T idx;
  boolean_T startIndex[2];
  int8_T ii_data[2];
  boolean_T exitg3;
  boolean_T guard1 = FALSE;
  int32_T loop_ub;
  int8_T b_ii_data[2];
  int8_T endIndex_data[2];
  int32_T i;
  emxArray_int32_T *r3;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  int32_T b_k;
  int32_T c_ii_data[1];
  boolean_T exitg2;
  int32_T d_ii_data[1];
  int32_T indStart__data[1];
  boolean_T exitg1;
  uint32_T indEnd__data[1];
  real_T t_mask_data[2];
  int32_T t_mask_size[2];
  emxArray_int32_T *ia;
  emxArray_real_T *r6;
  int32_T ib_size[1];
  int32_T ib_data[2];
  int32_T b_t_mask_size[2];
  emxArray_real_T *r7;
  emxArray_boolean_T *r8;

  /* APPLYSEGMENTATIONMASK Applies the result of the segmentation to the pitch */
  /*    Detailed explanation goes here */
  if (mask->size[1] == 0) {
    y = 0.0;
  } else {
    y = mask->data[0];
    for (k = 2; k <= mask->size[1]; k++) {
      y += (real_T)mask->data[k - 1];
    }
  }

  /*  We need to find where the zeros in the mask's time vector correspond to */
  /*  the zeros in the pitch time vector */
  x[0] = 1;
  x[1] = (int8_T)(y != 0.0);
  x[2] = 1;
  ixLead = 1;
  iyLead = 0;
  work = 1;
  for (m = 0; m < 2; m++) {
    idx = work;
    work = x[ixLead];
    idx = x[ixLead] - idx;
    ixLead++;
    b_y1[iyLead] = idx;
    iyLead++;
  }

  for (work = 0; work < 2; work++) {
    startIndex[work] = (b_y1[work] < 0);
  }

  idx = 0;
  ixLead = 1;
  exitg3 = FALSE;
  while ((exitg3 == FALSE) && (ixLead < 3)) {
    guard1 = FALSE;
    if (b_y1[ixLead - 1] > 0) {
      idx++;
      ii_data[idx - 1] = (int8_T)ixLead;
      if (idx >= 2) {
        exitg3 = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      ixLead++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  for (work = 0; work < loop_ub; work++) {
    b_y1[work] = 1 + work;
  }

  for (work = 0; work < loop_ub; work++) {
    iyLead = 0;
    while (iyLead <= 0) {
      b_ii_data[work] = ii_data[b_y1[work] - 1];
      iyLead = 1;
    }
  }

  for (work = 0; work < loop_ub; work++) {
    ii_data[work] = b_ii_data[work];
  }

  for (work = 0; work < loop_ub; work++) {
    endIndex_data[work] = (int8_T)(ii_data[work] - 1);
  }

  k = 0;
  for (i = 0; i < 2; i++) {
    if (startIndex[i]) {
      k++;
    }
  }

  ixLead = 0;
  for (i = 0; i < 2; i++) {
    if (startIndex[i]) {
      ii_data[ixLead] = (int8_T)(i + 1);
      ixLead++;
    }
  }

  i = 0;
  b_emxInit_int32_T(&r3, 2);
  emxInit_boolean_T(&b_x, 1);
  emxInit_int32_T(&r4, 1);
  b_emxInit_int32_T(&r5, 2);
  while (i <= k - 1) {
    y = t_mask->data[ii_data[i] - 1];
    work = b_x->size[0];
    b_x->size[0] = t_pitch->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, work, (int32_T)sizeof(boolean_T));
    m = t_pitch->size[0];
    for (work = 0; work < m; work++) {
      b_x->data[work] = (t_pitch->data[work] >= y);
    }

    idx = b_x->size[0];
    if (1 <= idx) {
      b_k = 1;
    } else {
      b_k = idx;
    }

    idx = 0;
    ixLead = 1;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (ixLead <= b_x->size[0])) {
      if (b_x->data[ixLead - 1]) {
        idx = 1;
        c_ii_data[0] = ixLead;
        exitg2 = TRUE;
      } else {
        ixLead++;
      }
    }

    if (b_k == 1) {
      if (idx == 0) {
        b_k = 0;
      }
    } else {
      if (1 > idx) {
        m = -1;
      } else {
        m = 0;
      }

      work = 0;
      while (work <= m) {
        d_ii_data[0] = c_ii_data[0];
        work = 1;
      }

      b_k = m + 1;
      m++;
      work = 0;
      while (work <= m - 1) {
        c_ii_data[0] = d_ii_data[0];
        work = 1;
      }
    }

    for (work = 0; work < b_k; work++) {
      indStart__data[work] = c_ii_data[work];
    }

    y = t_mask->data[endIndex_data[i] - 1];
    work = b_x->size[0];
    b_x->size[0] = t_pitch->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, work, (int32_T)sizeof(boolean_T));
    m = t_pitch->size[0];
    for (work = 0; work < m; work++) {
      b_x->data[work] = (t_pitch->data[work] <= y);
    }

    idx = b_x->size[0];
    if (1 <= idx) {
      b_k = 1;
    } else {
      b_k = idx;
    }

    idx = 0;
    ixLead = b_x->size[0];
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (ixLead > 0)) {
      if (b_x->data[ixLead - 1]) {
        idx = 1;
        c_ii_data[0] = ixLead;
        exitg1 = TRUE;
      } else {
        ixLead--;
      }
    }

    if (b_k == 1) {
      if (idx == 0) {
        b_k = 0;
      }
    } else {
      if (1 > idx) {
        m = -1;
      } else {
        m = 0;
      }

      work = 0;
      while (work <= m) {
        d_ii_data[0] = c_ii_data[0];
        work = 1;
      }

      b_k = m + 1;
      ixLead = m + 1;
      work = 0;
      while (work <= ixLead - 1) {
        c_ii_data[0] = d_ii_data[0];
        work = 1;
      }

      work = m + 1;
      iyLead = work / 2;
      ixLead = 1;
      while (ixLead <= iyLead) {
        ixLead = c_ii_data[0];
        c_ii_data[0] = c_ii_data[m];
        c_ii_data[m] = ixLead;
        ixLead = 2;
      }
    }

    for (work = 0; work < b_k; work++) {
      indEnd__data[work] = (uint32_T)c_ii_data[work];
    }

    if (indStart__data[0] > (int32_T)indEnd__data[0]) {
      work = 1;
      iyLead = 0;
    } else {
      work = indStart__data[0];
      iyLead = (int32_T)indEnd__data[0];
    }

    ixLead = r4->size[0];
    r4->size[0] = (iyLead - work) + 1;
    emxEnsureCapacity((emxArray__common *)r4, ixLead, (int32_T)sizeof(int32_T));
    m = iyLead - work;
    for (iyLead = 0; iyLead <= m; iyLead++) {
      r4->data[iyLead] = work + iyLead;
    }

    work = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)r3, work, (int32_T)sizeof(int32_T));
    idx = r4->size[0];
    work = r3->size[0] * r3->size[1];
    r3->size[1] = idx;
    emxEnsureCapacity((emxArray__common *)r3, work, (int32_T)sizeof(int32_T));
    m = r4->size[0];
    for (work = 0; work < m; work++) {
      r3->data[work] = r4->data[work] - 1;
    }

    work = r5->size[0] * r5->size[1];
    r5->size[0] = 1;
    r5->size[1] = r3->size[1];
    emxEnsureCapacity((emxArray__common *)r5, work, (int32_T)sizeof(int32_T));
    m = r3->size[1];
    for (work = 0; work < m; work++) {
      r5->data[r5->size[0] * work] = r3->data[r3->size[0] * work];
    }

    m = r3->size[1];
    for (work = 0; work < m; work++) {
      pitch->data[r5->data[r5->size[0] * work]] = 0.0;
    }

    i++;
  }

  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&r3);
  t_mask_size[0] = 1;
  t_mask_size[1] = k;
  for (work = 0; work < k; work++) {
    t_mask_data[work] = t_mask->data[ii_data[work] - 1];
  }

  emxInit_int32_T(&ia, 1);
  emxInit_real_T(&r6, 2);
  do_vectors(onsetTimes, t_mask_data, t_mask_size, r6, ia, ib_data, ib_size);
  work = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[0] = 1;
  onsetTimes->size[1] = r6->size[1];
  emxEnsureCapacity((emxArray__common *)onsetTimes, work, (int32_T)sizeof(real_T));
  m = r6->size[1];
  for (work = 0; work < m; work++) {
    onsetTimes->data[onsetTimes->size[0] * work] = r6->data[r6->size[0] * work];
  }

  emxFree_real_T(&r6);
  b_t_mask_size[0] = 1;
  b_t_mask_size[1] = loop_ub;
  for (work = 0; work < loop_ub; work++) {
    t_mask_data[work] = t_mask->data[endIndex_data[work] - 1];
  }

  emxInit_real_T(&r7, 2);
  do_vectors(onsetTimes, t_mask_data, b_t_mask_size, r7, ia, ib_data, ib_size);
  work = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[0] = 1;
  onsetTimes->size[1] = r7->size[1];
  emxEnsureCapacity((emxArray__common *)onsetTimes, work, (int32_T)sizeof(real_T));
  loop_ub = r7->size[1];
  emxFree_int32_T(&ia);
  for (work = 0; work < loop_ub; work++) {
    onsetTimes->data[onsetTimes->size[0] * work] = r7->data[r7->size[0] * work];
  }

  emxFree_real_T(&r7);
  b_emxInit_boolean_T(&r8, 2);

  /*  Hack to fix onsets occuring after the time scale t_pitch, don't really */
  /*  know why that happens */
  y = t_pitch->data[t_pitch->size[0] - 1];
  work = r8->size[0] * r8->size[1];
  r8->size[0] = 1;
  r8->size[1] = onsetTimes->size[1];
  emxEnsureCapacity((emxArray__common *)r8, work, (int32_T)sizeof(boolean_T));
  loop_ub = onsetTimes->size[1];
  for (work = 0; work < loop_ub; work++) {
    r8->data[r8->size[0] * work] = (onsetTimes->data[onsetTimes->size[0] * work]
      > y);
  }

  eml_null_assignment(onsetTimes, r8);

  /*  tZeros = linspace(0,length(upsamples)/Fs,length(upsamples)); */
  /*   */
  /*  t_int = t(2)-t(1); */
  /*  tz_int = tZeros(2)-tZeros(1); */
  /*   */
  /*  n = round(t_int/tz_int); */
  /*  % For every interval of pitch, there are n intervals in the samples */
  /*  % For every interval, check if the n samples are zero if it. */
  /*   */
  /*  for i = 1:size(t)-1 */
  /*      temp = upsamples((i-1)*n+1 : (i)*n); */
  /*      if(sum(temp~=0)<=16) % If less than 16 samples out of 32 are non zero */
  /*          pitch(i)=0; */
  /*      end */
  /*  end */
  emxFree_boolean_T(&r8);
}

static void b_eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
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
      for (i = 0; i < 4; i++) {
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
  b_x->size[0] = 4;
  b_x->size[1] = ncols;
  emxEnsureCapacity((emxArray__common *)b_x, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < ncols; i0++) {
    for (j = 0; j < 4; j++) {
      b_x->data[j + b_x->size[0] * i0] = x->data[j + x->size[0] * i0];
    }
  }

  i0 = x->size[0] * x->size[1];
  x->size[0] = 4;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T));
  ncols = b_x->size[1];
  for (i0 = 0; i0 < ncols; i0++) {
    for (j = 0; j < 4; j++) {
      x->data[j + x->size[0] * i0] = b_x->data[j + b_x->size[0] * i0];
    }
  }

  emxFree_real_T(&b_x);
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

static void b_std(const emxArray_real_T *varargin_1, real_T y[4])
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
  for (j = 0; j < 4; j++) {
    ix++;
    iy++;
    if (varargin_1->size[1] == 0) {
      b_y = rtNaN;
    } else {
      b_ix = ix;
      xbar = varargin_1->data[ix];
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 4;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)varargin_1->size[1];
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      for (k = 0; k <= varargin_1->size[1] - 2; k++) {
        b_ix += 4;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)d;
    }

    y[iy] = b_y;
  }

  for (k = 0; k < 4; k++) {
    y[k] = sqrt(y[k]);
  }
}

static real_T c_std(const emxArray_real_T *varargin_1)
{
  real_T y;
  int32_T d;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  if (varargin_1->size[1] == 0) {
    y = rtNaN;
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (real_T)d;
  }

  return sqrt(y);
}

static void do_vectors(const emxArray_real_T *a, const real_T b_data[2], const
  int32_T b_size[2], emxArray_real_T *c, emxArray_int32_T *ia, int32_T ib_data[2],
  int32_T ib_size[1])
{
  int32_T ncmax;
  int32_T iafirst;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T b_ialast;
  real_T ak;
  int32_T b_iblast;
  emxArray_real_T b_b_data;
  real_T bk;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  emxArray_real_T c_b_data;
  emxArray_int32_T *b_ia;
  int32_T b_ib_data[2];
  emxArray_real_T *b_c;
  ncmax = a->size[1] + b_size[1];
  iafirst = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = ncmax;
  emxEnsureCapacity((emxArray__common *)c, iafirst, (int32_T)sizeof(real_T));
  iafirst = ia->size[0];
  ia->size[0] = a->size[1];
  emxEnsureCapacity((emxArray__common *)ia, iafirst, (int32_T)sizeof(int32_T));
  ib_size[0] = b_size[1];
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= a->size[1]) && (iblast <= b_size[1])) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    b_iblast = iblast;
    b_b_data.data = (real_T *)b_data;
    b_b_data.size = (int32_T *)b_size;
    b_b_data.allocatedSize = 2;
    b_b_data.numDimensions = 2;
    b_b_data.canFreeData = FALSE;
    bk = skip_to_last_equal_value(&b_iblast, &b_b_data);
    iblast = b_iblast;
    absxk = fabs(bk / 2.0);
    if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((fabs(bk - ak) < absxk) || (rtIsInf(ak) && rtIsInf(bk) && ((ak > 0.0) ==
          (bk > 0.0)))) {
      p = TRUE;
    } else {
      p = FALSE;
    }

    if (p) {
      nc++;
      c->data[nc] = ak;
      nia++;
      ia->data[nia] = iafirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else {
      if ((ak < bk) || rtIsNaN(bk)) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      if (p) {
        nc++;
        nia++;
        c->data[nc] = ak;
        ia->data[nia] = iafirst;
        ialast = b_ialast + 1;
        iafirst = b_ialast + 1;
      } else {
        nc++;
        nib++;
        c->data[nc] = bk;
        ib_data[nib - 1] = ibfirst + 1;
        iblast = b_iblast + 1;
        ibfirst = b_iblast;
      }
    }
  }

  while (ialast <= a->size[1]) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    nc++;
    nia++;
    c->data[nc] = ak;
    ia->data[nia] = ialast;
    ialast = b_ialast + 1;
  }

  while (iblast <= b_size[1]) {
    b_iblast = iblast;
    c_b_data.data = (real_T *)b_data;
    c_b_data.size = (int32_T *)b_size;
    c_b_data.allocatedSize = 2;
    c_b_data.numDimensions = 2;
    c_b_data.canFreeData = FALSE;
    bk = skip_to_last_equal_value(&b_iblast, &c_b_data);
    nc++;
    nib++;
    c->data[nc] = bk;
    ib_data[nib - 1] = iblast;
    iblast = b_iblast + 1;
  }

  if (a->size[1] > 0) {
    if (1 > nia + 1) {
      nia = -1;
    }

    emxInit_int32_T(&b_ia, 1);
    iafirst = b_ia->size[0];
    b_ia->size[0] = nia + 1;
    emxEnsureCapacity((emxArray__common *)b_ia, iafirst, (int32_T)sizeof(int32_T));
    for (iafirst = 0; iafirst <= nia; iafirst++) {
      b_ia->data[iafirst] = ia->data[iafirst];
    }

    iafirst = ia->size[0];
    ia->size[0] = b_ia->size[0];
    emxEnsureCapacity((emxArray__common *)ia, iafirst, (int32_T)sizeof(int32_T));
    nia = b_ia->size[0];
    for (iafirst = 0; iafirst < nia; iafirst++) {
      ia->data[iafirst] = b_ia->data[iafirst];
    }

    emxFree_int32_T(&b_ia);
  }

  if (b_size[1] > 0) {
    if (1 > nib) {
      nia = 0;
    } else {
      nia = nib;
    }

    for (iafirst = 0; iafirst < nia; iafirst++) {
      b_ib_data[iafirst] = ib_data[iafirst];
    }

    ib_size[0] = nia;
    for (iafirst = 0; iafirst < nia; iafirst++) {
      ib_data[iafirst] = b_ib_data[iafirst];
    }
  }

  if (ncmax > 0) {
    if (1 > nc + 1) {
      nia = -1;
    } else {
      nia = nc;
    }

    emxInit_real_T(&b_c, 2);
    iafirst = b_c->size[0] * b_c->size[1];
    b_c->size[0] = 1;
    b_c->size[1] = nia + 1;
    emxEnsureCapacity((emxArray__common *)b_c, iafirst, (int32_T)sizeof(real_T));
    for (iafirst = 0; iafirst <= nia; iafirst++) {
      b_c->data[b_c->size[0] * iafirst] = c->data[c->size[0] * iafirst];
    }

    iafirst = c->size[0] * c->size[1];
    c->size[0] = 1;
    c->size[1] = b_c->size[1];
    emxEnsureCapacity((emxArray__common *)c, iafirst, (int32_T)sizeof(real_T));
    nia = b_c->size[1];
    for (iafirst = 0; iafirst < nia; iafirst++) {
      c->data[c->size[0] * iafirst] = b_c->data[b_c->size[0] * iafirst];
    }

    emxFree_real_T(&b_c);
  }
}

static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T k;
  int32_T i;
  int32_T j;
  k = 0;
  for (i = 1; i <= x->size[0]; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  j = y->size[0];
  y->size[0] = k;
  emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(int32_T));
  j = 0;
  for (i = 1; i <= x->size[0]; i++) {
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
  int32_T nxout;
  int32_T k;
  int32_T k0;
  emxArray_int32_T *r9;
  emxArray_real_T *b_x;
  nxin = x->size[1];
  nxout = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    nxout += idx->data[k - 1];
  }

  nxout = x->size[1] - nxout;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  if (1 > nxout) {
    nxout = 0;
  }

  emxInit_int32_T(&r9, 1);
  nxin = r9->size[0];
  r9->size[0] = nxout;
  emxEnsureCapacity((emxArray__common *)r9, nxin, (int32_T)sizeof(int32_T));
  for (nxin = 0; nxin < nxout; nxin++) {
    r9->data[nxin] = 1 + nxin;
  }

  emxInit_real_T(&b_x, 2);
  nxout = r9->size[0];
  nxin = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = nxout;
  emxEnsureCapacity((emxArray__common *)b_x, nxin, (int32_T)sizeof(real_T));
  for (nxin = 0; nxin < nxout; nxin++) {
    k0 = 0;
    while (k0 <= 0) {
      b_x->data[b_x->size[0] * nxin] = x->data[r9->data[nxin] - 1];
      k0 = 1;
    }
  }

  emxFree_int32_T(&r9);
  nxin = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity((emxArray__common *)x, nxin, (int32_T)sizeof(real_T));
  nxout = b_x->size[1];
  for (nxin = 0; nxin < nxout; nxin++) {
    x->data[x->size[0] * nxin] = b_x->data[b_x->size[0] * nxin];
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

static void mean(const emxArray_real_T *x, real_T y[4])
{
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  if (x->size[1] == 0) {
    for (iy = 0; iy < 4; iy++) {
      y[iy] = 0.0;
    }
  } else {
    iy = -1;
    ixstart = -1;
    for (j = 0; j < 4; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[1]; k++) {
        ix += 4;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }

  iy = x->size[1];
  for (ixstart = 0; ixstart < 4; ixstart++) {
    y[ixstart] /= (real_T)iy;
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

static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x)
{
  real_T xk;
  boolean_T exitg1;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  xk = x->data[*k - 1];
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (*k < x->size[1])) {
    absxk = fabs(xk / 2.0);
    if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((fabs(xk - x->data[*k]) < absxk) || (rtIsInf(x->data[*k]) && rtIsInf(xk)
         && ((x->data[*k] > 0.0) == (xk > 0.0)))) {
      p = TRUE;
    } else {
      p = FALSE;
    }

    if (p) {
      (*k)++;
    } else {
      exitg1 = TRUE;
    }
  }

  return xk;
}

void computePitchFeatures_exp(const emxArray_real_T *pitch, const
  emxArray_real_T *denoisedSpectrogram, const emxArray_boolean_T *onsets, const
  emxArray_real_T *T, real_T Fs1, real_T fileLength, real_T featureVector[10])
{
  int32_T sz[2];
  int32_T iy;
  emxArray_real_T *y;
  int32_T loop_ub;
  int32_T ix;
  int32_T i;
  int32_T ixstart;
  real_T s;
  int32_T k;
  emxArray_real_T *b_pitch;
  emxArray_boolean_T *x;
  emxArray_int32_T *r0;
  emxArray_boolean_T *c_pitch;
  emxArray_boolean_T *d_pitch;
  emxArray_real_T *e_pitch;
  emxArray_real_T *onsetTimes;
  emxArray_int32_T *r1;
  emxArray_real_T *b_onsetTimes;
  emxArray_boolean_T *b_y;
  emxArray_real_T *timesInPitch;
  int32_T ii_data[1];
  boolean_T exitg2;
  int32_T b_ii_data[1];
  uint32_T tmp_data[1];
  emxArray_real_T *features;
  int32_T exitg1;
  emxArray_boolean_T *c_y;
  real_T dv0[4];
  emxArray_boolean_T *r2;

  /* UNTITLED Summary of this function goes here */
  /*    Detailed explanation goes here */
  for (iy = 0; iy < 2; iy++) {
    sz[iy] = denoisedSpectrogram->size[iy];
  }

  emxInit_real_T(&y, 2);
  iy = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
  if ((denoisedSpectrogram->size[0] == 0) || (denoisedSpectrogram->size[1] == 0))
  {
    iy = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
    iy = y->size[0] * y->size[1];
    y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
    loop_ub = sz[1];
    for (iy = 0; iy < loop_ub; iy++) {
      y->data[iy] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= denoisedSpectrogram->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = denoisedSpectrogram->data[ixstart];
      for (k = 2; k <= denoisedSpectrogram->size[0]; k++) {
        ix++;
        s += denoisedSpectrogram->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }

  b_emxInit_real_T(&b_pitch, 1);

  /* PREPROCESSPITCH Convert Yin's pitch into the format I need */
  /*   Aneesh Vartakavi */
  sz[0] = pitch->size[0];
  iy = b_pitch->size[0];
  b_pitch->size[0] = sz[0];
  emxEnsureCapacity((emxArray__common *)b_pitch, iy, (int32_T)sizeof(real_T));
  for (k = 0; k < sz[0]; k++) {
    b_pitch->data[k] = rt_powd_snf(2.0, pitch->data[k]);
  }

  iy = b_pitch->size[0];
  emxEnsureCapacity((emxArray__common *)b_pitch, iy, (int32_T)sizeof(real_T));
  loop_ub = b_pitch->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    b_pitch->data[iy] *= 440.0;
  }

  emxInit_boolean_T(&x, 1);
  iy = x->size[0];
  x->size[0] = b_pitch->size[0];
  emxEnsureCapacity((emxArray__common *)x, iy, (int32_T)sizeof(boolean_T));
  loop_ub = b_pitch->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    x->data[iy] = rtIsNaN(b_pitch->data[iy]);
  }

  emxInit_int32_T(&r0, 1);
  eml_li_find(x, r0);
  loop_ub = r0->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    b_pitch->data[r0->data[iy] - 1] = 0.0;
  }

  emxInit_boolean_T(&c_pitch, 1);
  iy = c_pitch->size[0];
  c_pitch->size[0] = b_pitch->size[0];
  emxEnsureCapacity((emxArray__common *)c_pitch, iy, (int32_T)sizeof(boolean_T));
  loop_ub = b_pitch->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    c_pitch->data[iy] = (b_pitch->data[iy] >= 8000.0);
  }

  eml_li_find(c_pitch, r0);
  loop_ub = r0->size[0];
  emxFree_boolean_T(&c_pitch);
  for (iy = 0; iy < loop_ub; iy++) {
    b_pitch->data[r0->data[iy] - 1] = 0.0;
  }

  emxInit_boolean_T(&d_pitch, 1);
  iy = d_pitch->size[0];
  d_pitch->size[0] = b_pitch->size[0];
  emxEnsureCapacity((emxArray__common *)d_pitch, iy, (int32_T)sizeof(boolean_T));
  loop_ub = b_pitch->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    d_pitch->data[iy] = (b_pitch->data[iy] <= 100.0);
  }

  eml_li_find(d_pitch, r0);
  loop_ub = r0->size[0];
  emxFree_boolean_T(&d_pitch);
  for (iy = 0; iy < loop_ub; iy++) {
    b_pitch->data[r0->data[iy] - 1] = 0.0;
  }

  emxInit_real_T(&e_pitch, 2);
  iy = e_pitch->size[0] * e_pitch->size[1];
  e_pitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)e_pitch, iy, (int32_T)sizeof(real_T));
  ix = b_pitch->size[0];
  iy = e_pitch->size[0] * e_pitch->size[1];
  e_pitch->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)e_pitch, iy, (int32_T)sizeof(real_T));
  loop_ub = b_pitch->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    e_pitch->data[iy] = b_pitch->data[iy];
  }

  emxInit_real_T(&onsetTimes, 2);

  /*  Create a time vector, not sure how Yin does it's processing */
  s = fileLength / Fs1;
  sz[1] = e_pitch->size[1];
  iy = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[0] = 1;
  onsetTimes->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)onsetTimes, iy, (int32_T)sizeof(real_T));
  if (sz[1] >= 1) {
    onsetTimes->data[sz[1] - 1] = s;
    if (onsetTimes->size[1] >= 2) {
      onsetTimes->data[0] = 0.0;
      if (onsetTimes->size[1] >= 3) {
        if (fabs(s) > 8.9884656743115785E+307) {
          s /= (real_T)onsetTimes->size[1] - 1.0;
          iy = onsetTimes->size[1];
          for (k = 0; k <= iy - 3; k++) {
            onsetTimes->data[k + 1] = s * (1.0 + (real_T)k);
          }
        } else {
          s /= (real_T)onsetTimes->size[1] - 1.0;
          iy = onsetTimes->size[1];
          for (k = 0; k <= iy - 3; k++) {
            onsetTimes->data[k + 1] = (1.0 + (real_T)k) * s;
          }
        }
      }
    }
  }

  iy = b_pitch->size[0];
  b_pitch->size[0] = onsetTimes->size[1];
  emxEnsureCapacity((emxArray__common *)b_pitch, iy, (int32_T)sizeof(real_T));
  loop_ub = onsetTimes->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    b_pitch->data[iy] = onsetTimes->data[iy];
  }

  /* maxTime = tPitch(end); */
  /*  For now discarding the last onset */
  eml_li_find(onsets, r0);
  iy = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)onsetTimes, iy, (int32_T)sizeof(real_T));
  ix = r0->size[0];
  iy = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)onsetTimes, iy, (int32_T)sizeof(real_T));
  loop_ub = r0->size[0];
  for (iy = 0; iy < loop_ub; iy++) {
    onsetTimes->data[iy] = T->data[r0->data[iy] - 1];
  }

  emxFree_int32_T(&r0);
  ix = onsetTimes->size[1];
  ixstart = onsetTimes->size[1] - 1;
  while (ix <= ixstart) {
    onsetTimes->data[ix - 1] = onsetTimes->data[ix];
    ix++;
  }

  if (1 > ixstart) {
    loop_ub = 0;
  } else {
    loop_ub = ixstart;
  }

  emxInit_int32_T(&r1, 1);
  iy = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r1, iy, (int32_T)sizeof(int32_T));
  for (iy = 0; iy < loop_ub; iy++) {
    r1->data[iy] = 1 + iy;
  }

  emxInit_real_T(&b_onsetTimes, 2);
  ix = r1->size[0];
  iy = b_onsetTimes->size[0] * b_onsetTimes->size[1];
  b_onsetTimes->size[0] = 1;
  b_onsetTimes->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)b_onsetTimes, iy, (int32_T)sizeof(real_T));
  for (iy = 0; iy < ix; iy++) {
    ixstart = 0;
    while (ixstart <= 0) {
      b_onsetTimes->data[b_onsetTimes->size[0] * iy] = onsetTimes->data[r1->
        data[iy] - 1];
      ixstart = 1;
    }
  }

  emxFree_int32_T(&r1);
  iy = onsetTimes->size[0] * onsetTimes->size[1];
  onsetTimes->size[0] = 1;
  onsetTimes->size[1] = b_onsetTimes->size[1];
  emxEnsureCapacity((emxArray__common *)onsetTimes, iy, (int32_T)sizeof(real_T));
  loop_ub = b_onsetTimes->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    onsetTimes->data[onsetTimes->size[0] * iy] = b_onsetTimes->data
      [b_onsetTimes->size[0] * iy];
  }

  emxFree_real_T(&b_onsetTimes);
  b_emxInit_boolean_T(&b_y, 2);

  /*  Apply segmentation mask, and add onsets for segment boundaries */
  iy = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, iy, (int32_T)sizeof(boolean_T));
  loop_ub = y->size[0] * y->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    b_y->data[iy] = (y->data[iy] == 0.0);
  }

  applySegmentationMask(e_pitch, b_pitch, b_y, T, onsetTimes);

  /*  Pitch is at sourceFs, downsample to 6000 Hz */
  /*  downPitch = convertSampleRate(denoisedPitch,Fs1,6000); */
  /*  downPitch(downPitch<0) = 0; */
  /*   */
  /*  tPitch = convertSampleRate(tPitch,Fs1,6000); */
  /*  tPitch(end) = maxTime; */
  emxFree_boolean_T(&b_y);
  for (iy = 0; iy < 2; iy++) {
    sz[iy] = onsetTimes->size[iy];
  }

  emxInit_real_T(&timesInPitch, 2);
  iy = timesInPitch->size[0] * timesInPitch->size[1];
  timesInPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)timesInPitch, iy, (int32_T)sizeof(real_T));
  iy = timesInPitch->size[0] * timesInPitch->size[1];
  timesInPitch->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)timesInPitch, iy, (int32_T)sizeof(real_T));
  loop_ub = sz[1];
  for (iy = 0; iy < loop_ub; iy++) {
    timesInPitch->data[iy] = 0.0;
  }

  for (i = 0; i < onsetTimes->size[1]; i++) {
    s = onsetTimes->data[(int32_T)(1.0 + (real_T)i) - 1];
    iy = x->size[0];
    x->size[0] = b_pitch->size[0];
    emxEnsureCapacity((emxArray__common *)x, iy, (int32_T)sizeof(boolean_T));
    loop_ub = b_pitch->size[0];
    for (iy = 0; iy < loop_ub; iy++) {
      x->data[iy] = (b_pitch->data[iy] <= s);
    }

    ixstart = x->size[0];
    if (1 <= ixstart) {
      k = 1;
    } else {
      k = ixstart;
    }

    ix = 0;
    ixstart = x->size[0];
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (ixstart > 0)) {
      if (x->data[ixstart - 1]) {
        ix = 1;
        ii_data[0] = ixstart;
        exitg2 = TRUE;
      } else {
        ixstart--;
      }
    }

    if (k == 1) {
      if (ix == 0) {
        k = 0;
      }
    } else {
      if (1 > ix) {
        loop_ub = -1;
      } else {
        loop_ub = 0;
      }

      iy = 0;
      while (iy <= loop_ub) {
        b_ii_data[0] = ii_data[0];
        iy = 1;
      }

      k = loop_ub + 1;
      ixstart = loop_ub + 1;
      iy = 0;
      while (iy <= ixstart - 1) {
        ii_data[0] = b_ii_data[0];
        iy = 1;
      }

      iy = loop_ub + 1;
      ix = iy / 2;
      ixstart = 1;
      while (ixstart <= ix) {
        ixstart = ii_data[0];
        ii_data[0] = ii_data[loop_ub];
        ii_data[loop_ub] = ixstart;
        ixstart = 2;
      }
    }

    for (iy = 0; iy < k; iy++) {
      tmp_data[iy] = (uint32_T)ii_data[iy];
    }

    timesInPitch->data[(int32_T)(1.0 + (real_T)i) - 1] = tmp_data[0];
  }

  emxFree_real_T(&b_pitch);
  emxFree_boolean_T(&x);
  emxFree_real_T(&onsetTimes);
  emxInit_real_T(&features, 2);

  /*  Plug in polynomials between onsets */
  iy = features->size[0] * features->size[1];
  features->size[0] = 4;
  emxEnsureCapacity((emxArray__common *)features, iy, (int32_T)sizeof(real_T));
  ix = timesInPitch->size[1] - 1;
  iy = features->size[0] * features->size[1];
  features->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)features, iy, (int32_T)sizeof(real_T));
  loop_ub = (timesInPitch->size[1] - 1) << 2;
  for (iy = 0; iy < loop_ub; iy++) {
    features->data[iy] = 0.0;
  }

  /*  Remove the zero columns */
  sz[1] = timesInPitch->size[1] - 1;
  iy = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
  ix = timesInPitch->size[1] - 1;
  if (ix == 0) {
    iy = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
    iy = y->size[0] * y->size[1];
    y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T));
    loop_ub = sz[1];
    for (iy = 0; iy < loop_ub; iy++) {
      y->data[iy] = 0.0;
    }
  } else {
    iy = -1;
    i = 1;
    do {
      exitg1 = 0;
      ix = timesInPitch->size[1] - 1;
      if (i <= ix) {
        iy++;
        y->data[iy] = 0.0;
        i++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emxFree_real_T(&timesInPitch);
  b_emxInit_boolean_T(&c_y, 2);
  iy = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)c_y, iy, (int32_T)sizeof(boolean_T));
  loop_ub = y->size[0] * y->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    c_y->data[iy] = (y->data[iy] == 0.0);
  }

  emxFree_real_T(&y);
  b_eml_null_assignment(features, c_y);
  emxFree_boolean_T(&c_y);
  memset(&featureVector[0], 0, 10U * sizeof(real_T));
  mean(features, dv0);
  for (i = 0; i < 4; i++) {
    featureVector[i] = dv0[i];
  }

  b_std(features, dv0);
  emxFree_real_T(&features);
  for (i = 0; i < 4; i++) {
    featureVector[i + 5] = dv0[i];
  }

  b_emxInit_boolean_T(&r2, 2);

  /*  Storing some other pitch features */
  /*  Removing the zeros */
  iy = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = e_pitch->size[1];
  emxEnsureCapacity((emxArray__common *)r2, iy, (int32_T)sizeof(boolean_T));
  loop_ub = e_pitch->size[0] * e_pitch->size[1];
  for (iy = 0; iy < loop_ub; iy++) {
    r2->data[iy] = (e_pitch->data[iy] == 0.0);
  }

  eml_null_assignment(e_pitch, r2);
  emxFree_boolean_T(&r2);
  if (e_pitch->size[1] == 0) {
    s = 0.0;
  } else {
    s = e_pitch->data[0];
    for (k = 2; k <= e_pitch->size[1]; k++) {
      s += e_pitch->data[k - 1];
    }
  }

  featureVector[4] = s / (real_T)e_pitch->size[1];
  featureVector[9] = c_std(e_pitch);

  /* featureVector = vertcat(featureVector,fv); */
  emxFree_real_T(&e_pitch);
}

void computePitchFeatures_exp_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

void computePitchFeatures_exp_terminate(void)
{
  /* (no terminate code required) */
}

//emxArray_boolean_T *emxCreateND_boolean_T(int32_T numDimensions, int32_T *size)
//{
//  emxArray_boolean_T *emx;
//  int32_T numEl;
//  int32_T i;
//  emxInit_boolean_T(&emx, numDimensions);
//  numEl = 1;
//  for (i = 0; i < numDimensions; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = (boolean_T *)calloc((uint32_T)numEl, sizeof(boolean_T));
//  emx->numDimensions = numDimensions;
//  emx->allocatedSize = numEl;
//  return emx;
//}
//
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
//emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int32_T
//  numDimensions, int32_T *size)
//{
//  emxArray_boolean_T *emx;
//  int32_T numEl;
//  int32_T i;
//  emxInit_boolean_T(&emx, numDimensions);
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
//emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int32_T rows,
//  int32_T cols)
//{
//  emxArray_boolean_T *emx;
//  int32_T size[2];
//  int32_T numEl;
//  int32_T i;
//  size[0] = rows;
//  size[1] = cols;
//  emxInit_boolean_T(&emx, 2);
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
//emxArray_boolean_T *emxCreate_boolean_T(int32_T rows, int32_T cols)
//{
//  emxArray_boolean_T *emx;
//  int32_T size[2];
//  int32_T numEl;
//  int32_T i;
//  size[0] = rows;
//  size[1] = cols;
//  emxInit_boolean_T(&emx, 2);
//  numEl = 1;
//  for (i = 0; i < 2; i++) {
//    numEl *= size[i];
//    emx->size[i] = size[i];
//  }
//
//  emx->data = (boolean_T *)calloc((uint32_T)numEl, sizeof(boolean_T));
//  emx->numDimensions = 2;
//  emx->allocatedSize = numEl;
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
//void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray)
//{
//  emxFree_boolean_T(&emxArray);
//}
//
//void emxDestroyArray_real_T(emxArray_real_T *emxArray)
//{
//  emxFree_real_T(&emxArray);
//}

/* End of code generation (computePitchFeatures_exp.c) */
