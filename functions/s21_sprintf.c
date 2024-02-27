#include "../s21_string.h"

typedef struct format_options {
  char* p_str;
  char spec;
  int plus_flag;
  int minus_flag;
  int space_flag;
  int hash_flag;
  int zero_flag;
  int width;
  int is_precise;
  int precision;
  char length_type;
} format_options;

void s21_itoa(__int128 value, char* str, int radix) {
  char buf[BUFF_SIZE] = "";
  int size = 0;
  if (value == 0) {
    buf[size++] = '0';
  } else {
    for (; value; value /= radix, size++) {
      buf[size] = DIGITS[value % radix];
    }
  }
  while (size) {
    *str++ = buf[--size];
  }
  *str = 0;
}

void s21_ftoa(long double value, char* str, int precision, int hash_flag) {
  char integer_buf[BUFF_SIZE] = "";
  char fractional_buf[BUFF_SIZE] = "";
  long double integer_part;
  long double fractional_part;

  long double exp = powl(10, precision);

  // разделение на целую и дробную части
  if (!precision && (modfl(value, &integer_part) == 0.5)) {
    fractional_part = 0.0;
    integer_part += (int)integer_part % 2;
  } else {
    fractional_part = modfl(value, &integer_part);
    if (!precision) {
      integer_part = roundl(value);
    } else {
      integer_part += roundl(fractional_part * exp) / exp;
    }
  }

  // целая часть
  int i = 0;
  if (integer_part < 1) {
    *str++ = '0';
  }
  for (; integer_part >= 1; i++) {
    integer_buf[i] = (int)fmodl(integer_part, 10) + 48;
    integer_part /= 10;
  }
  i--;
  for (; i >= 0; --i) {
    *str++ = integer_buf[i];
  }

  // дробная часть
  if (precision || hash_flag) {
    *str++ = '.';
    // printf("||%s\n", str);
    fractional_part = roundl(fractional_part * exp);
    i = 0;
    for (; i < precision; i++) {
      fractional_buf[precision - i - 1] = (int)fmodl(fractional_part, 10) + 48;
      fractional_part /= 10;
    }
    // добавление нулей
    for (; i >= 0; i--) *str++ = fractional_buf[precision - i];
  }
  *str = 0;
}

void s21_etoa(long double value, char* str, format_options* options) {
  char buf[BUFF_SIZE] = "";
  long double expo = floorl(log10l(value));
  long double mant = value / powl(10, (int)expo);

  expo = (expo == POS_INF || expo == NEG_INF) ? 0 : expo;
  mant = isnan(mant) ? 0 : mant;
  s21_ftoa(mant, buf, options->precision, options->hash_flag);
  for (int i = 0; buf[i]; i++) {
    *str++ = buf[i];
  }

  *str++ = options->spec < 'a' ? 'E' : 'e';

  if (expo < 0) {
    *str++ = '-';
    expo = -expo;
  } else {
    *str++ = '+';
  }

  s21_itoa((long long)expo, buf, 10);
  if (s21_strlen(buf) == 1) {
    *str++ = '0';
  }
  for (int i = 0; buf[i]; i++) {
    *str++ = buf[i];
  }
  *str = 0;
}

void s21_shift_left(char* str) {
  while (*(str + 1)) {
    *str = *(str + 1);
    str++;
  }
  *str = 0;
}

void s21_gtoa(long double value, char* str, format_options* options) {
  char buf[BUFF_SIZE] = "";
  long double expo = floorl(log10l(value));
  long double mant = value / powl(10, (int)expo);
  expo = (expo == POS_INF || expo == NEG_INF) ? 0 : expo;
  mant = isnan(mant) ? 0 : mant;
  int len = 0;

  if (expo < -4 || expo >= (options->precision == 0 ? 1 : options->precision)) {
    options->precision =
        options->precision - 1 < 0 ? 0 : options->precision - 1;
    s21_etoa(value, buf, options);
    len = s21_strlen(buf) - 1;
    for (; buf[len] != 'e' && buf[len] != 'E'; len--)
      ;
    len--;

    for (; buf[len] == '0'; len--) {
      s21_shift_left(buf + len);
    }
    if (buf[++len] == '.') {
      s21_shift_left(buf + len);
    }

  } else {
    int precision = options->precision < 1 ? 1 : options->precision;

    int shift = 0;
    long double integer_part = floorl(value);
    long double fractional_part = value - integer_part;
    for (; integer_part >= 1; integer_part /= 10) shift++;
    fractional_part *= 10;

    for (; fractional_part != 0 && floorl(fractional_part) < 1;
         fractional_part *= 10)
      shift--;
    precision = precision - shift < 1 ? 1 : precision - shift;

    s21_ftoa(value, buf, precision, options->hash_flag);
    len = s21_strlen(buf) - 1;
    for (; buf[len] == '0'; len--) {
      buf[len] = 0;
    }
    if (buf[len] == '.') {
      buf[len] = 0;
    }
  }

  for (int i = 0; buf[i]; i++) *str++ = buf[i];
  *str = 0;
}

int s21_is_digit(int c) { return c >= '0' && c <= '9'; }

void s21_insert_zeros(char* str, int n) {
  int len = s21_strlen(str);
  for (int i = 0; i < n; i++) {
    for (int j = len + 1 + i; j > i; j--) str[j] = str[j - 1];
    str[i] = '0';
  }
}

void push_buf_to_output_buf(char** output_buf, const char* buf,
                            format_options* options) {
  options->width -= s21_strlen(buf);
  if (!options->minus_flag) {
    for (; options->width > 0; options->width--) {
      *(*output_buf)++ = ' ';
    }
  }
  if (options->spec == 'c' && !*buf) {
    *(*output_buf)++ = '\0';
    *(*output_buf) = '\0';
  } else {
    while (*buf) {
      *(*output_buf)++ = *buf++;
    }
  }

  for (; options->width > 0; options->width--) {
    *(*output_buf)++ = ' ';
  }
}

void format_string(char** output_buf, char* value, format_options* options) {
  char* buf = malloc(BUFF_SIZE);
  char* p_buf = buf;
  int len = (int)s21_strlen(value);
  if (options->precision > len || !options->is_precise)
    options->precision = len;
  for (; *value && options->precision; options->precision--) *buf++ = *value++;
  *buf = 0;
  push_buf_to_output_buf(output_buf, p_buf, options);
  free(p_buf);
}

void format_unsigned(char** output_buf, unsigned long long value,
                     format_options* options) {
  char* buf = malloc(BUFF_SIZE);
  char* p_buf = buf;
  int prefix = 0;
  int radix = 10;

  if (options->minus_flag) {
    options->zero_flag = 0;
  }
  if (options->spec == 'o') {
    radix = 8;
  } else if (options->spec == 'x' || options->spec == 'X') {
    radix = 16;
  }
  if (value && options->hash_flag) {
    switch (options->spec) {
      case 'o':
        *buf++ = '0';
        prefix = 1;
        break;
      case 'x':
        *buf++ = '0';
        *buf++ = 'x';
        prefix = 2;
        break;
      case 'X':
        *buf++ = '0';
        *buf++ = 'X';
        prefix = 2;
        break;
    }
  }
  s21_itoa(value, buf, radix);
  if (options->spec == 'X') {
    for (int i = 0; buf[i]; i++)
      if (buf[i] >= 'a' && buf[i] <= 'f') buf[i] -= 32;
  }
  if (!options->precision) {
    options->zero_flag = 0;
    if (*buf == '0') *buf = '\0';
  }
  if (options->precision || options->zero_flag) {
    int n = options->precision - s21_strlen(buf);
    if (options->spec == 'o') n -= prefix;
    if (options->zero_flag && options->width > options->precision)
      n += (options->width - options->precision - prefix);
    s21_insert_zeros(buf, n);
  }

  push_buf_to_output_buf(output_buf, p_buf, options);
  free(p_buf);
}

void format_float(char** output_buf, long double value,
                  format_options* options) {
  char* buf = malloc(BUFF_SIZE);
  char* p_buf = buf;
  int sign = 1;
  if (options->minus_flag) {
    options->minus_flag = 0;
  }
  if (value < 0) {
    *buf++ = '-';
    value = -value;
  } else if (options->plus_flag) {
    *buf++ = '+';
  } else if (options->space_flag) {
    *buf++ = ' ';
  } else {
    sign = 0;
  }

  if (isnan(value)) {
    *buf++ = 'n';
    *buf++ = 'a';
    *buf++ = 'n';
    *buf = 0;
  } else if (value == POS_INF || value == NEG_INF) {
    *buf++ = 'i';
    *buf++ = 'n';
    *buf++ = 'f';
    *buf = 0;
  } else {
    if (options->spec == 'f') {
      s21_ftoa(value, buf, options->precision, options->hash_flag);
    } else if (options->spec == 'e' || options->spec == 'E') {
      s21_etoa(value, buf, options);
    } else if (options->spec == 'g' || options->spec == 'G') {
      s21_gtoa(value, buf, options);
    }
    if (options->zero_flag) {
      int n = (options->width - s21_strlen(buf) - sign);
      s21_insert_zeros(buf, n);
    }
  }

  push_buf_to_output_buf(output_buf, p_buf, options);
  free(p_buf);
}

void format_int(char** output_buf, long long value, format_options* options) {
  char* buf = malloc(BUFF_SIZE);
  char* p_buf = buf;
  int sign = 1;
  if (value < 0) {
    *buf++ = '-';
    value = -value;
  } else if (options->plus_flag) {
    *buf++ = '+';
  } else if (options->space_flag) {
    *buf++ = ' ';
  } else {
    sign = 0;
  }
  s21_itoa(value, buf, 10);
  if (!options->precision) {
    options->zero_flag = 0;
    if (*buf == '0') *buf = '\0';
  }
  if (options->precision || options->zero_flag) {
    int zeros_number = options->precision - s21_strlen(buf);
    if (options->zero_flag && options->width > options->precision) {
      zeros_number += (options->width - options->precision - sign);
    }
    s21_insert_zeros(buf, zeros_number);
  }
  push_buf_to_output_buf(output_buf, p_buf, options);
  free(p_buf);
}

void format_char(char** output_buf, int value, format_options* options) {
  const char buf[2] = {value, '\0'};
  push_buf_to_output_buf(output_buf, buf, options);
}

void format_by_spec(char** output_buf, va_list* p_args, format_options* options,
                    const char* p_output_buf) {
  switch (options->spec) {
    case 'c':
      if (options->length_type == 'l')
        format_char(output_buf, va_arg(*p_args, wchar_t), options);
      else
        format_char(output_buf, va_arg(*p_args, int), options);
      break;
    case 'd':
    case 'i':
      if (options->length_type == 'l') {
        format_int(output_buf, va_arg(*p_args, long), options);
      } else if (options->length_type == 'h') {
        format_int(output_buf, (short)va_arg(*p_args, int), options);
      } else if (options->length_type == 'L') {
        format_int(output_buf, va_arg(*p_args, long long), options);
      } else {
        format_int(output_buf, va_arg(*p_args, int), options);
      }
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      if (options->length_type == 'L')
        format_float(output_buf, va_arg(*p_args, long double), options);
      else
        format_float(output_buf, va_arg(*p_args, double), options);
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
      if (options->length_type == 'l')
        format_unsigned(output_buf, va_arg(*p_args, unsigned long), options);
      else if (options->length_type == 'h')
        format_unsigned(output_buf, (short)va_arg(*p_args, unsigned int),
                        options);
      else if (options->length_type == 'L')
        format_unsigned(output_buf, va_arg(*p_args, unsigned long long),
                        options);
      else
        format_unsigned(output_buf, va_arg(*p_args, unsigned int), options);
      break;
    case 'p':
      options->spec = 'x';
      options->hash_flag = 1;
      unsigned long long value = va_arg(*p_args, unsigned long long);
#ifdef LINUX
      if (value == 0) {
        options->precision = 5;
        format_string(output_buf, "(nil)", options);
      } else
        format_unsigned(output_buf, value, options);
#else
      options->hash_flag = 1;
      format_unsigned(output_buf, value, options);
#endif
      break;
    case 's':
      format_string(output_buf, va_arg(*p_args, char*), options);
      break;
    case 'n':
      *va_arg(*p_args, int*) = *output_buf - p_output_buf;
      break;
  }
}

void parse_flags(char c, format_options* options) {
  switch (c) {
    case '+':
      options->plus_flag = 1;
      break;
    case '-':
      options->minus_flag = 1;
      break;
    case ' ':
      options->space_flag = 1;
      break;
    case '#':
      options->hash_flag = 1;
      break;
    case '.':
      options->is_precise = 1;
      options->precision = 0;
      break;
    case 'l':
      options->length_type = 'l';
      break;
    case 'h':
      options->length_type = 'h';
      break;
    case 'L':
      options->length_type = 'L';
      break;
  }
}

void parse_format(char** output_buf, char** format, va_list* p_args,
                  format_options* options, char* p_output_buf) {
  (*format)++;

  options->precision = 1;
  for (; *(*format) && !s21_strchr(PRINTF_SPECS, *(*format)); (*format)++) {
    parse_flags(*(*format), options);
    if (!options->is_precise && !options->zero_flag && *(*format) == '0' &&
        !options->width) {
      options->zero_flag = 1;
    }
    // я не до конца понимаю что здесь написано и откуда эти *10 и -48
    else if (options->is_precise && s21_is_digit(*(*format))) {
      options->precision = options->precision * 10 + *(*format) - 48;
    } else if (options->is_precise && *(*format) == '*') {
      options->precision =
          va_arg(*p_args, int);  // ЗДЕСЬ НАДО БЫТЬ АККУРАТНЫМ С УКАЗАТЕЛЯМИ,
                                 // МОЖЕТ ВОЗНИКНУТЬ ОШИБКА
    } else if (s21_is_digit(*(*format))) {
      options->width = options->width * 10 + *(*format) - 48;
    } else if (*(*format) == '*') {
      options->width =
          va_arg(*p_args, int);  // ЗДЕСЬ НАДО БЫТЬ АККУРАТНЫМ С УКАЗАТЕЛЯМИ,
      // МОЖЕТ ВОЗНИКНУТЬ ОШИБКА
    }
  }

  options->spec = *(*format)++;
  if (!options->is_precise && s21_strchr(SCIENTIFIC_SPECS, options->spec)) {
    options->precision = SCIENTIFIC_PRECISION;
  }
  format_by_spec(output_buf, p_args, options, p_output_buf);
}

void print_formatted_string_to_buf(char* output_buf, char* format,
                                   va_list* p_args) {
  char* p_output_buf = output_buf;
  while (*format) {
    if (*format == '%' && *(format + 1) != '%') {
      format_options options = {0};
      parse_format(&output_buf, &format, p_args, &options, p_output_buf);
      *output_buf++ = *format++;
    } else if (*format == '%' && *(format + 1) == '%') {
      *output_buf++ = *format++;
      format++;
    } else {
      *output_buf++ = *format++;
    }
  }
  *output_buf = '\0';
}

int s21_sprintf(char* str, const char* format, ...) {
  char* output_buf = str;
  va_list p_args;
  va_start(p_args, format);
  print_formatted_string_to_buf(output_buf, (char*)format, &p_args);
  va_end(p_args);
  return s21_strlen(output_buf);
}
