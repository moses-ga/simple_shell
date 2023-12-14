#include "shell.h"

/**
 * buiilt_in_execu - Executes built-in commands based ondklfv,
 *  the provided tokens.
 * It checks if a command is providesdlcd, and if not, cdreturns 1.
 * It iterates through an array of buifvvdflt-in commands
 * and their correspondsdc,d,mfing functions.
 * If the provided commandadfcv matches a buifvdfvlt-in command, it executes
 * the corresponding function adfvnd returns its status.
 * If the command is not a dfcdcfbuilt-in, it returns 1.
 * @tokens: Argumentsdfc being passed.
 * Return: The return vadfcvdcflue depends on execution built-in func.
 */
int buiilt_in_execu(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	if (tokens[0] == NULL)
		return (1);
	length = str_len(tokens[0]);
	num = shell_no_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (str_cmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
 * shell_no_builtins - Counts the shgnknumber of built-in commajkrf
 * nds in the array.
 * It iterates through kdmflthe array until akldfc;, NULL entr
 * y is encountered
 * and counts the numbesd,lcr of builts;dlc-in commands.
 * Returns the total ndlcumber of buid,lmclt-in commands.
 * @builtin: Array of lsd,;built-in commalsd,nds.
 * Return: The number of b;ls,duilt-in comfdmands.
 */
int shell_no_builtins(built_s builtin[])
{
	unsigned int i = 0;

	while (builtin[i].name != NULL)
		i++;
	return (i);
}
