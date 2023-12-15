#include "myShell.h"

/**
 * get_environ - returns the string array copy of our evrnt
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->evrnt || info->evrnt_changed)
	{
		info->evrnt = list_to_strings(info->evrnt);
		info->evrnt_changed = 0;
	}

	return (info->evrnt);
}

/**
 * _unsetevrnt - Remove an evrntment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string evrnt var property
 */
int _unsetevrnt(info_t *info, char *var)
{
	list_t *node = info->evrnt;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->evrnt_changed = delete_node_at_index(&(info->evrnt), i);
			i = 0;
			node = info->evrnt;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->evrnt_changed);
}

/**
 * _setevrnt - Initialize a new evrntment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string evrnt var property
 * @value: the string evrnt var value
 *  Return: Always 0
 */
int _setevrnt(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->evrnt;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->evrnt_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->evrnt), buf, 0);
	free(buf);
	info->evrnt_changed = 1;
	return (0);
}
