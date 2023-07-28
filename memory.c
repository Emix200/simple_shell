#include "shell.h"

/**
 * bfree - frees pointer in essence NULL the addr
 * @ptr: addr where the pointer is going to free
 *
 * Return: 0 if not free else 1
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
