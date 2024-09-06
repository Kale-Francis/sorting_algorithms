#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 * 
 * Return: Maximum value in the array
 */
int get_max(int *array, size_t size)
{
    int max;
    size_t i;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort_for_radix - Performs counting sort based on a specific digit
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Exponent representing the digit to sort by
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
    int *output;
    int count[10] = {0};
    size_t i;
    int index;

    output = malloc(size * sizeof(int));
    if (output == NULL)
        return;

    /* Count occurrences of each digit */
    for (i = 0; i < size; i++)
    {
        index = (array[i] / exp) % 10;
        count[index]++;
    }

    /* Update count[i] to contain actual position of this digit in output[] */
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        index = (array[i - 1] / exp) % 10;
        output[count[index] - 1] = array[i - 1];
        count[index]--;
    }

    /* Copy the output array to array[], so that array[] contains sorted numbers */
    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
}

/**
 * radix_sort - Sorts an array of integers using Radix Sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max;
    int exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    /* Perform counting sort for each digit */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_for_radix(array, size, exp);
        print_array(array, size);  /* Print array after each significant digit */
    }
}

