#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (!a || a->size != 2)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*max;
	int		position;

	if (!a || a->size != 3)
		return ;
	max = find_max_node(a);
	position = get_position(a, max);
	if (position == 0)
		ra(a);
	else if (position == 1)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_node	*min;

	if (!a || a->top == NULL || !b)
		return ;
	min = find_min_node(a);
	move_a_to_top(a, min);
	pb(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (!a || a->size != 4 || !b)
		return ;
	push_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size != 5)
		return ;
	push_smallest_to_b(a, b);
	sort_four(a, b);
	pa(a, b);
}
