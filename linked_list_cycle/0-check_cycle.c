#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
int check_cycle(listint_t *list)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (0);
    if (list == NULL)
        return 0;
        
    new->n = list -> n;
    new->next = list -> next;

    listint_t *current = list;
    
    while (current != NULL)
    {
        current = current -> next;
        if (current == NULL)
            return 0;
        if (new->n == current -> n)
            return 1;

    }
    return 0;

}
