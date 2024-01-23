#include "sort.h"

/**
* bubble_sort - bubble sort algorithm of numbers
* in ascending order
* @array: pointer to array
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, n = size;
	int tmp;
	bool swap = false;

	if (array == NULL || size < 2)
		return;
	while (i < (size - 1))
	{
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
				swap = true;
			}
		}
		if (swap == false)
			return;
		i++;
		n--;
	}
}
