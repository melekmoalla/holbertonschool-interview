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
    listint_t *slow, *fast, *second_half, *prev = NULL, *temp;
    int is_palindrome = 1;

    // If the list is empty or has one node, it's a palindrome
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    slow = *head;
    fast = *head;

    // Find the middle of the list using the fast and slow pointer technique
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // If the list has an odd number of nodes, skip the middle node
    if (fast != NULL)
        slow = slow->next;

    // Reverse the second half of the list
    second_half = slow;
    prev->next = NULL; // Terminate the first half of the list

    // Reverse the second half
    while (second_half != NULL)
    {
        temp = second_half;
        second_half = second_half->next;
        temp->next = prev;
        prev = temp;
    }

    // Compare the two halves
    listint_t *first_half = *head;
    second_half = prev; // The reversed second half

    while (second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            is_palindrome = 0; // Not a palindrome
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Restore the original list (optional)
    // Reverse the second half back to its original form
    second_half = prev; // Reset to the head of the reversed half
    prev = NULL;

    while (second_half != NULL)
    {
        temp = second_half;
        second_half = second_half->next;
        temp->next = prev;
        prev = temp;
    }

    return is_palindrome; // Return 0 or 1
}
