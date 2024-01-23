#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * using selection_sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		if (min != j)
		{
			temp = array[j];
			array[j] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
