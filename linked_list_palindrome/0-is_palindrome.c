#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *add_nodeint_front(listint_t **head, int n, listint_t *reserved_nodes, int *current_index)
{

	listint_t *new_node = &reserved_nodes[*current_index];
	(*current_index)++;
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
int get_length(listint_t *head)
{
	int length = 0;
	while (head != NULL)
	{
		length++;
		head = head->next;
	}
	return length;
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
		
	int length = get_length(*head);
	current = *head;
	listint_t reserved_nodes[length];
	int current_index = 0;

	while (current != NULL)
	{
		add_nodeint_front(&new, current->n, reserved_nodes, &current_index);
		current = current->next;
	}
	current = *head;

	while (current != NULL)
	{
		if (current->n != new->n)
			return 0;
		current = current->next;
		new = new->next;
	}
	return 1;
}
