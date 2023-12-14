#include "shell.h"

/**
 * get_line - This function is resporfhjafnfnfjefnjfnnsible for reading lirf
 * ne of input from user.
 * It takes a file stream (fp) as an argument, which allows it to read from
 * eitherstdin or a file, depending on usage.
 * @fp: File stream (stdin or a efrffr:wqfile, depending on usage).
 * Return: The buffereferfwef containing user input.
 */

char *get_line(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;

	read = getline(&line, &len, fp);

	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

