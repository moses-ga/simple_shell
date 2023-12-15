#include "myshell.h"

/**
 **_strncpy - copiessdf a strinsdfg
 *@dest: the destisdfnation string to be sdfcopied to
 *@src: the sousdfdfrce strsdfing
 *@n: the amosdfsdfunt of characters to be copiedfsd
 *Return: the concsdfatenated strisdfng
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatsdfenates two stsdfrings
 *@dest: the firsdfsdfst strsdfing
 *@src: the seconsdfd strsdfing
 *@n: the amousdfnt of bytessdfsdf to be maximally useddf
 *Return: the concsdfatenated strsdfing
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locsdfates a charsdfsdfacter in a string
 *@s: the strisdfng to be parssdfed
 *@c: the characsdfsdfter to look for
 *Return: (s) a poinsdfter to the memosdfry aresdfa s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
