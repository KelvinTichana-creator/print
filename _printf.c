#include <stdarg.h>
#include "main.h"

int handle_conversion_specifier(char specifier, va_list args);

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            printed_chars += handle_conversion_specifier(format[i], args);
        }
        else
        {
            _putchar(format[i]);
            printed_chars++;
        }

        i++;
    }

    va_end(args);
    return printed_chars;
}

int handle_conversion_specifier(char specifier, va_list args)
{
    switch (specifier)
    {
        case 'c':
            return print_char(va_arg(args, int));
        case 's':
            return print_string(va_arg(args, const char *));
        case 'd':
        case 'i':
            return print_int(va_arg(args, int));
        case 'b':
            return print_binary(va_arg(args, unsigned int));
        case 'u':
            return print_int(va_arg(args, unsigned int));
        case 'o':
            return print_octal(va_arg(args, unsigned int));
        case 'x':
            return print_hexadecimal(va_arg(args, unsigned int), 0);
        case 'X':
            return print_hexadecimal(va_arg(args, unsigned int), 1);
        case '%':
            _putchar('%');
            return 1;
        case 'S':
            return print_special_string(va_arg(args, const char *));
        case 'p':
            return print_memory_address(va_arg(args, void *));
        case 'r':
            return print_reversed_string(va_arg(args, const char *));
        case 'R':
            return print_rot13_string(va_arg(args, const char *));
        default:
            _putchar('%');
            _putchar(specifier);
            return 2;
    }
}
