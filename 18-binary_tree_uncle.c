#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: pointer to the node to find the uncle.
 * Return: a pointer to the uncle node.
 * If node is NULL, return NULL.
 * If node has no uncle, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL)
		return (NULL);
	parent = node->parent;
	if (parent == NULL)
		return (NULL);
	grandparent = parent->parent;
	if (grandparent == NULL)
		return (NULL);
	if (grandparent->right != NULL && grandparent->right == parent)
	{
		if (grandparent->left != NULL)
			return (grandparent->left);
	}
	if (grandparent->left != NULL && grandparent->left == parent)
	{
		if (grandparent->right != NULL)
			return (grandparent->right);
	}
	return (NULL);
}
