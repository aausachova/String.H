#include "../s21_test.h"

START_TEST(sprintf_1_n) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "%n Test1";
  int s21_charsWritten = 0;
  int charsWritten = 0;
  int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten);
  int res = sprintf(str, format, &charsWritten);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_charsWritten, charsWritten);
}
END_TEST

// START_TEST(sprintf_2_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "Test1 %n";
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten);
//   int res = sprintf(str, format, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_3_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = " Te%nst1 ";
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten);
//   int res = sprintf(str, format, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_4_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %n Test2 ";
//   int s21_charsWritten_1 = 0;
//   int s21_charsWritten_2 = 0;
//   int charsWritten_1 = 0;
//   int charsWritten_2 = 0;
//   int s21_res =
//       s21_sprintf(s21_str, format, &s21_charsWritten_1, &s21_charsWritten_2);
//   int res = sprintf(str, format, &charsWritten_1, &charsWritten_2);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten_1, charsWritten_1);
//   ck_assert_int_eq(s21_charsWritten_2, charsWritten_2);
// }
// END_TEST

// START_TEST(sprintf_5_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %n Test2 %n Test3 ";
//   int s21_charsWritten_1 = 0;
//   int s21_charsWritten_2 = 0;
//   int s21_charsWritten_3 = 0;
//   int charsWritten_1 = 0;
//   int charsWritten_2 = 0;
//   int charsWritten_3 = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten_1,
//                             &s21_charsWritten_2, &s21_charsWritten_3);
//   int res =
//       sprintf(str, format, &charsWritten_1, &charsWritten_2,
//       &charsWritten_3);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten_1, charsWritten_1);
//   ck_assert_int_eq(s21_charsWritten_2, charsWritten_2);
// }
// END_TEST

// START_TEST(sprintf_6_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%c Test1 %n Test2 ";
//   char a = 'a';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_7_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %c Test2 ";
//   char a = 'a';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_8_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%d Test1 %n Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_9_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %d Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_10_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%c Test1 %n Test2 ";
//   char a = '\0';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_11_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %c Test2 ";
//   char a = '\0';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_12_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%c Test1 %n Test2 ";
//   char a = '\n';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_13_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %c Test2 ";
//   char a = '\n';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_14_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %c Test2 ";
//   char a = '\t';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_15_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%c Test1 %n Test2 ";
//   char a = '\t';
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_16_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %ld Test2 ";
//   long int a = 123456789012345;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_17_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%ld Test1 %n Test2 ";
//   long int a = 123456789012345;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_18_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %i Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_19_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%i Test1 %n Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_20_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %i Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_21_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%i Test1 %n Test2 ";
//   int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_22_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %o Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_23_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%o Test1 %n Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_24_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %s Test2 ";
//   const char *a = "Hello, World!";
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_25_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%s Test1 %n Test2 ";
//   const char *a = "Hello, World!";
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_26_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %u Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_27_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%u Test1 %n Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_28_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %x Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_29_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%x Test1 %n Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_30_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %X Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, a);
//   int res = sprintf(str, format, &charsWritten, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_31_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%X Test1 %n Test2 ";
//   unsigned int a = 42;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, &s21_charsWritten);
//   int res = sprintf(str, format, a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_32_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%n Test1 %p Test2 ";
//   int variable = 42;
//   int *a = &variable;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, &s21_charsWritten, (void *)a);
//   int res = sprintf(str, format, &charsWritten, (void *)a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

// START_TEST(sprintf_33_n) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "%p Test1 %n Test2 ";
//   int variable = 42;
//   int *a = &variable;
//   int s21_charsWritten = 0;
//   int charsWritten = 0;
//   int s21_res = s21_sprintf(s21_str, format, (void *)a, &s21_charsWritten);
//   int res = sprintf(str, format, (void *)a, &charsWritten);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
//   ck_assert_int_eq(s21_charsWritten, charsWritten);
// }
// END_TEST

Suite *s21_sprintf_n_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_n "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");
  tc = tcase_create("tcase");

  tcase_add_test(tc, sprintf_1_n);
  // tcase_add_test(tc, sprintf_2_n);
  // tcase_add_test(tc, sprintf_3_n);
  // tcase_add_test(tc, sprintf_4_n);
  // tcase_add_test(tc, sprintf_5_n);
  // tcase_add_test(tc, sprintf_6_n);
  // tcase_add_test(tc, sprintf_7_n);
  // tcase_add_test(tc, sprintf_8_n);
  // tcase_add_test(tc, sprintf_9_n);
  // tcase_add_test(tc, sprintf_10_n);
  // tcase_add_test(tc, sprintf_11_n);
  // tcase_add_test(tc, sprintf_12_n);
  // tcase_add_test(tc, sprintf_13_n);
  // tcase_add_test(tc, sprintf_14_n);
  // tcase_add_test(tc, sprintf_15_n);
  // tcase_add_test(tc, sprintf_16_n);
  // tcase_add_test(tc, sprintf_17_n);
  // tcase_add_test(tc, sprintf_18_n);
  // tcase_add_test(tc, sprintf_19_n);
  // tcase_add_test(tc, sprintf_20_n);
  // tcase_add_test(tc, sprintf_21_n);
  // tcase_add_test(tc, sprintf_22_n);
  // tcase_add_test(tc, sprintf_23_n);
  // tcase_add_test(tc, sprintf_24_n);
  // tcase_add_test(tc, sprintf_25_n);
  // tcase_add_test(tc, sprintf_26_n);
  // tcase_add_test(tc, sprintf_27_n);
  // tcase_add_test(tc, sprintf_28_n);
  // tcase_add_test(tc, sprintf_29_n);
  // tcase_add_test(tc, sprintf_30_n);
  // tcase_add_test(tc, sprintf_31_n);
  // tcase_add_test(tc, sprintf_32_n);
  // tcase_add_test(tc, sprintf_33_n);

  suite_add_tcase(s, tc);

  return s;
}