#include "sort.h"

/**
 * sift_down - Rearranges the heap by moving the element at the given index down.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @index: The index of the element to be moved.
 * @heap_size: The current size of the heap.
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    int temp;

    if (left < heap_size && array[left] > array[largest])
        largest = left;
    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        sift_down(array, size, largest, heap_size);
    }
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t i;
    int temp;

    for (i = size / 2; i-- > 0;)
        sift_down(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {

        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        sift_down(array, size, 0, i);
    }
}
