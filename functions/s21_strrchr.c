#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;
  char *result = S21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      result = (char *)str;
    }
    str++;
  }
  if ((char)c == '\0' && *str == '\0') result = (char *)str;
  return result;
}