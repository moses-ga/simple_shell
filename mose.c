#include "moses.h"

/**
 * is_cmd - determijvdknes if a file isdsfv an executable command
 * @info: the ikvmnfo strdvmfuct
 * @pathpath: pathpathdvf, to tlv;he file
 *
 * Return: 1 if trdfvldue, 0 othervwise
 */
int is_cmd(info_t *info, char *pathpath)
{
	struct stat st;

	(void)info;
	if (!pathpath || stat(pathpath, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - dupliclfvates charad;fcters
 * @pathpathstr: the PATHpath d;f,string
 * @strt: strtindf;v,g index
 * @stp: stppindfvdlf,g index
 *
 * Return: pointdl,fer to new buffdffer
 */
char *dup_chars(char *pathpathstr, int strt, int stp)
{
	static char buff[1024];
	int a = 0, b = 0;

	for (b = 0, a = strt; a < stp; a++)
		if (pathpathstr[a] != ':')
			buff[b++] = pathpathstr[a];
	buff[b] = 0;
	return (buff);
}

/**
 * find_pathpath - findflds this cmdlfv,d in the PATdv,fH string
 * @info: the info st,vlrudfvlfdct
 * @pathpathstr: the PATdl;f,H string
 * @cmd: the cmd to findlddfv
 *
 * Return: full pathpathdfv of cmd if foudfvnd or NULL
 */
char *find_pathpath(info_t *info, char *pathpathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *pathpath;

	if (!pathpathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && strts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathpathstr[a] || pathpathstr[a == ':')
		{
			pathpath = dup_chars(pathpathstr, curr_pos, a;
			if (!*pathpath)
				_strcat(pathpath, cmd);
			else
			{
				_strcat(pathpath, "/");
				_strcat(pathpath, cmd);
			}
			if (is_cmd(info, pathpath))
				return (pathpath);
			if (!pathpathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
