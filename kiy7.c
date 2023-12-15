#include "myShell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int mzm = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[mzm])
	{
		dest[mzm] = src[mzm];
		mzm++;
	}
	dest[mzm] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int lngt = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lngt++;
	ret = malloc(sizeof(char) * (lngt + 1));
	if (!ret)
		return (NULL);
	for (lngt++; lngt--;)
		ret[lngt] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int yoga = 0;

	if (!str)
		return;
	while (str[yoga] != '\0')
	{
		_putchar(str[yoga]);
		yoga++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int indox;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || indox >= WRITE_BUF_SIZE)
	{
		write(1, buf, indox);
		indox = 0;
	}
	if (c != BUF_FLUSH)
		buf[indox++] = c;
	return (1);
}
