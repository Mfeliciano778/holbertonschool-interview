#include "slide_line.h"
int reverse(int *arr, size_t size);
/**
* slide_line - slides and merges list of ints
* @line: pointer to array of ints
* @size: number of elements in array
* @direction: 1 or -1 to tell slide left or right respectively
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	int size_copy, i = 0, j = 1, curr = -1;

	size_copy = (int) size;
	if (!line)
		return (0);
	if (direction != 0 && direction != 1)
		return (0);
	if (direction == 1)
		reverse(line, size);
	/* printf("i starts at %i\n", i); */
	for (; i < size_copy && curr < size_copy && i >= 0;)
	{
		if (curr == -1)
		{
			curr = i;
			i += j;
		}
		/* printf("%i %i\n", curr, i);  */
		if (line[i] == line[curr] && line[curr] && i != curr)
		{
			line[curr] *= 2;
			line[i] = 0;
			curr += j;
			i += j;
		}
		else if (line[curr] == 0 && line[i] != 0)
		{
			line[curr] += line[i];
			line[i] = 0;
			/* curr += j; */
			i += j;
		}
		else if (line[curr] == 0 && line[i] == 0)
			i += j;
		else if (line[i] != line[curr] && line[i] != 0)
		{
			curr += j;
		}
		else
			i += j;
	}
	if (direction == 1)
		reverse(line, size);
	return (1);
}

/**
* reverse - reverses array
* @array: the array
* @size: length of it
* Return: 1 or 0 failure
*/
int reverse(int *array, size_t size)
{
	unsigned int i;
	int temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - 1 - i] = temp;
	}
	return (1);
}
