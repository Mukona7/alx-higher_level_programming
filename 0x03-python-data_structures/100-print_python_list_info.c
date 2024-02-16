#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * is_palindrome - Checks if a singly linked list is a palindrome
  * @head: The head of the singly linked list
  *
  * Return: 0 if it is not a palindrome, 1 if it is a palindrome
  */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = NULL;
    listint_t *second_half = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    // Find the middle of the list
    while (fast && fast->next)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    second_half = slow;
    if (fast) // odd number of nodes
        second_half = slow->next;
    prev_slow->next = NULL; // end the first half

    reverse_list(&second_half); // reverse the second half

    // Compare first and second halves
    while (*head && second_half)
    {
        if ((*head)->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    // Restore the original list
    reverse_list(&second_half); // reverse the second half again
    if (fast) // odd number of nodes
        prev_slow->next = slow;
    else
        prev_slow->next = reverse_list(&second_half);

    return is_palindrome;
}

/**
  * reverse_list - Reverses a linked list
  * @head: The head of the linked list
  *
  * Return: The head of the reversed linked list
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

