#include "binary_trees.h"

/**
 * count - counts the size of a binary node.
 * @node: binary tree node to count.
 * @s: size of the tree to count.
 * Return: nothing.
 */
void count(const binary_tree_t *node, size_t *s)
{
	if (node != NULL)
	{
		*s += 1;
		count(node->right, s);
		count(node->left, s);
	}
}

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure its size.
 * Return: calculated size. if tree is NULL return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree == NULL)
		return (0);

	if (tree)
	{
		s += 1;
		count(tree->right, &s);
		count(tree->left, &s);
	}
	return (s);
}
