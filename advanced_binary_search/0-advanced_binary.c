#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the start of the array
 * @left: Start index of the subarray
 * @right: End index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper function
 * @array: Pointer to the array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of the value, or -1
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    if (left > right)
        return (-1);

    print_array(array, left, right);

    size_t mid = left + (right - left) / 2;

    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);

    if (array[mid] >= value)
        return advanced_binary_recursive(array, left, mid, value);

    return advanced_binary_recursive(array, mid + 1, right, value);
}

/**
 * advanced_binary - Advanced binary search
 * @array: Pointer to the array
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: Index of the value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return advanced_binary_recursive(array, 0, size - 1, value);
}
