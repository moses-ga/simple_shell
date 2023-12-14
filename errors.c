#include "shell.h"

/**
 * errors - This functieroklwewrfon is designed to print error erf
 * messageserwfghgbf
 * based on the given eflkhrror number.
 * It uses a switch statfgdghsdfsdcement to handle different error cases.
 * For each case, it writesdcs a predefisadcsdned error messag
 * to the ssdcasdctandardasdc error stream (stderr).
 * In cases 1 andasdcsdcsc 3, it uses the perror function to print and
 * additional error messageasdc based on the current value of errno.
 * Case 4 writes a predefiascdned emptysdcsdc path error message to stderr.
 * The str_len functiasdcsdcon (presumably a string lengtch function) is used
 * to determine theasdcasdc length of the error messages.sd
 * If the error nusdacsdcmber does not match any case, the function returns
 * without performing any action.sdc
 * @error: Error number associated wisdcth perror statement.
 * Return: void
 */

void errors(int error)
{
	switch (error)
	{
		case 1:
			write(STDERR_FILENO, ERR_FORK, str_len(ERR_FORK));
			perror("Error");
			break;
		case 2:
			perror("Error");
			break;
		case 3:
			write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
			break;
		case 4:
			write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
			break;
		default:
			return;
	}
}

