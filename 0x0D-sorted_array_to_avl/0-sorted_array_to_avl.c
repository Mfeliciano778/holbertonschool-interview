#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Takes an array an forms an AVL tree from it
 *
 * @array: The array to be organized
 * @size: Size of the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    unsigned int mid;
    avl_t *new_node;

    if (!array || size == 0)
        return (NULL);
    mid = size / 2;

    new_node = new_Node(NULL, array[mid]);
    if (!new_node)
        return (NULL);

    new_node->left = sorted_array_to_avl(array, mid);
    if (new_node->left)
        new_node->left->parent = new_node;
    else if (mid > 0)
    {
        return (NULL);
    }
    new_node->right = sorted_array_to_avl(&array[mid + 1], size / 2);
    if (new_node->right)
        new_node->right->parent = new_node;
    else if (size / 2 > 0)
    {
        return (NULL);
    }
    return (new_node);
}
/**
 * sorted_array_to_avl - Takes an array an forms an AVL tree from it
 *
 * @array: The array to be organized
 * @size: Size of the array
 */
binary_tree_t *new_Node(binary_tree_t *parent, int n)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->n = n;

    return (new_node);
}