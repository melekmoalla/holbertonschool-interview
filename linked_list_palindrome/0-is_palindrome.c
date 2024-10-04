#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{

	listint_t *current = NULL;
	listint_t *current2 = NULL;


	if (*head == NULL)
		return (1);

	current2 = NULL;
	current = *head;
	
    while (current != NULL)
    {
        
        listint_t *new = malloc(sizeof(listint_t));
        if (new == NULL) 
            return (0);

        new->n = current->n;
        new->next = current2;
        current2 = new;
        current = current->next;
    }

	current = *head;

	while (current != NULL)
	{
		if (current->n != current2->n)
		{


			return (0);
		}
		current = current->next;
		current2 = current2->next;
	}


	return (1);
}
