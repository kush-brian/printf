#include "main.h"

/**
 * print_integers - writes integers to buffer
 * @dime: the arguments inventory with most commonly used arguments
 * @n: integer to be printed, may be type casted to long int.
 */
void print_integers(list_t *dime, long int n)
{
	long int size, ones, copy;
	int nth;

	ones = n % 10;
	size = 1;
	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		dime->c0 = '-';
		if (dime->space)
			dime->space = 0, dime->buf_index--;
		write_buffer(dime);
	}
	else if (dime->c1 == '+')
	{
		dime->c0 = '+';
		write_buffer(dime);
	}
	if (copy > 0)
	{
		while (copy / 10 != 0)
			copy /= 10, size *= 10;
		while (size > 0)
		{
			nth = n / size;
			dime->c0 = ('0' + nth);
			write_buffer(dime);
			n -= nth * size;
			size /= 10;
		}
	}
	dime->c0 = ('0' + ones);
	write_buffer(dime);
}

/**
 * print_int - writes integers to buffer
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_int(list_t *dime)
{
	int n;

	n = va_arg(*(dime->args), int);

	print_integers(dime, (long int)n);
}

/**
 * print_longint - writes long integers to buffer
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_longint(list_t *dime)
{
	long int n;

	n = va_arg(*(dime->args), long int);

	print_integers(dime, n);
}
