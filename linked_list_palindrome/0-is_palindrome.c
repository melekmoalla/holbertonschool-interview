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
    listint_t *current2 = NULL; // Pointer for the reversed list
    listint_t *current3; // Pointer to keep track of the head of the reversed list

    // If the list is empty or has one element, it is a palindrome
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    current = *head;
    // Create a reversed copy of the original list
    while (current != NULL)
    {
        new = malloc(sizeof(listint_t));
        if (new == NULL)
        {
            // Free any allocated memory before returning
            while (current2 != NULL)
            {
                listint_t *temp = current2;
                current2 = current2->next;
                free(temp);
            }
            return (0);
        }

        new->n = current->n;
        new->next = current2; // Reverse the link
        current2 = new; // Move to the new head
        current = current->next; // Move to the next element in the original list
    }

    // Compare the original list with the reversed list
    current = *head;
    current3 = current2; // Keep track of the head of the reversed list

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

    // Free the reversed list
    while (current3 != NULL)
    {
        listint_t *temp = current3;
        current3 = current3->next;
        free(temp);
    }
    
    return (1);
}
