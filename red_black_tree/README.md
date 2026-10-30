# Red-Black Trees

Implementation of Red-Black trees in C.

A Red-Black tree is a self-balancing binary search tree. Each node carries a
color (red or black), and the tree keeps these properties:

1. Every node is either red or black.
2. The root is black.
3. Every leaf (NULL) is black.
4. A red node never has a red child.
5. Every path from a node to its descendant leaves contains the same number
   of black nodes.

These rules keep the height below `2 * log2(n + 1)`, so search, insertion and
deletion run in `O(log n)`.

## Files

| File | Description |
| --- | --- |
| `rb_trees.h` | Data structures and prototypes |
| `0-rb_tree_node.c` | `rb_tree_node`: creates a Red-Black tree node |
| `1-rb_tree_is_valid.c` | `rb_tree_is_valid`: checks if a binary tree is a valid Red-Black tree |

## Compilation

```
gcc -Wall -Werror -Wextra -pedantic *.c -o rb_trees
```