#include "../s21_test.h"
START_TEST(test_s21_strncat_basic) {
  char dest[20] = "Hello, ";
  const char *src = "World!";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest[20] = "Hello, ";
  const char *src = "";

  ck_assert_pstr_eq(strncat(dest, src, 5), s21_strncat(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncat_empty_dest) {
  char dest[20] = "";
  const char *src = "World!";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strncat_long_src) {
  char dest[20] = "Hello, ";
  const char *src = "This is a long string";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ strcat "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("StrncatCore");

  tcase_add_test(tc_core, test_s21_strncat_basic);
  tcase_add_test(tc_core, test_s21_strncat_empty_src);
  tcase_add_test(tc_core, test_s21_strncat_empty_dest);
  tcase_add_test(tc_core, test_s21_strncat_long_src);

  suite_add_tcase(s, tc_core);

  return s;
}