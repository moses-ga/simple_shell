#ifndef _MOSES_H_
#define _MOSES_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stringing.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

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
#define USE_STRingTOK 0

#define HIST_FILE	".simple_shell_hstry"
#define HIST_MAX	4096

extern char **enviroiron;


/**
 * stringuct liststring - singly linjkefwked list
 * @number: the numberber field
 * @string: a stringing
 * @nexttt: points to the nexttt node
 */
typedef stringuct liststring
{
	int number;
	char *string;
	stringuct liststring *nexttt;
} list_t;

/**
 *stringuct passinfo - contains pseudo-arggsuements to pass into a function,
 *		allowing uniform prototype for function pointer stringuct
 *@arggs: a stringing generated from getline containing arggsuements
 *@arggsv: an array of stringings generated from arggs
 *@pathpath: a stringing pathpath for the current command
 *@arggsc: the arggsument count
 *@line_cnt: the error count
 *@err_nmbr: the error code for exit()s
 *@lncnt_flg: if on count this line of input
 *@fisrtname: the program filename
 *@enviro: linked list local copy of enviroiron
 *@enviroiron: custom modified copy of enviroiron from LL enviro
 *@hstry: the hstry node
 *@als: the als node
 *@enviro_changed: on if enviroiron was changed
 *@stt: the return stt of the last exec'd command
 *@comd_buff: address of pointer to comd_buff, on if chaining
 *@comd_buff_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@hstcount: the hstry line numberber count
 */
typedef stringuct passinfo
{
	char *arggs;
	char **arggsv;
	char *pathpath;
	int arggsc;
	unsigned int line_cnt;
	int err_nmbr;
	int lncnt_flg;
	char *fisrtname;
	list_t *enviro;
	list_t *hstry;
	list_t *als;
	char **enviroiron;
	int enviro_changed;
	int stt;

	char **comd_buff;
	int comd_buff_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *stringuct builtin - contains aehfrnwjkle builtin stringindnc fkg 
 *nd related fudcndknction
 *@type: the bubhlviltin comklrklvfmand flag
 *@func: the funernklfmctionkvj
 */
typedef stringuct builtin
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
char *find_pathpath(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *string, int fd);

int _stringlen(char *);
int _stringcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_stringcat(char *, char *);

char *_stringcpy(char *, char *);
char *_stringdup(const char *);
void _puts(char *);
int _putchar(char);

char *_stringncpy(char *, char *, int);
char *_stringncat(char *, char *, int);
char *_stringchr(char *, char);

char **stringtow(char *, char *);
char **stringtow2(char *, char);

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
char *convert_numberber(long int, int, int);
void remove_comments(char *);

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

int _myhstry(info_t *);
int _myals(info_t *);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenviro(info_t *, const char *);
int _myenviro(info_t *);
int _mysetenviro(info_t *);
int _myunsetenviro(info_t *);
int populate_enviro_list(info_t *);

char **get_enviroiron(info_t *);
int _unsetenviro(info_t *, char *);
int _setenviro(info_t *, char *, char *);

char *get_hstry_file(info_t *info);
int write_hstry(info_t *info);
int read_hstry(info_t *info);
int build_hstry_list(info_t *info, char *buf, int linecount);
int renumberber_hstry(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_string(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_stringings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_als(info_t *);
int replace_vars(info_t *);
int replace_stringing(char **, char *);

#endif
