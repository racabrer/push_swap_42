#include "push_swap.h"

static void	insert_all(t_stack *a, t_stack *b)
{
	t_node	*node;

	while (b->size)
	{
		node = find_cheapest(a, b);
		move_node(a, b, node);
		pa(a, b);
	}
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size <= 1)
		return ;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	push_to_b(a, b);
	sort_three(a);
	insert_all(a, b);
	move_to_top(a, find_min_node(a));
}
