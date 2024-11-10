#include "slide_line.h"
#include <stddef.h>
#include <stdio.h> // Include this header for printf

/**
 * slide_line - Slides and merges an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, 0 on failure.
 */

int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;
    if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; i > 0; i--) {
            if (line[i] == 0) {
                for (j = i; j > 0; j--) {
                    line[j] = line[j - 1];
                }
                line[0] = 0;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] == line[i - 1])
            {
                line[i] += line[i - 1];
                line[i - 1] = 0;
            }
        }
                for (i = size - 1; i > 0; i--) {
            if (line[i] == 0) {
                for (j = i; j > 0; j--) {
                    line[j] = line[j - 1];
                }
                line[0] = 0;
            }
        }
    }
    else if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == 0)
            {
                for (j = i; j < size - 1; j++)
                {
                    line[j] = line[j + 1];
                }
                line[size - 1] = 0;
            }
        }
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == line[i + 1] )
            {
                line[i] +=  line[i + 1];
                line[i + 1] = 0;
            }
        }

        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == 0)
            {
                for (j = i; j < size - 1; j++)
                {
                    line[j] = line[j + 1];
                }
                line[size - 1] = 0;
            }
        }
    }

    return (1);
}
