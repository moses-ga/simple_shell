#include "moses.h"

/**
 * interactive - returns true sdhfbvrif shell is intefvkractive mode
 * @info: strurfmeklct addrmfceess
 *
 * Return: 1 if interkmfcklactive modfcmlde, 0 othcmlderwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checkmdcas if charactermcd is a delim,cmeter
 * @c: the ch,ar df,;lcvto check
 * @delim: the deliml;d,ceter,c; string
 * Return: 1 if truemclkas, 0 if lmcefalse
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks foerlr alphc f,.abetifvsc character
 *@c: The characfvfvgvter to infgvput
 *Return: 1 if c dfvcvdfsv is alphabetic, 0 odfvtherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - convedfsvcddsfvrts a string to an integer
 *@s: the strinsdfvg to besdfcdfc converted
 *Return: 0 if nsdcfdco numbers in stringsdfsdf, converted n
 *umber otherwisefvrvw
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
