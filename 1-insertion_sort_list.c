#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (*n1 == n2)
		return;

	if ((*n1)->prev)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	if (n2->next)
		n2->next->prev = *n1;

	(*n1)->next = n2->next;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	(*n1)->prev = n2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion sort.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, &current, current->prev);
			print_list(*list);
		}

		current = temp;
	}
}
