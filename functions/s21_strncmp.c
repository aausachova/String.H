#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  if (str1 == NULL || str2 == NULL || n > s21_strlen(str1) ||
      n > s21_strlen(str2) || n == 0)
    return S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) return (int)(str1[i]) - (int)(str2[i]);
  }
  return 0;
}