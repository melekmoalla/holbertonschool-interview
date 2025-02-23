#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct List - Doubly linked list node structure
 * @str: malloc'ed string
 * @prev: Points to the previous node
 * @next: Points to the next node
 *
 * Description: Circular doubly linked list structure for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;


List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif
