#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in the array
 * @array: Array of integers
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
    int temp;

    if (array[i] != array[j])
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * bitonic_merge - Merge function for bitonic sort
 * @array: Array of integers
 * @low: Starting index
 * @cnt: Number of elements
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
    size_t i, k;

    if (cnt > 1)
    {
        k = cnt / 2;
        for (i = low; i < low + k; i++)
        {
            if ((dir && array[i] > array[i + k]) || (!dir && array[i] < array[i + k]))
                swap(array, i, i + k);
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_rec - Recursive function for bitonic sort
 * @array: Array of integers
 * @low: Starting index
 * @cnt: Number of elements
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t low, size_t cnt, int dir)
{
    size_t k;

    if (cnt > 1)
    {
        k = cnt / 2;
        bitonic_sort_rec(array, low, k, 1);
        bitonic_sort_rec(array, low + k, k, 0);
        bitonic_merge(array, low, cnt, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic Sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_rec(array, 0, size, 1);
}
