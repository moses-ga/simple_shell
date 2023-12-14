#include "shell.h"

/**
 * shell_exit - Exits hfdsl shell.
 * This function is desigsfgvned to be used as a sdfvbuilt-in comma
 * ndsdfv to exit the shell
 * Return: The fdfvcdfvunction returns -1 to indfcvdicate to the main ssdfv
 * hell loosdfvdfsvp that the
 * program shouldfvsdfvd exit.
 */

int shell_exit(void)
{
	return (-1);
}

/**
 * shell_env - Prints esdfvdfsvnvironment variables.
 * It uses the `environ` vsdfvdfsvcdfvariable, which is an external
 * ariable contaisdfvdfvning
 * the environment variables.dfvdfsv
 * The function iterates through the `environ`sdfvc array and prints each
 * environment variable folldsfvdfvdfvcowed by a newline character.
 * Return: The functidfvon returndfss 0.
 */
int shell_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

