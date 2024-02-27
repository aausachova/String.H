#include "../s21_string.h"

#ifdef __APPLE__  // Для операционной системы macOS
#define ERRORS_ARRAY_SIZE 5
#define ERRORS_ARRAY \
  { "Error 1", "Error 2", "No such file or directory", "Error 4", "Error 5" }
#elif __linux__  // Для операционной системы Linux
#define ERRORS_ARRAY_SIZE 3
#define ERRORS_ARRAY \
  { "Error A", "Error B", "No such file or directory" }
#else
#define ERRORS_ARRAY_SIZE 0
#define ERRORS_ARRAY \
  {}
#endif

char *s21_strerror(int errnum) {
  static char *errors[] = ERRORS_ARRAY;
  if (errnum >= 0 && errnum < ERRORS_ARRAY_SIZE) return errors[errnum];
  return "Unknown error -1";
}