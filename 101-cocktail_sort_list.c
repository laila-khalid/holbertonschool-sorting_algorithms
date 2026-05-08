#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;
	listint_t *next = node->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	if (next->next)
		next->next->prev = node;

	node->next = next->next;
	next->prev = prev;
	next->next = node;
	node->prev = next;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		curr = *list;

		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
