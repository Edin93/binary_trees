#include "binary_trees.h"

/**
 * height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, return 0. otherwise, return the height.
 */
int height(const binary_tree_t *tree)
{
	int h = 0;
	const binary_tree_t *tmp;

	if (tree == NULL)
		return (0);
	if (tree != NULL)
		h += 1;
	tmp = tree;
	while (tmp)
	{
		if (tmp->left != NULL)
		{
			h += 1;
			tmp = tmp->left;
		}
		else if (tmp->right != NULL)
		{
			h += 1;
			tmp = tmp->right;
		}
		else
			return (h);
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: the calculated balance factor. if tree is NULL return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int b = 0;

	if (tree == NULL)
		return (0);
	b = height(tree->left) - height(tree->right);
	return (b);
}
