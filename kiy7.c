#include "myShell.h"

/**
 * _strcpy - copiessss a stringggg
 * @dest: the destinationgfbkd
 * @src: theffg sofgfurce
 *
 * Return: pointtert to dtrestinrtation
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
 * _strdup - duppplicartecates a sstritring
 * @str: the ststringring to duplpuvlicate
 *
 * Return: poinrtter to the duplrticated strtring
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
 *_puts - printrts an inpurtt stritrng
 *@str: the rtstring to rbe prirtnted
 *
 * Return: Nothingnothing
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
 * _putchar - writrtes the chartracter c to strtdout
 * @c: The charactrter to prrtint
 *
 * Return: On suctrcess 1.
 * On error, -1 is returtrtrned, and errno is set
 * apprtroprtriately.
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
