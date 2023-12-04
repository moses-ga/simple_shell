#include <stdio.h>
#include <string.h>

int main(void)
{
	char *argv[] = {"programs", "arg 0", "arg 1", "arg 2", NULL};

	for (int i = 0; argv[i] != NULL; i++)
	{
		printf("%s ", argv[i]);
	}

	printf("\n");

	return (0);
}
