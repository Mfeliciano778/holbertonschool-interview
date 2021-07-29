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
    listint_t *curr = *head;
    listint_t *prev = NULL;
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;
    
    if (!*head || number <= (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }
    while (curr && number >= curr->n)
    {
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;
    prev->next = new_node;

    return (new_node);
}