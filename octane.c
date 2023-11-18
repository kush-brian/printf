#include "main.h"

/**
 * print_oct - writes unsigned long integer to buffer or stdout in base 8
 * @inv: the arguments inventory with most commonly used arguments
 * @n: integer to be printed in octal
 * @size: the size to be malloc'd
 */
void print_octal(list_t *dime, unsigned long int n, int size)
{
	int i, j;
	char *oct, *copy;

	if (!n)
	{
		dime->c0 = '0';
		write_buffer(dime);
	}
	else
	{
		oct = _calloc(size, sizeof(char));
		if (oct)
		{
			for (i = 0; n; i++, n /= 8)
				oct[i] = (n % 8 + '0');
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = oct[i];
				if (dime->c1 == '#')
				{
					dime->c0 = '0';
					write_buffer(dime);
				}
				puts_buffer(dime, copy);
				free(copy);
			}
			else
				dime->error = 1;
			free(oct);
		}
		else
			dime->error = 1;
	}
}

/**
 * p_octal - writes unsigned integer to buffer in base 8: octal
 * @dime: the arguments inventory with most commonly used arguments
 */
void p_octal(list_t *dime)
{
	unsigned int n;

	n = va_arg(*(dime->args), int);

	print_octal(dime, (unsigned long int)n, 12);
}

/**
 * print_longoct - writes unsigned long integer to buffer or stdout in base 8
 * @inv: the arguments inventory with most commonly used arguments
 */
void print_longoct(list_t *dime)
{
	unsigned long int n;

	n = va_arg(*(dime->args), unsigned long int);

	print_octal(dime, n, 23);
}
