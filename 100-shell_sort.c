#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *						using a custom version of Shell sort algorithm
 *							with a custom sequence.
 * @arr: The array to be sorted
 * @len: The size of the array
 */
void shell_sort(int *arr, size_t len)
{
	size_t gap, i, j;
	int temp;

	if (arr == NULL || len < 2)
		return;

	for (gap = 1; gap < len / 3; gap = gap * 3 + 1)
		;

	while (gap > 0)
	{
		for (i = gap; i < len; i++)
		{
			temp = arr[i];

			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			arr[j] = temp;
		}

		print_array(arr, len);

		gap = (gap - 1) / 3;
	}
}
