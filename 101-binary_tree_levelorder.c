#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through binary tree using levelorder traversal
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer fo a function a call for each node.
 * If tree or func is NULL, do nothing.
 * Return: nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *arr[1024];
	binary_tree_t * node;
	int i = 0, j = 0;

	if (tree == NULL || func == NULL)
		return;
	arr[i] = (binary_tree_t *)tree;
	j = i;
	while (arr[i])
	{
		node = arr[i];
		func(node->n);
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
}
