#include "../s21_test.h"

START_TEST(test_s21_strstr_basic) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "World";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

START_TEST(test_s21_strstr_not_found) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "Universe";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strstr "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_basic);
  tcase_add_test(tc_core, test_s21_strstr_not_found);
  tcase_add_test(tc_core, test_s21_strstr_empty_needle);

  suite_add_tcase(s, tc_core);

  return s;
}