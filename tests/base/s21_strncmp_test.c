#include "../s21_test.h"

START_TEST(test_s21_strncmp_equal) {
  const char *str1 = "hello";
  const char *str2 = "hello";

  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}

START_TEST(test_s21_strncmp_inequal) {
  const char *str1 = "hello";
  const char *str2 = "world";

  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));
}

START_TEST(test_s21_strncmp_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";

  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}

START_TEST(test_s21_strncmp_null_strings) {
  const char *str1 = S21_NULL;
  const char *str2 = S21_NULL;

  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strncmp "
      "НАЧАЛО\033[1;32m =======================\033[0m\n\n");
  tc_core = tcase_create("StrncmpCore");
  tcase_add_test(tc_core, test_s21_strncmp_equal);
  tcase_add_test(tc_core, test_s21_strncmp_inequal);
  tcase_add_test(tc_core, test_s21_strncmp_empty_strings);
  tcase_add_test(tc_core, test_s21_strncmp_null_strings);
  suite_add_tcase(s, tc_core);
  return s;
}