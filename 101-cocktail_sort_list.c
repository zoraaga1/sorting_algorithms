#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker Sort
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *temp;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;

        for (temp = *list; temp->next != NULL; temp = temp->next)
        {
            if (temp->n > temp->next->n)
            {
                swap_nodes(temp, temp->next, list);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Traverse the list from right to left */
        for (; temp->prev != NULL; temp = temp->prev)
        {
            if (temp->n < temp->prev->n)
            {
                swap_nodes(temp->prev, temp, list);
                swapped = 1;
                print_list(*list);
            }
        }

    } while (swapped);
}
