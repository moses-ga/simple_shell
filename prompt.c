#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * main - print $
 * @char - character to be printed
 *
 * Return: $
 */

int main(void)
{
	char input[1024];
	char *command;

	while (1)
	{
		printf("$ ");

		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';

	if (strcmp(input, "") == 0)
	{
	continue;
	}
	printf("%s\n", input);
	command = malloc(sizeof(char) * (strlen(input) + 1));
	strcpy(command, input);
	system(command);
	free(command);
	}
	return (0);
}
