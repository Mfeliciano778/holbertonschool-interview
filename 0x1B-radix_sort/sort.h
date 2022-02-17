#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void radix_recursive(int *array, int *buff, size_t size, int step);

#endif /* _SORT_H_ */
