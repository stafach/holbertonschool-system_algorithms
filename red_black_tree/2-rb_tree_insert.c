#include "rb_trees.h"

/**
 * rotate_left - Performs a left rotation around a node
 * @tree: Double pointer to the root node of the tree
 * @x: Node to rotate around (its right child moves up)
 */
static void rotate_left(rb_tree_t **tree, rb_tree_t *x)
{
	rb_tree_t *y = x->right;

	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;
	if (x->parent == NULL)
		*tree = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

/**
 * rotate_right - Performs a right rotation around a node
 * @tree: Double pointer to the root node of the tree
 * @y: Node to rotate around (its left child moves up)
 */
static void rotate_right(rb_tree_t **tree, rb_tree_t *y)
{
	rb_tree_t *x = y->left;

	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;
	if (y->parent == NULL)
		*tree = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else
		y->parent->left = x;

	x->right = y;
	y->parent = x;
}

/**
 * fix_rotation - Fixes a red-red conflict when the uncle is black
 * @tree: Double pointer to the root node of the tree
 * @node: Red node whose parent is also red
 *
 * Return: Pointer to the node from which to continue the fix
 */
static rb_tree_t *fix_rotation(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *grandparent = node->parent->parent;

	if (node->parent == grandparent->left)
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			rotate_left(tree, node);
		}
		node->parent->color = BLACK;
		grandparent->color = RED;
		rotate_right(tree, grandparent);
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			rotate_right(tree, node);
		}
		node->parent->color = BLACK;
		grandparent->color = RED;
		rotate_left(tree, grandparent);
	}
	return (node);
}

/**
 * fix_insert - Restores the Red-Black properties after an insertion
 * @tree: Double pointer to the root node of the tree
 * @node: Newly inserted (red) node
 */
static void fix_insert(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *grandparent, *uncle;

	while (node->parent != NULL && node->parent->color == RED)
	{
		grandparent = node->parent->parent;
		if (node->parent == grandparent->left)
			uncle = grandparent->right;
		else
			uncle = grandparent->left;

		if (uncle != NULL && uncle->color == RED)
		{
			node->parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			node = grandparent;
		}
		else
			node = fix_rotation(tree, node);
	}
	(*tree)->color = BLACK;
}

/**
 * rb_tree_insert - Inserts a value in a Red-Black tree
 * @tree: Double pointer to the root node of the tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *parent = NULL, *current, *node;

	if (tree == NULL)
		return (NULL);

	current = *tree;
	while (current != NULL)
	{
		if (value == current->n)
			return (NULL);
		parent = current;
		current = value < current->n ? current->left : current->right;
	}

	node = rb_tree_node(parent, value, RED);
	if (node == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = node;
	else if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	fix_insert(tree, node);
	return (node);
}
