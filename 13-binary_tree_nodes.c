#include "binary_trees.h"

/**
 * count_nodes - count nodes of a binary tree node.
 * @node: pointer to the node to count.
 * @n: pointer to the number of the nodes to update.
 * Return: nothing.
 */
void count_nodes(const binary_tree_t *node, size_t *n)
{
	if (node != NULL && (node->right != NULL || node->left != NULL))
	{
		*n += 1;
		count_nodes(node->right, n);
		count_nodes(node->left, n);
	}
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root node of the tree to count its nodes.
 * Return: number of nodes. if tree is NULL return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
	{
		n += 1;
		count_nodes(tree->left, &n);
		count_nodes(tree->right, &n);
	}
	return (n);
}
