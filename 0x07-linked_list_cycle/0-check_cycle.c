#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - check Linked List for a cycle.
 * @list: Linked List
 *
 * Return: 0 if there's no cycle, 1 if there is.
 */
int check_cycle(listint_t *list)
{
    listint_t *fast, *slow;

    if (!list)
        return (0);
    slow = list;
    fast = list->next;
    while (fast)
    {
        if (slow == fast)
            return (1);
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
        else
            return (0);
    }
    return (0);
}