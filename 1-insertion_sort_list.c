#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap_node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		swap_node = current;
		current = current->next;

		while (swap_node->prev != NULL && swap_node->n < swap_node->prev->n)
		{
			prev_node = swap_node->prev;

			prev_node->next = swap_node->next;
			if (swap_node->next != NULL)
				swap_node->next->prev = prev_node;

			swap_node->prev = prev_node->prev;
			swap_node->next = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = swap_node;
			else
				*list = swap_node;

			prev_node->prev = swap_node;

			print_list(*list);
		}
	}
}
