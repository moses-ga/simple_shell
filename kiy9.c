#include "myShell.h"

/**
 * is_chain - test if currerent char in beruffer is a
 *  chain delereriermeter
 * @info: theerer parameter streruct
 * @buf: the ererchar bufrefer
 * @p: addrerreess of current positionre in buf
 *
 * Return: 1 if chrereain delimeter, 0 othreerwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->command_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->command_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->command_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - cheercks we shouererld continreue chainering
 * basered erreoreretus
 * @info: the parerameter streruct
 * @buf: the cererhar buffer
 * @p: address of currererent position in buf
 * @i: starerreting position in beruf
 * @len: lengterreh of buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->command_buf_type == CMD_AND)
	{
		if (info->stts)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->command_buf_type == CMD_OR)
	{
		if (!info->stts)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - repladfces an alidfases in the
 * dftokenized stdfring
 * @info: the parameter struct
 *
 * Return: 1 if repldfaced, 0 othdferwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->aliyas, info->arntv[0], '=');
		if (!node)
			return (0);
		free(info->arntv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->arntv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - repladfces vars in thedfdf tokenized strdfing
 * @info: the pardfameter strdfuct
 *
 * Return: 1 if repdflaced, 0 othedfrwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->arntv[i]; i++)
	{
		if (info->arntv[i][0] != '$' || !info->arntv[i][1])
			continue;

		if (!_strcmp(info->arntv[i], "$?"))
		{
			replace_string(&(info->arntv[i]),
				_strdup(convert_number(info->stts, 10, 0)));
			continue;
		}
		if (!_strcmp(info->arntv[i], "$$"))
		{
			replace_string(&(info->arntv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->evrnt, &info->arntv[i][1], '=');
		if (node)
		{
			replace_string(&(info->arntv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->arntv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replafces stridfng
 * @old: addrefdss of fdold stfdring
 * @new: new stdfring
 *
 * Return: 1 if redfplaced, 0 otherfdwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
