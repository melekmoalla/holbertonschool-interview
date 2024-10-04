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
    listint_t *new;
    listint_t *current;
    listint_t *current2;

    if (*head == NULL)
        return (1);

    current2 = NULL;
    current = *head;

    // Create a reversed copy of the linked list
    while (current != NULL)
    {
        new = malloc(sizeof(listint_t));
        if (new == NULL)
        {
            // Free allocated memory in case of error
            while (current2 != NULL)
            {
                listint_t *temp = current2;
                current2 = current2->next;
                free(temp);
            }
            return (0);
        }

        new->n = current->n;
        new->next = current2;  // Attach new node at the beginning of reversed list
        current2 = new;  // Move current2 to the new node
        current = current->next;
    }

    // Compare original list with reversed list
    current = *head;
    listint_t *current3 = current2;  // Point to the start of the reversed list

    while (current != NULL && current3 != NULL)
    {
        if (current->n != current3->n)
        {
            // Free reversed list in case of mismatch
            while (current3 != NULL)
            {
                listint_t *temp = current3;
                current3 = current3->next;
                free(temp);
            }
            return (0);  // Not a palindrome
        }
        current = current->next;
        current3 = current3->next;
    }

    // Free the reversed list
    while (current3 != NULL)
    {
        listint_t *temp = current3;
        current3 = current3->next;
        free(temp);
    }

    return (1);  // It is a palindrome
}
