#include "regex.h"

/**
 * regex_match - checks if a pattern matches a string
 * @str: string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);

	/* If pattern is empty, return true if str is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if current characters match or pattern has '.' */
	int first_match = (*str != '\0' &&
		(*pattern == *str || *pattern == '.'));

	/* Handle '*' in pattern */
	if (*(pattern + 1) == '*')
	{
		/* Move past '*' (0 occur) OR match one and continue */
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		/* Regular match and advance both */
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
