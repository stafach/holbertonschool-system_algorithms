#include "rb_trees.h"

/**
 * check_node - Recursively checks the Red-Black properties of a subtree
 * @node: Pointer to the root node of the subtree to check
 * @min: Node holding the lower bound (exclusive), or NULL if none
 * @max: Node holding the upper bound (exclusive), or NULL if none
 *
 * Return: Black height of the subtree, or -1 if a property is violated
 */
static int check_node(const rb_tree_t *node, const rb_tree_t *min,
		      const rb_tree_t *max)
{
	int left_height, right_height;

	if (node == NULL)
		return (1);

	if (node->color != RED && node->color != BLACK)
		return (-1);

	if ((min != NULL && node->n <= min->n) ||
	    (max != NULL && node->n >= max->n))
		return (-1);

	if (node->color == RED &&
	    ((node->left != NULL && node->left->color == RED) ||
	     (node->right != NULL && node->right->color == RED)))
		return (-1);

	left_height = check_node(node->left, min, node);
	if (left_height == -1)
		return (-1);
	right_height = check_node(node->right, node, max);
	if (right_height == -1 || left_height != right_height)
		return (-1);

	return (left_height + (node->color == BLACK ? 1 : 0));
}

/**
 * rb_tree_is_valid - Checks if a binary tree is a valid Red-Black tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Red-Black tree, 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL || tree->color != BLACK)
		return (0);

	return (check_node(tree, NULL, NULL) != -1);
}
