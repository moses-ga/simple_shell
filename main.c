#include "shell.h"
/**
 * main - The program enters a continuous loop that
 * Return Status: The loop continues until the user requests to exit the shell.
 * The program returns 0 on successful completion.
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *fullpath, **tokens;
	int flag = 0;
	int builtin_status, child_status;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		line = get_line(stdin);
		if (str_cmp(line, "\n", 1) == 0)
		{
		free(line);
		continue;
		}
		tokens = tokenizer(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			continue;
		}
		builtin_status = buiilt_in_execu(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		path = get_env("PATH");
		fullpath = which_path(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1;
		child_status = child(fullpath, tokens);
		if (child_status == -1)
			errors(2), free_all(tokens, path, line, fullpath, flag);
	}	return (0);
}
