#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_by_index - Retrieves a node using level-order traversal index.
 * @root: Pointer to the root node.
 * @index: Index of the node to retrieve.
 * Return: Pointer to the node at the given index, or NULL if not found.
 */
binary_tree_t *get_node_by_index(binary_tree_t *root, size_t index)
{
    if (!root || index == 0)
        return (root);

    size_t left_size = binary_tree_size(root->left);
    if (index <= left_size)
        return (get_node_by_index(root->left, index - 1));
    return (get_node_by_index(root->right, index - left_size - 1));
}

/**
 * heapify_down - Restores the Max Heap property by sifting down a node.
 * @node: Pointer to the node to sift down.
 */
/**
 * heapify_down - Restores the Max Heap property by sifting down a node.
 * @node: Pointer to the node to sift down.
 */
void heapify_down(heap_t *node)
{
    if (!node)
        return;

    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;

        heapify_down(largest);
    }
}


/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    if (!root || !(*root))
        return (0);

    int root_value = (*root)->n;
    size_t size = binary_tree_size(*root);
    if (size == 1)
    {
        free(*root);
        *root = NULL;
        return (root_value);
    }

    heap_t *last_node = get_node_by_index(*root, size - 1);
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    (*root)->n = last_node->n;
    free(last_node);

    heapify_down(*root);
    return (root_value);
}
