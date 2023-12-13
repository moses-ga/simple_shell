#include "shell.h"

/**
 **_strCop - copies a string
 *@dest: the destination str to be copied to
 *@src: the source str
 *@n: the amount of characters to be copied
 *Return: the concatenated str
 */

char *_strCop(char *dest, char *src, int n)
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
 **_strcat - concatenates two strs
 *@dest: the first str
 *@src: the second str
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */


char *_strcat(char *dest, char *src, int n)
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
 **_strchr - locates a character in a str
 *@s: the str to be parsed
 *@c: the char to look for
 *Return: (s) a pointer to the memory area s
 */


char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

