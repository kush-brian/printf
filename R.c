#include "main.h"

/**
 * _rot13 - Apply ROT13 substitution cipher to a string
 * @str: The input string
 * Return: The string with 13 letter substitution
 */
char *_rot13(char *str)
{
	char *ptr = str;

	while (*ptr)

	{
		if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
		{
			char base = (*ptr >= 'a') ? 'a' : 'A';
			*ptr = (char)(((int)(*ptr - base + 13) % 26) + base);
		}
		ptr++;
	}
	return (str);
}
/**
 * _printf2 - custom printf
 * @format: initial specifiers
 * Return: returns count of input
 */
int _printf2(const char *format, ...)
{
	va_list list2;
	int count2;

	count2 = 0;

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
		else if (*(format + 1) == 'R')
		{
			char *str = va_arg(list2, char *);
			char *rot13_str = _rot13(str);

			write(1, rot13_str, strlen(rot13_str));
			count2 += strlen(rot13_str);
			format++;
		}
		format++;
	}
	va_end(list2);
	return (count2);
}
