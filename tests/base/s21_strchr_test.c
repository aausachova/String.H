#include "../s21_test.h"
START_TEST(test_s21_strchr_basic) {
  const char str[] = "Hello, World!";
  const char ch = 'o';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char str[] = "Hello, World!";
  const char ch = 'z';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strchr_null_character) {
  const char str[] = "Hello, World!";
  const char ch = '\0';

  ck_assert_ptr_null(s21_strchr(str, ch));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char str[] = "";
  const char ch = 'a';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strchr "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("StrchrCore");

  tcase_add_test(tc_core, test_s21_strchr_basic);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_null_character);
  tcase_add_test(tc_core, test_s21_strchr_empty_string);

  suite_add_tcase(s, tc_core);

  return s;
}