#include "main.h"
/**
 * _printf - prints anything
 * @format: the format string
 * Return: returns the length of inputs
 */

int _printf(const char *format, ...)
{
	int i = 0;
	va_list list;
	int lenst;

	va_start(list, format);
	if (format == NULL)
		return (-1); /*returns error*/
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			i++;
		}
		format++;
		if (*format == '\0')
			break;
		if (*format == 'c')
		{
			char c = va_arg(list, int);

			write(1, &c, 1);
			i++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(list, char*);

			lenst = 0;
			while (str[lenst] != '\0')
				lenst++;
			write(1, str, lenst);
			i += lenst;
		}
		else if (*format == '%')
		{
			write(1, format, 1);
			i++;
		}
	}
	format++;
	va_end(list);
	return (i);
}
