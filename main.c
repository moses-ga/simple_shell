#include "moses.h"

/**
 * main - entry point
 * @acc: arg count
 * @avv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int acc, char **avv)
{
	info_t info[] = { INFO_INIT };
	int fdd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fdd)
		: "r" (fdd));

	if (acc == 2)
	{
		fdd = open(avv[1], O_RDONLY);
		if (fdd == -1)
		{
			if (errno == EACcCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(avv[0]);
				_eputs(": 0: Can't open ");
				_eputs(avv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfdd = fdd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, avv);
	return (EXIT_SUCCESS);
}
