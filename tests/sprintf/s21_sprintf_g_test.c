#include "../s21_test.h"

// START_TEST(sprintf_1_g) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "Helo%Lg";
//   double a = -764231539.;
//   int s21_res = s21_sprintf(s21_str, format, a);
//   int res = sprintf(str, format, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

START_TEST(sprintf_2_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\n%g\n%.g\n%4g\n%4.g\n%5.10g!";
  double a = -764231539.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
  int res = sprintf(str, format, a, a, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_3_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\n%#g\n%#.g\n%#5.g\n%#.0g\n%#0.0g!";
  double a = -665695342471359.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
  int res = sprintf(str, format, a, a, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_4_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_5_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %010g\nForth test: %010.g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_6_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: %0.0g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a);
  int res = sprintf(str, format, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_7_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.g!";
  double a =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_8_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %010g\nForth test: %010.g\nFifth test:%0.0g!";
  double a =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a);
  int res = sprintf(str, format, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_9_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_10_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %020.4g\nForth test: %020.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_11_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: %020.2g\nSixth test: %020.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_12_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: %020.g\n Eighth test: %020.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_13_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: % 21g\nSecond test: % 21.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_14_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: % 20.4g\nForth test: % 20.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_15_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: % 20.2g\nSixth test: % 20.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_16_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: % 20.g\n Eighth test: % 20.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_17_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: % 31g\nSecond test: % 30.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_18_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: % 33.4g\nForth test: % 35.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_19_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: % 36.2g\nSixth test: % 45.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_20_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: % 64.g\n Eighth test: % 80.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

// START_TEST(sprintf_21_g) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %g\nSecond test: %g!";
//   double a = -89435776876.;
//   double b = -894357768.76;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_22_g) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %g\nForth test: %g\n!";
//   double a = -89435.776876;
//   double b = -0.89435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_23_g) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nNew test: %g\nSecond test: %g!";
//   double a = -.89435776876;
//   double b = -.00089435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_24_g) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\nThird test: %g\nForth test: %g\n!";
//   double a = -0.000000089435776876;
//   double b = -0000000000000.89435776876;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_25_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %.G!\ntest: %#G!\ntest: %#.G!\ntest: %0.G!\n";
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

// START_TEST(sprintf_26_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 013.G\ntest: %#4.9G\ntest: %016.2G!";
//   double a = -.3529373967;
//   double b = -.0003529373967;
//   double c = -0.00000003529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b, c);
//   int res = sprintf(str, format, a, b, c);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_27_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %20.G\ntest: %-20.G\n!";
//   double a = -.3529373967;
//   double b = -0000000000000.3529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_28_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 30.1G\ntest: % 30.G\ntest: %030.0G!";
//   double a = .3529373967;
//   double b = .0003529373967;
//   double c = 0.00000003529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b, c);
//   int res = sprintf(str, format, a, b, c);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_29_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %066.G\ntest: %-20.G\n!";
//   double a = .3529373967;
//   double b = 0000000000000.3529373967;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_30_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %- 17.1G\ntest: % -17.1G!";
//   double a = 53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_31_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %# 10.2G\ntest: % #10.0G\ntest: %010.G\n!";
//   double a = -53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_32_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %- 67.1G\ntest: % -67.1G!";
//   double a = 1234567890000.0938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_33_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %# 100.0G\ntest: % #100.0G\ntest: %0100.G\n!";
//   double a = -.12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_34_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 070.10G\ntest: % -67.10G\n!";
//   double a = 1234567890000.0938217586;
//   double b = -.12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_35_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 070.10G\ntest: % -67.10G\n!";
//   double a = -12345678900000938217586.;
//   double b = .12345678900000938217586;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_36_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 10.1G\ntest: %- 10.1G!";
//   double a = 53296575676899283734747273752737878257.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_37_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % -10.0G\ntest: %- 10.0G\ntest: % -10.G\n!";
//   double a = 53296575676899283.734747273752737878257;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_38_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: % 20G\ntest: %-20G\ntest: %+ 020.G\n!";
//   double a = .000000005329657567689928373474727375273787825732159676631957;
//   double b = 53296575676899283.73474727375273787825732159676631957;
//   int s21_res = s21_sprintf(s21_str, format, a, b, a);
//   int res = sprintf(str, format, a, b, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_39_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %#20.G\ntest: %- 20G!";
//   double a = 5329657567689928373474727375.273787825732159676631957;
//   double b = 53296575676899283734747273752737878257.32159676631957;
//   int s21_res = s21_sprintf(s21_str, format, a, b);
//   int res = sprintf(str, format, a, b);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_40_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%.g\n%.2g\n%.5G\n%.9G\n%.13G!";
//   double a = -2599999999.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_41_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%.Lg\n%.2Lg\n%.5Lg\n%.9Lg\n%.13LG!";
//   long double a = -2599999999.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_42_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\n%g\n%.g\n%.5g\n%.9g\n%.15G!";
//   double a = 0;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
//   int res = sprintf(str, format, a, a, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_43_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %20Lg!\ntest: %Lg!\ntest: %-10Lg!";
//   long double a =
//       -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
//   int s21_res = s21_sprintf(s21_str, format, a, a, a);
//   int res = sprintf(str, format, a, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

// START_TEST(sprintf_44_G) {
//   char s21_str[BUFF_SIZE] = {0};
//   char str[BUFF_SIZE] = {0};
//   char *format = "\ntest: %060Lg!\ntest: %.14Lg!";
//   long double a =
//       -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
//   int s21_res = s21_sprintf(s21_str, format, a, a);
//   int res = sprintf(str, format, a, a);
//   ck_assert_pstr_eq(s21_str, str);
//   ck_assert_int_eq(s21_res, res);
// }
// END_TEST

Suite *s21_sprintf_g_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_g "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  // tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);
  tcase_add_test(tc, sprintf_8_g);
  tcase_add_test(tc, sprintf_9_g);
  tcase_add_test(tc, sprintf_10_g);
  tcase_add_test(tc, sprintf_11_g);
  tcase_add_test(tc, sprintf_12_g);
  tcase_add_test(tc, sprintf_13_g);
  tcase_add_test(tc, sprintf_14_g);
  tcase_add_test(tc, sprintf_15_g);
  tcase_add_test(tc, sprintf_16_g);
  tcase_add_test(tc, sprintf_17_g);
  tcase_add_test(tc, sprintf_18_g);
  tcase_add_test(tc, sprintf_19_g);
  tcase_add_test(tc, sprintf_20_g);
  // tcase_add_test(tc, sprintf_21_g);
  // tcase_add_test(tc, sprintf_22_g);
  // tcase_add_test(tc, sprintf_23_g);
  // tcase_add_test(tc, sprintf_24_g);
  // tcase_add_test(tc, sprintf_25_G);
  // tcase_add_test(tc, sprintf_26_G);
  // tcase_add_test(tc, sprintf_27_G);
  // tcase_add_test(tc, sprintf_28_G);
  // tcase_add_test(tc, sprintf_29_G);
  // tcase_add_test(tc, sprintf_30_G);
  // tcase_add_test(tc, sprintf_31_G);
  // tcase_add_test(tc, sprintf_32_G);
  // tcase_add_test(tc, sprintf_33_G);
  // tcase_add_test(tc, sprintf_34_G);
  // tcase_add_test(tc, sprintf_35_G);
  // tcase_add_test(tc, sprintf_36_G);
  // tcase_add_test(tc, sprintf_37_G);
  // tcase_add_test(tc, sprintf_38_G);
  // tcase_add_test(tc, sprintf_39_G);
  // tcase_add_test(tc, sprintf_40_G);
  // tcase_add_test(tc, sprintf_41_G);
  // tcase_add_test(tc, sprintf_42_G);
  // tcase_add_test(tc, sprintf_43_G);
  // tcase_add_test(tc, sprintf_44_G);
  suite_add_tcase(s, tc);

  return s;
}