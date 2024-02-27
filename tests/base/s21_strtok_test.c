#include "../s21_test.h"
START_TEST(test_s21_strtok_basic) {
  char str[] = "Hello, World!";
  const char *delimiters = " ,!";

  char *str_copy = (char *)malloc(strlen(str) + 1);
  strcpy(str_copy, str);

  char *result_s21_strtok = s21_strtok(str_copy, delimiters);

  char *str_copy_strtok = (char *)malloc(strlen(str) + 1);
  strcpy(str_copy_strtok, str);

  char *result_strtok = strtok(str_copy_strtok, delimiters);

  ck_assert_str_eq(result_s21_strtok, result_strtok);

  free(str_copy);
  free(str_copy_strtok);
}
END_TEST

START_TEST(test_s21_strtok_null) {
  char str[] = "/";
  char empty_str[] = "";
  ck_assert_pstr_eq(strtok(empty_str, str), s21_strtok(empty_str, str));
}
END_TEST

START_TEST(test_s21_strtok_multiple_delimiters) {
  char str[] = "Hello, World!";
  const char *delimiters = ",!";
  char *result_s21_strtok = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21_strtok, result_strtok);
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strtok "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_basic);
  tcase_add_test(tc_core, test_s21_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_null);

  suite_add_tcase(s, tc_core);

  return s;
}