#include "myShell.h"

/**
 * interactive - returns tgfgfgfgrue if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interacfgtive mode, 0 otherfgwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checkfgs if charactfger is a delifgmeter
 * @c: the chfgar to chfgeck
 * @delim: the delimfgeter stfgring
 * Return: 1 if trufge, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checkfgs for alphafgbetic chafgracter
 *@c: The characfgter to inpfgut
 *Return: 1 if c is alpfghabetic, 0 othfgerwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a strifgng to an infgteger
 *@s: the string to fgbe convefgfgrted
 *Return: 0 if no nufgmbers in strfging, convfgerted numbe
 r othfgerwisefg fgfg
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
