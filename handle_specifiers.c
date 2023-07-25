// handle_specifiers.c
#include <stddef.h>

#include "main.h"

// Function to print a character to stdout
// Returns the number of characters printed
int print_char(char c)
{
    return _putchar(c);
}

// Function to print a string to stdout
// Returns the number of characters printed
int print_string(const char *str)
{
    if (str == NULL)
        str = "(null)";

    int printed_chars = 0;
    while (*str)
    {
        _putchar(*str);
        printed_chars++;
        str++;
    }
    return printed_chars;
}

// Function to print an integer to stdout
// Returns the number of characters printed
int print_int(int num)
{
    // Handle negative numbers
    if (num < 0)
    {
        _putchar('-');
        num = -num;
    }

    // Convert the integer to a string in reverse order
    char buffer[20]; // A buffer to store the string representation of the integer
    int length = 0;  // Length of the string

    do
    {
        buffer[length++] = '0' + (num % 10);
        num /= 10;
    } while (num > 0);

    // Print the string in reverse order
    for (int i = length - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
    }

    return length;
}

