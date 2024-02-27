#include "../s21_test.h"

START_TEST(sprintf_1_u_minus) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %-u Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_u_L) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %Lu Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_x_h) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %hx Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned_o) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %ou Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned_x) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %xu Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// // Three unsigned parameters
// START_TEST(sprintf_2_unsigned) {
//   char str1[BUFF_SIZE] = {0};
//   char str2[BUFF_SIZE] = {0};
//   char *str3 = "%u Test %u Test %u";
//   unsigned int val = 012;
//   unsigned int val2 = 017;
//   unsigned int val3 = 07464;
//   int res1 = s21_sprintf(str1, str3, val, val2, val3);
//   int res2 = sprintf(str2, str3, val, val2, val3);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST
// // PROCESS_X

// START_TEST(test_X_2) {
//   char str1[BUFF_SIZE] = {0};
//   char str2[BUFF_SIZE] = {0};
//   int a = s21_sprintf(
//       str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3,
//       126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
//   int b = sprintf(str2,
//   "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
//                   3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
//                   41, -41, 33);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_X_hash) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", 33), sprintf(str2, "%#X", 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_X_l) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%lX";
  ck_assert_int_eq(s21_sprintf(str1, format, 33), sprintf(str2, format, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_ouxX_suite(void) {
  Suite *s;
  TCase *tc;
  // TODO: split to 4 files
  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_ouxX "
      "НАЧАЛО\033[1;32m ==================\033[0m\n\n");
  tc = tcase_create("tcase");
  // tcase_add_test(tc, sprintf_1_hex);
  // tcase_add_test(tc, sprintf_2_hex);
  // tcase_add_test(tc, sprintf_3_hex);

  // process_u
  tcase_add_test(tc, sprintf_1_u_minus);
  tcase_add_test(tc, sprintf_1_unsigned_o);
  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_1_unsigned_x);
  // tcase_add_test(tc, sprintf_2_unsigned);

  // // // process_p
  // tcase_add_test(tc, sprintf_1_pointer);
  // tcase_add_test(tc, sprintf_2_pointer);

  // tcase_add_test(tc, sprintf_1_octal);
  // tcase_add_test(tc, sprintf_2_octal);

  tcase_add_test(tc, sprintf_1_u_L);
  tcase_add_test(tc, sprintf_1_x_h);
  tcase_add_test(tc, test_X_hash);
  tcase_add_test(tc, test_X_l);
  // tcase_add_test(tc, test_X_h);
  // tcase_add_test(tc, test_X_L);

  suite_add_tcase(s, tc);

  return s;
}