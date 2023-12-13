#include "shell.h"

/**
 * which_path - Searches directories in the PATH variable for a command.
 * Takes a command, a pointer to store the full path of the command (fullpath),
 * and the PATH variable (path).
 * Copies the PATH variable to a temporary variable path_copy.
 * Iterates through directories in the PATH variable using strtok.
 * Constructs the full path of the command by concatenating the directory
 * path and the command.
 * Checks if the full path is executable using the access function.
 * Returns the full path if executable, otherwise, returns NULL.
 * @command: Command to search for.
 * @fullpath: Full path of the command to execute.
 * @path: Full PATH variable.
 * Return: Pointer to the full_path of the command.
 */
char *which_path(char *command, char *fullpath, char *path)
{
/* Length variables */
unsigned int com_length, pa_length, orig_pa_length;
char *path_copy, *token;  /* String pointers */
com_length = str_len(command);
orig_pa_length = str_len(path);
/* Allocate memory for a copy of the PATH variable */
path_copy = malloc(sizeof(char) * orig_pa_length + 1);
if (path_copy == NULL)
{
errors(3);  /* Print error message return NULL on memory alo */
return (NULL);
}
str_cpy(path_copy, path);
token = strtok(path_copy, ":");
if (token == NULL)
token = strtok(NULL, ":");
while (token != NULL)
{
pa_length = str_len(token);
fullpath = malloc(sizeof(char) * (pa_length + com_length) +2);
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
