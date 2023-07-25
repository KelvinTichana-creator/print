#include <stddef.h>
#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format.
 *
 * @num: The unsigned integer to be printed in binary format.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	int binary_digits[32];
	int index = 0;

	while (num > 0)
	{
		binary_digits[index++] = num % 2;
		num /= 2;
	}

	int printed_chars = 0;

	for (int i = index - 1; i >= 0; i--)
	{
		_putchar('0' + binary_digits[i]);
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_octal - Prints an unsigned integer in octal format
 *
 * @num: The unsigned integer to be printed in octal format.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	char buffer[20];
	int length = 0;

	while (num > 0)
	{
		buffer[length++] = '0' + (num % 8);
		num /= 8;
	}

	for (int i = length - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (length);
}

/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal
 *
 * @num: The unsigned integer to be printed in hexadecimal format.
 * @lowercase: A flag indicating whether to use lowercase
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int lowercase)
{
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	char buffer[20];
	int length = 0;
	char base = lowercase ? 'a' : 'A';

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			buffer[length++] = '0' + remainder;

		else
			buffer[length++] = base + remainder - 10;

		num /= 16;
	}

	for (int i = length - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (length);
}
