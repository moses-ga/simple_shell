#include "myshell.h"

/**
 * bfree - fretrrtes a poinrtter and NtrULLs the trtr
 * @ptr: addrtress of ttrhe pointrter to frete
 *
 * Return: 1 if fretred, otherwtrise 0.
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
