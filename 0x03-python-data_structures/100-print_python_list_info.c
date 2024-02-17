#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the pointer of the head of the list
 *
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: The head of the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half = NULL, *prev_slow = *head;
    listint_t *mid_node = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) // odd nodes; move slow one step forward
    {
        mid_node = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev_slow->next = NULL; // Terminate first half

    reverse_list(&second_half); // reverse the second half

    is_palindrome = compare_lists(*head, second_half);

    // Reverse the second half back to its original position
    reverse_list(&second_half);

    // If the list was originally odd, reconnect the second half to the middle node
    if (mid_node != NULL)
    {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    }
    else
    {
        prev_slow->next = second_half;
    }

    return is_palindrome;
}

