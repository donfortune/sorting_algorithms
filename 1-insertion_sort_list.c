#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 *
 * Description: The function sorts the elements of the doubly linked list
 * in ascending order using the insertion sort algorithm.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = *list;

    while (current)
    {
        while (current->next && current->n > current->next->n)
        {
            temp = current->next;
            current->next = temp->next;
            temp->prev = current->prev;

            if (current->prev)
                current->prev->next = temp;

            if (temp->next)
                temp->next->prev = current;

            current->prev = temp;
            temp->next = current;

            if (temp->prev)
                current = temp->prev;
            else
                *list = temp;

            print_list(*list);
        }

        current = current->next;
    }
}
