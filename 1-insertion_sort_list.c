#include "sort.h"
void bac_swap(listint_t *b, listint_t *c);
void for_swap(listint_t *a, listint_t *b);
/**
 * for_swap - swapps forward
 * @a: the firts node
 * @b: the second node
 */
void for_swap(listint_t *a, listint_t *b)
{
	if (a && b)
	{
		a->next = b->next;
		b->prev = a->prev;
		a->prev = b;
		b->prev->next = b;
		b->next = a;
		if (a->next)
			a->next->prev = a;
	}
}

/**
 * bac_swap - backwards swap
 * @b: one to swap
 * @c: two to swap
 */
void bac_swap(listint_t *b, listint_t *c)
{
	if (b && c)
	{
		if (b->prev == NULL)
		{
			b->next = c->next;
			c->next->prev = b;
			c->prev = NULL;
			b->prev = c;
			c->next = b;
		}
		else
		{
			c->prev = b->prev;
			b->prev->next = c;
			b->prev = c;
			b->next = c->next;
			c->next = b;
			b->next->prev = b;
		}
	}
}
/**
 * insertion_sort_list - sorts a linked list
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *h, *i, *j;

	if (!list || !(*list) || !(*list)->next)
		return;
	if (!(*list)->next->next)
		return;
	h = *list;
	while(h->next)
	{
		i = h;
		j = h->next;
		if (i->n > j->n)
		{
			for_swap(i, j);
			print_list(*list);
		}
		while (j->prev && j && j->n <j->prev->n)
		{
			bac_swap(j->prev, j);
			if (!j->prev)
				*list = j;
			print_list(*list);
		}

		h = j;
	}
}
