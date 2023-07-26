#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT__UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE
#define HIST_MAX

extern char **environ;

/**
 * struct liststr - structure linked singly list
 * @num: int involved
 * @str: string involved
 * @next: node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
}
list_t;

/**
 * struct passinfo - contains pseudo-arg passed to function
 * @arg: getline string with arguement
 * @argv: an arrayfrom argument
 * @path: a string path
 * @argc: arg count
 * @line_count: err count
 * @err_num: exit err code
 * @linecount_flag: input line count
 * @fname: filename
 * @env: environment for list local copy
 * @environ: copy from LL env
 * @history: history node
 * @alias: alias node
 * @env_changed: in case environment change occurs
 * @status: return status
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd that read input of line
 * cmd_buf: pointer addr to command buff
 * @histcount: history count
 */
typedef struct passinfo
{
	char **argv;
	char *path;
	char *arg;
	int argc;
	unsigned int line_count;
	int linecount_flag;
	int err_num;
	char *fname;
	list_t *env;
	list_t *alias;
	list_t *history;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string
 * @type: cmd builtin flag
 * @func: function involved
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/*toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_memory.c */
int bfree(void **);


#endif
