#include "../s21_test.h"

START_TEST(test_s21_memcmp_equal) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, World!";

  int result_s21_memcmp = s21_memcmp(str1, str2, sizeof(str1));
  int result_memcmp = memcmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(result_s21_memcmp, result_memcmp);
}

// START_TEST(test_s21_memcmp_inequal) {
//   const char str1[] = "Hello, World!";
//   const char str2[] = "HELLO, WORLD!";

//   int result_s21_memcmp = s21_memcmp(str1, str2, sizeof(str1));
//   int result_memcmp = memcmp(str1, str2, sizeof(str1));

//   ck_assert_int_eq(result_s21_memcmp, result_memcmp);
// }

START_TEST(test_s21_memcmp_partial) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, Universe!";

  int result_s21_memcmp = s21_memcmp(str1, str2, 7);
  int result_memcmp = memcmp(str1, str2, 7);

  ck_assert_int_eq(result_s21_memcmp, result_memcmp);
}

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ memcmp "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("MemcmpCore");

  tcase_add_test(tc_core, test_s21_memcmp_equal);
  // tcase_add_test(tc_core, test_s21_memcmp_inequal);
  tcase_add_test(tc_core, test_s21_memcmp_partial);

  suite_add_tcase(s, tc_core);

  return s;
}