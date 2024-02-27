#include "../s21_test.h"

// START_TEST(sprintf_spec_d_gen_test_1) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "d");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, 122),
//                      sprintf(str2, format, 122));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, -122),
//                      sprintf(str2, format, -122));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_d_gen_test_2) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "hd");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)0),
//                      sprintf(str2, format, (short)0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)122),
//                      sprintf(str2, format, (short)122));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)-122),
//                      sprintf(str2, format, (short)-122));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_d_gen_test_3) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "ld");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)0),
//                      sprintf(str2, format, (long)0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)122),
//                      sprintf(str2, format, (long)122));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)-122),
//                      sprintf(str2, format, (long)-122));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_d_gen_test_4) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "Ld");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (long long)0),
//                      sprintf(str2, format, (long long)0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long long)122),
//                      sprintf(str2, format, (long long)122));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long long)-122),
//                      sprintf(str2, format, (long long)-122));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

START_TEST(sprintf_spec_d_simple) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%d";
  ck_assert_int_eq(s21_sprintf(str1, format, 5), sprintf(str2, format, 5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_zero) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%010d";
  ck_assert_int_eq(s21_sprintf(str1, format, 10), sprintf(str2, format, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_dot) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.10d";
  ck_assert_int_eq(s21_sprintf(str1, format, 10), sprintf(str2, format, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_spec_d_def_test_1) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   const char *format = "%*d";
//   ck_assert_int_eq(s21_sprintf(str1, format, 5, 122),
//                    sprintf(str2, format, 5, 122));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_d_def_test_2) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   const char *format = "%.*d";
//   ck_assert_int_eq(s21_sprintf(str1, format, 5, 122),
//                    sprintf(str2, format, 5, 122));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

Suite *s21_sprintf_d_suite(void) {
  Suite *s;
  TCase *tc;
  // int n = 5 * 4 * 2 * 2 * 2 * 2;  // TODO: do define

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_d "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  // tcase_add_loop_test(tc, sprintf_spec_d_gen_test_1, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_d_gen_test_2, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_d_gen_test_3, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_d_gen_test_4, 0, n);
  tcase_add_test(tc, sprintf_spec_d_simple);
  tcase_add_test(tc, sprintf_spec_d_zero);
  tcase_add_test(tc, sprintf_spec_d_dot);
  // tcase_add_test(tc, sprintf_spec_d_def_test_1);
  // tcase_add_test(tc, sprintf_spec_d_def_test_2);
  suite_add_tcase(s, tc);

  return s;
}