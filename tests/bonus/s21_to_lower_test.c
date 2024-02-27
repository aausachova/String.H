#include "../s21_test.h"
START_TEST(test_to_lower_uppercase) {
  const char str[] = "HELLO";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_to_lower_lowercase) {
  const char str[] = "hello";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_to_lower_empty_string) {
  const char str[] = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_lower_mixed_case) {
  const char str[] = "HeLlO123";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello123");
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ to_lower "
      "НАЧАЛО\033[1;32m ======================\033[0m\n\n");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_uppercase);
  tcase_add_test(tc_core, test_to_lower_lowercase);
  tcase_add_test(tc_core, test_to_lower_empty_string);
  tcase_add_test(tc_core, test_to_lower_mixed_case);

  suite_add_tcase(s, tc_core);

  return s;
}