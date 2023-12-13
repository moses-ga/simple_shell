#include "shell.h"

/**
 * main - The program enters a continuous loop that
 * represents the main shell execution.
 * Prompt and User Input: prompt(STDIN_FILENO, buf): Displays the shell prompt
 * if in interactive mode.
 * line = get_line(stdin): Reads a line of input from the user.
 * Check for Empty Input: Checks if the entered line is empty (contains only
 * a newline character).If so, skips to the next iteration.
 * Tokenization: tokens = tokenizer(line): Tokenizes the input line into
 * individual commands and arguments.
 * Execute Built-in Commands: builtin_status = buiilt_in_execu(tokens):
 * Checks and executes built-in commands such as "exit" or "env."
 * If a built-in command was successful or the user requested exit, free
 * allocated memory and continue to the next iteration.
 * Get PATH Environment Variable: path = get_env("PATH"): Retrieves the value
 * of the PATH environment variable.
 * Determine Full Path: fullpath = which_path(tokens[0], fullpath, path):
 *Determines the full path of the command to be executed.
 * Execute Command in Child Process: child_status = child(fullpath, tokens):
 * Executes the command in a child process.
 * Error Handling: Displays an error if the child process fails to execute.
 * Free Allocated Memory: free_all(tokens, path, line, fullpath, flag):
 * Frees the memory allocated for tokens, the PATH variable, the input line,
 * and fullpath if it was dynamically allocated.
 * Return Status: The loop continues until the user requests to exit the shell.
 * The program returns 0 on successful completion.
 * Return: 0 on success
 */

int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
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
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}

