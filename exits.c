#include "shell.h"

/**
 **_strncpy - copies  string
 *@dest: string's destination
 *@src: string's source
 *@n: number of char copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, y;
	char *s = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (s);
}

/**
 **_strncat - link two strings
 *@dest: the destination
 *@src: the source
 *@n: the number of string
 *Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x, y;
	char *s = dest;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
		dest[x] = '\0';
	return (s);
}

/**
 **_strchr - locates a char
 *@s: string involved to be parsed
 *@c: char to be searched for
 *Return: --
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
