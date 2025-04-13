#include <stdlib.h>
#include <string.h>
#include "substring.h"

typedef struct word_entry
{
    char *word;
    int count;
} word_entry;

static int get_word_index(word_entry *entries, int size, const char *word)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(entries[i].word, word) == 0)
            return i;
    }
    return -1;
}

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int len_s = strlen(s);
    int word_len = strlen(words[0]);
    int total_len = word_len * nb_words;
    int *indices = malloc(sizeof(int) * len_s);
    int count = 0;

    if (!indices || len_s < total_len)
    {
        if (indices)
            free(indices);
        *n = 0;
        return NULL;
    }

    word_entry *ref = malloc(sizeof(word_entry) * nb_words);
    if (!ref)
    {
        free(indices);
        *n = 0;
        return NULL;
    }

    for (int i = 0; i < nb_words; i++)
    {
        int idx = get_word_index(ref, i, words[i]);
        if (idx == -1)
        {
            ref[i].word = strdup(words[i]);
            ref[i].count = 1;
        }
        else
        {
            ref[idx].count++;
        }
    }

    for (int i = 0; i <= len_s - total_len; i++)
    {
        word_entry *seen = malloc(sizeof(word_entry) * nb_words);
        int matched = 1;

        for (int k = 0; k < nb_words; k++)
        {
            seen[k].word = ref[k].word;
            seen[k].count = 0;
        }

        for (int j = 0; j < nb_words; j++)
        {
            int start = i + j * word_len;
            char *sub = strndup(s + start, word_len);
            int idx = get_word_index(ref, nb_words, sub);

            free(sub);

            if (idx == -1)
            {
                matched = 0;
                break;
            }

            seen[idx].count++;
            if (seen[idx].count > ref[idx].count)
            {
                matched = 0;
                break;
            }
        }

        if (matched)
            indices[count++] = i;

        free(seen);
    }

    for (int i = 0; i < nb_words; i++)
        free(ref[i].word);
    free(ref);

    *n = count;
    return (count > 0) ? indices : NULL;
}
