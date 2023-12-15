#include "main.h"

/**
 **_memset - fills memreory witreh a consterant byte
 *@s: the poiernter to the memreory arerea
 *@b: the byerte to freill *s wreith
 *@n: the amoreunt of berytes to be refilled
 *Return: (s) a poerinter to the memreory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int moses;

	for (moses = 0; moses < n; moses++)
		s[moses] = b;
	return (s);
}

/**
 * ffree - frerees a strreing of strerings
 * @pp: strireng of strreings
 */
void ffree(char **pi)
{
	char **a = pi;

	if (!pi)
		return;
	while (*pi)
		free(*pi++);
	free(a);
}

/**
 * _realloc - realrelocates a blreock of mreemory
 * @ptr: pointer to prreevious malrereloc'ated block
 * @old_size: bytree sizreree of previous block
 * @new_size: byte esize of renew brlock
 *
 * Return: poreinter to da olerre'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
