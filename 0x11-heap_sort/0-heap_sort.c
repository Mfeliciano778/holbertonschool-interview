#include "sort.h"

void arrayToHeap(int *array, size_t size, unsigned int idx, size_t print);
/**
* heap_sort - performs heap sort on array
* Return: void
* @array: the list of numbers to sort
* @size: the size of the array
*/
void heap_sort(int *array, size_t size)
{
/*	unsigned int i;*/
	int tmp, i;

	for (i = size / 2 - 1; i >= 0; i--)
		arrayToHeap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		arrayToHeap(array, i, 0, size);
	}
}

/**
* arrayToHeap - makes array into heap form
* Return: void
* @array: the list of numbers to sort
* @size: the size of the array
* @idx: current spot in the heap
* @print: how big is the orginal array for printing
*/
void arrayToHeap(int *array, size_t size, unsigned int idx, size_t print)
{
	unsigned int left, j, i;
	int temp;

	i = idx;
	left = 2 * idx + 1;
	j = 2 * idx + 2;
	if (left < size && array[left] > array[i])
		i = left;
	if (j < size && array[j] > array[i] && array[j] > array[left])
		i = j;
	if (i != idx)
	{
		temp = array[idx];
		array[idx] = array[i];
		array[i] = temp;
		print_array(array, print);
		arrayToHeap(array, size, i, print);
	}
}
