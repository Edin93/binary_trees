#include "binary_trees.h"
/**
 * make_insertion - function that inserts a value in a Binary Search Tree
 * @root: first node of the tree
 * @value: value to insert
 * Return: New inserted node, if value is already in the tree returns NULL
**/
bst_t *make_insertion(bst_t *root, int value)
{
	bst_t *tree = root;

	if (tree)
	{

		if (value == tree->n)
			return (NULL);
		else if (value < tree->n)
		{
			if (tree->left == NULL)
			{
				tree->left = binary_tree_node(tree, value);
				return (tree->left);
			}
			else
				return (make_insertion(tree->left, value));
		}
		else if (value > tree->n)
		{
			if (tree->right == NULL)
			{
				tree->right = binary_tree_node(tree, value);
				return (tree->right);
			}
			else
				return (make_insertion(tree->right, value));
		}
		make_insertion(tree->left, value);
		make_insertion(tree->right, value);
	}
	return (NULL);
}
/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
**/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *new;

	if (!*tree)
	{
		new = binary_tree_node(*tree, value);
		*tree = new;
		return (new);
	}

	node = *tree;
	if (value < node->n && node->left == NULL
			&& node->parent == NULL)
	{
		new = binary_tree_node(node, value);
		node->left = new;
		return (new);
	}
	else if (value > node->n && node->right == NULL
			&& node->parent == NULL)
	{
		new = binary_tree_node(node, value);
		node->right = new;
		return (new);
	}

	node = make_insertion(*tree, value);
	if (node == NULL)
		return (NULL);
	return (node);
}
