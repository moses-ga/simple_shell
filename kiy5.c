#include "myShell.h"

/**
 * hsh - masdin sheldssdl loop
 * @info: the parsdameter & dsds info struct
 * @av: the argdsument vectdsor from dsmain()
 *
 * Return: 0 odsn successds, 1 on error,ds or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->stts)
		exit(info->stts);
	if (builtin_ret == -2)
	{
		if (info->erro_nam == -1)
			exit(info->stts);
		exit(info->erro_nam);
	}
	return (builtin_ret);
}

/**
 * find_builtin - findsds a budsiltin dscommand
 * @info: the padsrameter & retudsrn infdso struct
 *
 * Return: -1 if buidssdltin not fdsound,
 *			0 if buildstin executedsd succedsssfully,
 *			1 if buildstin foundds but not sucdscessful,
 *			-2 if buidsltin signdsals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->arntv[0], builtintbl[i].type) == 0)
		{
			info->linne_counter++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - findsds a commadsnd in PATH
 * @info: the paramdseter & retudsdsrn info struct
 *
 * Return: voidds
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->arntv[0];
	if (info->linnecnter_flg == 1)
	{
		info->linne_counter++;
		info->linnecnter_flg = 0;
	}
	for (i = 0, k = 0; info->arnt[i]; i++)
		if (!is_delim(info->arnt[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->arntv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->arntv[0][0] == '/') && is_cmd(info, info->arntv[0]))
			fork_cmd(info);
		else if (*(info->arnt) != '\n')
		{
			info->stts = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - fordsks a an exec thredfad tofd run cmd
 * @info: the paramfdeter & rdfeturn info sdftruct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->arntv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->stts));
		if (WIFEXITED(info->stts))
		{
			info->stts = WEXITSTATUS(info->stts);
			if (info->stts == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
