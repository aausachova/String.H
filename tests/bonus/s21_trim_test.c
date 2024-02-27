#include "../s21_test.h"
START_TEST(test_trim_spaces) {
  const char src[] = "   Hello, World!   ";
  const char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_custom_chars) {
  const char src[] = "###Hello, World!***";
  const char trim_chars[] = "#*";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_spaces_punctuation) {
  const char src[] = " !!! Hello, World?...";
  const char trim_chars[] = " !?.";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World");
  free(result);
}
END_TEST

START_TEST(test_trim_middle_chars) {
  const char src[] = "abc_xyz123abc";
  const char trim_chars[] = "abc";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "_xyz123");
  free(result);
}
END_TEST

START_TEST(test_trim_null_terminator) {
  const char *src = "h";
  const char *trim_chars = "h";
  char *s21_result = s21_trim(src, trim_chars);
  ck_assert_str_eq(s21_result, "\0");
  free(s21_result);
}
END_TEST

START_TEST(test_trim_tab_new_line) {
  const char *src = "hello world";
  const char *trim_chars = "\0";
  char *s21_result = s21_trim(src, trim_chars);
  ck_assert_str_eq(s21_result, "hello world");
  free(s21_result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ trim "
      "НАЧАЛО\033[1;32m ==========================\033[0m\n\n");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_trim_spaces);
  tcase_add_test(tc_core, test_trim_custom_chars);
  tcase_add_test(tc_core, test_trim_spaces_punctuation);
  tcase_add_test(tc_core, test_trim_middle_chars);
  tcase_add_test(tc_core, test_trim_null_terminator);
  tcase_add_test(tc_core, test_trim_tab_new_line);

  suite_add_tcase(s, tc_core);

  return s;
}