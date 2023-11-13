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

    if (format == NULL)
        return (-1); /*returns error*/
    va_start(list, format);
    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            i++;
        }
        else if (*(format + 1) == '%')
        {
            write(1, "%", 1);
            i++;
            format += 2; /* Skip both '%' characters*/
            continue;
        }
        else if (*(format + 1) == 's')
        {
            char *str = va_arg(list, char*);

            lenst = strlen(str);
            write(1, str, lenst);
            i += lenst;
            format += 2; /* Skip the 's' character*/
            continue;
        }
        else if (*(format + 1) == 'c')
        {
            char c = va_arg(list, int);

            write(1, &c, 1);
            i++;
            format += 2; /* Skip the 'c' character*/
            continue;
        }
        write(1, format, 1);
        i++;
        format++;
    }
    va_end(list);
    return (i);
}

