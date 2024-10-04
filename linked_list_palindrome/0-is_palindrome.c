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
    listint_t *new, *current, *current2;
    int is_palindrome = 1; // Flag to indicate palindrome status

    if (head == NULL || *head == NULL)
        return (1); // Empty list is a palindrome

    current2 = NULL;
    current = *head;

    // Reverse the list while creating a new one
    while (current != NULL)
    {
        new = malloc(sizeof(listint_t));
        if (new == NULL)
        {
            // Free previously allocated nodes in case of allocation failure
            while (current2 != NULL)
            {
                listint_t *temp = current2;
                current2 = current2->next;
                free(temp);
            }
            return (0); // Memory allocation failed
        }

        new->n = current->n;
        new->next = current2; // Add to the front of new list (reversing)
        current2 = new; // Move current2 to new node
        current = current->next; // Move to the next node in the original list
    }

    // Compare original list and reversed list
    current = *head; // Reset current to the head of the original list
    listint_t *temp2 = current2; // Keep a pointer to the head of the reversed list

    while (current != NULL)
    {
        if (current->n != temp2->n)
        {
            is_palindrome = 0; // Set flag if not a palindrome
            break;
        }
        current = current->next;
        temp2 = temp2->next;
    }

    // Free the reversed list
    while (current2 != NULL)
    {
        listint_t *temp = current2;
        current2 = current2->next;
        free(temp);
    }

    return (is_palindrome);
}
