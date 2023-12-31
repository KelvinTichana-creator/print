#include <stddef.h>
#include "main.h"
#include <unistd.h>

/**
 * print_memory_address - Prints the memory address in hex
 *
 * @ptr: The memory address to be printed.
 *
 * Return: The number of characters printed.
 */
int print_memory_address(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;

	buffer[buffer_index++] = '0';
	buffer[buffer_index++] = 'x';

	/* Convert the memory address to hexadecimal */
	do {
		int remainder = address % 16;

		if (remainder < 10)
			buffer[buffer_index++] = '0' + remainder;
		else
			buffer[buffer_index++] = 'a' + remainder - 10;

		address /= 16;
	} while (address > 0);

	/* Print the memory address in reverse order */
	for (int i = buffer_index - 1; i >= 0; i--)
	{
		write(1, &(buffer[i]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_reversed_string - Prints a reversed string to stdout.
 *
 * @str: The string to be printed in reverse order.
 *
 * Return: The number of characters printed.
 */
int print_reversed_string(const char *str)
{
	if (str == NULL)
		str = "(null)";

	int length = 0;

	while (str[length])
		length++;

	int printed_chars = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		write(1, &(str[i]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_rot13_string - Applies the rot13 algorithm to a string
 *
 * @str: The string to be printed after applying rot13.
 *
 * Return: The number of characters printed.
 */
int print_rot13_string(const char *str)
{
	if (str == NULL)
		str = "(null)";

	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;

	while (*str)
	{
		char c = *str;

		if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		{
			char base = (c >= 'a') ? 'a' : 'A';

			c = base + ((c - base + 13) % 26);
		}

		buffer[buffer_index++] = c;
		printed_chars++;

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

