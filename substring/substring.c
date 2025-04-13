#include <stdlib.h>
#include <string.h>
#include "substring.h"

typedef struct word_entry
{
    char *word;
    int count;
} word_entry;

/**
 * get_word_index - Finds the index of a word in the entries array.
 * @entries: Array of word_entry.
 * @size: Size of the entries array.
 * @word: Word to find.
 *
 * Return: Index of the word if found, -1 otherwise.
 */
static int get_word_index(word_entry *entries, int size, const char *word)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(entries[i].word, word) == 0)
            return i;
    }
    return -1;
}

/**
 * find_substring - Finds all starting indices of substrings in s that are
 *                  concatenations of all words in words array.
 * @s: The input string.
 * @words: Array of words to concatenate.
 * @nb_words: Number of words in the array.
 * @n: Pointer to store the number of indices found.
 *
 * Return: Array of starting indices, or NULL if none found.
 */
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

    int ref_size = 0;
    for (int i = 0; i < nb_words; i++)
    {
        int idx = get_word_index(ref, ref_size, words[i]);
        if (idx == -1)
        {
            ref[ref_size].word = strdup(words[i]);
            ref[ref_size].count = 1;
            ref_size++;
        }
        else
        {
            ref[idx].count++;
        }
    }

    for (int i = 0; i <= len_s - total_len; i++)
    {
        word_entry *seen = malloc(sizeof(word_entry) * ref_size);
        if (!seen)
            continue;

        for (int k = 0; k < ref_size; k++)
        {
            seen[k].word = ref[k].word;
            seen[k].count = 0;
        }

        int matched = 1;
        for (int j = 0; j < nb_words; j++)
        {
            int start = i + j * word_len;
            char *sub = strndup(s + start, word_len);
            if (!sub)
            {
                matched = 0;
                break;
            }

            int idx = get_word_index(ref, ref_size, sub);
            free(sub);

            if (idx == -1 || seen[idx].count + 1 > ref[idx].count)
            {
                matched = 0;
                break;
            }

            seen[idx].count++;
        }

        if (matched)
            indices[count++] = i;

        free(seen);
    }

    for (int i = 0; i < ref_size; i++)
        free(ref[i].word);
    free(ref);

    if (count == 0)
    {
        free(indices);
        *n = 0;
        return NULL;
    }

    *n = count;
    return indices;
}
