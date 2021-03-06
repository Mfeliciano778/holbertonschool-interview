#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * heap_make - restructure to a heap tree
 * @node: moving node
 * Return: void
 */
void heap_make(heap_t *node)
{
		if (node->left && node->right && node->left->n > node->n &&
		node->right->n > node->n)
		{
			if (node->right->n > node->left->n)
			{
				swap(node, node->right);
				heap_make(node->right);
			} else
			{
				swap(node, node->left);
				heap_make(node->left);
			}
		}
		else if (node->right && node->right->n > node->n)
		{
			swap(node, node->right);
			heap_make(node->right);
		}
		else if (node->left && node->left->n > node->n)
		{
			swap(node, node->left);
			heap_make(node->left);
		}
}

/**
 * swap - swap parent and child node
 * @parent: parent node
 * @child: child node
 * Return: void
 */
void swap(heap_t *parent, heap_t *child)
{
	int temp = parent->n;

	parent->n = child->n;
	child->n = temp;
}

/**
 * get_last - Will return the last node in heap tree
 * @root: root node
 * @head: original root node
 * @height: the current height
 * @max_height: the max height of heap tree
 * Return: 0 on failure, else the value stored in the root node
 */
heap_t *get_last(heap_t *root, heap_t *head, int height, int max_height)
{
	heap_t *left, *right;

	if (height == max_height)
		/* last node is root */
		return (root);
	left = get_last(root->left, head, height + 1, max_height);
	right = get_last(root->right, head, height + 1, max_height);
	if (right)
		return (right);
	if (left)
		return (left);
	return (NULL);
}

/**
 * get_height - gets the height of given heap tree
 * @root: root node
 * Return: 0 on failure, else the value stored in the root node
 */
int get_height(heap_t *root)
{
	if (root)
		return (get_height(root->left) + 1);
	return (0);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: root node
 * Return: 0 on failure, else the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int extract;

	if (!*root)
		return (0);
	last_node = get_last(*root, *root, 1, get_height(*root));
	extract = root[0]->n;

	root[0]->n = last_node->n;
	if (!root[0]->left && !root[0]->right)
	{
		free(*root);
		*root = NULL;
		return (extract);
	}
	else if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	free(last_node);
	heap_make(*root);
	return (extract);
}
