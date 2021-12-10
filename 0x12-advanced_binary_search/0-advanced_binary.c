#include "search_algos.h"

/**
 * advanced_binary - searches for a value in sorted array of integers
 * @array: array
 * @size: array size
 * @value: value
 * Return: index at value, else -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (simple_binary(array, 0, size - 1, value));
}
/**
 * simple_binary - searches through an array like a binary tree
 * @array: array
 * @left: left index
 * @right: right index
 * @value: value
 * Return: index at value, else -1
 */
int simple_binary(int *array, int left, int right, int value)
{
	int mid;

	if (right >= left)
	{
		print_array(array, left, right);

		mid = left + (right - left) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (simple_binary(array, left, mid, value));
		return (simple_binary(array, mid + 1, right, value));
	}
	return (-1);
}
/**
* print_array - prints the array
* Return: void
* @array: pointer to first element
* @start: where to start printing
* @size: how much to print
*/
void print_array(int *array, int start, int size)
{
	printf("Searching in array: %i", array[start]);
	start += 1;
	for (; start <= size; start++)
		printf(", %i", array[start]);
	printf("\n");
}
