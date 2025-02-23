#include <stdlib.h>
#include <string.h>
#include "list.h"



List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp_node;


	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (!*list)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}

	tmp_node = (*list)->prev;
	new_node->next = *list;
	new_node->prev = tmp_node;
	tmp_node->next = new_node;
	(*list)->prev = new_node;

	return (new_node);

}



List *add_node_begin(List **list, char *str)
{
	List *new_node = add_node_end(list, str);

	if (!new_node)
		return (NULL);

	*list = new_node;

	return (new_node);
}
