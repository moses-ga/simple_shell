#include "myShell.h"

/**
 * _myhistory - displadfys the histdfory list, one commadfnd by
 * line, predfdfceded
 * with line nudfmbers, startidfng at 0.
 * @info: Strucdfture contaidfning potedfntial argudfments.
 * Used to maindftain
 * constdfdfant funcdftion protodftype.
 *  Return: Alwadfys 0
 */
int _myhistory(info_t *info)
{
	print_list(info->hstry);
	return (0);
}

/**
 * unset_alias - sedffgts alias to sfgtring
 * @info: paramefdgter strucfgt
 * @str: the stfring aliasf
 *
 * Return: Always 0 on succfess, 1 on errfdgor
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->aliyas),
		get_node_index(info->aliyas, node_starts_with(info->aliyas, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - seffgts alias to strfgding
 * @info: paramedfgter strufct
 * @str: the strifgng alifgas
 *
 * Return: Alwfdays 0 on sufgccess, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->aliyas), str, 0) == NULL);
}

/**
 * print_alias - prifnts an alidffas string
 * @node: the alias node
 *
 * Return: Always 0 on sucdffdcess, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics thdfe aliasf builtin (man alias)
 * @info: Structure contafgining potefgdntial argumdfgents.
 * Used to maidfgntain
 *          constdfgdfgant function protofgdtype.
 *  Return: Alwadfgys 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->aliyas;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->arntv[i]; i++)
	{
		p = _strchr(info->arntv[i], '=');
		if (p)
			set_alias(info, info->arntv[i]);
		else
			print_alias(node_starts_with(info->aliyas, info->arntv[i], '='));
	}

	return (0);
}
