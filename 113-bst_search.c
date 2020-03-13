#include "binary_trees.h"
/**
 * find_value - Find value in a BST
 * @tree: Binary Search Tree
 * @value: Value to search
 * Return: Node of the finded value, otherwise NULL if nothing is found
**/
bst_t *find_value(bst_t *tree, int value)
{
	if (tree)
	{
		if (value == tree->n)
			return (tree);
		if (value < tree->n)
			return (find_value(tree->left, value));
		else if (value > tree->n)
			return (find_value(tree->right, value));
	}
	return (NULL);
}
/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: NULL if tree is NULL or if nothing is found.
**/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	return (find_value((bst_t *)tree, value));
}
