#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>

typedef struct word_entry
{
	char *word;
	int count;
} word_entry;


int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
