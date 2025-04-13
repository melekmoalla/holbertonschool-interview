#include "substring.h"
/**
 * compare_words - Compares two strings for equality.
 * @word1: The first string.
 * @word2: The second string.
 * Return: (1) if equal, (0) otherwise.
 */
int compare_words(const char *word1, const char *word2)
{return (strcmp(word1, word2) == 0); }
/**
 * check_concat - Checks if the substring starting at 'start' in 's'
 * @s: Input string.
 * @start: Starting index in s.
 * @word_len: Length of one word.
 * @nb_words: Total number of words.
 * @ref: Array of word_entry with reference counts.
 * @ref_size: Number of unique words in ref.
 * Return: (1) if the concatenation is valid, (0) otherwise.
 */
int check_concat(const char *s, int start, int word_len, int nb_words,
				 word_entry *ref, int ref_size)
{
	int i, j, found;
	word_entry temp[ref_size];

	for (i = 0; i < ref_size; i++)
	{
		temp[i].word = ref[i].word;
		temp[i].count = ref[i].count; }
	for (i = 0; i < nb_words; i++)
	{
		const char *word = s + start + i * word_len;

		found = 0;
		for (j = 0; j < ref_size; j++)
		{
			if (strncmp(word, temp[j].word, word_len) == 0)
			{
				if (temp[j].count == 0)
				{return (0); }
				temp[j].count--;
				found = 1;
				break; }
		}
		if (!found)
		{return (0); }
	}
	return (1);
}
/**
 * find_substring - Finds all starting indices of substrings
 * @s: Input string.
 * @words: Array of words.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of elements in the returned array.
 * Return: An allocated array of starting indices, or (NULL) if no solution.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int len, word_len, total_len, count = 0, *indices = NULL;
	word_entry ref[nb_words];
	int ref_size = 0, i, j, found;

	if (!s || !words || nb_words == 0 || !n)
	return (NULL);
	len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	for (i = 0; i < nb_words; i++)
	{
		len = strlen(s);
		word_len = strlen(words[0]);
		total_len = word_len * nb_words;
			if (len < total_len)
		{
			*n = 0;
			return (NULL);
		}

		found = 0;
		for (j = 0; j < ref_size; j++)
		{
			if (compare_words(words[i], ref[j].word))
			{ref[j].count++;
				found = 1;
				break; } }
		if (!found)
		{ref[ref_size].word = (char *)words[i];
			ref[ref_size].count = 1;
			ref_size++; } }
	indices = malloc(sizeof(int) * (len - total_len + 1));
	if (!indices)
	return (NULL);
	for (i = 0; i <= len - total_len; i++)
	{
		if (check_concat(s, i, word_len, nb_words, ref, ref_size))
		{indices[count++] = i; } }
	*n = count;
	if (count)
	return (indices);
	else
	{free(indices);
		return (NULL); }
}
