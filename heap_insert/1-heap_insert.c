#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int tmp;
	heap_t *new;

	if (root == NULL)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	new->parent = _insert(*root, new);

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->parent->n;
		new->parent->n = new->n;
		new->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * _insert - inserts a value into a Binary Tree
 * @tree: pointer to the root node
 * @new: pointer to the new node
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *_insert(heap_t *tree, heap_t *new)
{
	size_t nb_nodes;
	heap_t *parent;

	if (tree == NULL)
		return (tree);
	nb_nodes = binary_tree_size(tree);
	parent = find_parent(tree, 0, (nb_nodes - 1) / 2);
	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	return (parent);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return:  measures the size of a binary tree
 */

size_t binary_tree_size(const heap_t *tree)
{
	size_t counter_l = 0;
	size_t counter_r = 0;

	if (tree == NULL)
		return (0);

	counter_l += binary_tree_size(tree->left);
	counter_r += binary_tree_size(tree->right);
	return (counter_l + counter_r + 1);
}

/**
 * find_parent - find the parent who don't have two children
 * @tree: pointer to the root node of the tree
 * @index: index of the node in the tree
 * @nb_nodes: number of nodes in the binary tree
 * Return: left child, right child or NULL if the parent have two children
 */

heap_t *find_parent(heap_t *tree, int index, int nb_nodes)
{
	heap_t *left_child, *right_child;

	if (index == nb_nodes)
		return (tree);
	if (index > nb_nodes)
		return (NULL);

	left_child = find_parent(tree->left, 2 * index + 1, nb_nodes);
	right_child = find_parent(tree->right, 2 * index + 2, nb_nodes);

	if (left_child)
		return (left_child);
	else if (right_child)
		return (right_child);
	else
		return (NULL);
}
