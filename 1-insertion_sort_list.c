#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order
 * @list: double pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		temp = current;
		while (temp != NULL && temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
		current = next;
	}
}
