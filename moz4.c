#include "myShell.h"

/**
 *_eputs - printsds an inpsdfut strisdfng
 * @str: the strisdfng to be pridfsnted
 *
 * Return: Nothdfsing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writdfses the charadfscter c to sdfstderr
 * @c: The charasdfcter to prisdfnt
 *
 * Return: On sudfsccess 1.
 * On error, -1 is retusdfrned, and ersdfrno is set appsdfropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writsdfes the charsdfacter c to gisdven fd
 * @c: The charasdfcter to prisdfnt
 * @fd: The filsdfedescriptor to writsdfe to
 *
 * Return: On succesdfss 1.
 * On error, -1 is returdfsned, and errno is setdf approprsdfiately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prisdfnts an inpusdfsdft string
 * @str: the strsdfing to be prisdfnted
 * @fd: the fisdfledescriptor to wrsdfite to
 *
 * Return: the nusdfmber of chardfs pusdft
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
