#include "myShell.h"

/**
 * bfree - fretrrtes a poinrtter and NtrULLs the trtr
 * @ptr: addrtress of ttrhe pointrter to frete
 *
 * Return: 1 if fretred, otherwtrise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
