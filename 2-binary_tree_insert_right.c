#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node at the right-child of another node
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 * Return: pointer to the new node. NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *btn = malloc(sizeof(binary_tree_t));

	if (btn == NULL || parent == NULL)
		return (NULL);
	btn->parent = parent;
	btn->n = value;
	btn->right = NULL;
	btn->left = NULL;
	if (parent->right != NULL)
	{
		parent->right->parent = btn;
		btn->right = parent->right;
	}
	parent->right = btn;
	return (btn);
}
