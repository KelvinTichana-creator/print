// main.h

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_int(int num);
int print_binary(unsigned int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, int lowercase);
int print_hexadecimal_upper(unsigned int num);
int print_special_string(const char *str);
int print_memory_address(void *ptr);
int print_reversed_string(const char *str);
int print_rot13_string(const char *str);

#endif /* MAIN_H */

