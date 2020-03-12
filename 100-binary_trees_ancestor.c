#include "binary_trees.h"
/**
 * depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth.
 * Return: the depth calculated. if tree is NULL return 0.
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent)
	{
		d += 1;
		tree = tree->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: pointer to the lowest common ancestor otherwise NULL
**/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		ancestor = (binary_tree_t *)first;
	while (first != second)
	{
		if (first->parent == second->parent)
		{
			return (first->parent);
		}
		else if (depth(first) == depth(second) && first != second)
		{
			if (first->parent != NULL && second->parent != NULL)
			{
				first = first->parent;
				second = second->parent;
				ancestor = first->parent;
			}
		}
		else if (depth(first) > depth(second))
		{
			if (first->parent == second)
				return (first->parent);
			first = first->parent;
			ancestor = first->parent;
		}
		else if (depth(first) < depth(second))
		{
			if (second->parent == first)
				return (second->parent);
			second = second->parent;
			ancestor = second->parent;
		}
	}
	return (ancestor);
}
