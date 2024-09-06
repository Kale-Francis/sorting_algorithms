#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * heapify - Turns a subtree into a heap
 * @array: The array
 * @size: Size of the array
 * @i: Index of the root of the subtree
 * @n: Size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(array, i, largest);
        printf("Swapping %d with %d\n", array[i], array[largest]);
        print_array(array, size);
        heapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        heapify(array, size, i - 1, size);

    heapify(array, size, 0, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(array, 0, i);
        printf("Swapping %d with %d\n", array[0], array[i]);
        print_array(array, size);
        heapify(array, size, 0, i);
    }
}
