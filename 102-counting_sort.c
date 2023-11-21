#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t i, j;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *counting_array = malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	printf("Counting array: ");
	for (i = 0; i <= max; i++)
	{
		printf("%d", counting_array[i]);
		if (i < max)
			printf(", ");
	}
	printf("\n");
	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (counting_array[i]-- > 0)
			array[j++] = i;
	}
	free(counting_array);
}
