#include "../s21_test.h"
START_TEST(test_s21_strlen_empty_string) {
  const char *str = "";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strlen_short_string) {
  const char *str = "Hello";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
  const char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strlen "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("StrlenCore");

  tcase_add_test(tc_core, test_s21_strlen_empty_string);
  tcase_add_test(tc_core, test_s21_strlen_short_string);
  tcase_add_test(tc_core, test_s21_strlen_long_string);

  suite_add_tcase(s, tc_core);

  return s;
}