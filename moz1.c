#include "myShell.h"

/**
<<<<<<< HEAD
 * _myexit - exitsds the shesdll
 * @info: Structure contaisdning potensdsdtial argumsdents.
 *  Ussdssdded to mainsdtain
 *  constasdnt functsdion protsdotype.
 *  Return: exits wisdth a givesdn exit stasdtus
 *         (0) if infosd.argv[0] != "exit"
=======
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit stts
 *         (0) if info.arntv[0] != "exit"
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
 */
int _myexit(info_t *info)
{
	int exitcheck;

<<<<<<< HEAD
	if (info->argv[1])
=======
	if (info->arntv[1])  /* If there is an exit arguement */
>>>>>>> 771bfd101e25d71d57932670b064105e740373bc
	{
		exitcheck = _erratoi(info->arntv[1]);
		if (exitcheck == -1)
		{
			info->stts = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->arntv[1]);
			_eputchar('\n');
			return (1);
		}
		info->erro_nam = _erratoi(info->arntv[1]);
		return (-2);
	}
	info->erro_nam = -1;
	return (-2);
}

/**
 * _mycd - changes the currdfasent direcdfastory of the proadfscess
 * @info: Strucdfture contasdfaining poteasndftial argumadfsents.
 * Useadfdfsd to maindftain
 * consastant funcdftasion protoadfstype.
 *  Return: Alwadfys 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->arntv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->arntv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->arntv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->arntv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the currdfent direcdftory of the prodfcess
 * @info: Structdfdfure containidfng potentidfal arguments.
 * Useddf to dfdfdf
 * constdfant functdfion prototydfpe.
 *  Return: Alwadfys 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->arntv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
