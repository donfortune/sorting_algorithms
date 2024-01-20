#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * using selection_sort algorithm 
 * @array: The array of integer
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

    /**
	* j moves size - 1 times 
	* and i moves half of size times
    */
    for (j = 0; j < size - 1; j++)
    {
		/* Updates i to be in front of j by 1 */
        for (i = j + 1; i < size; i++)
        {
            if (array[j] > array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
				print_array(array, size);
            }
        }
    }
}
