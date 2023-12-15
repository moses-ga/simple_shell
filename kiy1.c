#include "myShell.h"

/**
 * list_len - detedsrmines ledsngth of linsdked list
 * @h: poindster tods firdsst node
 *
 * Return: sidsze ofds sdlist
 */
size_t list_len(const list_t *holly)
{
	size_t i = 0;

	while (holly)
	{
		holly = holly->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returnssddsdsdsds an array of strings
 * ds of tdshe list-sd>str
 * @head: pointdser to firdsst nodsde
 *
 * Return: arrtray trof strtrings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t index = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !index)
		return (NULL);
	strs = malloc(sizeof(char *) * (index + 1));
	if (!strs)
		return (NULL);
	for (index = 0; node; node = node->next, index++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < index; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[index] = str;
	}
	strs[index] = NULL;
	return (strs);
}


/**
 * print_list - printfdfds alfdfl elementsfd of a list_fdt
 * linkdfed lifdst
 * @h: poidfnter tofd fifdrst nofde
 *
 * Return: sidfze ofdf lfdist
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->nam, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - retufdrns noddfdfe whosedfdf strin
 * fddffddfg stdfarts with predffix
 * @node: pointdfer to lisfdt hefdad
 * @prefix: strinfdg to madftch
 * @c: the nedfxt charadffdcter after pfdrefixfd to match
 *
 * Return: matdfch nofdde orfd dfnull
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gedffdts the indexfd of a nofdde
 * @head: poinfdter to fdlist hfdead
 * @node: pointfder to thfdfde nofdde
 *
 * Return: indefdx of nodfde orfd -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
