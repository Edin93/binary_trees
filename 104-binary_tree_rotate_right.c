#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of th etree to rotate.
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		pivot = tree->left;
		if (pivot->right)
		{
			tmp = pivot->right;
			tmp->parent = tree;
			tree->left = tmp;
		}
		else
		{
			tree->left = NULL;
		}
		pivot->right = tree;
		tree->parent = pivot;
	}
	else
		pivot = tree;
	return (pivot);
}
