#include "main.h"
/**
 * write_buffer - adds input char to buffer 1 at a time
 * @dime: the arguments inventory with most commonly used arguments
 */
void write_buffer(list_t *dime)
{
	unsigned int old, new;
	char *temp;

	if (dime->buffer)
	{
		dime->buffer[dime->buf_index++] = dime->c0;

		if ((dime->buf_index + 1) % BUFSIZE == 0)
		{
			old = dime->buf_index + 1;
			new = old + BUFSIZE;
			temp = _realloc(dime->buffer, old, new);
			if (!temp)
				dime->error = 1;
			else
				dime->buffer = temp;
		}
	}
}

/**
 * puts_buffer - puts string to buffer without newline
 * @dime: the arguments inventory with most commonly used arguments
 * @str: string to print
 */
void puts_buffer(list_t *dime, char *str)
{
	int i, l;

	l = strlen(str);

	for (i = 0; i < l; i++)
	{
		dime->c0 = str[i];
		write_buffer(dime);
	}
}
