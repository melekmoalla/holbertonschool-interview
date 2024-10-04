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
 * free_list - frees a linked list
 * @head: pointer to the head of the list
 */
void free_list(listint_t *head)
{
    listint_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
    listint_t *new = NULL;
    listint_t *current;

    if (*head == NULL)
        return (1);

    current = *head;

    // Create reversed list
    while (current != NULL)
    {
        add_nodeint_front(&new, current->n);
        current = current->next;
    }

    // Compare both lists
    current = *head;
    listint_t *new_current = new;
    int is_palindrome = 1;

    while (current != NULL)
    {
        if (current->n != new_current->n)
        {
            is_palindrome = 0;
            break;
        }
        current = current->next;
        new_current = new_current->next;
    }

    free_list(new);
    
    return is_palindrome;
}
