#include "main.h"

/**
 * print_stringhex - writes string to buffer or stdout ascii
 * @inv: the arguments inventory with most commonly used arguments
 */
void print_stringhex(list_t *dime)
{
    char *string, *temp, *hexvalues, *null_string;
    int c = 0, num;

    hexvalues = "0123456789ABCDEF";
    null_string = "(null)";
    string = va_arg(*(dime->args), char*);

    if (!string)
    {
        string = null_string;
        puts_buffer(dime, null_string);
    }
    else
    {
        temp = _calloc(5, sizeof(char));
        temp[0] = 92;
        temp[1] = 'x';
        while (string[c] != '\0')
        {
            num = string[c];
            if (num > 31 && num < 127)
            {
                dime->c0 = num;
                write_buffer(dime);
            }
            else
            {
                temp[2] = hexvalues[(num / 16) % 16];
                temp[3] = hexvalues[num % 16];
                puts_buffer(dime, temp);
            }
            c++;
        }
        free(temp);
    }
}

/**
 * print_pointer - writes pointer value (an address) to buffer in hexadecimal
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_pointer(list_t *dime)
{
    unsigned long int pointer_value;
    char *hex, *null_string, *hexvalues, *copy;
    void *pointer;
    int i, j;

    pointer = va_arg(*(dime->args), void *);
    hexvalues = "0123456789abcdef";
    null_string = "(nil)";

    if (!pointer)
    {
        puts_buffer(dime, null_string);
    }
    else
    {
        hex = calloc(13, sizeof(char));
        puts_buffer(dime, "0x");

        i = 0;
        pointer_value = (unsigned long int)pointer;
        while (pointer_value)
        {
            hex[i] = hexvalues[pointer_value % 16];
            i++;
            pointer_value /= 16;
        }

        copy = calloc(i + 1, sizeof(char));
        j = 0;
        while (i--)
        {
            copy[j] = hex[i];
            j++;
        }

        puts_buffer(dime, copy);
        free(copy);
        free(hex);
    }
}

