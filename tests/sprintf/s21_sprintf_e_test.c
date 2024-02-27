#include "../s21_test.h"

// START_TEST(sprintf_spec_e_gen_test_1) {  // TODO: split to 3 cases
//   char *format = s21_gen_fe_cases(_i, "e");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0e0),
//                      sprintf(str2, format, 0e0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, 122e2),
//                      sprintf(str2, format, 122e2));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, 122e-2),
//                      sprintf(str2, format, 122e-2));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, -122e-2),
//                      sprintf(str2, format, -122e-2));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

START_TEST(sprintf_spec_e_def_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 122e2);
  sprintf(str2, format, 122e2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 1.05e-5);
  sprintf(str2, format, 1.05e-5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, -122e-2);
  sprintf(str2, format, -122e-2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, NAN);
  sprintf(str2, format, NAN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_5) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 1.0 / 0.0);
  sprintf(str2, format, 1.0 / 0.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_6) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%E";
  s21_sprintf(str1, format, -122e-2);
  sprintf(str2, format, -122e-2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_1_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%e Test %5e Test %5.e";
//   double a = -764231539.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_2_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%e\n%.e\n%4e\n%4.e\n%5.10e!";
//   double a = -764231539.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_3_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
//   double a = -665695342471359.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_4_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %020e\nSecond test: %020.e!";
//   double a = -5921563224775967.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_5_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %010e\nForth test: %010.e!";
//   double a = -5921563224775967.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_6_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nFifth test: %0.0e!";
//   double a = -5921563224775967.;
//   int s21_res = s21_sprintf(s21_str, format, a);
//   int res = sprintf(str, format, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_7_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %020e\nSecond test: %020.e!";
//   double a =
//       -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_8_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %010e\nForth test: %010.e\nFifth test:
//   %0.0e!"; double a =
//       -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_9_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %020e\nSecond test: %020.5e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_10_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %020.4e\nForth test: %020.3e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_11_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nFifth test: %020.2e\nSixth test: %020.1e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_12_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nSeventh test: %020.e\n Eighth test: %020.0e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_13_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: % 20e\nSecond test: % 20.5e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_14_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: % 20.4e\nForth test: % 20.3e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_15_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nFifth test: % 20.2e\nSixth test: % 20.1e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_16_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nSeventh test: % 20.e\n Eighth test: % 20.0e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_17_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: % 31e\nSecond test: % 30.5e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_18_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: % 33.4e\nForth test: % 35.3e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_19_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nFifth test: % 36.2e\nSixth test: % 45.1e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_20_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nSeventh test: % 64.e\n Eighth test: % 80.0e!";
//   double a = -592156322477596.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_21_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %e\nSecond test: %e!";
//   double a = -89435776876.;
//   double b = -894357768.76;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_22_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %e\nForth test: %e\n!";
//   double a = -89435.776876;
//   double b = -0.89435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_23_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %e\nSecond test: %e!";
//   double a = -.89435776876;
//   double b = -.00089435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_24_e) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %e\nForth test: %e\n!";
//   double a = -0.000000089435776876;
//   double b = -0000000000000.89435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_25_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %.E!\ntest: %#E!\ntest: %#.E!\ntest: %0.E!\n";
//   double a = -.89435776876;
//   double b = -.00089435776876;
//   double c = -0.000000089435776876;
//   double d = -0000000000000.89435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b, c, d);
//   int res = sprintf(str, format, a, b, c, d);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_26_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 013.E\ntest: %#4.9E\ntest: %016.2E!";
//   double a = -.3529373967;
//   double b = -.0003529373967;
//   double c = -0.00000003529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b, c);
//   int res = sprintf(str, format, a, b, c);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_27_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %20.E\ntest: %-20.E\n!";
//   double a = -.3529373967;
//   double b = -0000000000000.3529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_28_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 30.1E\ntest: % 30.E\ntest: %030.0E!";
//   double a = .3529373967;
//   double b = .0003529373967;
//   double c = 0.00000003529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b, c);
//   int res = sprintf(str, format, a, b, c);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_29_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %066.E\ntest: %-20.E\n!";
//   double a = .3529373967;
//   double b = 0000000000000.3529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_30_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %- 17.1E\ntest: % -17.1E!";
//   double a = 53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_31_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %# 10.2E\ntest: % #10.0E\ntest: %010.E\n!";
//   double a = -53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_32_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %- 67.1E\ntest: % -67.1E!";
//   double a = 1234567890000.0938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_33_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %# 100.0E\ntest: % #100.0E\ntest: %0100.E\n!";
//   double a = -.12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_34_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 070.10E\ntest: % -67.10E\n!";
//   double a = 1234567890000.0938217586;
//   double b = -.12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_35_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 070.10E\ntest: % -67.10E\n!";
//   double a = -12345678900000938217586.;
//   double b = .12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_36_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 10.1E\ntest: %- 10.1E!";
//   double a = 53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_37_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % -10.0E\ntest: %- 10.0E\ntest: % -10.E\n!";
//   double a = 53296575676899283.734747273752737878257;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_38_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 20E\ntest: %-20E\ntest: %+ 020.E\n!";
//   double a = .000000005329657567689928373474727375273787825732159676631957;
//   double b = 53296575676899283.73474727375273787825732159676631957;
//   int s21_res = s21_sprintf(s21_str, format, a, b, a);
//   int res = sprintf(str, format, a, b, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_39_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %#20.E\ntest: %- 20E!";
//   double a = 5329657567689928373474727375.273787825732159676631957;
//   double b = 53296575676899283734747273752737878257.32159676631957;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_40_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%.e\n%.2e\n%.5E\n%.9E\n%.13E!";
//   double a = -2599999999.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_41_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
//   long double a = -2599999999.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_42_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%e\n%.e\n%.5e\n%.9e\n%.15E!";
//   double a = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_43_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %20Le!\ntest: %Le!\ntest: %-10Le!";
//   long double a =
//       -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_44_E) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %060Le!\ntest: %.13Le!";
//   long double a =
//       -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

Suite *s21_sprintf_e_suite(void) {
  Suite *s;
  TCase *tc;
  // int n = 5 * 4 * 2 * 2 * 2 * 2 * 2;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_e "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  // tcase_add_loop_test(tc, sprintf_spec_e_gen_test_1, 0, n);
  tcase_add_test(tc, sprintf_spec_e_def_test_1);
  tcase_add_test(tc, sprintf_spec_e_def_test_2);
  tcase_add_test(tc, sprintf_spec_e_def_test_3);
  tcase_add_test(tc, sprintf_spec_e_def_test_4);
  tcase_add_test(tc, sprintf_spec_e_def_test_5);
  tcase_add_test(tc, sprintf_spec_e_def_test_6);
  // tcase_add_test(tc, sprintf_1_e);
  // tcase_add_test(tc, sprintf_2_e);
  // tcase_add_test(tc, sprintf_3_e);
  // tcase_add_test(tc, sprintf_4_e);
  // tcase_add_test(tc, sprintf_5_e);
  // tcase_add_test(tc, sprintf_6_e);
  // tcase_add_test(tc, sprintf_7_e);
  // tcase_add_test(tc, sprintf_8_e);
  // tcase_add_test(tc, sprintf_9_e);
  // tcase_add_test(tc, sprintf_10_e);
  // tcase_add_test(tc, sprintf_11_e);
  // tcase_add_test(tc, sprintf_12_e);
  // tcase_add_test(tc, sprintf_13_e);
  // tcase_add_test(tc, sprintf_14_e);
  // tcase_add_test(tc, sprintf_15_e);
  // tcase_add_test(tc, sprintf_16_e);
  // tcase_add_test(tc, sprintf_17_e);
  // tcase_add_test(tc, sprintf_18_e);
  // tcase_add_test(tc, sprintf_19_e);
  // tcase_add_test(tc, sprintf_20_e);
  // tcase_add_test(tc, sprintf_21_e);
  // tcase_add_test(tc, sprintf_22_e);
  // tcase_add_test(tc, sprintf_23_e);
  // tcase_add_test(tc, sprintf_24_e);
  // tcase_add_test(tc, sprintf_25_E);
  // tcase_add_test(tc, sprintf_26_E);
  // tcase_add_test(tc, sprintf_27_E);
  // tcase_add_test(tc, sprintf_28_E);
  // tcase_add_test(tc, sprintf_29_E);
  // tcase_add_test(tc, sprintf_30_E);
  // tcase_add_test(tc, sprintf_31_E);
  // tcase_add_test(tc, sprintf_32_E);
  // tcase_add_test(tc, sprintf_33_E);
  // tcase_add_test(tc, sprintf_34_E);
  // tcase_add_test(tc, sprintf_35_E);
  // tcase_add_test(tc, sprintf_36_E);
  // tcase_add_test(tc, sprintf_37_E);
  // tcase_add_test(tc, sprintf_38_E);
  // tcase_add_test(tc, sprintf_39_E);
  // tcase_add_test(tc, sprintf_40_E);
  // tcase_add_test(tc, sprintf_41_E);
  // tcase_add_test(tc, sprintf_42_E);
  // tcase_add_test(tc, sprintf_43_E);
  // tcase_add_test(tc, sprintf_44_E);
  suite_add_tcase(s, tc);

  return s;
}