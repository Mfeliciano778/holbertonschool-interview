#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - Checks whether an unsigned integer is a palindrome
 * @n: Unsigned Integer
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int last_digit, n_copy = n, reverse = 0;

	if (n < 10)
		return (1);
	while (n != 0)
	{
		last_digit = n % 10;
		reverse = reverse * 10 + last_digit;
		n = n / 10;
	}
	if (n_copy == reverse)
		return (1);
	return (0);
}
