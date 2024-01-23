#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - sorts an array of integers in ascending order
 * using selection_sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_index = 0;
	if (size > 1)
	{
		pivot_index = lomuto_partition(array, 0, size - 1);

		if (pivot_index != 0)
			quick_sort(array, pivot_index);

		if (pivot_index != size - 1)
			quick_sort(array + pivot_index + 1, size - pivot_index - 1);
	}
}

int lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t n = array_size(array);
	size_t i = low, temp = 0, j = 0;

	for (j = 0; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, n);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	return (i);
}

size_t array_size(int *array)
{
	int j = 0;
	for (; array[j]; j++)
		;
	return (j);
}
