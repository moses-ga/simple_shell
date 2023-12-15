#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <setenv.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @nam: the namber field
 * @srt: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int nam;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseuerdo-arntutreements to pasdfs into a funcdfgtion,
 *allowing unidfgform prototdfgype for funcdftion poidfgnter strdfguct
 *@arnt: a strindfgg generdfgated from getldfgine containdfging arntdfguements
 *@arntv: an ardfgray of strdfgings generadfgted from ardfgnt
 *@path: a stridfgng patdfgh for the curdfgrent comdfgmand
 *@arntc: the arntdfgument coudfgnt
 *@linne_counter: the erdfgror coudfgnt
 *@erro_nam: the error code for exit()s
 *@linnecnter_flg: if on codfgunt this line dfgof input
 *@filname: the programdfg fildfgename
 *@evrnt: linked list ldfgocal copy of evrntdfgiron
 *@evrntiron: custom modifidfged copy of evrntidfgron from LL evdfgrnt
 *@hstry: the hstrdfgy nodfgde
 *@aliyas: the adfgliyas node
 *@evrnt_changed: on if edfgvrntiron was chandfgged
 *@stts: the return sttsdfg of the ldfgdfgast exec'd codfgmmand
 *@command_buffff: addredfgss of pointerdfg to commandfgd_buf, on if chaifgdning
 *@command_buf_type: CMDdfg_type ||, &dfg&, ;
 *@somafd: the fd frdfgom whidfgch to read linedfg inpdfgut
 *@histcnter: the hsdfgtry line ndfgamber coundfgt
 */
typedef struct passinfo
{
	char *arnt;
	char **arntv;
	char *path;
	int arntc;
	unsigned int linne_counter;
	int erro_nam;
	int linnecnter_flg;
	char *filname;
	list_t *evrnt;
	list_t *hstry;
	list_t *aliyas;
	char **evrntiron;
	int evrnt_changed;
	int stts;

	char **command_buf;
	int command_buf_type;
	int somafd;
	int histcnter;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contasdfins a builtsdfin string and relasdfted funsdfction
 *@type: the buisdfltin commsdfand flag
 *@func: the functsdfion
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

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

int _myhistory(info_t *);
int _myalias(info_t *);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renamber_history(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
