#include "shell.h"
/**
 * interactive - positive if shell is interactable
 * @info: structure addr
 *
 * Return: 0 else 1 if its an interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim -  checks if char is delimeter
 * @c: character involved
 * @delim: delimeter's strings
 * Return: 0 on false 1 on true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - runs an alphabetic check on char
 * @c: char involved
 * Return: 1 if char is alphabetic 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts from integar to string
 * @s: string being converted
 * Return: 0 if strings is no number
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
