#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: Node's parent pointer
 * @value: Value to insert
 * Return: pointer to new node or NULL on failure
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value){
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return NULL;

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	if (parent == NULL)
		new->parent = NULL;
	else
	{
		new->parent = parent;
		if (value < parent->n)
			parent->left = new;
		else
			parent->right = new;
	}
	return new;
}
