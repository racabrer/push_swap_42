#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	t_node	*moved_node;

	if (!dest || !src || src->top)
		return ;
	moved_node = src->top;
	src->top = moved_node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	if (dest->top)
		dest->top->prev = moved_node;
	else
		dest->bottom = moved_node;
	moved_node->next = dest->top;
	moved_node->prev = NULL;
	dest->top = moved_node;
	src->size--;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}