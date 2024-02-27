#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest == NULL || src == NULL || n == 0) return S21_NULL;
  char *dest_end = dest;
  while (*dest_end != '\0') dest_end++;
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) dest_end[i] = src[i];
  dest_end[i] = '\0';
  return dest;
}