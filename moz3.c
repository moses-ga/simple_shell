#include "main.h"

/**
 * getEnviron - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

char **getEnviron(info_t *info)
{
	if (!info->evrntiron || info->evrnt_changed)
	{
		info->evrntiron = list_to_strings(info->evrnt);
		info->evrnt_changed = 0;
	}

	return (info->evrntiron);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
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
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
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
