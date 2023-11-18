#include "main.h"

/**
 * print_hex - writes in base hexadecimal
 * @dime: the arguments inventory with most commonly used arguments
 * @n: unsigned long int number to be converted
 * @hexcase: the hexcase either upper or lower
 * @size: the size to be malloc'd
 */
void print_hex(list_t *dime, unsigned long int n, int hexcase, int size)
{
    char *hex = NULL, *copy = NULL;
    const char *conv, *pre;
    static const char *const convset[] = {"0123456789abcdef", "0123456789ABCDEF", NULL};
    static const char *const preset[] = {"0x", "0X", NULL};
    int i, j;

    conv = convset[hexcase];
    if (!n)
    {
        dime->c0 = '0';
        write_buffer(dime);
        return;
    }

    if (dime->c1 == '#')
    {
        pre = preset[hexcase];
        puts_buffer(dime, (char *)pre);
    }

    hex = calloc(size, sizeof(char));
    copy = calloc(size, sizeof(char));

    if (!hex || !copy)
    {
        dime->error = 1;
        free(hex);
        free(copy);
        return;
    }

    i = 0;
    while (n)
    {
        hex[i++] = conv[n % 16];
        n /= 16;
    }

    j = 0;
    while (i-- > 0)
        copy[j++] = hex[i];

    puts_buffer(dime, copy);
    free(hex);
    free(copy);
}

/**
 * print_lowhex - writes unsigned integer to buffer in base hexadecimal downcase
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_lowhex(list_t *dime)
{
    unsigned int n;
    
    n = va_arg(*(dime->args), int);
    print_hex(dime, (unsigned long int)n, LOWHEX, 9);
}

/**
 * print_uphex - writes unsigned integer to buffer in base hexadecimal upcase
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_uphex(list_t *dime)
{
    unsigned int n;
    
    n = va_arg(*(dime->args), int);
    print_hex(dime, (unsigned long int)n, UPHEX, 9);
}

/**
 * print_longlow_hex - writes unsigned long int in base hexadecimal
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_longlow_hex(list_t *dime)
{
    unsigned long int n;
    
    n = va_arg(*(dime->args), unsigned long int);
    print_hex(dime, n, LOWHEX, 17);
}

/**
 * print_longup_hex - writes unsigned long integer in base hexadecimal upcase
 * @dime: the arguments inventory with most commonly used arguments
 */
void print_longup_hex(list_t *dime)
{
    unsigned long int n;
    
    n = va_arg(*(dime->args), unsigned long int);
    print_hex(dime, n, UPHEX, 17);
}

