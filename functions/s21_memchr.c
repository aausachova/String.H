#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (str == NULL || n > s21_strlen(str)) return S21_NULL;
  const unsigned char *s = (const unsigned char *)str;
  s21_size_t i = 0;
  void *result = S21_NULL;

  while (i < n) {
    if (s[i] == (unsigned char)c) {
      result = (void *)(s + i);
      break;
    }
    i++;
  }
  return result;
}