#include "s21_math.h"

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Функция тестирования какой-либо задачи.
START_TEST(abs_test) {
  int x1 = 5.3;
  ck_assert_int_eq(abs(x1), s21_abs(x1));

  int x2 = -17.9;
  ck_assert_int_eq(abs(x2), s21_abs(x2));

  int x3 = 0;
  ck_assert_int_eq(abs(x3), s21_abs(x3));
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(DBL_MIN), acos(DBL_MIN), S21_EPS);
  ck_assert_ldouble_nan(s21_acos(7));
  ck_assert_ldouble_nan(s21_acos(-15));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(DBL_MAX));
  ck_assert_double_nan(s21_acos(s21_Infinity));
  ck_assert_double_nan(s21_acos(s21_negInfinity));
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPS);
  ck_assert_ldouble_nan(s21_asin(-7));
  ck_assert_ldouble_nan(s21_asin(15));
  ck_assert_ldouble_eq_tol(s21_asin(DBL_MIN), asin(DBL_MIN), S21_EPS);
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(DBL_MAX));
  ck_assert_ldouble_nan(s21_asin(s21_Infinity));
  ck_assert_double_nan(s21_asin(s21_negInfinity));
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(s21_Infinity), atan(s21_Infinity), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(s21_negInfinity), atan(s21_negInfinity),
                           S21_EPS);
}
END_TEST

START_TEST(atan_test2) {
  for (float i = -7; i <= 7; i += 1.33) {
    double x = s21_atan(i);
    double y = atan(i);
    ck_assert_double_eq_tol(x, y, S21_EPS);
  }
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(DBL_MIN), ceil(DBL_MIN));
  ck_assert_ldouble_eq(s21_ceil(-DBL_MIN), ceil(-DBL_MIN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_eq(s21_ceil(s21_Infinity), ceil(s21_Infinity));
  ck_assert_ldouble_eq(s21_ceil(s21_negInfinity), ceil(s21_negInfinity));
  ck_assert_double_eq(ceil(-7.), s21_ceil(-7.));
  ck_assert_double_eq(ceil(-765.8), s21_ceil(-765.8));
  ck_assert_double_eq(ceil(1.02), s21_ceil(1.02));
  ck_assert_double_eq(ceil(19999.087), s21_ceil(19999.087));
  ck_assert_double_eq(ceil(-19999.087), s21_ceil(-19999.087));
  ck_assert_double_eq(ceil(0.05), s21_ceil(0.05));
  ck_assert_double_eq(ceil(-0.1), s21_ceil(-0.1));
  ck_assert_double_eq(ceil(-1e-7), s21_ceil(-1e-7));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_double_eq_tol(s21_cos(0), cos(0), S21_EPS);
  ck_assert_double_eq_tol(s21_cos(DBL_MIN), cos(DBL_MIN), S21_EPS);
  ck_assert_int_eq(s21_cos(s21_Infinity), cos(s21_Infinity));
  ck_assert_int_eq(s21_cos(s21_negInfinity), cos(s21_negInfinity));
}
END_TEST

START_TEST(cos_test2) {
  for (int x = -24; x <= 24; x += 2) {
    ck_assert_double_eq_tol(cos(x * S21_PI / 12), s21_cos(x * S21_PI / 12),
                            S21_EPS);
  }
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), S21_EPS);
  ck_assert_int_eq(s21_exp(DBL_MAX), exp(DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_exp(-DBL_MAX), exp(-DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(1e-9), exp(1e-9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-1e-9), exp(-1e-9), S21_EPS);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_int_eq(s21_exp(s21_Infinity), exp(s21_Infinity));
  ck_assert_ldouble_eq_tol(s21_exp(s21_negInfinity), exp(s21_negInfinity),
                           S21_EPS);
  ck_assert_double_eq_tol(s21_exp(DBL_MIN), exp(DBL_MIN), S21_EPS);
  ck_assert_double_eq_tol(s21_exp(DBL_MIN), exp(DBL_MIN), S21_EPS);
  ck_assert_double_eq_tol(s21_exp(-DBL_MIN), exp(-DBL_MIN), S21_EPS);
}
END_TEST

START_TEST(exp_test2) {
  for (double i = -21; i < 21; i += 2) {
    double x = s21_exp(i);
    double y = exp(i);
    ck_assert_double_eq_tol(x, y, S21_EPS);
  }
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_eq_tol(s21_fabs(DBL_MIN), fabs(DBL_MIN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-DBL_MIN), fabs(-DBL_MIN), S21_EPS);
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(s21_negInfinity));
  ck_assert_double_eq(fabs(-7.), s21_fabs(-7.));
  ck_assert_double_eq(fabs(-765.8), s21_fabs(-765.8));
  ck_assert_double_eq(fabs(1.02), s21_fabs(1.02));
  ck_assert_double_eq(fabs(19999.087), s21_fabs(19999.087));
  ck_assert_double_eq(fabs(-19999.087), s21_fabs(-19999.087));
  ck_assert_double_eq(fabs(0.05), s21_fabs(0.05));
  ck_assert_double_eq(fabs(-0.1), s21_fabs(-0.1));
  ck_assert_double_eq(fabs(-1e-7), s21_fabs(-1e-7));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(DBL_MIN), floor(DBL_MIN));
  ck_assert_ldouble_eq(s21_floor(-DBL_MIN), floor(-DBL_MIN));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq(s21_floor(s21_Infinity), floor(s21_Infinity));
  ck_assert_ldouble_eq(s21_floor(s21_negInfinity), floor(s21_negInfinity));
  ck_assert_double_eq(floor(-7.), s21_floor(-7.));
  ck_assert_double_eq(floor(-765.8), s21_floor(-765.8));
  ck_assert_double_eq(floor(1.02), s21_floor(1.02));
  ck_assert_double_eq(floor(19999.087), s21_floor(19999.087));
  ck_assert_double_eq(floor(-19999.087), s21_floor(-19999.087));
  ck_assert_double_eq(floor(0.05), s21_floor(0.05));
  ck_assert_double_eq(floor(-0.1), s21_floor(-0.1));
  ck_assert_double_eq(floor(-1e-7), s21_floor(-1e-7));
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_ldouble_eq_tol(s21_fmod(0, DBL_MAX), fmod(0, DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, -DBL_MAX), fmod(0, -DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MAX, -DBL_MIN), fmod(DBL_MAX, -DBL_MIN),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MAX, DBL_MIN), fmod(DBL_MAX, DBL_MIN),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-DBL_MAX, -DBL_MIN),
                           fmod(-DBL_MAX, -DBL_MIN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-DBL_MAX, DBL_MIN), fmod(-DBL_MAX, DBL_MIN),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MAX, -DBL_MAX), fmod(DBL_MAX, -DBL_MAX),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MAX, DBL_MAX), fmod(DBL_MAX, DBL_MAX),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MIN, -DBL_MAX), fmod(DBL_MIN, -DBL_MAX),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(DBL_MIN, DBL_MAX), fmod(DBL_MIN, DBL_MAX),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-DBL_MIN, -DBL_MAX),
                           fmod(DBL_MIN, -DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-DBL_MIN, DBL_MAX), fmod(DBL_MIN, DBL_MAX),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, s21_Infinity), fmod(0, s21_Infinity),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, s21_negInfinity),
                           fmod(0, s21_negInfinity), S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(s21_Infinity, -DBL_MIN));
  ck_assert_ldouble_nan(s21_fmod(s21_Infinity, 0));
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, s21_Infinity));
}
END_TEST

START_TEST(fmod_test2) {
  for (double a = -150; a < 150; a += 12) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_eq(s21_log(0), log(0));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(0.666), log(0.666), S21_EPS);
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_infinite(s21_log(s21_Infinity));
  ck_assert_ldouble_nan(s21_log(-DBL_MAX));
}
END_TEST

START_TEST(log_test2) {
  for (double i = 1; i < 150; i += 21.25) {
    double x = s21_log(i);
    double y = log(i);
    ck_assert_double_eq_tol(x, y, 1e-6);
  }
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0.000, 1), pow(0.000, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0.000), pow(1, 0.000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0.000, 0.000), pow(0.000, 0.000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, DBL_MIN), pow(1, DBL_MIN), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(-15, 1.567));
  ck_assert_ldouble_infinite(s21_pow(0.988, s21_negInfinity));
  ck_assert_ldouble_eq_tol(s21_pow(0.988, s21_Infinity),
                           pow(0.988, s21_Infinity), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_pow(DBL_MAX, DBL_MIN), pow(DBL_MAX, DBL_MIN),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_Infinity), pow(1, s21_Infinity),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_negInfinity), pow(1, s21_negInfinity),
                           S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(s21_Infinity, 1));
  ck_assert_ldouble_eq_tol(s21_pow(s21_Infinity, -1), pow(s21_Infinity, -1),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(s21_Infinity, 0), pow(s21_Infinity, 0),
                           S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(DBL_MAX, DBL_MAX));
}
END_TEST

START_TEST(pow_test2) {
  for (double i = -21; i <= 21; i += 2.025) {
    for (double k = -7; k < 7; k += 2) {
      long double x = s21_pow(i, k);
      long double y = pow(i, k);
      if ((x != S21_NAN && y != S21_NAN) &&
          !(x == s21_Infinity && y == s21_Infinity) &&
          !(x == s21_negInfinity && y == s21_negInfinity)) {
        ck_assert_double_eq_tol(x, y, S21_EPS);
      }
      x = s21_pow(i, k);
      y = pow(i, k);
      if ((x != S21_NAN && y != S21_NAN) &&
          !(x == s21_Infinity && y == s21_Infinity) &&
          !(x == s21_negInfinity && y == s21_negInfinity)) {
        ck_assert_double_eq_tol(x, y, S21_EPS);
      }
    }
  }
}
END_TEST

START_TEST(sin_test) {
  ck_assert_double_eq_tol(s21_sin(0), sin(0), S21_EPS);
  ck_assert_double_eq_tol(s21_sin(DBL_MIN), sin(DBL_MIN), S21_EPS);
  ck_assert_int_eq(s21_sin(s21_Infinity), sin(s21_Infinity));
  ck_assert_int_eq(s21_sin(s21_negInfinity), sin(s21_negInfinity));
}
END_TEST

START_TEST(sin_test2) {
  for (int x = -24; x <= 24; x += 2) {
    ck_assert_double_eq_tol(sin(x * S21_PI / 12), s21_sin(x * S21_PI / 12),
                            S21_EPS);
  }
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), S21_EPS);
  ck_assert_ldouble_infinite(s21_sqrt(s21_Infinity));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(S21_PI), sqrt(S21_PI), S21_EPS);
}
END_TEST

START_TEST(tan_test) {
  ck_assert_double_eq_tol(s21_tan(0), tan(0), S21_EPS);
  ck_assert_double_eq_tol(s21_tan(DBL_MIN), tan(DBL_MIN), S21_EPS);
  ck_assert_int_eq(s21_tan(s21_Infinity), tan(s21_Infinity));
  ck_assert_int_eq(s21_tan(s21_negInfinity), tan(s21_negInfinity));
}
END_TEST

// Функция создания набора тестов.
Suite *example_suite_create(void) {
  Suite *suite = suite_create("Example");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("Core of example");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, acos_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, atan_test2);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, cos_test2);
  tcase_add_test(tcase_core, exp_test);
  tcase_add_test(tcase_core, exp_test2);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test);
  tcase_add_test(tcase_core, fmod_test2);
  tcase_add_test(tcase_core, log_test);
  tcase_add_test(tcase_core, log_test2);
  tcase_add_test(tcase_core, pow_test);
  tcase_add_test(tcase_core, pow_test2);
  tcase_add_test(tcase_core, sin_test);
  tcase_add_test(tcase_core, sin_test2);
  tcase_add_test(tcase_core, sqrt_test);
  tcase_add_test(tcase_core, tan_test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = example_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
