#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *p1 = str1;
  const char *p2;

  while (*p1 != '\0') {
    p2 = str2;
    while (*p2 != '\0') {
      if (*p1 == *p2) return (char *)p1;
      p2++;
    }
    p1++;
  }

  return S21_NULL;
}
