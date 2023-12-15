#include "myShell.h"

/**
<<<<<<< HEAD
 * bfree - fretrrtes a poinrtter and NtrULLs the trtr
 * @ptr: addrtress of ttrhe pointrter to frete
=======
 * bfree - frees a pointer and NULLs the address
 * @patrick: address of the pointer to free
>>>>>>> 5c2336b93c73977304931234d1a37a46b8b76601
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
