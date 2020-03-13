#include "binary_trees.h"
/**
 * array_to_bst - unction that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
**/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i, value;
	bst_t *root;

	if (array == NULL || size <= 0)
		return (NULL);
	root = NULL;
	for (i = 0; i < size; i++)
	{
		value = array[i];
		bst_insert(&root, value);
	}
	return (root);
}
