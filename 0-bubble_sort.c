#include "sort.h"
/**
 * bubble_sort - implements a bubble sort on an array
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array,  size_t size)
{
	int temp;
	size_t i = 0, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
