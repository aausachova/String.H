#include "../s21_test.h"
START_TEST(test_s21_insert_basic) {
  char dest[20] = "Hello, World!";
  const char *src = "beautiful ";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_str_eq(result_s21_insert, "Hello, beautiful World!");
  if (result_s21_insert != S21_NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  char dest[20] = "Hello, World!";
  const char *src = "";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_str_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != S21_NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_at_beginning) {
  char dest[20] = "World!";
  const char *src = "Hello, ";
  s21_size_t pos = 0;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_str_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != S21_NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_at_end) {
  char dest[20] = "Hello, ";
  const char *src = "World!";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_str_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != S21_NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_invalid_position) {
  char dest[50] = "Hello, ";
  const char *src = "World!!!!";
  s21_size_t pos = 49;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_ptr_eq(S21_NULL, result_s21_insert);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ insert "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("InsertCore");

  tcase_add_test(tc_core, test_s21_insert_basic);
  tcase_add_test(tc_core, test_s21_insert_empty_src);
  tcase_add_test(tc_core, test_s21_insert_at_beginning);
  tcase_add_test(tc_core, test_s21_insert_at_end);
  tcase_add_test(tc_core, test_s21_insert_invalid_position);

  suite_add_tcase(s, tc_core);

  return s;
}