#include "myShell.h"

/**
 * get_environ - returnssdfsdf the string arraysddsf copy of our environ
 * @info: Strucsddfsdfture contasdfining potesntial argumsdfents.
 * Usesdfd to maisdfntain onstant functsdfion prosdftotype.
 * Return: Alwaysdfs 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Removsdfe an environsdfdfsment variable
 * @info: Strucsdfsdfture containingsdf potentisdfal argumesdfnts.
 *  Used sdfto masdfintainonstant function protosdftype.
 *  Return: 1 on deldfdfsete, 0 otherwise
 * @var: the strisdfng edfnv var propsdferty
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Iniasdflize a nesdfsdfw environment variadfssdfble,
 * or modify an exsdfisting onedfs
 * @info: Strucsdfture containisdfsdfng potential argumentsdfs. Used to masdfintain
 * conssdtant functisdfsdfon prototype.
 * @var: the strisdfng env var prsdfoperty
 * @value: the stsdfring env var vsdfalue
 *  Return: Alwasdfys 0
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
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
