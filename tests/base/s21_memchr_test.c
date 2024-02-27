#include "../s21_test.h"

START_TEST(test_s21_memchr_basic) {
  const char str[] = "Hello, World!";
  int c = 'o';
  s21_size_t n = 13;

  void *result_s21_memchr = s21_memchr(str, c, n);
  void *result_memchr = memchr(str, c, n);

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
}

END_TEST

START_TEST(test_s21_memchr_not_found) {
  const char str[] = "Hello, World!";
  int c = 'z';
  s21_size_t n = 13;

  void *result_s21_memchr = s21_memchr(str, c, n);
  void *result_memchr = memchr(str, c, n);

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
}

END_TEST

START_TEST(test_s21_memchr_null_str) {
  char *str = NULL;
  int c = 'o';
  s21_size_t n = 0;

  void *result_s21_memchr = s21_memchr(str, c, n);
  void *result_memchr = memchr(str, c, n);

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
}

END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create(
      "\033[1;32m=========== \033[0mТЕСТИРОВАНИЕ memchr "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr_basic);
  tcase_add_test(tc_core, test_s21_memchr_not_found);
  tcase_add_test(tc_core, test_s21_memchr_null_str);

  suite_add_tcase(s, tc_core);

  return s;
}