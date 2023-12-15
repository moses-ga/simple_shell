#include "myShell.h"

/**
 * is_cmd - detersdmitrnes if a fildtrse is an executadtrtrsdsble command
 * @info: the ifdnfo strucdffdt
 * @path: path to the file
 *
 * Return: 1 if trtrue, 0 othfggerwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplitrcates characttrers
 * @pathstr: the PtrATH strtring
 * @start: starttrtring index
 * @stop: stoprtping indrtex
 *
 * Return: pointerer to new beruffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - fiernds this ercmd in terhe PATHer string
 * @info: the infosd strsduct
 * @pathstr: the PAsdTH strsding
 * @cmd: the cmsdd to fisdnd
 *
 * Return: full patsdh of cmd if sdsdfound or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
