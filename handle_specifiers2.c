#include "main.h"
#include <unistd.h>

/**
 * print_hexadecimal_upper - Prints an unsigned integer in hex
 *
 * @num: The unsigned integer to be printed in uppercase hexadecimal format.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal_upper(unsigned int num)
{
	return (print_hexadecimal(num, 0));
}

/**
 * print_special_string - Prints a string with special characters handled.
 *
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_special_string(const char *str)
{
	if (str == NULL)
		str = "(null)";

	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;

	while (*str)
	{
		if (*str < ' ' || *str >= 127)
		{
			/* Print non-printable characters in the specified format */
			buffer[buffer_index++] = '\\';
			buffer[buffer_index++] = 'x';
			buffer[buffer_index++] = "0123456789ABCDEF"[(*str >> 4) & 0xF];
			buffer[buffer_index++] = "0123456789ABCDEF"[(*str & 0xF)];
			printed_chars += 4;
		}
		else
		{
			/* Print printable characters as is */
			buffer[buffer_index++] = *str;
			printed_chars++;
		}
		if (buffer_index >= 1020)
		{
			/* Buffer is almost full, flush it to stdout */
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}

		str++;
	}

	/* Flush any remaining characters in the buffer */
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}
	return (printed_chars);
}
