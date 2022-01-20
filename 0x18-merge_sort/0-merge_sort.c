#include "sort.h"

/**
* merge_sort - merge sorts array
* Return: void
* @array: the numbers to sort
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	unsigned int index;
	int *array_copy;

	array_copy = malloc(sizeof(int) * size);
	for (index = 0; index < size; index++)
		array_copy[index] = array[index];
	tdmerge(array_copy, size, array, size);
	free(array_copy);
}

/**
* tdmerge - the recursive function for merge sorting
* Return: void
* @array: the array unsorted
* @size: size of the array
* @cpy: the second work array
* @cpysize: the size of b
*/
void tdmerge(int *array, size_t size, int *cpy, size_t cpysize)
{
	int midpoint = size / 2;

	(void)cpysize;
	if (size <= 1)
		return;
	tdmerge(cpy, midpoint, array, midpoint);
	tdmerge((cpy + midpoint), size - midpoint, (array + midpoint), 0);

	printf("Merging...\n[left]: ");
	print_array(array, midpoint);
	printf("[right]: ");
	print_array((array + midpoint), size - midpoint);
	mergearrays(array, size, midpoint, cpy);
	printf("[Done]: ");
	print_array(cpy, size);
}

/**
* mergearrays - merge the two arrays
* Return: void
* @array: numbers to get from
* @size:total size of the array
* @mp:midpoint of the array to split the array into 2
* @cpy: work array
*/
void mergearrays(int *array, size_t size, size_t mp, int *cpy)
{
	unsigned int i, jindex = mp, k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < mp && (jindex >= size || array[k] <= array[jindex]))
			cpy[i] = array[k], k++;
		else
			cpy[i] = array[jindex], jindex++;
	}
}
