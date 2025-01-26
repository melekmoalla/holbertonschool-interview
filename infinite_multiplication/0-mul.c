#include "holberton.h"
#include <stdlib.h>

/**
 * print_error_and_exit - Prints "Error" and exits with status 98
 */
void print_error_and_exit(void)
{
	char *error_msg = "Error\n";


	while (*error_msg)
		_putchar(*error_msg++);
	exit(98);
}

/**
 * is_digit_string - Checks if a string is composed only of digits
 * @str: The string to check
 * Return: 1 if the string is valid, 0 otherwise
 */
int is_digit_string(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * multiply_numbers - Multiplies two numbers and prints the result
 * @num1: The first number (as string)
 * @num2: The second number (as string)
 */
void multiply_numbers(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry, prod;
	int *result;

	/* Calculate lengths of num1 and num2 */
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	/* Allocate memory for result */
	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		exit(98);

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
			carry = prod / 10;
			result[i + j + 1] = prod % 10;
			result[i + j] += carry;
		}
	}

	/* Skip leading zeros */
	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	/* Print the result */
	if (i == len1 + len2)
		_putchar('0');
	while (i < len1 + len2)
		_putchar(result[i++] + '0');
	_putchar('\n');

	free(result);
}

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error_and_exit();

	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
		print_error_and_exit();

	multiply_numbers(argv[1], argv[2]);
	return (0);
}
