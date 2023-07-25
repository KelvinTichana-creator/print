#include <stdarg.h>
#include "main.h"

int handle_conversion_specifier(char specifier, va_list args);

/**
 * _printf - Prints formatted output to the standard output.
 *
 * @format: A pointer to a character string containing the format.
 *          The format string is composed of zero or more directives.
 *          See the format specifiers documentation for more detail.
 * @...: The optional arguments to be inserted into the format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings). On error, -1 is returned.
 *
 * Description: The _printf function produces output according to a format
 *              as described in the format string. It can handle various
 *              conversion specifiers, such as %c, %s, %d, %i, %u, %o, %x,
 *              %X, %p, %b, %r, %R, and other non-custom specifiers. It also
 *              handles custom specifiers for special string printing and
 *              ROT13 cipher. The function writes output to the std
 */
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
	return (printed_chars);
}

/**
 * handle_conversion_specifier - Handles conversion specifier for _printf.
 *
 * @specifier: The conversion specifier to be handled.
 * @args: The va_list containing the optional arguments.
 *
 * Return: The number of characters printed for the specific specifier.
 */
int handle_conversion_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			return (print_char(va_arg(args, int)));
		case 's':
			return (print_string(va_arg(args, const char *)));
		case 'd':
		case 'i':
			return (print_int(va_arg(args, int)));
		case 'b':
			return (print_binary(va_arg(args, unsigned int)));
		case 'u':
			return (print_int(va_arg(args, unsigned int)));
		case 'o':
			return (print_octal(va_arg(args, unsigned int)));
		case 'x':
			return (print_hexadecimal(va_arg(args, unsigned int), 0));
		case 'X':
			return (print_hexadecimal(va_arg(args, unsigned int), 1));
		case '%':
			_putchar('%');
			return (1);
		case 'S':
			return (print_special_string(va_arg(args, const char *)));
		case 'p':
			return (print_memory_address(va_arg(args, void *)));
		case 'r':
			return (print_reversed_string(va_arg(args, const char *)));
		case 'R':
			return (print_rot13_string(va_arg(args, const char *)));
		default:
			_putchar('%');
			_putchar(specifier);
			return (2);
	}
}
