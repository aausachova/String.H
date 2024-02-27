#include "../s21_test.h"

START_TEST(test_s21_strcspn_basic) {
  const char str[] = "Hello, World!";
  const char charset[] = ",! ";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strcspn_no_match) {
  const char str[] = "Hello, World!";
  const char charset[] = "z";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strcspn_empty_string) {
  const char str[] = "";
  const char charset[] = "abc";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
  ck_assert_int_eq(result_s21, 0);
}
END_TEST

START_TEST(test_s21_strcspn_charset_empty) {
  const char str[] = "Hello, World!";
  const char charset[] = "";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strcspn "
      "НАЧАЛО\033[1;32m =======================\033[0m\n\n");
  tc_core = tcase_create("StrcspnCore");

  tcase_add_test(tc_core, test_s21_strcspn_basic);
  tcase_add_test(tc_core, test_s21_strcspn_no_match);
  tcase_add_test(tc_core, test_s21_strcspn_empty_string);
  tcase_add_test(tc_core, test_s21_strcspn_charset_empty);

  suite_add_tcase(s, tc_core);

  return s;
}