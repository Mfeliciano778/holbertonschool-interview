#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void mergearrays(int *array, size_t size, size_t mp, int *cpy);
void tdmerge(int *array, size_t size, int *cpy, size_t cpysize);

#endif
