#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, return 0. otherwise, return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int h = 0;
	const binary_tree_t *tmp;

	if (tree == NULL)
		return (0);
	tmp = tree;
	while (tmp)
	{
		if (tmp->right != NULL)
		{
			h += 1;
			tmp = tmp->right;
		}
		else if (tmp->left != NULL)
		{
			h += 1;
			tmp = tmp->left;
		}
		else
			return (h);
	}
	return (0);
}
