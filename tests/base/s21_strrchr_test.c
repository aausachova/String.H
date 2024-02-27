#include "../s21_test.h"
START_TEST(test_s21_strrchr_basic) {
  const char str[] = "Hello, World!";
  const char *result_s21_strrchr = s21_strrchr(str, 'o');
  const char *result_strrchr = strrchr(str, 'o');

  ck_assert_str_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

START_TEST(test_s21_strrchr_null_character) {
  const char str_with_null[] = "Hello\0World";
  const char *result_s21_strrchr = s21_strrchr(str_with_null, '\0');
  const char *result_strrchr = strrchr(str_with_null, '\0');

  ck_assert_ptr_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
  const char str[] = "Hello, World!";
  const char *result_s21_strrchr = s21_strrchr(str, 'z');
  const char *result_strrchr = strrchr(str, 'z');

  ck_assert_ptr_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strrchr "
      "НАЧАЛО\033[1;32m =======================\033[0m\n\n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_basic);
  tcase_add_test(tc_core, test_s21_strrchr_not_found);
  tcase_add_test(tc_core, test_s21_strrchr_null_character);

  suite_add_tcase(s, tc_core);

  return s;
}