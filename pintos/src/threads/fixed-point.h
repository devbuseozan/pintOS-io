#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/* 17.14 fixed-point aritmetik.
   F = 2^14 = 16384 */

#define FP_F (1 << 14)

/* Integer -> fixed-point */
#define FP_FROM_INT(n)       ((n) * FP_F)

/* Fixed-point -> integer (sıfıra yuvarla) */
#define FP_TO_INT_ZERO(x)    ((x) / FP_F)

/* Fixed-point -> integer (en yakına yuvarla) */
#define FP_TO_INT_NEAR(x)    ((x) >= 0 ? ((x) + FP_F / 2) / FP_F \
                                        : ((x) - FP_F / 2) / FP_F)

/* Fixed-point toplama/çıkarma */
#define FP_ADD(x, y)         ((x) + (y))
#define FP_SUB(x, y)         ((x) - (y))
#define FP_ADD_INT(x, n)     ((x) + (n) * FP_F)
#define FP_SUB_INT(x, n)     ((x) - (n) * FP_F)

/* Fixed-point çarpma/bölme */
#define FP_MUL(x, y)         ((int64_t)(x) * (y) / FP_F)
#define FP_DIV(x, y)         ((int64_t)(x) * FP_F / (y))
#define FP_MUL_INT(x, n)     ((x) * (n))
#define FP_DIV_INT(x, n)     ((x) / (n))

#endif /* threads/fixed-point.h */