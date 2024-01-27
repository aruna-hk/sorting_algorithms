#include "sort.h"

/**
* insertion_sort_list - insertion sort for doubly linked list
* @list: linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	bool swap = false;
	listint_t *current = *list, *tmp, *next;

	while (current != NULL)
	{
		next = current;
		tmp = current->next;
		while (tmp->n <= next->n)
		{
			next = next->prev;
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			if (next == NULL)
			{
				tmp->prev = next;
				tmp->next = *list;
				*list = tmp;
				print_list(*list);
				break;
			}
			else
			{
				tmp->next = next->next;
				tmp->prev = next;
				next->next->prev = tmp;
				next->next = tmp;
				print_list(*list);
			}
			swap = true;
		}
		if (swap == false || current->next == NULL)
			current = current->next;
		swap = false;
	}
}
