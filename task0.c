#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * print_char - prints a character
 * @types: va_list containing the character to print
 * @buffer: buffer to store the output
 * @buff_ind: pointer to the buffer index
 * Return: void
 */
void print_char(va_list types, char buffer[], int *buff_ind)
{
	char c = va_arg(types, int);

	buffer[*buff_ind] = c;
	(*buff_ind)++;

	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
}

/**
 * print_string - prints a string
 * @types: va_list containing the string to print
 * @buffer: buffer to store the output
 * @buff_ind: pointer to the buffer index
 * Return: void
 */
void print_string(va_list types, char buffer[], int *buff_ind)
{
	char *str = va_arg(types, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*buff_ind] = str[i];
		(*buff_ind)++;

		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
	}
}

/**
 * print_percent - prints a percent character
 * @types: unused
 * @buffer: buffer to store the output
 * @buff_ind: pointer to the buffer index
 * Return: void
 */
void print_percent(va_list types, char buffer[], int *buff_ind)
{
	(void)types;

	buffer[*buff_ind] = '%';
	(*buff_ind)++;

	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
}

/**
 * _printf - printf function
 * @format: format
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE]; /* Declare the buffer array*/

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)

	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				print_char(list, buffer, &buff_ind);
			else if (format[i] == 's')
				print_string(list, buffer, &buff_ind);
			else if (format[i] == '%')
				print_percent(list, buffer, &buff_ind);
			else if (format[i] == 'd' || format[i] == 'i')
				print_int(list, buffer, &buff_ind);
			else
			{
				buffer[buff_ind++] = '%';
				buffer[buff_ind++] = format[i];
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				printed_chars += 2;
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - prints the buffer and resets the buffer index
 * @buffer: buffer to print
 * @buff_ind: pointer to the buffer index
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}

