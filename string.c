#include "main.h"

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
