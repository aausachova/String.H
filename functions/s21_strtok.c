#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = NULL;
  char *d;
  if (str != NULL) last_token = str;
  if (last_token == NULL) return NULL;
  d = last_token;
  while (*d != '\0' && s21_strchr(delim, *d) != NULL) d++;
  if (*d == '\0') {
    last_token = NULL;
  } else {
    char *start = d;
    d = s21_strpbrk(start, delim);
    if (d != NULL) {
      *d = '\0';
      last_token = d + 1;
    } else {
      last_token = NULL;
    }
    return start;
  }
  return NULL;
}
