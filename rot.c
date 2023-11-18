#include "main.h"

/**
 * print_rot13 - translates string to ROT13 and writes to stdout buffer
 * @dime: the arguments inventory with most commonly used arguments
 * Return: string after conversion of ROT13
 */
void print_rot13(list_t *dime)
{
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *rot_13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
    char *str = va_arg(*(dime->args), char *);
    int l = str ? strlen(str) : 0;

    if (l)
    {
        char *copy = calloc(l + 1, sizeof(char));

        int i = 0;
        while (str[i] != '\0')
        {
            int j = 0;
            while (j < 52)
            {
                if (str[i] == alphabet[j])
                {
                    copy[i] = rot_13[j];
                    break;
                }
                j++;
            }
            if (j == 52)
            {
                copy[i] = str[i];
            }

            i++;
        }

        puts_buffer(dime, copy);
        free(copy);
    }
}

