#include "shell.h"

/**
 * str_cmp - Comparerjgeoes two strings (name afvdl,d,lv
 * nd variable) character byf,df.,d character up
 * to the specified length (length).rfmfmekfm
 * Returns 1 if the sfv,ld;v,vtrings are nofv,v
 * t equal, -1 if the lefv;v.ngths are different,
 * and 0 if the fv,d;fv.v are v'/fdequal.
 * @name: Name supplv.ff.ied by the user ;vd'f/to search for.
 * @variable: Variable to cof;d'vmpare against.
 * @length: Length odfvdfv.d'fv.'vf the name.
 * Return: 1 if strin c gs are equal, -1 if they are not.
 */
int str_cmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = str_len(variable);
	if (var_length != length)
		return (-1);
	i = 0;

	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * str_ncmp - Compares two stjfekfjrings (name and variable) up to
 * a specified length (length)dfnkjcc.
 * Returns 1 if the strings are edcmkldcmdcqual up to the specified length,
 * and -1 otherwise.
 * @name: Name supplied by the ucdmslcmdsser to search for.
 * @variable: Variable to comdmsokcmlcpare against.
 * @length: Length to compcmsdl,care up to.
 * Return: 1 if strings aredcm cms  equal, -1 if they are not.
 */
int str_ncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;

	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * str_cpy - Copies the sejifnerrfmtring pointed to by src
 * rferfmorkfmto buffer pointed to by dest.
 * Returns the pointerhfifrfr to dest.
 * @dest: String destirffefnation.
 * @src: String srfrferfource.
 * Return: The pointer trferffo dest.
 */
char *str_cpy(char *dest, char *src)
{
	int i;
	int j = str_len(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * str_len - Returns the jerifjeir of the input string s.
 *  Counts characters untenwkdmwdmil
 * the null terminator is encountered.
 * @s: String to brjoee evaluated.
 * Return: Length ofjrejf the string.
 */
int str_len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

