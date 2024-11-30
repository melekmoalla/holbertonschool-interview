#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    avl_t *root = malloc(sizeof(avl_t));
    if (!root)
        return NULL;

    size_t mid = size / 2 - 1;
    root->n = array[mid];
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;

    avl_t *nodes[size];
    size_t left_start[size], left_end[size], right_start[size], right_end[size];
    size_t top = 0;

    nodes[top] = root;
    left_start[top] = 0;
    left_end[top] = mid - 1;
    right_start[top] = mid + 1;
    right_end[top++] = size - 1;

    while (top > 0)
    {

        avl_t *current = nodes[--top];
        size_t left_s = left_start[top], left_e = left_end[top];
        size_t right_s = right_start[top], right_e = right_end[top];

        if (left_s <= left_e)
        {
            size_t mid_left = (left_s + left_e) / 2;

            if (array[mid_left] == 0) { // Assuming -1 is your sentinel value
                break;
            }
            avl_t *left_node = malloc(sizeof(avl_t));
            if (!left_node)
                return NULL;

            left_node->n = array[mid_left];
            left_node->parent = current;
            left_node->left = NULL;
            left_node->right = NULL;
            current->left = left_node;

            nodes[top] = left_node;
            left_start[top] = left_s;
            left_end[top] = mid_left - 1;
            right_start[top] = mid_left + 1;
            right_end[top++] = left_e;
        }
        if (right_s <= right_e)
        {
            size_t mid_right = (right_s + right_e) / 2;
            if (array[mid_right] == 0) { // Assuming -1 is your sentinel value
                break;
            }
            avl_t *right_node = malloc(sizeof(avl_t));
            if (!right_node)
                return NULL;

            right_node->n = array[mid_right];
            right_node->parent = current;
            right_node->left = NULL;
            right_node->right = NULL;
            current->right = right_node;

            nodes[top] = right_node;
            left_start[top] = right_s;
            left_end[top] = mid_right - 1;
            right_start[top] = mid_right + 1;
            right_end[top++] = right_e;
        }
        binary_tree_print(root);
    }

    return root;
}
