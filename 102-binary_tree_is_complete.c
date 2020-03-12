#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if complete, else 0. If tree is NULL return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i = 0, j = 0, has_left_only = 0;
	binary_tree_t *arr[1024], *node;

	if (tree == NULL)
		return (0);
	for (i = 0; i < 1024; i++)
		arr[i] = NULL;
	i = 0;
	arr[i] = (binary_tree_t *)tree;
	j = i;
	while (arr[i] != NULL)
	{
		node = arr[i];
		if (node->left != NULL && has_left_only == 1)
			return (0);
		if (node->left == NULL && node->right != NULL)
			return (0);
		if (node->left && !node->right && has_left_only == 0)
			has_left_only = 1;
		if (node->left != NULL)
		{
			j++;
			arr[j] = node->left;
		}
		if (node->right != NULL)
		{
			j++;
			arr[j] = node->right;
		}
		i++;
	}
	return (1);
}
