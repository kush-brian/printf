#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_int(va_list types, char buffer[], int *buff_ind);
int write_int(char buffer[], int is_negative, int start, int end);
void print_buffer(char buffer[], int *buff_ind);
void print_char(va_list types, char buffer[], int *buff_ind);
void print_string(va_list types, char buffer[], int *buff_ind);
void print_percent(va_list types, char buffer[], int *buff_ind);

#endif
