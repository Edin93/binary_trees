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

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}
