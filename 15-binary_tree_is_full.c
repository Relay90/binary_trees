#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If a node has either no children or two children, it's full */
	if ((tree->left == NULL && tree->right == NULL) ||
	    (tree->left && tree->right))
	{
		/* Recursively check for left and right subtrees */
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	}

	return (0);
}
