#include "main.h"
/**
 * print_int - prints an integer
 * @types: valist containing integer
 * @buffer: buffer to store output
 * @buff_ind: pointer to buffer index
 * Return: void
 */
void print_int(va_list types, char buffer[], int *buff_ind)
{
        int num = va_arg(types, int);
        int temp, digit, count = 0;

        /* Count the number of digits in the integer*/
        temp = num;
        while (temp != 0)
        {
                temp /= 10;
                count++;
        }

        /* Convert the integer to characters and store in the buffer*/
        for (; count > 0; count--)
        {
                temp = 1;
                for (digit = 1; digit < count; digit++)
                        temp *= 10;

                buffer[*buff_ind] = (num / temp) + '0';
                (*buff_ind)++;

                if (*buff_ind == BUFF_SIZE)
                        print_buffer(buffer, buff_ind);

                num %= temp;
        int num = va_arg(types, int);
        }
}
