#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
**/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent != NULL && tree && tree->left && tree->right)
		return (1);
	return (0);
}
