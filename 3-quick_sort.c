#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick Sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 *
 * Return: The final position of the pivot
 */
int lomuto_partition(int *arr, int low, int high, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[high];
	i = low;

	for (i2 = low; i2 < high; i2++)
	{
		if (arr[i2] < pivot)
		{
			if (i != i2)
			{
				tmp = arr[i2];
				arr[i2] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[high])
	{
		tmp = arr[i];
		arr[i] = arr[high];
		arr[high] = tmp;
		print_array(arr, size);
	}

	return (i);
}
