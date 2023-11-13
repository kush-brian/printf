#include <stdio.h>
#include <stdarg.h>
int count;
char ch;
int print_char(char ch) {
    putchar(ch);
    return 1;
}

int print_str(const char *str) {
    int count = 0;
    while (*str != '\0') {
        putchar(*str++);
        count++;
    }
    return count;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    count = 0;

    while ((ch = *format++) != '\0') {
        if (ch == '%') {
            ch = *format++;
            if (ch == 'c') {
                count += print_char(va_arg(args, int));
            } else if (ch == 's') {
                count += print_str(va_arg(args, const char *));
            } else if (ch == '%') {
                count += print_char('%');
            } else {
            }
        } else {
            count += print_char(ch);
        }
    }

    va_end(args);
    return count;
}
