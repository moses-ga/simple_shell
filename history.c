#include "shell.h"

/**
 * getFileHistory - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *getFileHistory(info_t *info)
{
	char *buffr, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buffr = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buffr)
		return (NULL);
	buffr[0] = 0;
	_strcpy(buffr, dir);
	_strcat(buffr, "/");
	_strcat(buffr, HIST_FILE);
	return (buffr);
}

/**
 * writeHistr - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
 
 
int writeHistr(info_t *info)
{
	ssize_t fd;
	char *filename = getFileHistory(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * readHistr - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
 
 
int readHistr(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffr = NULL, *filename = getFileHistory(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffr = malloc(sizeof(char) * (fsize + 1));
	if (!buffr)
		return (0);
	rdlen = read(fd, buffr, fsize);
	buffr[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffr), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buffr[i] == '\n')
		{
			buffr[i] = 0;
			linkHistr(info, buffr + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		linkHistr(info, buffr + last, linecount++);
	free(buffr);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	linkedNumberHistr(info);
	return (info->histcount);
}

/**
 * linkHistr - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buffr: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
 
 
int linkHistr(info_t *info, char *buffr, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buffr, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * linkedNumberHistr - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
 
 
int linkedNumberHistr(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}