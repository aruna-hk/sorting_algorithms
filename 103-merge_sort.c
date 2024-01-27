#include "sort.h"
/**
* merge - this function merges sorted portions of array
* @array: original array
* @low: leftmost index
* @middle: middle index
* @high: rightmost index
*/
void merge(int *array, int low, int middle, int high)
{
	int l_size = middle - low + 1, r_size = high - middle, idx;
	int *l_array, *r_array, i = low, j = 0, l = 0;

	printf("Merging...\n");
	l_array = malloc(sizeof(int) * l_size);
	r_array = malloc(sizeof(int) * r_size);
	while (i <= high)
	{
		if (i <= middle)
		{
			l_array[j] = array[i];
			j++;
		}
		else
		{
			r_array[l] = array[i];
			l++;
		}
		i++;
	}
	printf("[left]: ");
	print_array(l_array, l_size);
	printf("[right]: ");
	print_array(r_array, r_size);

	i = j = 0;
	idx = low;
	while (i < l_size && j < r_size)
	{
		if (l_array[i] <= r_array[j])
		{
			array[idx] = l_array[i];
			i++;
		}
		else
		{
			array[idx] = r_array[j];
			j++;
		}
		idx++;
	}
	while (i < l_size)
	{
		array[idx] = l_array[i];
		i++;
		idx++;
	}
	while (j < r_size)
	{
		array[idx] = r_array[j];
		j++;
		idx++;
	}
}
/**
* merge_sort_recursion - merge sort helper function
* this is wheresorting hapens recusrively
* @array: array to sort
* @low: lowest index
* @high: rightmost index
*/
void merge_sort_recursion(int *array, int low, int high)
{
	int middle;

	if (low >= high)
		return;
	middle = (high + low) / 2;
	merge_sort_recursion(array, low, middle);
	merge_sort_recursion(array, middle + 1, high);
	merge(array, low, middle, high);
}
/**
* merge_sort -merge sort algorithm
* argument - list to sort and its size
* @array: array to sort
* @size: size of the alist
*/
void merge_sort(int *array, size_t size)
{
	if (size > 1)
		merge_sort_recursion(array, 0, size - 1);
}
