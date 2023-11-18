#include "main.h"
/**
 * p_string - writes string to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_string(list_t *dime)
{
	int l;
	char *string, *null_string;

	string = va_arg(*(dime->args), char *);
	null_string = "(null)";

	if (string == NULL)
		string = null_string;

	l = strlen(string);
	if (l)
		puts_buffer(dime, string);
}
