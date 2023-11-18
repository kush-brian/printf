#include "main.h"
/**
 * print_revstr - writes string to buffer or stdout in reverse
 * @dime: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_revstr(list_t *dime)
{
	int i = 0, j, length;
	char *string, *copy;

	string = va_arg(*(dime->args), char *);

	length = strlen(string);
	if (length == 1)
	{
		dime->c0 = string[0];
		write_buffer(dime);
	}
	else
	{
		copy = calloc(length + 1, sizeof(char));
		for (i = length - 1, j = 0; i >= 0; i--, j++)
			copy[j] = string[i];

		puts_buffer(dime, copy);
		free(copy);
	}
}
