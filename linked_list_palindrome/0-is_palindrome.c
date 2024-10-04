#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *add_nodeint_front(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{

	listint_t *new;

	new = NULL;

	listint_t *current;

	if (*head == NULL)
		return (1);

	current = *head;

	while (current != NULL)
	{
		add_nodeint_front(&new, current->n);

		current = current->next;
	}

	current = *head;

	while (current != NULL)
	{
		if (current->n != new->n)
		{
			free_listint(new);
			return 0;
		}
		current = current->next;
		new = new->next;
	}
	free_listint(new);
	return 1;
}
