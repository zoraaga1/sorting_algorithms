#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			temp = curr->prev;
			curr->prev = temp->prev;
			temp->prev = curr;

			if (curr->next != NULL)
				curr->next->prev = temp;

			temp->next = curr->next;
			curr->next = temp;

			if (temp->prev != NULL)
				temp->prev->next = curr;
			else
				*list = curr;
			print_list(*list);
		}
	}
}