#include "binary_trees.h"

#define LOW(A,B) ((A) < (B)) ? (A) : (B);
/**
 * binary_trees_ancestor - function that finds the lowest common ancestor 
 * of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
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
				return second->parent;

			second = second->parent;
		}

		first = first->parent;
	}

	return (NULL);
}
