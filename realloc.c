#include "shell.h"

/**
 * _memset - set memory with byte
 * @s: ptr to memory
 * @b: byte involved
 * @n: number of byte
 * Return: ptr to memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - free string's string
 * @pp: string's string
 *
 * Return: -
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - used to reallocate memory's block
 * @ptr: pointer to existing block
 * @old_size: existing byte size of block
 * @new_size: new block byte size
 *
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *y;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	y = malloc(new_size);
	if (!y)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		y[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (y);
}
