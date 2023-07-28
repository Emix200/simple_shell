#include "shell.h"

/**
 * _strlen - returns strings length
 * @s: string involved
 *
 * Return: int
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - compare two strings
 * @s1: initial string
 * @s2: other string
 *
 * Return: 0 pos or neg depending the situation
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks for starts
 * @haystack: string involved to seach for
 * @needle: string sub section find
 *
 * Return: NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenate two strings between each other
 * @dest: destination
 * @src: source
 *
 * Return: ptr dest
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
