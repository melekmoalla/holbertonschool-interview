#ifndef SORT_H
#define SORT_H

#include <stddef.h>  // For size_t

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *array, size_t size, size_t index, size_t heap_size);

#endif /* SORT_H */
