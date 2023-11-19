#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *						in ascending order using Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		prev = curr->prev;
		while (prev != NULL && curr->n < prev->n)
		{
			temp = prev->prev;
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->prev = temp;
			if (temp != NULL)
				temp->next = curr;
			else
				*list = curr;

			prev->prev = curr;
			curr->next = prev;

			print_list(*list);

			prev = curr->prev;
		}
	}
}
