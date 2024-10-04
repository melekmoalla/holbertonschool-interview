#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_front - Adds a node at the beginning of a list
 * @head: Double pointer to the head of the list
 * @n: Value to store in the new node
 * Return: Pointer to the new head of the list
 */
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
 * free_list - Frees a linked list
 * @head: Pointer to the head of the list
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
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *new = NULL;
    listint_t *current;

    // An empty list is considered a palindrome
    if (*head == NULL)
        return (1);

    current = *head;

    // Create a reversed copy of the list
    while (current != NULL)
    {
        if (add_nodeint_front(&new, current->n) == NULL)
        {
            free_list(new); // Free memory in case of allocation failure
            return (0);
        }
        current = current->next;
    }

    // Compare the original list and the reversed list
    current = *head;
    listint_t *new_current = new;
    int is_palindrome = 1;

    while (current != NULL && new_current != NULL)
    {
        if (current->n != new_current->n)
        {
            is_palindrome = 0; // Not a palindrome
            break;
        }
        current = current->next;
        new_current = new_current->next;
    }

    // Free the reversed list
    free_list(new);

    return is_palindrome;
}
