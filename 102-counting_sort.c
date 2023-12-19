#include "sort.h"

/**
 * get_max - Finds the maximum value in an array
 * @array: The array to find the maximum from
 * @size: The size of the array
 *
 * Return: The maximum value in the array
 */
int get_max(int *array, int size)
{
    int max = array[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sorts an array of integers using Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Description: Assumes that array contains only non-negative numbers.
 */
void counting_sort(int *array, size_t size)
{
    int max, *count, *output_array;
    size_t i;

    max = get_max(array, size);

    count = malloc(sizeof(int) * (max + 1));
    output_array = malloc(sizeof(int) * size);

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)  // Corrected loop condition
    {
        output_array[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(count);
    free(output_array);
}
