#include "myShell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->arnt = NULL;
	info->arntv = NULL;
	info->path = NULL;
	info->arntc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: arntument vector
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->filname = av[0];
	if (info->arnt)
	{
		info->arntv = strtow(info->arnt, " \t");
		if (!info->arntv)
		{

			info->arntv = malloc(sizeof(char *) * 2);
			if (info->arntv)
			{
				info->arntv[0] = _strdup(info->arnt);
				info->arntv[1] = NULL;
			}
		}
		for (i = 0; info->arntv && info->arntv[i]; i++)
			;
		info->arntc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->arntv);
	info->arntv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->command_buf)
			free(info->arnt);
		if (info->arnt)
			free_list(&(info->arnt));
		if (info->hstry)
			free_list(&(info->hstry));
		if (info->aliyas)
			free_list(&(info->aliyas));
		ffree(info->evrntiron);
			info->evrntiron = NULL;
		bfree((void **)info->command_buf);
		if (info->somafd > 2)
			close(info->somafd);
		_putchar(BUF_FLUSH);
	}
}
