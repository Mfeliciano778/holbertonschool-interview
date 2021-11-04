#include <stdio.h>
#include <stdlib.h>

#include "search.h"
/**
 * linear_skip - function searches a sorted list for a value
 * @list: pointer to the head of the skip list
 * @value: the value to search for
 *
 * Return: NULL on fail, else a pointer to the first node at value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *curr_node, *skip;

    if (!list)
        return (NULL);
    curr_node = list;
    skip = list->express;
    while (skip)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               skip->index, skip->n);
        if (skip->express == NULL || skip->n >= value)
        {
            if (skip->express == NULL && skip->n < value)
            {
                curr_node = skip;
                while (skip->next)
                {
                    skip = skip->next;
                }
            }
            printf("Value found between indexes [%lu] and [%lu]\n",
                   curr_node->index, skip->index);
            while (curr_node)
            {
                printf("Value checked at index [%lu] = [%d]\n",
                       curr_node->index, curr_node->n);
                if (curr_node->n == value)
                    return (curr_node);
                curr_node = curr_node->next;
            }
        }
        curr_node = skip;
        skip = skip->express;
    }
    return (NULL);
}
