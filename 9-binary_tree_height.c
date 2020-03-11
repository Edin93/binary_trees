#include "binary_trees.h"

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
/**
 * tree_max_height - measures the max height of a binary tree
 * @node: pointer to the root node of the tree to measure the height.
 * Return: return the max height
**/
size_t tree_max_height(const binary_tree_t *node)
{
	size_t l = 0, r = 0;

	if (node->left)
		l = tree_max_height(node->left);
	if (node->right)
		r = tree_max_height(node->right);
	return (1 + MAX(l, r));
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, return 0. otherwise, return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h = 0;

	if (tree == NULL)
		return (0);

	h = tree_max_height(tree);
	h--;
	return (h);
}
