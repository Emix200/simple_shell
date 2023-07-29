#include "shell.h"

/**
 * is_chain - tests current chain delimeter
 * @info: structure parameter
 * @buf: character buff
 * @p: addr of current position in buffer
 *
 * Return: 1 success else 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t y = *p;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[y] == ';')
	{
		buf[y] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = y;
	return (1);
}

/**
 * check_chain - checks chain
 * @info: structure parameter
 * @buf: the character buffer
 * @p: addr of present position in buffer
 * @i: beginning position in buffer
 * @len: length
 *
 * Return: NULL
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t y = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}

	*p = y;
}

/**
 * replace_alias - substitutes in the tokenized string for alias
 * @info: struct parameter
 *
 * Return: 1 on success else 0
 */
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - substitutes in the tokenized string for var
 * @info: struct parameter
 *
 * Return: 1 on success else 0
 */
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - substitutes strings
 * @old: addr of former string
 * @new: addr of new string
 *
 * Return: 1 on success else 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
