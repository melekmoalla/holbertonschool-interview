#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses the linked list.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Pointer to pointer of the head of the list.
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head) {
    if (!head || !*head) {
        return 1;
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half = NULL;
    listint_t *prev_of_slow = NULL;
    int result = 1;

    // Move slow pointer one step and fast pointer two steps
    while (fast && fast->next) {
        prev_of_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If there are odd nodes, then ignore the middle node
    if (fast) {
        slow = slow->next;
    }

    // Reverse the second half and compare it with the first half
    second_half = reverse_list(slow);
    listint_t *copy_of_second_half = second_half;

    while (*head && second_half) {
        if ((*head)->n != second_half->n) {
            result = 0;
            break;
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    // Restore the original list (optional)
    reverse_list(copy_of_second_half);

    // Restore the first half (optional)
    if (prev_of_slow) {
        prev_of_slow->next = slow;
    }

    return result;
}
