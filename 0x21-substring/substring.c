#include "substring.h"

/**
* find_substring - finds substring of all words
* Return: an array of indices of where the substrings start, or NULL
* @s: string to scan
* @words: array of words all substrings
* @nb_words: number of elements in array words
* @n: holds address at which to store number of elements in returned array
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int string_length, *indexs;

    if (s == NULL || words == NULL || nb_words == 0 || n == NULL)
        return (NULL);

    string_length = strlen(s);
    indexs = malloc(string_length * sizeof(int));
    if (indexs == NULL)
        return (NULL);

    return (indexs);
}