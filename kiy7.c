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
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
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
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
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
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
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
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
