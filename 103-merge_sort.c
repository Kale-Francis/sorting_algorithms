#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays of an array
 * @array: The array to be sorted
 * @temp: The temporary array to hold sorted elements
 * @left: Starting index of the left sub-array
 * @middle: Ending index of the left sub-array and starting index of right
 * @right: Ending index of the right sub-array
 */
void merge(int *array, int *temp, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, middle - left + 1);
    printf("[right]: ");
    print_array(array + middle + 1, right - middle);

    i = left;
    j = middle + 1;
    k = left;

    while (i <= middle && j <= right)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort
 * @array: The array to be sorted
 * @temp: Temporary array to hold sorted elements
 * @left: Left index
 * @right: Right index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t middle;

    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort_recursive(array, temp, left, middle);
        merge_sort_recursive(array, temp, middle + 1, right);
        merge(array, temp, left, middle, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size - 1);

    free(temp);
}
