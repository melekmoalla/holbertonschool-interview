#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "palindrome.h"

/**
 * is_palindrome - given unsigned integer is a palindrome.
 *
 * @n: Arguments counter
 *
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{

    int i, length;
    char name[500];

    sprintf(name, "%lu", n);
    length = strlen(name);


    for (i = 0; i <= length / 2; i++)
    {
        if (name[i] != name[length - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
