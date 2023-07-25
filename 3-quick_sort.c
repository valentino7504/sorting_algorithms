#include "sort.h"
/**
 * swap - swaps elements of an array
 * @array: the array
 * @i: the index of the first element
 * @j: the index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: does the partitioning
 * @low: the index to start from
 * @high: the index of the last element
 * @size: The size of the array
 * Return: the pivot index
 */
int lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_helper - implements the quick sort and maintains OG array
 * @array: the array
 * @low: the starting point
 * @high: the end point
 * @size: the size of the array
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	int pivot_index;

	if (low >= high)
		return;
	pivot_index = lomuto_partition(array, low, high, size);
	if (pivot_index > 0)
		quick_sort_helper(array, low, pivot_index - 1, size);
	quick_sort_helper(array, pivot_index + 1, high, size);
}
/**
 * quick_sort - sorts an array using Lomuto partition scheme
 * quicksort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
