#include "search_algos.h"

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

