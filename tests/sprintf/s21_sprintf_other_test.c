#include "../s21_test.h"

START_TEST(sprintf_minus) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%-19s $%10.2f";
  char *s1 = "Sum of Deposits: ";
  float d1 = 50000000000.528;
  ck_assert_int_eq(s21_sprintf(str1, format, s1, d1),
                   sprintf(str2, format, s1, d1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%+d\t%+d\n";
  int d1 = 786;
  int d2 = -786;
  ck_assert_int_eq(s21_sprintf(str1, format, d1, d2),
                   sprintf(str2, format, d1, d2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%p\n";
  int a = 10;
  int *b = &a;
  ck_assert_int_eq(s21_sprintf(str1, format, b), sprintf(str2, format, b));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_other_test_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_p "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  tcase_add_test(tc, sprintf_minus);
  tcase_add_test(tc, sprintf_plus);
  tcase_add_test(tc, sprintf_p);
  suite_add_tcase(s, tc);

  return s;
}