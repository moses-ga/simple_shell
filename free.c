#include "shell.h"

/**
 * free_all - This functionrhafl is designed to free dynamicwefnl
 * nfwefwefally allocated memory
 * atthe end of the maiednwn loop in your shefwasll program.
 * The function uses asefsdfvthe free function to release
 * sdftsdfhe memory occupied
 * by each dynamically allocated variablsdme.
 * It checks whesdcmsklcmther fullpath was dynamically allocated
 * (flag == 1) beforsdmckldsdke attempting to free it.
 * @tokens: Pointer to tokenssdfvv array.
 * @path: Pointer tsdcsdco path variable.
 * @line: Pointer to udsfvfvser input buffer.
 * @fullpath: Pointer tosdvvd full path.
 * @flag: Flag markingsdcscsdc if full_path was malloc'd.
 * Return: voidcsc sc
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{

	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - This function is responrgtrggtrhg
 * sible for freeing a double pointer (array)
 * and the meerfefmoryoccupied by the srfjeiroterferings it points to.
 * The function useerferffs for loop to iterate each element o
 * f terffhe double pointer.rfvfvv
 * It uses the fefffvvree function to dfvdfvrelease the me
 * mory occupidfvved by the stringsgtgdrf
 * pointed to by the double pointer.dfvdfvdfv
 * Finally, it frees the memory occuptrhhbied by the double pointer
 * itself using free(array).efnek
 * @array: Double pointer to free.ekwokd
 * @length: Length of the double pointer.ekdmkdm
 * Return: voidsekep
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	for (i = 0; i < length; i++)
	{
		free(array[i]);
	}
	free(array);
}

