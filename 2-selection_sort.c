#include "sort.h"
void swap(int *one, int *two);
/**
 * selection_sort - sorting algorithm
 * @array: the arrya to sort
 * @size the size of the array
 */ 
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_id = 0;

	for (i = 0; i < size - 1; i++)
	{
		min_id = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_id])
				min_id = j;
		}
		if (min_id != i)
		{
			swap(&array[i], &array[min_id]);
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
