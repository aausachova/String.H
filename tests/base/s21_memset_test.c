#include "../s21_test.h"
START_TEST(test_s21_memset_basic) {
  char str[10];
  s21_size_t n = sizeof(str);
  int c = 'A';

  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(test_s21_memset_partial) {
  char dest[10] = "abcdefghij";
  s21_size_t n = 5;
  int value = 'X';

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

START_TEST(test_s21_memset_null) {
  char dest[10] = "abcdefghij";
  s21_size_t n = 0;
  int value = 'X';

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

START_TEST(test_s21_memset_large_buffer) {
  char dest[381] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
      "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
      "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi"
      "ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
      "reprehenderit "
      "in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
      "Excepteur sint occaecat cupidatat non proident";
  s21_size_t n = strlen(dest);
  int value = 127;

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ memset "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("MemsetCore");

  tcase_add_test(tc_core, test_s21_memset_basic);
  tcase_add_test(tc_core, test_s21_memset_partial);
  tcase_add_test(tc_core, test_s21_memset_null);
  tcase_add_test(tc_core, test_s21_memset_large_buffer);

  suite_add_tcase(s, tc_core);

  return s;
}