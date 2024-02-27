#include "../s21_test.h"

START_TEST(test_s21_memcpy_single_char) {
  char src = 'A';
  char dest;
  s21_size_t n = 1;
  ck_assert_mem_eq(memmove(&dest, &src, n), s21_memcpy(&dest, &src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_multiple_char) {
  // Define the expected and actual memory regions
  char expected[] = "Hello, World!";
  char actual[14];
  char s21_actual[14];

  // Copy the expected data into the actual memory region using memcpy
  memcpy(actual, expected, sizeof(expected));
  s21_memcpy(s21_actual, expected, sizeof(expected));

  // Check if the memory regions are equal using ck_assert_mem_eq
  ck_assert_mem_eq(s21_actual, actual, sizeof(expected));
}
END_TEST

START_TEST(test_s21_memcpy_to_overlapping_memory_regions) {
  char src[] = "Hello";
  char dest[6];

  ck_assert_mem_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5), 5);
  ck_assert_mem_eq(memmove(dest + 1, dest, 4), s21_memcpy(dest + 1, dest, 4),
                   4);
}
END_TEST

START_TEST(test_s21_memcpy_from_overlapping_memory_regions) {
  char src[] = "Hello";
  char dest[6];

  ck_assert_mem_eq(memcpy(dest, src + 1, 4), s21_memcpy(dest, src + 1, 4), 4);
}
END_TEST

START_TEST(test_s21_memcpy_zero_bytes) {
  char src[] = "Hello";
  char dest[6];

  ck_assert_mem_eq(memcpy(dest, src, 0), s21_memcpy(dest, src, 0), 0);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "\033[1;32m========================= \033[0mТЕСТИРОВАНИЕ memcpy "
      "НАЧАЛО\033[1;32m ========================\033[0m\n\n");
  tc_core = tcase_create("MemcpyCore");

  tcase_add_test(tc_core, test_s21_memcpy_single_char);
  tcase_add_test(tc_core, test_s21_memcpy_multiple_char);
  tcase_add_test(tc_core, test_s21_memcpy_to_overlapping_memory_regions);
  tcase_add_test(tc_core, test_s21_memcpy_from_overlapping_memory_regions);
  tcase_add_test(tc_core, test_s21_memcpy_zero_bytes);

  suite_add_tcase(s, tc_core);

  return s;
}