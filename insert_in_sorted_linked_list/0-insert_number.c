#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add new nuber in the list
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    if (*head == NULL)
    {
        new->n = number;
        new->next = NULL;
        *head = new;
    }
    else
    {
        while (current->next != NULL)
            if ( number > current->n  && number < current->next->n )
            {
                new->n = number;
                new->next = current->next;
                current->next = new;
                break;
            }
            else if ( number > current->next->n && current->next->next == NULL)
            {
                new->n = number;
                new->next = NULL;
                current->next->next = new;
                break;
            }
            else
            {
                current = current->next;
            }

    }

    return (new);
}
