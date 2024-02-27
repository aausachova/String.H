#include "../s21_test.h"
START_TEST(test_s21_strpbrk_basic) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "lo");
  const char *result_strpbrk = strpbrk(str, "lo");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_not_found) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "xyz");
  const char *result_strpbrk = strpbrk(str, "xyz");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_string) {
  const char str[] = "";
  const char *result_s21_strpbrk = s21_strpbrk(str, "abc");
  const char *result_strpbrk = strpbrk(str, "abc");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_charset) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "");
  const char *result_strpbrk = strpbrk(str, "");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strpbrk "
      "НАЧАЛО\033[1;32m =======================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_basic);
  tcase_add_test(tc_core, test_s21_strpbrk_not_found);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_string);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_charset);

  suite_add_tcase(s, tc_core);

  return s;
}