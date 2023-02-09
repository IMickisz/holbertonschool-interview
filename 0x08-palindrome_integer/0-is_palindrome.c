#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int reversed = 0, remainder, original;

	if (n < 10)
		return (1);
	original = n;
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	else
		return (0);

}
