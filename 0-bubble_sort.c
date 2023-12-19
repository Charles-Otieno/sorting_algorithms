#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int array[], int size)
{
	int i = 0;

	while (i < size - 1)
	{
		int j = 0;

		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
}
