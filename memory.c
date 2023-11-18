#include "main.h"

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: elements of memory needed
 * @size: size in bytes of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int memint, unsigned int size)
{
	unsigned int i;
	char *p;

	if (memint == 0 || size == 0)
		return (NULL);
	if (size >= UINT_MAX / memint || memint >= UINT_MAX / size)
		return (NULL);
	p = malloc(size * memint);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < memint * size; i++)
		p[i] = '\0';
	return ((void *)p);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory
 * @old: size in bytes of allocated memory
 * @new: newsize of memory block in bytes
 *
 * Return: void pointer to new allocation of memory
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *p;
	unsigned int i;

	if (ptr == NULL)
	{
		p = _calloc(new, sizeof(char));
		return (p);
	}
	if (new == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old == new)
		return (ptr);

	p = _calloc(new, sizeof(char));
	if (p == NULL)
		return (NULL);

	for (i = 0; i < old && i < new; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);

	return ((void *)p);
}
