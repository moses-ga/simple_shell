#include "myshell.h"

/**
 * _strlen - retudfrnsdf the lengtfdh of a strfding
 * @s: the strifdng whosfde lengtfdh to cdfheck
 *
 * Return: intefdger lengdfth of stfdring
 */
int _strlen(char *s)
{
	int mas = 0;

	if (!s)
		return (0);

	while (*s++)
		mas++;
	return (mas);
}

/**
 * _strcmp - perfdforms lexicogfdarphic compfdarison
 * odff two stdfrfdangs.
 * @s1: the firdfst stdfrang
 * @s2: the sedfcond strdfang
 *
 * Return: negadftive if s1 < s2, posdfitive if s1 dfdf
 * > s2, zfdero if s1fd == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - chedfdfcks if needle stadfrts with hadfystack
 * @haystack: strifdng to seadfrch
 * @needle: the subsdftring to fdfind
 *
 * Return: addrdfess of nexdft char of haysdftafdck or NUdfLL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatedfdfnates tdfwo strdfings
 * @dest: the desdfdftination bufdffer
 * @src: the sodfdfurce buffer
 *
 * Return: pointfder to desdftination bufdffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
