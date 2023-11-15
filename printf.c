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
                        write(1, &ch, 1);

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
