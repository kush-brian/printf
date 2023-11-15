#include "main.h"
/**
 * _printf - prints anything
 * @format: the format string
 * Return: returns the length of inputs
 */
int _printf(const char *format, ...)
{
        va_list list;
        int count = 0;
        char ch;

        if (format == NULL)
                return (-1);

        va_start(list, format);

        while ((ch = *format++))
        {
                if (ch != '%')
                {
                        write(1, &ch, 1);
                        count++;
                                buffer[buff_ind++] = forma                }
                else if (*format == '%')
                {
                        write(1, "%", 1);
                        count++;
                        format++;
                }
                else if (*format == 's')
                {
                        char *str = va_arg(list, char*);

                        count += write(1, str, strlen(str));
                        format++;
                }
                else if (*format == 'c')
                {
                        char c = va_arg(list, int);

                        count += write(1, &c, 1);
                        format++;
                }
        }
        va_end(list);
        return (count);
}
