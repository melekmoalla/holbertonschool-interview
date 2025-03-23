#include "holberton.h"

/**
 * wildcmp - compares two strings, considering '*' wildcard in s2.
 * @s1: first string
 * @s2: second string, may contain '*'
 * Return: 1 if considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{

    if (*s1 == '\0' && *s2 == '\0')
        return (1);


    if (*s2 == '*')
    {

        while (*(s2 + 1) == '*')
            s2++;

        if (wildcmp(s1, s2 + 1))
            return (1);
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return (1);
    }

    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));


    return (0);
}
