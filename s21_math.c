#include "s21_math.h"

int s21_abs(int x) { return x >= 0 ? x : (-1) * x; }

long double s21_atan(double x) {
  long double rez = 0.;
  if (x == s21_Infinity) {
    rez = S21_PI / 2;
  } else if (x == s21_negInfinity) {
    rez = -S21_PI / 2;
  } else if (s21_abs(x) < 0) {
    rez = S21_NAN;
  } else if (x == 1.) {
    rez = S21_PI / 4;
  } else if (x == -1.) {
    rez = -S21_PI / 4;
  } else if (x < 1.0 && x > -1.0) {
    for (int i = 0; i < 500; i++) {
      double f = 1.0 + 2 * i;
      rez = rez + (s21_pow(-1.0, i) * s21_pow(x, f) / f);
    }
  } else if ((x > 1.0 || x < -1.0) && x != s21_Infinity &&
             x != s21_negInfinity) {
    for (int i = 0; i < 500; i++) {
      rez += (s21_pow(-1, i) * s21_pow(x, (-1 - 2 * i))) / (1 + 2 * i);
    }
    rez = (S21_PI * s21_pow(s21_pow(x, 2), 0.5)) / (2 * x) - rez;
  }
  return rez;
}

long double s21_pow(double base, double exp) {
  long double rez = 0;
  if (base == 1 || exp == 0)
    rez = 1;
  else if (base < 0 && (int)exp != exp)
    rez = S21_NAN;
  else if (base == S21_NAN || exp == S21_NAN)
    ;
  else if (exp == s21_Infinity)
    rez = 0;
  else if (exp == s21_negInfinity)
    rez = s21_negInfinity;
  else if (base == 0)
    rez = 0;
  else {
    if (exp < 0)
      rez = 1. / s21_pow(base, -exp);
    else if ((int)exp == exp)
      rez = s21_intPow(base, (int)exp);
    else
      rez = s21_exp(exp * s21_log(base));
  }
  return rez;
}

long double s21_asin(double x) {
  long double rez = 0.;
  if (x > 1. || x < -1.) {
    rez = S21_NAN;
  } else if (s21_abs(x) < 0) {
    rez = S21_NAN;
  } else if (x == 1.) {
    rez = S21_PI / 2;
  } else if (x == -1.) {
    rez = -S21_PI / 2;
  } else {
    rez = s21_atan(x / s21_pow(1. - s21_pow(x, 2.), 0.5));
  }
  return rez;
}

long double s21_acos(double x) {
  long double rez = 0.;
  if (x > 1.0 || x < -1.0) {
    rez = S21_NAN;
  } else if (s21_abs(x) < 0) {
    rez = S21_NAN;
  } else if (x == 1.0) {
    rez = 0;
  } else if (x == -1.0) {
    rez = S21_PI;
  } else {
    rez = 2 * s21_atan(s21_pow(((1 - x) / (1 + x)), 0.5));
  }
  return rez;
}

long double s21_ceil(double x) {
  long double rez = 0.;
  if (x == s21_Infinity) {
    rez = s21_Infinity;
  } else if (x == s21_negInfinity) {
    rez = s21_negInfinity;
  } else if (s21_abs(x) < 0) {
    rez = S21_NAN;
  } else {
    rez = x - s21_fmod(x, 1.);
    if (x > 0) rez += 1.;
  }
  return rez;
}

long double s21_cos(double x) {
  long double rez = 0.;
  if (x == S21_NAN || x >= s21_Infinity || x <= s21_negInfinity)
    rez = S21_NAN;
  else
    rez = s21_sin(x + S21_PI / 2);
  return rez;
}

long double s21_exp(double x) {
  if (s21_isNAN(x)) return S21_NAN;
  if (S21_ISINF(x)) return x < 0 ? 0 : s21_Infinity;
  int sign = x < 0;
  if (sign) x = -x;
  long double result = 1, temp = x;
  unsigned n = 1;
  while (s21_fabs(temp) >= S21_EPS && result != s21_Infinity) {
    result += temp;
    temp = (temp * x) / ++n;
    if (result > __DBL_MAX__) {
      result = s21_Infinity;
    }
  }
  return sign ? (1 / result) : result;
}

long double s21_fabs(double x) {
  if (x < 0) x *= -1.;
  return x;
}

long double s21_floor(double x) {
  long double rez = (long long int)x;
  if (x == s21_Infinity)
    rez = s21_Infinity;
  else if (x == s21_negInfinity)
    rez = s21_negInfinity;
  else if (s21_abs(x) < 0)
    rez = S21_NAN;
  else if (s21_fabs(x - rez) > 0. && s21_fabs(x) > 0.) {
    if (x < 0.) rez -= 1;
  }
  return rez;
}

long double s21_fmod(double x, double y) {
  long double rez = 0;
  if (x == s21_Infinity || x == s21_negInfinity)
    rez = S21_NAN;
  else if (y == s21_Infinity || y == s21_negInfinity)
    rez = x;
  else if (y == 0 || y != y)
    rez = S21_NAN;
  else {
    y = s21_fabs(y);
    long long int mean = x / y;
    rez = x - mean * y;
    if (s21_fabs(rez) > y) rez = 0;
  }
  return rez;
}

long double s21_log(double x) {
  long double rez = 0;
  if (x < 0 || x != x) {
    rez = S21_NAN;
  } else if (x == 0) {
    rez = (-1) * s21_Infinity;
  } else if (x == s21_Infinity) {
    rez = s21_Infinity;
  } else if (x <= 1) {
    x--;
    int i = 1;
    long double mean = (-1) * x, prev = 1, it = mean / i;
    while (s21_fabs(it) > S21_EPS) {
      mean = prev * (-1) * x;
      it = mean / i;
      rez -= it;
      prev = mean;
      i++;
    }
  } else {
    int i = 0;
    while (s21_exp(i) < x) i++;
    long double prev, l = i - 1, r = i;
    rez = (l + r) / 2;
    prev = rez + 1;
    while (s21_fabs(prev - rez) > S21_EPS) {
      if (s21_exp(rez) > x) r = rez;
      if (s21_exp(rez) < x) l = rez;
      prev = rez;
      rez = (l + r) / 2;
    }
  }
  return rez;
}

long double s21_sin(double x) {
  long double rez;
  if (x == S21_NAN || x == s21_Infinity || x == s21_negInfinity)
    rez = S21_NAN;
  else {
    double mx = x;
    int fz = 1;
    if (mx < 0) {
      mx = -mx;
      fz = -1;
    }
    if (mx > 2 * S21_PI) {
      mx = s21_fmod(x, 2 * S21_PI);
      fz = 1;
    }
    long double step;
    int n = 0;
    rez = mx;
    do {
      n++;
      step = (s21_znak(n) * s21_intPow(mx, 2 * n + 1)) / s21_factor(2 * n + 1);
      rez += step;
    } while (s21_fabs(step) >= S21_EPS);
    rez = rez * fz;
  }
  return rez;
}

long double s21_sqrt(double a) { return s21_pow(a, 0.5); }

long double s21_tan(double x) {
  long double res = 0.0;
  int tmp = 0;
  if (x == S21_NAN || x == s21_negInfinity || x == s21_Infinity) {
    res = S21_NAN;
    tmp = 1;
  }

  if (tmp == 0) {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

int s21_znak(int i) {
  int rez = 0;
  if (i % 2 == 0)
    rez = 1;
  else
    rez = -1;
  return rez;
}

long double s21_factor(int n) {
  long double rez = 1;
  for (int i = 1; i <= n; i++) rez *= i;
  return rez;
}

long double s21_intPow(long double arg, int pow) {
  long double rez = 1;
  for (int i = 1; i <= pow; i++) rez *= arg;
  return rez;
}
