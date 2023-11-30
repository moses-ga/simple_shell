#include <stdio.h>
#include <unistd.h>

/*
 * main - max_pid
 *
 *
 * Return: Always (0) Success.
 */
int main(void)
{
	pid_t max_pid;

	max_pid = sysconf(_SC_CHILD_MAX);

	if (max_pid == -1)
	{
		perror("Error getting max pid");
			return (1);
	}

	printf("Maximum process id: %d\n", max_pid);
	return (0);
}
