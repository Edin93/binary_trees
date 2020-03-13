#include "binary_trees.h"

/**
 * inorder - function that goes through a binary tree using
 * in-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @arr: array to add node elements to.
 * @i: index of current element to add to the array.
 * must be passed as a parameter to this function.
 **/
void inorder(binary_tree_t *tree, binary_tree_t *arr[], int *j)
{
        if (tree)
        {
                inorder(tree->left, arr, j);
		arr[*j] = tree;
		*j = *j + 1;
                inorder(tree->right, arr, j);
        }
}

/**
 * binary_tree_is_bst - check if a binary tree is a valid BST.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is BST, else 0. If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *node;
	binary_tree_t *arr[1024];
	int i;
	int *j;

	if (tree == NULL)
		return (0);
	for (i = 0; i < 1024; i++)
		arr[i] = NULL;
	i = 0;
	j = &i;
	node = (binary_tree_t *)tree;
	inorder(node, arr, j);
	for (i = 1; arr[i] != NULL; i++)
	{
		if (arr[i]->n <= arr[i - 1]->n)
		{
			return (0);
		}
	}
	return (1);
}
