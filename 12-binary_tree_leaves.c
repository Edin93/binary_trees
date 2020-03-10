#include "binary_trees.h"

/**
 * count_leaves - counts the number of leaves of a binary node.
 * @node: binary tree node to count its leaves.
 * @l: number of leaves of the node to count.
 * Return: nothing.
 */
void count_leaves(const binary_tree_t *node, size_t *l)
{
	if (node->right == NULL && node->left == NULL)
	{
		*l += 1;
	}
	else if (node->right != NULL)
		count_leaves(node->right, l);
	else if (node->left != NULL)
		count_leaves(node->left, l);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of leaves.
 * Return: number of leaves. if tree is NULL return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l = 0;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if (tree->right)
		count_leaves(tree->right, &l);
	if (tree->left)
		count_leaves(tree->left, &l);
	return (l);
}
