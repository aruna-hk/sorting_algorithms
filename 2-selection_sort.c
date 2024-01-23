#include "sort.h"
/**
* selection_sort - selection sort sort elements of a list by
* "based on sorting creteria" bring the element to from of the list
* the sorted potion of the list -building sorted list from left to right
* @array: list to be sorted
* @size: size of the list
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, small, idx;

	for (i = 0; i < size; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}
		if (idx != i)
		{
			small = array[idx];
			array[idx] = array[i];
			array[i] = small;
			print_array(array, size);
		}
	}
}
