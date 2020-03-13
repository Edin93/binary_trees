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
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value
 **/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *search;

	if (root == NULL)
		return (NULL);
	search = find_value(root, value);
	if (search == NULL)
		return (NULL);
	if (search->left == NULL && search->right == NULL)
		free(search);
	else if (search->left == NULL && search->right != NULL)
	{
		if (search->parent->n > search->n)
			search->parent->left = search->right;
		else
			search->parent->right = search->right;
		free(search);
	}
	else if (search->left != NULL && search->right == NULL)
	{
		if (search->parent->n > search->n)
			search->parent->left = search->left;
		else
			search->parent->right = search->left;
		free(search);
	}
	else if (search->left != NULL && search->right != NULL)
	{
		search->right->left->left = search->left;
		search->right->left->right = search->right;
		root = search->right->left;
	}
	return (root);
}
