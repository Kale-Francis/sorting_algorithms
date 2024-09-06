#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array;
    size_t i;
    int max_value = 0;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
        if (array[i] > max_value)
            max_value = array[i];

    /* Allocate memory for the count array */
    count_array = malloc((max_value + 1) * sizeof(int));
    if (!count_array)
        return;

    /* Initialize the count array to 0 */
    for (i = 0; i <= (size_t)max_value; i++)
        count_array[i] = 0;

    /* Store the count of each element in the array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the count array */
    print_array(count_array, max_value + 1);

    /* Modify the count array by adding the previous counts */
    for (i = 1; i <= (size_t)max_value; i++)
        count_array[i] += count_array[i - 1];

    /* Allocate memory for the output array */
    output_array = malloc(size * sizeof(int));
    if (!output_array)
    {
        free(count_array);
        return;
    }

    /* Build the sorted output array */
    for (i = size; i > 0; i--)
    {
        output_array[count_array[array[i - 1]] - 1] = array[i - 1];
        count_array[array[i - 1]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free allocated memory */
    free(count_array);
    free(output_array);
}

