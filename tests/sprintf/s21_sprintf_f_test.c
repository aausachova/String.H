#include "../s21_test.h"

// START_TEST(sprintf_spec_f_gen_test_1) {  // TODO: split to 3 cases
//   char *format = s21_gen_fe_cases(_i, "f");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0.0),
//                      sprintf(str2, format, 0.0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, 122.87654321098),
//                      sprintf(str2, format, 122.87654321098));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, format, -122.87654321098),
//                      sprintf(str2, format, -122.87654321098));
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

// START_TEST(sprintf_spec_f_gen_test_2) {  // TODO: split to 3 cases
//   char *format = s21_gen_fe_cases(_i, "Lf");
//   if (format) {
//     char str1[BUFF_SIZE] = "";
//     char str2[BUFF_SIZE] = "";
//     s21_sprintf(str1, format, (long double)0.0);
//     sprintf(str2, format, (long double)0.0);
//     ck_assert_str_eq(str1, str2);
//     s21_sprintf(str1, format, (long double)122.87654321098);
//     sprintf(str2, format, (long double)122.87654321098);
//     ck_assert_str_eq(str1, str2);
//     s21_sprintf(str1, format, (long double)-122.87654321098);
//     sprintf(str2, format, (long double)-122.87654321098);
//     ck_assert_str_eq(str1, str2);
//     free(format);
//   }
// }
// END_TEST

START_TEST(sprintf_spec_f_def_test_0) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  const float f1 = 0.21098;
  ck_assert_int_eq(s21_sprintf(str1, format, f1), sprintf(str2, format, f1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%*f";
  ck_assert_int_eq(s21_sprintf(str1, format, 5, 122.87654321098),
                   sprintf(str2, format, 5, 122.87654321098));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.*f";
  ck_assert_int_eq(s21_sprintf(str1, format, 5, 122.87654321098),
                   sprintf(str2, format, 5, 122.87654321098));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.05),
                   sprintf(str2, format, 2.05));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.0f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.5), sprintf(str2, format, 2.5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_5) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.1f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.05),
                   sprintf(str2, format, 2.05));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_6) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, NAN);
  sprintf(str2, format, NAN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_7) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, POS_INF);
  sprintf(str2, format, POS_INF);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_8) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, NEG_INF);
  sprintf(str2, format, NEG_INF);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_1_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
//   double num = 76.756589367;
//   int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_2_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
//   double num = -76.756589367;
//   int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_3_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%Lf\n%.Lf!";
//   long double num_long = -76.756589;
//   int res1 = s21_sprintf(str1, str3, num_long, num_long);
//   int res2 = sprintf(str2, str3, num_long, num_long);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_4_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%20.10f\n%20.15f\n%-20.5f!";
//   double num = -76.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_5_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
//   long double num = 76.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_6_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %5f\ntest: %6.1f\ntest: %8.2f!";
//   double num = 76.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_7_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %10.5f\ntest: %12.4f!";
//   double num = 76.756589;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_8_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %15.1f\ntest: %16.2f\ntest: %18.3f!";
//   double num = -7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_9_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %10.4f\ntest: %25.5f!";
//   double num = -7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_10_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
//   double num = 7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_11_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
//   double num = 7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_12_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
//   double num = 7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_13_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %-#15.f\ntest: %-+25.f!";
//   double num = 7648938790.756589;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_14_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
//   double num = -365289.3462865487;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_15_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %#-10.9f!\ntest: %-+25.15f!";
//   double num = -365289.3462865487;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_16_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %15.13f!\ntest: %26.15f!";
//   double num = -365289.34628654873789362746834;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_17_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
//   double num = -365289.34628654873789362746834;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_18_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %15.13f!\ntest: %26.15f!";
//   double num = 365289.34628654873789362746834;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_19_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %18.7f!\ntest: %10.15f!";
//   double num = 365289.34628654873789362746834;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_20_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %- 23.14f!\ntest: %+ 25.15f!";
//   double num = 365289.34628654873789362746834;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_21_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: % 15f!\ntest: % -26f!\ntest: %- 18f!";
//   double num = -365789.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_22_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
//   double num = -365789.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_23_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: % 14f!\ntest: % -27f!\ntest: %- 19f!";
//   double num = 365789.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_24_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
//   double num = 365789.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_25_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
//   long double num = -3752765839673496.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_26_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %15Lf!test: %100Lf!";
//   long double num = -3752765839673496.34;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_27_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %- 26Lf!\ntest: %+- 18Lf!\ntest: %60Lf!";
//   long double num = 3752765839673496.34;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_28_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: % +15Lf!test: %100Lf!";
//   long double num = 3752765839673496.34;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_30_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %020f!\ntest: %-020f!\ntest: %+025f!";
//   double num = 837564.4753366;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_31_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %-+ 025.5f!\ntest: %- 020.4f\ntest: %+ 016.6f!";
//   double num = 837564.4753366;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_32_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %015f!\ntest: %-026f!\ntest: %+018f!";
//   double num = -947.6785643;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_33_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+- 010.2f!\ntest: %- 025.7f\ntest: %+- 18.4f!";
//   double num = -947.6785643;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_34_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
//   long double num = 278.723786;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_35_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 50.15Lf!\ntest: % +40.15Lf!";
//   long double num = 278.723786;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_36_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: % 15.1Lf!\ntest: % -26.13Lf!\ntest: %- 30.8Lf!";
//   long double num = -2358.367776967;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_37_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 50.14Lf!\ntest: % +40.14Lf!";
//   long double num = -2358.367776967;
//   int res1 = s21_sprintf(str1, str3, num, num);
//   int res2 = sprintf(str2, str3, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_38_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
//   long double num = -9999.99999;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_39_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.10Lf!\ntest: %.6Lf!\ntest: %.Lf!";
//   long double num = -9999.99999;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_40_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
//   long double num = 000000000000000.00000000000;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_41_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.6Lf!\ntest: %.Lf\ntest: %+ 0Lf!!";
//   long double num = 000000000000000.00000000000;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// // Поведение функции меняется при проверке valgrind
// START_TEST(sprintf_42_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
//   long double num = -635293201236.6495633;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_43_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
//   long double num = -635293201236.6495633;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_44_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
//   long double num = -236310753.6495633;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_45_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 0Lf!\ntest: %.6Lf!\ntest: %.13Lf!";
//   long double num = -236310753.6495633;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_46_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
//   long double num = -932578123568.;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_47_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 0Lf!\ntest: %.6Lf!\ntest: %.13Lf!";
//   long double num = -932578123568.;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_50_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
//   long double num = -93257812356836.;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_51_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %+ 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
//   long double num = -93257812356836.;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_52_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\ntest: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
//   long double num = -0.999999;
//   int res1 = s21_sprintf(str1, str3, num, num, num);
//   int res2 = sprintf(str2, str3, num, num, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_54_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\nfshgkaljck% 10.12f hgsakul";
//   double num = 0.235300;
//   int res1 = s21_sprintf(str1, str3, num);
//   int res2 = sprintf(str2, str3, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_55_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%f";
//   double num = 0.00000001;
//   int res1 = s21_sprintf(str1, str3, num);
//   int res2 = sprintf(str2, str3, num);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sprintf_56_f) {
//   char str1[BUFF_SIZE] = "";
//   char str2[BUFF_SIZE] = "";
//   char *str3 = "\n%.5f %.5f %.5f %.5f";
//   double num1 = -999.666;
//   double num2 = 0.0001;
//   double num3 = 666.999;
//   double num4 = -100.001;
//   int res1 = s21_sprintf(str1, str3, num1, num2, num3, num4);
//   int res2 = sprintf(str2, str3, num1, num2, num3, num4);
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// test 2.5 with 0 prec
// test 3.45 with 1 prec

Suite *s21_sprintf_f_suite(void) {
  Suite *s;
  TCase *tc;
  // int n = 5 * 4 * 2 * 2 * 2 * 2 * 2;  // TODO: do define

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ sprintf_f "
      "НАЧАЛО\033[1;32m =====================\033[0m\n\n");

  tc = tcase_create("tcase");

  // tcase_add_loop_test(tc, sprintf_spec_f_gen_test_1, 0, n);
  // tcase_add_loop_test(tc, sprintf_spec_f_gen_test_2, 0, n);
  tcase_add_test(tc, sprintf_spec_f_def_test_0);
  tcase_add_test(tc, sprintf_spec_f_def_test_1);
  tcase_add_test(tc, sprintf_spec_f_def_test_2);
  tcase_add_test(tc, sprintf_spec_f_def_test_3);
  tcase_add_test(tc, sprintf_spec_f_def_test_4);
  tcase_add_test(tc, sprintf_spec_f_def_test_5);
  tcase_add_test(tc, sprintf_spec_f_def_test_6);
  tcase_add_test(tc, sprintf_spec_f_def_test_7);
  tcase_add_test(tc, sprintf_spec_f_def_test_8);
  // tcase_add_test(tc, sprintf_1_f);
  // tcase_add_test(tc, sprintf_2_f);
  // tcase_add_test(tc, sprintf_3_f);
  // tcase_add_test(tc, sprintf_4_f);
  // tcase_add_test(tc, sprintf_5_f);
  // tcase_add_test(tc, sprintf_6_f);
  // tcase_add_test(tc, sprintf_7_f);
  // tcase_add_test(tc, sprintf_8_f);
  // tcase_add_test(tc, sprintf_9_f);
  // tcase_add_test(tc, sprintf_10_f);
  // tcase_add_test(tc, sprintf_11_f);
  // tcase_add_test(tc, sprintf_12_f);
  // tcase_add_test(tc, sprintf_13_f);
  // tcase_add_test(tc, sprintf_14_f);
  // tcase_add_test(tc, sprintf_15_f);
  // tcase_add_test(tc, sprintf_16_f);
  // tcase_add_test(tc, sprintf_17_f);
  // tcase_add_test(tc, sprintf_18_f);
  // tcase_add_test(tc, sprintf_19_f);
  // tcase_add_test(tc, sprintf_20_f);
  // tcase_add_test(tc, sprintf_21_f);
  // tcase_add_test(tc, sprintf_22_f);
  // tcase_add_test(tc, sprintf_23_f);
  // tcase_add_test(tc, sprintf_24_f);
  // tcase_add_test(tc, sprintf_25_f);
  // tcase_add_test(tc, sprintf_26_f);
  // tcase_add_test(tc, sprintf_27_f);
  // tcase_add_test(tc, sprintf_28_f);
  // tcase_add_test(tc, sprintf_30_f);
  // tcase_add_test(tc, sprintf_31_f);
  // tcase_add_test(tc, sprintf_32_f);
  // tcase_add_test(tc, sprintf_33_f);
  // tcase_add_test(tc, sprintf_34_f);
  // tcase_add_test(tc, sprintf_35_f);
  // tcase_add_test(tc, sprintf_36_f);
  // tcase_add_test(tc, sprintf_37_f);
  // tcase_add_test(tc, sprintf_38_f);
  // tcase_add_test(tc, sprintf_39_f);
  // tcase_add_test(tc, sprintf_40_f);
  // tcase_add_test(tc, sprintf_41_f);
  // tcase_add_test(tc, sprintf_42_f);
  // tcase_add_test(tc, sprintf_43_f);
  // tcase_add_test(tc, sprintf_44_f);
  // tcase_add_test(tc, sprintf_45_f);
  // tcase_add_test(tc, sprintf_46_f);
  // tcase_add_test(tc, sprintf_47_f);
  // tcase_add_test(tc, sprintf_50_f);
  // tcase_add_test(tc, sprintf_51_f);
  // tcase_add_test(tc, sprintf_52_f);
  // tcase_add_test(tc, sprintf_54_f);
  // tcase_add_test(tc, sprintf_55_f);
  // tcase_add_test(tc, sprintf_56_f);
  suite_add_tcase(s, tc);

  return s;
}