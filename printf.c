#include "main.h"

/**
 * _printf - replication of some of the features from C function printf()
 * @_list: character string of directives, flags, modifiers, & specifiers
 * Description: This function uses the variable arguments functionality and is
 * supposed to resemble printf(). Please review the README for more
 * information on how it works.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	list_t *dime;
	void (*temp_func)(list_t *);

	if (!format)
		return (-1);

	va_start(arguments, format);
	dime = the_list(&arguments, format);
	for (; dime && format[dime->i] && !dime->error; dime->i++)
	{
		dime->c0 = format[dime->i];
		if (dime->c0 != '%')
			write_buffer(dime);
		else
		{
			parsespec(dime);
			temp_func = matchspec(dime);
			if (temp_func)
				temp_func(dime);
			else if (dime->c1)
			{
				if (dime->flag)
					dime->flag = 0
						write_buffer(dime);
			}
			else
			{
				if (dime->space)
					dime->buffer[--(dime->buf_index)] = '\0';
				dime->error = 1;
			}
		}
	}

	return (end_func(dime));
}
