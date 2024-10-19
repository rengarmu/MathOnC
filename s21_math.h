#ifndef S21_MATH_C
#define S21_MATH_C

#include <string.h>

#define S21_PI 3.14159265358L
#define S21_EXP 2.71828182845L
#define S21_EPS 1e-10
#define S21_NAN (0. / 0.)
#define s21_Infinity 1. / 0.
#define s21_negInfinity -1. / 0.
#define s21_isNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == s21_Infinity) || (x == s21_negInfinity))

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

int s21_znak(int);
long double s21_factor(int n);
long double s21_intPow(long double arg, int st);

#endif