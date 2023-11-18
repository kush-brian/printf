#include "main.h"

/**
 * print_unsigned - writes unsigned long integers to buffer
 * @dime: the arguments inventory with most commonly used arguments
 * @n: unsigned long int to print (function can be used for shorts as well)
 */
void print_unsigned(list_t *dime, unsigned long int n)
{
	unsigned long int copy, size;
	int nth;

	size = 1;
	copy = n;
	if (n < 10)
	{
		dime->c0 = ('0' + n);
		write_buffer(dime);
	}
	else
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
}

/**
 * print_u_int - writes unsigned integers to buffer or stdout in decimal
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_u_int(list_t *dime)
{
	unsigned int n;

	n = va_arg(*(dime->args), int);

	print_unsigned(dime, (unsigned long int)n);
}

/**
 * print_ulong_int - writes unsigned long integers to buffer or stdout in decimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void print_ulong_int(list_t *dime)
{
	unsigned long int n;

	n = va_arg(*(dime->args), unsigned long int);

	print_unsigned(dime, n);
}
