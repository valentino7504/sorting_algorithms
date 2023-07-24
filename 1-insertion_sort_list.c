#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list using
 * insertion sort
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted;
	listint_t *next_node, *current_node;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;
	unsorted = (*list)->next;
	while (unsorted != NULL)
	{
		next_node = unsorted->next;
		current_node = unsorted->prev;
		while (current_node != NULL)
		{
			if (unsorted->n < current_node->n)
			{
				current_node->next = unsorted->next;
				if (unsorted->next != NULL)
					unsorted->next->prev = current_node;
				unsorted->next = current_node;
				unsorted->prev = current_node->prev;
				if (current_node->prev != NULL)
					current_node->prev->next = unsorted;
				else
					*list = unsorted;
				current_node->prev = unsorted;
				print_list(*list);
			}
			else
				break;
			current_node = unsorted->prev;
		}
		unsorted = next_node;
	}
}
