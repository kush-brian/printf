#include "main.h"
/**
 * _printf - customized printf
 * @format: initial specifiers
 * Return: returns count of input
 */
int _printf(const char *format, ...)
{
	va_list list2;
	int count2 = 0;

	va_start(list2, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%' || (*format + 1) == '%')
		{
			write(1, format, 1);
			count2++;
		}
		else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		{
			int i = va_arg(list2, int);
			char buffer[32];
			int len = snprintf(buffer, sizeof(buffer), "%d", i);

			write(1, buffer, len);
			count2 += len;
			format++;
		}
		format++;
	}
	va_end(list2);
	return (count2);
}
