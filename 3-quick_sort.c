#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The array to be partitioned
 * @size: Number of elements in the array
 * @left: The left index of the partition
 * @right: The right index of the partition
 * Return: The pivot index after partitioning
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != right)
	{
		swap_ints(&array[i + 1], &array[right]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @left: The left index of the partition
 * @right: The right index of the partition
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int pivot = lomuto_partition(array, size, left, right);

		if (pivot > 0)
			lomuto_sort(array, size, left, pivot - 1);
		lomuto_sort(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
