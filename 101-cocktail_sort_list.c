#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to be swapped.
 * @node2: A pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;

	if (node2->prev != NULL)
		node2->prev->next = node1;
	else
		*head = node1;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 *                      the Cocktail Shaker Sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;
	listint_t *last = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	do {
		swapped = 0;
		current = *list;

		while (current->next != last)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			current = current->next;
		}

		if (!swapped)
			break;

		last = current;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			current = current->prev;
		}
	} while (swapped);
}
