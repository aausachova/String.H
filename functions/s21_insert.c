#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == NULL || str == NULL || start_index > s21_strlen(src))
    return S21_NULL;
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_result = len_src + len_str;
  char *result = (char *)malloc(len_result + 1);
  if (result == NULL) return S21_NULL;
  s21_size_t i, j;
  for (i = 0; i < start_index; i++) result[i] = src[i];
  for (j = 0; j < len_str; j++) result[i + j] = str[j];
  for (j = i; j < len_src; j++) result[len_str + j] = src[j];
  result[len_result] = '\0';
  return result;
}