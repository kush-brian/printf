#include "main.h"

/**
 * print_binary - writes unsigned integer to buffer
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_binary(list_t *dime)
{
	unsigned int n = va_arg(*(dime->args), unsigned int);
	int i, j;
	char *binary, *copy;

	binary = calloc(33, sizeof(char));

	if (binary)
	{
		for (i = 0; n; i++, n /= 2)
			binary[i] = ((n % 2) + '0');

		if (i == 0)
		{
			dime->c0 = '0';
			write_buffer(dime);
		}
		else
		{
			copy = calloc(i + 1, sizeof(char));
			if (copy)
			{
				j = 0;
				while (i >= 0)
				{
					copy[j++] = binary[i--];
				}
				puts_buffer(dime, copy);
				free(copy);
			}
			else
			{
				dime->error = 1;
			}
		}
		free(binary);
	}
	else
	{
		dime->error = 1;
	}
}
