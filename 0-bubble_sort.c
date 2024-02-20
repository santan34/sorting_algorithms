#include "sort.h"
void swap(int *one, int *two);
/**
 * bubble_sort - The bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
			print_array(array, size);
		}
	}
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
