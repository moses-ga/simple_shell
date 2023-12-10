#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define USE_GETLINE 0
#define USE_STRTOK 0

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
 
 
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passinfo - contains pseudo-arguements to pass in the function,
 * allowing uniform prototype for function pointer struct
 *
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 *
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 *
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 *
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on while chaining
 *
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
 
 
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
 

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _ptchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strnCopy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

int activeoff(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

char **_strRepeat(char *, char *);
char **strtow2(char *, char);

char *memFills(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int freePointer(void **);



int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _extin(info_t *);
int _mycd(info_t *);
int Help(info_t *);

ssize_t get_input(info_t *);
int _getLines(info_t *, char **, size_t *);
void sigintHandler(int);

int historyDisp(info_t *);
int _myalias(info_t *);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char **getEnviron(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenviron(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

char *getFileHistory(info_t *info);
int writeHistr(info_t *info);
int readHistr(info_t *info);
int linkHistr(info_t *info, char *buf, int linecount);
int linkedNumberHistr(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

int chainDelim(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replaceAlias(info_t *);
int replaceVars(info_t *);
int replace_string(char **, char *);

size_t _listLen(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

#endif

