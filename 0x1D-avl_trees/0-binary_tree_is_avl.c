#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an avl tree
 * @tree: Pointer to root node
 * Return: 1 if tree is an avl tree, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (!is_tree_bst(tree->left, tree->n, 0))
		return (0);

	if (!is_tree_bst(tree->right, tree->n, 1))
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (abs(left - right) > 1)
		return (0);

	if (tree->left && tree->right)
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
	if (tree->left)
		return (binary_tree_is_avl(tree->left));
	return (binary_tree_is_avl(tree->right));
}
/**
 * is_tree_bst - Checks if a binary tree is a binary search tree
 * @tree: Pointer to root of the tree
 * Return: 1 if a bst, 0 if not
 */
int is_tree_bst(const binary_tree_t *tree, int n, int side)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (side == 0 && tree->n > n)
		return (0);

	if (side == 1 && tree->n < n)
		return (0);

	return (is_tree_bst(tree->left, n, side) && is_tree_bst(tree->right, n, side));
}
/**
 * tree_height - Height of a binary tree
 * @tree: Pointer to root of the tree
 * Return: Height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (1 + (left > right ? left : right));
}
