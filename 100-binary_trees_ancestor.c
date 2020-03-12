#include "binary_trees.h"

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

	if (first == NULL || second == NULL)
		return (NULL);
	while (first->parent != NULL)
	{
		while (second->parent != NULL)
		{
			if (first->parent->n == second->parent->n ||
					first->n == second->parent->n)
			{
				if (second->parent->n < first->n)
					return (second->parent);
				else
					return (first->left->parent);
			}
			second = second->parent;
		}

		first = first->parent;
	}
	return (NULL);
}
