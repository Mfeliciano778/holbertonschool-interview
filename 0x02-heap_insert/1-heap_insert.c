#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a new node into a Max Binary Heap
 *
 * @root: Pointer to the root of the binary tree
 * @value: value we are inserting into the binary tree
 *
 * Return: return a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node;
	/**
	 * // Check if the root and *root is empty and if so create new node as
	 * // head node
	*/
	if (!(*root))
	{
		new_node = binary_tree_node(NULL, value);
		(*root) = new_node;
		return (new_node);
	}
	else
	{
		if ((*root)->n < value)
		{
			new_node = binary_tree_node((*root), value);
			if (!(*root)->left)
				(*root)->left = new_node;
			else
				(*root)->right = new_node;

			swap((*root), new_node);
		}
		else
		{
			new_node = binary_tree_node((*root), value);
			if (!(*root)->left)
				(*root)->left = new_node;
			else
				(*root)->right = new_node;
		}
	}
	return (new_node);
}
/**
 * swap - swaps the pointers that are given
 *
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 *
 * Return: Always nothing
 */
void swap(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}
