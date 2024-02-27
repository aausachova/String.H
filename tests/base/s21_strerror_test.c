#include "../s21_test.h"

START_TEST(test_s21_strerror_basic) {
  int errnum = 2;  // ENOENT: No such file or directory

  const char *result_s21 = s21_strerror(errnum);
  const char *result_original = strerror(errnum);

  ck_assert_str_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strerror_invalid_errnum) {
  int errnum = -1;  // Invalid error number

  const char *result_s21 = s21_strerror(errnum);
  const char *result_original = strerror(errnum);

  ck_assert_str_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strerror "
      "НАЧАЛО\033[1;32m ======================\033[0m\n\n");
  tc_core = tcase_create("StrerrorCore");

  tcase_add_test(tc_core, test_s21_strerror_basic);
  tcase_add_test(tc_core, test_s21_strerror_invalid_errnum);

  suite_add_tcase(s, tc_core);

  return s;
}