#include "main.h"

/**
 * build_inventory - builds variables inventory
 * @args_list: variadic arguments list
 * @format: format input string
 * Return: struct of arguments initialized
 */
list_t *the_list(va_list *arguments, const char *format)
{
	list_t *dime;

	dime = malloc(sizeof(list_t) * 1);

	if (dime)
	{
		dime->buffer = _calloc(BUFSIZE, sizeof(char));
		dime->buf_index = 0;
		dime->args = arguments;
		dime->f = format;
		dime->i = 0;
		dime->flag = 0;
		if (!dime->buffer)
			dime->error = 1;
		else
			dime->error = 0;
	}

	return (dime);
}
