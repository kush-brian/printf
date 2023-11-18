#include "main.h"
/**
 * rev_string - reverses string
 i* @s: pointer to the input string
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0, c;
	char temp;

	while (s[length] != '\0')
		length++;
	for (c = 0; c < (length / 2); c++)
	{
		temp = s[c];
		s[c] = s[length - c - 1];
		s[length - c - 1] = temp;
	}
}
/**
 * _strlenconst - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
int _strlenconst(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * puts_mod - prints input buffer
 * @str: buffer to print
 */
void puts_mod(char *str, unsigned int l)
{
	write(STDOUT_FILENO, str, l);
}
