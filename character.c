#include "main.h"
/**
 * print_char - writes char to buffer or standard output
 * @dime: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_char(list_t *dime)
{
	dime->c0 = va_arg(*(dime->args), int);

	write_buffer(dime);
}
/**
 * print_perct - writes a percent symbol to buffer or stdout
 * @dime: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_perct(list_t *dime)
{
	dime->c0 = '%';

	if (dime->space)
	{
		dime->space = 0;
		dime->buffer[--(dime->buf_index)] = '\0';
	}

	write_buffer(dime);
}
