#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * create_node - creates a new node for the linked list
 * @n: value for the new node
 * Return: pointer to the new node
 */
listint_t *create_node(int n)
{
    listint_t *new = (listint_t *)malloc(sizeof(listint_t));
    if (new == NULL)
    {
        return NULL;
    }
    new->n = n;
    new->next = NULL;
    return new;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if not palindrome, 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *new;
    listint_t *current;
    listint_t *current2;

    if (*head == NULL)
        return (1);

    current2 = NULL;
    current = *head;

    // Create the reversed list
    while (current != NULL)
    {
        new = create_node(current->n);  // Use create_node for better readability
        if (new == NULL)
        {
            // Free allocated memory if malloc fails
            while (current2 != NULL)
            {
                listint_t *temp = current2;
                current2 = current2->next;
                free(temp);
            }
            return (0);
        }

        // Insert the new node at the beginning of the reversed list
        new->next = current2;
        current2 = new;
        current = current->next;
    }

    // Compare the original list and the reversed list
    listint_t *current3 = current2;  // Preserve the reversed list head
    current = *head;

    while (current != NULL)
    {
        if (current->n != current2->n)
        {
            // Free the reversed list if not a palindrome
            while (current3 != NULL)
            {
                listint_t *temp = current3;
                current3 = current3->next;
                free(temp);
            }
            return (0);
        }
        current = current->next;
        current2 = current2->next;
    }

    // Free the reversed list after comparison
    while (current3 != NULL)
    {
        listint_t *temp = current3;
        current3 = current3->next;
        free(temp);
    }

    return (1);
}
