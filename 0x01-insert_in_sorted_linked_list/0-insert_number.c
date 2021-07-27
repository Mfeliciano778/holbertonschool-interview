#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - prints all elements of a listint_t list
 * @head: pointer to head of list
 * @number: number we are inserting into the list
 * Return:  the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    if (!head || !*head || number < 0)
        return (NULL);
    listint_t *curr = *head;

    return (curr);
}