#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024
#define FALSE !TRUE
#define TRUE (1==1)
#define LOWHEX 0
#define UPHEX 1

/* structs */
/**
 * struct list - list of common variables
 * @f: the input format string
 * @i: index to traverse the format string
 * @args: the variadic args list
 * @buffer: buffer writen to b4 stdout
 * @buf_index: index to traverse the buffer
 * @flag: notifies if theres a modifier flag
 * @space: notifies if space was writen
 * @c0: character to be written to buffer
 * @c1: char checking after %
 * @c2: char to check 2 spaces after %
 * @c3: may become a 3rd specifier
 * @error: indicates error
 */

typedef struct list
{
	const char *f;
	int i;
	va_list *args;
	char *buffer;
	int buf_index;
	int flag;
	int space;
	char c0;
	char c1;
	char c2;
	char c3;
	int error;
} list_t;

/**
 * struct match - printf specifiers
 * @spec: the specifier
 * @func: pointer to conversion spec func
 */

typedef struct match
{
	char spec;
	void (*func)(list_t *dime);
} match_t;


int _printf(const char *format, ...);
list_t *the_list(va_list *arguments, const char *format);
int end_func(list_t *arg_inv);

/* custom mem allocation*/
void *_calloc(unsigned int memint, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(list_t *dime);
void puts_buffer(list_t *dime, char *str);

void rev_string(char *s);
int _strlen(char *s);
int _strlenconst(const char *s);
int _putchar(char c);
void puts_mod(char *str, unsigned int l);

void (*matchspec(list_t *dime))(list_t *dime);
void parsespec(list_t *dime);

void print_hex(list_t *dime, unsigned long int n, int hexcase, int size);
void print_longlow_hex(list_t *dime);
void print_longup_hex(list_t *dime);
void print_lowhex(list_t *dime);
void print_uphex(list_t *dime);

void print_integers(list_t *dime, long int n);
void print_int(list_t *dime);
void print_longint(list_t *dime);
void print_unsigned(list_t *dime, unsigned long int n);
void print_u_int(list_t *dime);
void print_ulong_int(list_t *dime);

void print_octal(list_t *dime, unsigned long int n, int size);
void p_octal(list_t *dime);
void print_longoct(list_t *dime);

void print_char(list_t *dime);
void print_string(list_t *dime);
void print_stringhex(list_t *dime);
void print_pointer(list_t *dime);
void print_revstr(list_t *dime);
void print_rot13(list_t *dime);
void print_perct(list_t *dime);
void print_binary(list_t *dime);

#endif
