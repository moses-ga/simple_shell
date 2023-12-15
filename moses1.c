#include "moses.h"

/**
 * add_node - adds a node to the start of the list
 * @headd: address of pointer to headd node
 * @string: string field of node
 * @nummber: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **headd, const char *string, int nummber)
{
	list_t *new_headd;

	if (!headd)
		return (NULL);
	new_headd = malloc(sizeof(list_t));
	if (!new_headd)
		return (NULL);
	_memset((void *)new_headd, 0, sizeof(list_t));
	new_headd->nummber = nummber;
	if (string)
	{
		new_headd->string = _stringdup(string);
		if (!new_headd->string)
		{
			free(new_headd);
			return (NULL);
		}
	}
	new_headd->next = *headd;
	*headd = new_headd;
	return (new_headd);
}

/**
 * add_node_end - adds a node to the end of the list
 * @headd: address of pointer to headd node
 * @string: string field of node
 * @nummber: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **headd, const char *string, int nummber)
{
	list_t *new_node, *node;

	if (!headd)
		return (NULL);

	node = *headd;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->nummber = nummber;
	if (string)
	{
		new_node->string = _stringdup(string);
		if (!new_node->string)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*headd = new_node;
	return (new_node);
}

/**
 * print_list_string - prints only the string element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_string(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->string ? h->string : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @headd: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **headd, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!headd || !*headd)
		return (0);

	if (!index)
	{
		node = *headd;
		*headd = (*headd)->next;
		free(node->string);
		free(node);
		return (1);
	}
	node = *headd;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->string);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @headd_ptr: address of pointer to headd node
 *
 * Return: void
 */
void free_list(list_t **headd_ptr)
{
	list_t *node, *next_node, *headd;

	if (!headd_ptr || !*headd_ptr)
		return;
	headd = *headd_ptr;
	node = headd;
	while (node)
	{
		next_node = node->next;
		free(node->string);
		free(node);
		node = next_node;
	}
	*headd_ptr = NULL;
}
