#include "binary_trees.h"
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

/**
 * _pow_recursion - return x to power of y
 * @x: base.
 * @y: power.
 * Return: x ** y.
 */
int _pow_recursion(int x, int y)
{
	if (y > 0)
	{
		return (_pow_recursion(x, y - 1) * x);
	}
	else if (y < 0)
	{
		return (-1);
	}
	else
		return (1);
}

/**
 * calc_nodes - calculate the number of nodes in a tree.
 * @tree: pointer to root of the tree to calculate.
 * @nodes: pointer to the variable representing the number of nodes.
 * Return: nothing.
 */
void calc_nodes(const binary_tree_t *tree, int *nodes)
{
	if (tree != NULL)
		*nodes += 1;
	if (tree->left != NULL)
		calc_nodes(tree->left, nodes);
	if (tree->right != NULL)
		calc_nodes(tree->right, nodes);
}

/**
 * calc_height - measures the max height of a binary tree
 * @node: pointer to the root node of the tree to measure the height.
 * Return: return the max height
 **/
int calc_height(const binary_tree_t *node)
{
	size_t l = 0, r = 0;

	if (node->left)
		l = calc_height(node->left);
	if (node->right)
		r = calc_height(node->right);
	return (1 + MAX(l, r));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is perfect, 0 otherwise. If tree is NULL return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;
	int nodes = 0;
	int perfect_number;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	height = calc_height(tree);
	height--;
	calc_nodes(tree, &nodes);
	perfect_number = (_pow_recursion(2, (height + 1)) - 1);

	if (perfect_number == nodes)
		return (1);
	return (0);
}
