#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the start of the array
 * @left: Start index of the subarray
 * @right: End index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */


int advanced_binary(int *array, size_t size, int value)
{
    for (size_t i=0; i<size; i++)
    {
        if(array[i] == value){
            return i;
        }
    }
    return -1;
}

