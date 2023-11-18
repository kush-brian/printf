#include "main.h"

/**
 * end_func - terminates _printf() in error cases
 * @dime: the arguments inventory with most commonly used arguments
 * Return: -1 always
 */
int end_func(list_t *dime)
{
    int return_value = -1;

    if (!dime)
        return return_value;

    return_value = (dime->error ? -1 : dime->buf_index);

    if (dime->i)
        puts_mod(dime->buffer, dime->buf_index);

    va_end(*(dime->args));
    
    if (dime->buffer)
        free(dime->buffer);

    free(dime);

    return (return_value);
}

