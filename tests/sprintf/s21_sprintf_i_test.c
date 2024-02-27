#include "../s21_test.h"

START_TEST(sprintf_spec_i_simple) {
  char *format = "%i";
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, format, -0172),
                   sprintf(str2, format, -0172));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_li) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%li";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_hi) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hi";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_Li) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hi";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(sprintf_spec_oct_gen_test_1) {  // TODO: split to 3 cases
// char *format = s21_gen_di_cases(_i, "i");
//   if (format) {
// char str1[BUFF_SIZE] = "";
// char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, 00), sprintf(str2, format,
// 00)); ck_assert_str_eq(str1, str2); ck_assert_int_eq(s21_sprintf(str1,
// format, 0172),
//                  sprintf(str2, format, 0172));
// ck_assert_str_eq(str1, str2);
// ck_assert_int_eq(s21_sprintf(str1, format, -0172),
//                  sprintf(str2, format, -0172));
// ck_assert_str_eq(str1, str2);
// free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_oct_gen_test_2) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "hi");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)00),
//                      sprintf(str2, format, (short)00));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)0172),
//                      sprintf(str2, format, (short)0172));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)-0172),
//                      sprintf(str2, format, (short)-0172));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_oct_gen_test_3) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "li");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)00),
//                      sprintf(str2, format, (long)00));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)0172),
//                      sprintf(str2, format, (long)0172));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)-0172),
//                      sprintf(str2, format, (long)-0172));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_hex_gen_test_1) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "i");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0x0),
//                      sprintf(str2, format, 0x0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, 0x7a),
//                      sprintf(str2, format, 0x7a));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, -0x7a),
//                      sprintf(str2, format, -0x7a));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_hex_gen_test_2) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "hi");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)0x0),
//                      sprintf(str2, format, (short)0x0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)0x7a),
//                      sprintf(str2, format, (short)0x7a));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (short)-0x7a),
//                      sprintf(str2, format, (short)-0x7a));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_hex_gen_test_3) {  // TODO: split to 3 cases
//   char *format = s21_gen_di_cases(_i, "li");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)0x0),
//                      sprintf(str2, format, (long)0x0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)0x7a),
//                      sprintf(str2, format, (long)0x7a));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, (long)-0x7a),
//                      sprintf(str2, format, (long)-0x7a));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

Suite *s21_sprintf_i_suite(void) {
  Suite *s;
  TCase *tc;
  // int n = 5 * 4 * 2 * 2 * 2 * 2;  // TODO: do define

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_i "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  tcase_add_test(tc, sprintf_spec_i_simple);
  tcase_add_test(tc, sprintf_spec_i_li);
  tcase_add_test(tc, sprintf_spec_i_hi);
  tcase_add_test(tc, sprintf_spec_i_Li);
  // tcase_add_loop_test(tc, sprintf_spec_oct_gen_test_1, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_oct_gen_test_2, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_oct_gen_test_3, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_hex_gen_test_1, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_hex_gen_test_2, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_hex_gen_test_3, 0, n);
  suite_add_tcase(s, tc);

  return s;
}