#include "s21_test.h"

int main(void) {
  printf("\033[1;32mVERTER is watching your code...¯Â_/(*_*)_/Â¯\n\n");
  Suite *base_functions_tests[] = {
      s21_memchr_suite(),  s21_strncmp_suite(),  s21_memcmp_suite(),
      s21_memcpy_suite(),  s21_memset_suite(),   s21_strchr_suite(),
      s21_strcspn_suite(), s21_strerror_suite(), s21_strlen_suite(),
      s21_strncat_suite(), s21_insert_suite(),   s21_strncpy_suite(),
      s21_strpbrk_suite(), s21_strrchr_suite(),  s21_strstr_suite(),
      s21_strtok_suite(),  s21_to_upper_suite(), s21_to_lower_suite(),
      s21_trim_suite(),    s21_sscanf_suite(),   NULL};

  Suite *sprintf_tests[] = {s21_sprintf_c_suite(),
                            s21_sprintf_d_suite(),
                            s21_sprintf_f_suite(),
                            s21_sprintf_i_suite(),
                            s21_sprintf_e_suite(),
                            s21_sprintf_other_test_suite(),
                            s21_sprintf_g_suite(),
                            s21_sprintf_ouxX_suite(),
                            s21_sprintf_s_suite(),
                            s21_sprintf_n_suite(),
                            NULL};

  int number_failed;
  SRunner *runner;
  runner = srunner_create(base_functions_tests[0]);
  for (int i = 1; base_functions_tests[i] != NULL; i++) {
    srunner_add_suite(runner, base_functions_tests[i]);
  }

  for (int i = 0; sprintf_tests[i] != NULL; i++) {
    srunner_add_suite(runner, sprintf_tests[i]);
  }

  srunner_set_log(runner, "tests/test.log");
  srunner_set_xml(runner, "tests/test.xml");
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

char *s21_gen_di_cases(int num, const char *spec) {
  const char *prec[5] = {"", ".3", ".5", ".", ".0"};
  const char *width[4] = {"", "3", "4", "7"};
  const char *zero[2] = {"", "0"};
  const char *space[2] = {"", " "};
  const char *plus[2] = {"", "+"};
  const char *minus[2] = {"", "-"};
  const int i[6] = {(num / 2 / 2 / 2) % 2,
                    (num) % 2,
                    (num / 2) % 2,
                    (num / 2 / 2) % 2,
                    (num / 2 / 2 / 2 / 2) % 4,
                    (num / 2 / 2 / 2 / 2 / 4) % 5};
  char *buf = NULL;
  if (strlen(plus[i[2]]) && strlen(space[i[3]]))
    ;
  else if (strlen(minus[i[1]]) && strlen(zero[i[0]]))
    ;
  else if (strlen(prec[i[5]]) && strlen(zero[i[0]]))
    ;
  else {
    buf = malloc(BUFF_SIZE);
    sprintf(buf, "%%%s%s%s%s%s%s%s", zero[i[0]], minus[i[1]], plus[i[2]],
            space[i[3]], width[i[4]], prec[i[5]], spec);
  }
  return buf;
}

char *s21_gen_fe_cases(int num, const char *spec) {
  const char *prec[5] = {"", ".3", ".5", ".", ".0"};
  const char *width[4] = {"", "3", "4", "13"};
  const char *zero[2] = {"", "0"};
  const char *space[2] = {"", " "};
  const char *plus[2] = {"", "+"};
  const char *minus[2] = {"", "-"};
  const char *hash[2] = {"", "#"};
  const int i[7] = {(num / 2 / 2 / 2) % 2,
                    (num) % 2,
                    (num / 2) % 2,
                    (num / 2 / 2) % 2,
                    (num / 2 / 2 / 2 / 2) % 4,
                    (num / 2 / 2 / 2 / 2 / 4) % 5,
                    (num / 2 / 2 / 2 / 2 / 4 / 5) % 2};
  char *buf = NULL;
  if (strlen(plus[i[2]]) && strlen(space[i[3]]))
    ;
  else if (strlen(minus[i[1]]) && strlen(zero[i[0]]))
    ;
  else {
    buf = malloc(BUFF_SIZE);
    sprintf(buf, "%%%s%s%s%s%s%s%s%s", hash[i[6]], zero[i[0]], minus[i[1]],
            plus[i[2]], space[i[3]], width[i[4]], prec[i[5]], spec);
  }
  return buf;
}