#include "binary_trees.h"

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
/**
 * height - measures the max height of a binary tree
 * @node: pointer to the root node of the tree to measure the height.
 * Return: return the max height
 **/
size_t height(const binary_tree_t *node)
{
	size_t l = 0, r = 0;

	if (node->left)
		l = height(node->left);
	if (node->right)
		r = height(node->right);
	return (1 + MAX(l, r));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: the calculated balance factor. if tree is NULL return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (height(tree->left));
	else if (tree->left == NULL && tree->right != NULL)
		return ((height(tree->right)) * (-1));
	else if (tree->left == NULL && tree->right == NULL)
		return (0);
	return ((height(tree->left)) - (height(tree->right)));
}
