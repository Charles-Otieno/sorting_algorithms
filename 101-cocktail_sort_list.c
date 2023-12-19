#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: double pointer to the first element of the list
 */
void cocktail_sort_list(listint_t **list)
{
   listint_t *current, *next, *temp;
   int swapped;

   if (list == NULL || *list == NULL || (*list)->next == NULL)
       return;

   do
   {
       swapped = 0;
       current = (*list)->next;
       while (current != NULL)
       {
           next = current->next;
           if (current->prev != NULL && current->n < current->prev->n)
           {
               temp = current->prev;
               current->prev->next = current->next;
               if (current->next != NULL)
                  current->next->prev = current->prev;
               current->next = temp;
               current->prev = temp->prev;
               temp->prev->next = current;
               if (temp->prev != NULL)
                  temp->prev->next = temp;
               else
                  *list = temp;
               swapped = 1;
               print_list(*list);
           }
           current = next;
       }
       current = (*list)->prev;
       while (current != NULL)
       {
           next = current->prev;
           if (current->next != NULL && current->n > current->next->n)
           {
               temp = current->next;
               current->next->prev = current->prev;
               if (current->prev != NULL)
                  current->prev->next = current->next;
               current->prev = temp;
               current->next = temp->next;
               temp->next->prev = current;
               if (temp->next != NULL)
                  temp->next->prev = temp;
               else
                  *list = temp;
               swapped = 1;
               print_list(*list);
           }
           current = next;
       }
   } while (swapped);
}
