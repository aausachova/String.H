#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

char *s21_gen_di_cases(int num, const char *spec);
char *s21_gen_fe_cases(int num, const char *spec);

Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_strncmp_suite(void);

Suite *s21_insert_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_to_upper_suite(void);
Suite *s21_trim_suite(void);

Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_d_suite(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_i_suite(void);
Suite *s21_sprintf_e_suite(void);
Suite *s21_sprintf_g_suite(void);
Suite *s21_sprintf_n_suite(void);
Suite *s21_sprintf_ouxX_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_other_test_suite(void);

Suite *s21_sscanf_suite(void);

#endif