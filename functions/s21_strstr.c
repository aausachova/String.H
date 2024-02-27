#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *str = (char *)haystack;
  char *ndl = (char *)needle;
  char *res = S21_NULL;
  if (*ndl == '\0' || *ndl == '\0') res = str;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] == *ndl) {
      char *tmp = &str[i];
      int tmp_res = s21_strncmp(tmp, ndl, s21_strlen(ndl));
      if (tmp_res == 0) {
        res = &str[i];
        break;
      }
    }
  }
  return res;
}