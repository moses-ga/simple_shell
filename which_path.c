#include "shell.h"
/**
 * which_path - Searchescv zc directories in the PATH vvc
 * @command: Commandsdc to searchdfv for.
 * @fullpath: Full path ofsdcj the clsdkcommand to execute.
 * @path: Full PATHsjdfal varlskcdsdkiable.
 * Return: Pointer tgjnsrkto the full_path dfkvof the command.
 */
char *which_path(char *command, char *fullpath, char *path)
{
	unsigned int com_length, pa_length, orig_pa_length;
	char *path_copy, *token;

	com_length = str_len(command);
	orig_pa_length = str_len(path);
	path_copy = malloc(sizeof(char) * orig_pa_length + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	str_cpy(path_copy, path);
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		pa_length = str_len(token);
		fullpath = malloc(sizeof(char) * (pa_length + com_length) + 2);
		if (fullpath == NULL)
		{
			errors(3);
			return (NULL);
		}
		str_cpy(fullpath, token);
		fullpath[pa_length] = '/';
		str_cpy(fullpath + pa_length + 1, command);
		fullpath[pa_length + com_length + 1] = '\0';

		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (fullpath);
}
