#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_node - insert a binary tree
 * @root: is a double pointer to the root node of the Heap
 * @value:  is the value to store in the node to be inserted
 * Return:  pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current, **queue;
	size_t front = 0, rear = 0;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);
	queue[rear++] = *root;
	while (1)
	{current = queue[front++];
		if (current->left == NULL)
		{current->left = new_node;
			new_node->parent = current;
			break;
		}
		else
			queue[rear++] = current->left;
		if (current->right == NULL)
		{current->right = new_node;
			new_node->parent = current;
			break;
		}
		else
			queue[rear++] = current->right; }
	while (new_node->parent && new_node->n > new_node->parent->n)
	{int tmp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}
	free(queue);
	return (new_node);
}
