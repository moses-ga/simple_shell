#include <stdio.h>
#include <string.h>

int main(void)
{
	char *argv[] = {"program", "arg 0", "arg 1", "arg 2", NULL};
	int i = 0;

	while (argv[i])
	{
		printf("%s ", argv[i]);
		i++;
	}

	printf("\n");

	return (0);
}
