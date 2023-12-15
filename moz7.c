#include "myShell.h"

/**
<<<<<<< HEAD
 * get_environ - returnssdfsdf the string arraysddsf copy of our environ
 * @info: Strucsddfsdfture contasdfining potesntial argumsdfents.
 * Usesdfd to maisdfntain onstant functsdfion prosdftotype.
 * Return: Alwaysdfs 0
=======
 * get_environ - returns the string array copy of our evrnt
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
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
<<<<<<< HEAD
 * _unsetenv - Removsdfe an environsdfdfsment variable
 * @info: Strucsdfsdfture containingsdf potentisdfal argumesdfnts.
 *  Used sdfto masdfintainonstant function protosdftype.
 *  Return: 1 on deldfdfsete, 0 otherwise
 * @var: the strisdfng edfnv var propsdferty
=======
 * _unsetevrnt - Remove an evrntment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string evrnt var property
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
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
<<<<<<< HEAD
 * _setenv - Iniasdflize a nesdfsdfw environment variadfssdfble,
 * or modify an exsdfisting onedfs
 * @info: Strucsdfture containisdfsdfng potential argumentsdfs. Used to masdfintain
 * conssdtant functisdfsdfon prototype.
 * @var: the strisdfng env var prsdfoperty
 * @value: the stsdfring env var vsdfalue
 *  Return: Alwasdfys 0
=======
 * _setevrnt - Initialize a new evrntment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string evrnt var property
 * @value: the string evrnt var value
 *  Return: Always 0
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
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
