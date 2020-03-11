#include "binary_trees.h"

/**
 * binary_tree_sibling - It finds the sibling of a node.
 * @node: a pointer to the node to find the sibling.
 * Return: a pointer to the sibling node.
 * If node is NULL or the parent is NULL, return NULL.
 * If node has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parentNode;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parentNode = node->parent;
	if (parentNode->right != NULL && parentNode->right == node)
	{
		if (parentNode->left != NULL)
			return (parentNode->left);
	}
	if (parentNode->left != NULL && parentNode->left == node)
	{
		if (parentNode->right != NULL)
			return (parentNode->right);
	}
	return (NULL);
}
