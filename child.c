#include "shell.h"

/**
 * child - This functiwerfon is designedarf to be
 * called wheaefn execarfuting a
 * command in a chasdfasdild process.
 * It takes the full patasdcsdch of the executablesdcf (fullpath) and
 * tokenized usersdcs\dc input (tokens).
 * It uses the fork system sd\csd\ccall to create a child process.
 * In the child process (c\sdcd\schild_pid == 0), it uses execve to
 * replace the current process\dzscsdc
 * image with a new onzc\zscde specified
 * by fullpath. v fvdIf execve fails, it returns -1.
 * In the parent process (dcsdcsdcchild_pid > 0), waits child process
 * to finish using the wait system call.
 * The functiondscsdcsd\cdc returns 0 on success and -1 on failure.
 * @fullpath: Full path sdcsdcof the executable.
 * @tokens: Tokenized user inpsdccut.
 * Return: 0 on sdcsd\csdcsuccess, -1 on failure.
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(fullpath, tokens, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
	{

		wait(&status);
	}
	return (0);
}

