#include "sort.h"
#include <stdlib.h>

/**
 * get_max - finds maximum value in array
 * @array: array
 * @size: size of array
 *
 * Return: maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * fill_count - fills count array
 * @array: array
 * @size: size of array
 * @count: count array
 * @max: maximum value
 */
void fill_count(int *array, size_t size, int *count, int max)
{
	size_t i;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
}

/**
 * counting_sort - sorts an array using counting sort
 * @array: array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	fill_count(array, size, count, max);
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
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
