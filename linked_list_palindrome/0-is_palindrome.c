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
    listint_t *current = *head;
    listint_t *reversed = NULL;
    listint_t *temp;

    // If the list is empty, it's considered a palindrome
    if (*head == NULL)
        return (1);

    // Reverse the linked list without malloc
    while (current != NULL)
    {
        // Create a new node in the reversed list
        temp = malloc(sizeof(listint_t));  // Use temp to hold the new node
        if (temp == NULL)
            return (0);  // Handle malloc failure
        
        temp->n = current->n;
        temp->next = reversed;  // Point to the previous head of reversed list
        reversed = temp;        // Update the head of the reversed list
        current = current->next; // Move to the next node
    }

    current = *head; // Reset current to the head of the original list

    // Compare the original list with the reversed list
    while (current != NULL && reversed != NULL)
    {
        if (current->n != reversed->n)
        {
            // Free the reversed list before returning
            while (reversed != NULL)
            {
                temp = reversed;
                reversed = reversed->next;
                free(temp);  // Free the temporary node
            }
            return (0); // Not a palindrome
        }
        current = current->next;  // Move to the next node in the original list
        reversed = reversed->next; // Move to the next node in the reversed list
    }

    // Free the reversed list after comparison
    while (reversed != NULL)
    {
        temp = reversed;
        reversed = reversed->next;
        free(temp); // Free the temporary node
    }

    return (1); // It's a palindrome
}
