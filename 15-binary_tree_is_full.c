#include "binary_trees.h"

/**
 * check_is_full - check if a binary tree is full or not.
 * @node: root of the tree to check.
 * @r: the result to return by the other function. it must be set to 0 if
 * tree isn't full. otherwise remain at 1.
 * Return: nothing.
 */
void check_is_full(const binary_tree_t *node, int *r)
{
	if (node->left != NULL && node->right != NULL)
	{
		check_is_full(node->left, r);
		check_is_full(node->right, r);
	}
	else if (node->left != NULL && node->right == NULL)
	{
		*r = 0;
		return;
	}
	else if (node->left == NULL && node->right != NULL)
	{
		*r = 0;
		return;
	}
	else if (node->left == NULL && node->right == NULL)
		return;
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
**/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int r = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		check_is_full(tree->left, &r);
		check_is_full(tree->right, &r);
	}
	else if (tree->left != NULL && tree->right == NULL)
	{
		r = 0;
		return (r);
	}
	else if (tree->left == NULL && tree->right != NULL)
	{
		r = 0;
		return (r);
	}
	return (r);
}
