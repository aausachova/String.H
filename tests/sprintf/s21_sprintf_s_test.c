#include "../s21_test.h"

START_TEST(sprintf_1_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "Test %s Test";
  char *val = "Hello work";
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// test for 3 values

START_TEST(sprintf_2_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%s Test %s Test %s";
  char *val = "Let's";
  char *val2 = "Again";
  char *val3 = "and again";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// // Different width
START_TEST(sprintf_3_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "take only 3";
  char *val2 = "no, dont take 5";
  char *val3 = "realy!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_4_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "wake me up";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_5_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "wake me up";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeroes
START_TEST(sprintf_6_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "wake me up";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";
  char *val5 = "Who are you'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_7_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "wake me up";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_8_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "wake me up";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";
  char *val5 = "Who are you'?!";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_9_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WAKE ME UP";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";
  char *val5 = "Who are you'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_10_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "WAKE ME UP";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";
  char *val5 = "Who are you'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_11_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WAKE ME UP";
  char *val2 = "before you go go go";
  char *val3 = "wanna sleep";
  char *val4 = "today is the good day";
  char *val5 = "Who are you'?!";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_12_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_13_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  int res1 = s21_sprintf(str1, str3, val, val2, val4, val3);
  int res2 = sprintf(str2, str3, val, val2, val4, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// DOES NOTT WORK ON MAC
// ZERO flag
#ifdef LINUX
START_TEST(sprintf_14_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
#endif

// Asterisk
START_TEST(sprintf_15_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;

  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  int res1 = s21_sprintf(str1, str3, val, val2, val4, val3);
  int res2 = sprintf(str2, str3, val, val2, val4, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_s_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_s "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");
  tc = tcase_create("tcase");

  // process_string  "S"
  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_4_string);
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  tcase_add_test(tc, sprintf_10_string);
  tcase_add_test(tc, sprintf_11_string);
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_13_string);
  tcase_add_test(tc, sprintf_15_string);
  tcase_add_test(tc, sprintf_16_string);
  suite_add_tcase(s, tc);

  return s;
}