#include "mul.h"


/**
 * main - multiples two positive numbers
 * @argc: the number of args
 * @argv: array of args
 *
 * Return: The multiplication result, else "Error" and exit code 98
 */
int main(int argc, char *argv[])
{
	int length1, length2, *word1, *word2, *result;

	if (argc != 3)
		easy_exit();
	length1 = get_length(argv[1]);
	length2 = get_length(argv[2]);
	word1 = easy_convert(length1, argv[1]);
	word2 = easy_convert(length2, argv[2]);
	result = easy_multiply(word1, word2, length1, length2);

	print_arr(result, (length1 + length2) * 1.5);
	free(result);
	free(word1);
	free(word2);
	exit(0);
	return (0);
}
/**
 * print_arr - prints the result array
 * @array: the result array
 * @size: the size of the array
 *
 * Return: Always nothing
 */
void print_arr(int *array, int size)
{
	int index, z = 0;

	for (index = 0; index < size; index++)
	{
		if (array[index] != 0)
		{
			z = 1;
			break;
		}
	}
	for (; index < size; index++)
	{
		_putchar(array[index] + '0');
	}
	if (z == 0)
		_putchar('0');
	_putchar('\n');
}
/**
 * easy_multiply - multiplies two int arrays
 * @word1: the first array
 * @word2: the second array
 * @len1: the length of the first array
 * @len2: the length of the second array
 *
 * Return: the result array of the two int arrays
 */
int *easy_multiply(int *word1, int *word2, int len1, int len2)
{
	int *res_array, length, index, jindex = 0;

	length = (len1 + len2) * 1.5;
	res_array = buffer(len1, len2);

	for (index = len2 - 1; index >= 0; index--)
	{
		res_array = not_easy_multiply(word1, len1, word2[index],
									  res_array, length - jindex);
		jindex++;
	}
	return (res_array);
}
/**
 * buffer - creates buffer array
 * @length1: the first size
 * @length2: the second size
 *
 * Return: New char array
 */
int *buffer(int length1, int length2)
{
	int length, index, *buffer;

	length = (length1 + length2) * 1.5;
	buffer = malloc(length * sizeof(int));
	if (!buffer)
		easy_exit();

	for (index = 0; index < length; index++)
		buffer[index] = 0;
	return (buffer);
}
/**
 * check_tens - checks for tens and carries them over
 * @buff: the array
 * @length: the length of the array
 *
 * Return: Always nothing
 */
void check_tens(int *buff, int length)
{
	int index;

	for (index = length - 1; index > 0; index--)
	{
		if (buff[index] > 9)
		{
			buff[index - 1] += buff[index] / 10;
			buff[index] = buff[index] % 10;
		}
	}
}
/**
 * not_easy_multiply - multiplies array by one number
 * @w1: the array
 * @l1: the length of the array
 * @n: the number
 * @buff: where we put the result
 * @size: size of the buffer
 *
 * Return: the buffer that was modified by the product
 */
int *not_easy_multiply(int *w1, int l1, int n, int *buff, int size)
{
	int index, jindex;

	jindex = size - 1;
	for (index = l1 - 1; index >= 0; index--)
	{
		buff[jindex] += w1[index] * n;
		jindex--;
	}
	check_tens(buff, size);
	return (buff);
}
/**
 * easy_convert - converts char array to int array
 * @word: the array
 * @length: the length of the array
 *
 * Return: New char array
 */
int *easy_convert(int length, char *word)
{
	int *new_array, count;

	new_array = malloc(length * sizeof(int));
	if (!new_array)
		easy_exit();

	count = length - 1;
	while (count >= 0)
	{
		if (word[count] < '0' || word[count] > '9')
		{
			free(new_array);
			easy_exit();
		} else
		{
			new_array[count] = word[count] - 48;
		}
		count--;
	}
	return (new_array);
}
/**
 * get_length - gets length of an array
 * @word: the array
 *
 * Return: The length of the word
 */
int get_length(char *word)
{
	int length;

	for (length = 0; word[length] != 0; length++)
		;
	return (length);
}
/**
 * easy_exit - exits program with code 98
 *
 * Return: Always nothing
 */
void easy_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
