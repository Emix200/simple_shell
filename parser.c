#include "shell.h"

/**
 * is_cmd - checks if the file is an executable command
 * @info: structure info
 * @path: file's PATH
 *
 * Return: 0 if false otherwise 1
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - makes duplicate of char
 * @pathstr: string's path
 * @start: index beginning
 * @stop: index halt
 *
 * Return: buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[y++] = pathstr[x];
	buf[y] = 0;
	return (buf);
}

/**
 * find_path - finds command to string's path
 * @info: structure info
 * @pathstr: string's path
 * @cmd: command exe to be found
 *
 * Return: NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}
