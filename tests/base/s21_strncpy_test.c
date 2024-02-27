#include "../s21_test.h"
START_TEST(test_s21_strncpy_basic) {
  char dest[50] = "Hello, World!";
  char src[] = "Testing";
  s21_size_t n = 7;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_long_source) {
  char dest[50] = "Hello, World!";
  char src[] = "ThisIsALongSourceString";
  s21_size_t n = 5;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_long_destination) {
  char dest[10] = "Hello";
  char src[] = "Test";
  s21_size_t n = 8;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_exact_length) {
  char dest[50] = "Hello, World!";
  char src[] = "Testing";
  s21_size_t n = 7;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_empty_source) {
  char dest[50] = "Hello, World!";
  char src[] = "";
  s21_size_t n = 5;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ stncpy "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_basic);
  tcase_add_test(tc_core, test_s21_strncpy_long_source);
  tcase_add_test(tc_core, test_s21_strncpy_long_destination);
  tcase_add_test(tc_core, test_s21_strncpy_exact_length);
  tcase_add_test(tc_core, test_s21_strncpy_empty_source);

  suite_add_tcase(s, tc_core);

  return s;
}