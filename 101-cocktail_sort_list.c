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

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 * @list: Pointer to a pointer to the head of the list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *prev1, *next1, *prev2, *next2;

    if (node1 == NULL || node2 == NULL)
        return;

    prev1 = node1->prev;
    next1 = node1->next;
    prev2 = node2->prev;
    next2 = node2->next;

    if (prev1 != NULL)
        prev1->next = node2;
    else
        *list = node2;

    if (next1 != NULL)
        next1->prev = node2;

    node2->prev = prev1;
    node2->next = node1;
    node1->prev = node2;
    node1->next = next2;

    if (next2 != NULL)
        next2->prev = node1;
}
