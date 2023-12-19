#include "sort.h"

/**
 * swap_node_ahead - Swap the given node with the one ahead of it.
 * @list: Double pointer to the head of the linked list.
 * @tail: Double pointer to the tail of the linked list.
 * @shaker: Double pointer to the node to be swapped.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *current = *shaker;
    listint_t *ahead = current->next;

    if (ahead->next != NULL)
        ahead->next->prev = current;

    current->next = ahead->next;
    ahead->next = current;
    ahead->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = ahead;
    else
        *list = ahead;

    current->prev = ahead;

    if (*tail == current)
        *tail = current->prev;

    *shaker = ahead;
}

/**
 * swap_node_behind - Swap the given node with the one behind it.
 * @list: Double pointer to the head of the linked list.
 * @tail: Double pointer to the tail of the linked list.
 * @shaker: Double pointer to the node to be swapped.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *current = *shaker;
    listint_t *behind = current->prev;

    if (behind->prev != NULL)
        behind->prev->next = current;

    current->prev = behind->prev;
    behind->prev = current;
    behind->next = current->next;

    if (current->next != NULL)
        current->next->prev = behind;
    else
        *tail = behind;

    current->next = behind;

    if (*list == current)
        *list = current->next;

    *shaker = behind;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *shaker;
    listint_t *tail;
    int swapped;

    if (list == NULL || *list == NULL)
        return;

    tail = NULL;
    do {
        swapped = 0;
        for (shaker = *list; shaker->next != NULL; shaker = shaker->next)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_node_ahead(list, &tail, &shaker);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; shaker->prev != NULL; shaker = shaker->prev)
        {
            if (shaker->n < shaker->prev->n)
            {
                swap_node_behind(list, &tail, &shaker);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}
