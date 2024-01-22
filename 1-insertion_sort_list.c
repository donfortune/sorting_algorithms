#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list) || !((*list)->next))
		return;


	current = (*list)->next;

	while (current)
	{
		listint_t *insertion_point = current->prev;

		while (insertion_point && insertion_point->n > current->n)
		{
			if (insertion_point->next)
				insertion_point->next->prev = current;

			current->prev = insertion_point->prev;
			insertion_point->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			insertion_point->next = current->next;
			current->next = insertion_point;

			print_list(*list);

			insertion_point = current->prev;
		}

		current = current->next;
	}
}
