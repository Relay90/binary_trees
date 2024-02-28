#include "binary_trees.h"

/**
 * bst_insert - Inserts nodes to create a Binary Search Tree (BST).
 * @tree: A pointer to a pointer to the root of the BST.
 * @value: The value to insert into the BST.
 * Return: A pointer to the newly inserted node or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				new = bst_insert(&temp->left, value);
			else
			{
			aux = binary_tree_node((binary_tree_t *)temp, value);
			new = temp->left = (bst_t *)aux;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new = bst_insert(&temp->right, value);
			else
			{
			aux = binary_tree_node((binary_tree_t *)temp, value);
			new = temp->right = (bst_t *)aux;
			}
		}
		else
			return (NULL);
	}

	return (new);
}
