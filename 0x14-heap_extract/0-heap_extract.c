#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of the heap
 * @root: The root of the heap
 *
 * Return: Either the root node's value or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int val;

	if (*root == NULL || (*root)->n == NULL)
		return (0);

	val = (*root)->n;

	return (val);
}
