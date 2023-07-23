#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t first_unsorted = 0, i, j, min_index = 0;
	int minimum = 0, temp;
	for (i = 0; i < size; i++)
	{
		for (j = first_unsorted; j < size; j++)
		{
			if (array[j] < minimum)
			{
				minimum = array[j];
				min_index = j;
			}
		}
		if (min_index != first_unsorted)
		{
			temp = array[first_unsorted];
			array[first_unsorted] = minimum;
			array[min_index] = temp;
			print_array(array, size);
		}
		first_unsorted++;
		minimum = array[first_unsorted];
		min_index = first_unsorted;
	}
}
