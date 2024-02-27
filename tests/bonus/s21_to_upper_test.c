#include "../s21_test.h"
START_TEST(test_s21_to_upper_basic) {
  char str[] = "Hello, World!";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "HELLO, WORLD!");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

START_TEST(test_s21_to_upper_empty_str) {
  char str[] = "";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

START_TEST(test_s21_to_upper_null_str) {
  char *str = S21_NULL;
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_ptr_eq(result_s21_to_upper, S21_NULL);

  free(result_s21_to_upper);
}
END_TEST

START_TEST(test_s21_to_upper_mixed_case) {
  char str[] = "HeLLo, WoRLd!";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "HELLO, WORLD!");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ to_upper "
      "НАЧАЛО\033[1;32m ======================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper_basic);
  tcase_add_test(tc_core, test_s21_to_upper_empty_str);
  tcase_add_test(tc_core, test_s21_to_upper_null_str);
  tcase_add_test(tc_core, test_s21_to_upper_mixed_case);

  suite_add_tcase(s, tc_core);

  return s;
}