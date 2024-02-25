#include "sort.h"
void swap(int *one, int *two);
void quicky(int *arr, int lo, int hi, size_t size);
int partition(int *arr, int lo, int hi, size_t size);
/**
 * partition - partionan array
 * @arr: the array
 * @lo: the lower bound
 * hi: the upper bound
 * Return: the position of the pivot
 */
int partition(int *arr, int lo, int hi, size_t size)
{
	int pivot = arr[hi];
	int i = lo;
	int j = 0;

	for (j = lo; j < hi; j++)
	{
		if (arr[j] < pivot)
		{
			if (j == i)
				i++;
			else
			{
				swap(&arr[j], &arr[i]);
				i++;
				print_array(arr, size);
			}
		}
	}
	if (i != hi)
	{
		swap(&arr[i], &arr[hi]);
		print_array(arr, size);
	}
	return (i);
}
/**
 * quicky - partionan array
 * @arr: the array
 * @lo: the lower bound
 * hi: the upper bound
 */
void quicky(int *arr, int lo, int hi, size_t size)
{
	int part = 0;

	if (lo < hi)
	{
		part = partition(arr, lo, hi, size);
		quicky(arr, lo, part - 1, size);
		quicky(arr, part + 1, hi, size);
	}
}
/**
 * quick_sort - the sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	size_t high = size - 1;

	quicky(array, low, high, size);
}
/**
 * swap - swaps 2 values
 * @one: one of the values to swap
 * @two: two of the value to swap
 */
void swap(int *one, int *two)
{
	int temp = 0;

	temp = *one;
	*one = *two;
	*two = temp;
}
