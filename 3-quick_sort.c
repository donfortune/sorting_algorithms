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

	if (size > 1 && array)
	{
		qs(array, 0, size - 1, size);
	}
}


/**
 * qs - sorts an array of integers in ascending order
 * using selection_sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 * @low: start
 * @high: end
 *
 * Return: void
 */
void qs(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index = 0;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		if (pivot_index > low)
			qs(array, low, pivot_index - 1, size);
		if (pivot_index < high)
			qs(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - sorts an array of integers in ascending order
 * using selection_sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 * @low: start
 * @high: end
 * Return: void
 */
int lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, temp = 0, j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[j] != array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);

			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
