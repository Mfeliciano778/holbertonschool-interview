#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sort an array of ints using the Radix sort algorithm
 * @array: Pointer to start of array to sort
 * @size: Number of elements in the array
 *
 * Returns: Always nothing
 */
void radix_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		exit(EXIT_FAILURE);

	radix_recursive(array, buff, size, 1);

	free(buff);
}
/**
 * radix_recursive - Sort an array recursively using LSD radix sort
 * @array: Pointer to array to sort
 * @buffer: Pointer to temporary buffer
 * @size: Number of elements in array and buffer
 * @step: Significant digit to sort by
 *
 * Returns: Always nothing
 */
void radix_recursive(int *array, int *buff, size_t size, int step)
{
	int num;
	size_t index, bindex = 0, sorted = 1;

	for(num = 0; num < 10; num++)
	{
		for (index = 0; index < size; index++)
		{
			if (array[index] / step > 0)
				sorted = 0;
			if ((array[index] / step) %  10 == num)
				buff[bindex++] = array[index];
		}
	}

	for (index = 0; index < size; index++)
	{
		array[index] = buff[index];
	}

	if (sorted)
		return;

	print_array(array, size);
	radix_recursive(array, buff, size, step * 10);
}
