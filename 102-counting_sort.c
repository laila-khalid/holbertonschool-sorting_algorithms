#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array using counting sort
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, *count, *output;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
