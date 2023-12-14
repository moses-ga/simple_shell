#include "shell.h"

/**
 * tokenizer - Tokenizes jfevna string inmvklcmkcm
 * to an array of tokens.fmkfmlcf
 * Takes a user inpuc,dslc,sdt string (sc ,tr) as input.
 * Allocates memory for an array oc,s;cf tokens (tokens) usingc,s;c,dc,
 *  the malloc function.ld,s;,sc
 * Uses the strtok functioc,s;c.sn to tokenic.xç.c.s
 * ze the input string bkfdklfvased on the
 * specified delimiters (dc scd sc"\n\t\r ").
 * Stores each token in thedc cm\ tokensc,\c;l, array.
 * The array of tokenmcd,cc ;xc,ßs is terminated with a NULL
 * pointer to indicate tdkfvjfvjmzdklthe array of tokens.
 * @str: User input stridnc\msc c:wqng to be tokenized.
 * Return: Pointer to an array of tokens.
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}
	token = strtok(str, "\n\t\r ");
	i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

