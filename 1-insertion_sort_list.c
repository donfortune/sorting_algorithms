#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                        using the insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *temp;

	current = *list;

	while (current)
	{
		while (current->next && current->n > current->next->n)
		{
			temp = current->next;
			current->next = temp->next;

			if (current->next)
				current->next->prev = current;

			temp->prev = current->prev;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next = current;
			current->prev = temp;

			if (temp->prev)
				current = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
