#include <stdlib.h>
#include "rb_trees.h"
 
/**
 * rb_tree_node - Creates a Red-Black tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 * @color: Color of the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node;
 
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
 
	node->n = value;
	node->color = color;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
 
	return (node);
}
 