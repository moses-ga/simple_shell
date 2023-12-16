#include <stdlib.h>
#include "main.h"
/**
 * _myenv - princvbts the currcvbcbvent environment
 * @info: Structbvcbvure containing potentibval argumencbvts.
 * Uscbved to mbvcainvtain
 * constant funccbvtion prototbvcype.
 * Return: Alwcbvays 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->evrnt);
	return (0);
}

/**
 * _getenv - getcbvs the valcbvue of an envibvcron varibvable
 * @info: Structure contaicbvning potential argumbvcents. Used to maibvntain
 * @name: env vcbvar ncbvame
 *
 * Return: the valcbvue
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->evrnt;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialicbvcbvze a new envircbvonment variabbvcle,
 * or mocbvdify an existcbving one
 * @info: Structure contacbvining potcbvential argumcbvents.
 * Usedcbv to maicbvntain
 * onstant functcbvion protocbvtype.
 *  Return: Alwcbvays 0
 */
int _mysetenv(info_t *info)
{
	if (info->arntc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (setenv(info->arntv[0], info->arntv[1], 1))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remocbvve an environcbvcbvment variablbve
 * @info: Structure contcbvaining potcbvential argucbvments. Used tcbv
 * o maintain conscbvtant function procbvtotype.
 *  Return: Alwacbvys 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->arntc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->arntc; i++)
		_unsetenv(info, info->arntv[i]);

	return (0);
}

/**
 * populate_env_list - populatecbvs env linkecbvd list
 * @info: Structure concbvcbvtaining potential argucbvments.
 * Used to maicbvntaincbvconcbvstcbvant function prvbototype.
 * Return: Alwacbvys 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->evrnt = node;
	return (0);
}
