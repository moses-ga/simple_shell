#include "myShell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @patrick: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **patrick)
{
	if (patrick && *patrick)
	{
		free(*patrick);
		*patrick = NULL;
		return (1);
	}
	return (0);
}
