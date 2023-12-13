#include "shell.h"

/**
 * get_env - This function searches for a specific environment
 * variable (name) in the array environ.
 * It creates a copy of the environment variables using the
 * copy_env function to avoid modifying the original environment.
 * It then compares the input name with each environment variable
 * and extracts the corresponding value.
 * If a match is found, it allocates memory for the value and returns it.
 * If no match is found, it returns NULL.
 * @name: Environment variable to get.
 * Return: Pointer to the environment variable or NULL if there is no match.
 */
char *get_env(const char *name)
{
	char **env_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int pa_length, env_length, length, i;

	env_length = 0;
	while (environ[env_length] != NULL)
		env_length++;
	env_copy = NULL;
	env_copy = copy_env(env_copy, env_length);
	length = str_len((char *)name);
	i = 0;
	while (env_copy[i] != NULL)
	{
		variable = env_copy[i];
		compare = str_ncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			pa_length = str_len(value);
			path = malloc(sizeof(char) * pa_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = str_cpy(path, value);
			free_dp(env_copy, env_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copy_env - This function creates a copy of the environment
 * variables to avoid
 * modifying the original environment.
 * It allocates memory for the copy and each individual environment variable.
 * It uses str_cpy to copy each environment variable to the new memory.
 * It returns the double pointer to the copy of environment variables.
 * @env_copy: Pointer to the copy of environment variables.
 * @env_length: Length of the environment variables.
 * Return: Double pointer to the copy of environment variables.
 */
char **copy_env(char **env_copy, unsigned int env_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	env_copy = malloc(sizeof(char **) * (env_length));
	if (env_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	i = 0;

	while (i < env_length)
	{
		variable = environ[i];
		variable_length = str_len(variable);
		env_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (env_copy[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		str_cpy(env_copy[i], environ[i]);
		i++;
	}
	return (env_copy);
}

