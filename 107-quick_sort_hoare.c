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
        /* Print the array after each swap */
        print_array(array, 10);  /* Adjust size for print_array if needed */
    }
}

/**
 * hoare_partition - Partition using Hoare scheme
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 *
 * Return: The index of the pivot element
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
    }
}

/**
 * quick_sort_rec - Recursive Quick Sort function
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 */
void quick_sort_rec(int *array, int low, int high)
{
    int p;

    if (low < high)
    {
        p = hoare_partition(array, low, high);
        quick_sort_rec(array, low, p);
        quick_sort_rec(array, p + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers using Quick Sort algorithm with Hoare partition
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1);
}
