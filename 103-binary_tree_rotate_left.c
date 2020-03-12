#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		pivot = tree->right;
		if (pivot->left)
		{
			tmp = pivot->left;
			tmp->parent = tree;
			tree->right = tmp;
		}
		else
		{
			tree->right = NULL;
		}
		pivot->left = tree;
		tree->parent = pivot;
	}
	else
		pivot = tree;
	return (pivot);
}
