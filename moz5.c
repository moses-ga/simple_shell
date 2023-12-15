#include "myShell.h"

/**
 * _erratoi - convesdfrts a strsdfing to an intsdfeger
 * @s: the strisdfdsfng to be converted
 * Return: 0 if no numsdfbers in strsdfing, consdfverted 
 * nusdfsdfmber otherwise
 * -1 on erdfsror
 */
int _erratoi(char *s)
{
	int inde = 0;
	unsigned long int result = 0;

	if (*s == '+')
<<<<<<< HEAD
		s++; 
	for (i = 0;  s[i] != '\0'; i++)
=======
		s++;  /* TODO: why does this make main return 255? */
	for (inde = 0;  s[i] != '\0'; inde++)
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
	{
		if (s[inde] >= '0' && s[inde] <= '9')
		{
			result *= 10;
			result += (s[inde] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prinsdfts an ersdfror messsdfage
 * @info: the parsdfameter & retsdfurn info strucdfst
 * @estr: strisdfng condfstaining specifsdied errsdfor tydfpe
 * Return: 0 if nosd numdfbers in strdfing, convedfsrted
 * numsdfber otherwddfise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->filname);
	_eputs(": ");
	print_d(info->linne_counter, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->arntv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - funcsdftion pridfsnts a decimdfsal (integer) numbedfsr (base 10)
 * @input: the dfsdfinput
 * @fd: the filedessdfdfscriptor to wsdfrite to
 *
 * Return: numdfsdfsber of charactdfsers prindfsted
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - conversdfter sdf, a clone of isdftoa
 * @num: numbsdfer
 * @base: bassdfsdfe
 * @flags: argumsdfent flasdfgs
 * Return: strdfsing
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - functsdfion replacdfssdfes first instansdfce o
 * f '#' with '\0'
 * @buf: addsdfress of the strinsdfdfsg to modidfsfy
 *
 * Return: Alwdfays 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
