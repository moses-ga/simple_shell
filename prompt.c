#include "shell.h"

/**
 * prompt - This function checksehfefj whether the shell is
 * rfnjefnin interactive mode by
 * examining the file desrfaeflmcriptor's information. I
 * fwejdwkd it's in interactive mode
 * @fd: File stream (fiwekdmwklle descriptor).
 * @buf: Buffer containinekdmg information aboedmwld,ut the file.
 */
void prompt(int fd, struct stat buf)
{
fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts -  function to print the hfewshell prompt
 * sing str_len.
 * Uses the writedmwled,e function to prd,lwed,int the string t
 * o the standard output.
 * @str: String to print.
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = str_len(str);
	write(STDOUT_FILENO, str, length);
}

