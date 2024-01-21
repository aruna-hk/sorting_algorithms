#include "sort.h"

/**
* bubble_sort - bubble sort algorithm, stps through each element of the list
* as it compares th element with the previous element if need be, it swaps the
* elements according to comparison operator
* @array: list to be sorted
* @size: size of the list to be sorted
*/
void bubble_sort(int *array, size_t size)
{
	bool swap = false;
	int i, j, len = size, tmp;

	if (array == NULL || size < 2)
		return; 
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = true;
				print_array(array, size);
			}
		}
		if (swap == false)
			return;
	}
}
