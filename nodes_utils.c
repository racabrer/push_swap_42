#include "push_swap.h"

t_node	*find_min_node(t_stack *stack)
{
	t_node	*compare;
	t_node	*min;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	min = stack->top;
	compare = stack->top->next;
	while (compare != NULL)
	{
		if (compare->value < min->value)
			min = compare;
		compare = compare->next;
	}
	return (min);
}

void	move_a_to_top(t_stack *a, t_node *node)
{
	int	pos;

	if (!a || !node || !a->top)
		return ;
	while (node != a->top)
	{
		pos = get_position(a, node);
		if (pos == -1)
			break ;
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	move_b_to_top(t_stack *b, t_node *node)
{
	int	position;

	if (!b || !node || !b->top)
		return ;
	while (node != b->top)
	{
		position = get_position(b, node);
		if (position == -1)
			break ;
		if (position <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

t_node	*find_max_node(t_stack *stack)
{
	t_node	*compare;
	t_node	*max;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	max = stack->top;
	compare = stack->top->next;
	while (compare != NULL)
	{
		if (compare->index > max->index)
			max = compare;
		compare = compare->next;
	}
	return (max);
}

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*position;
	int		counter;

	if (stack == NULL || node == NULL || stack->top == NULL)
		return (-1);
	position = stack->top;
	counter = 0;
	while (position != NULL)
	{
		if (position == node)
			return (counter);
		position = position->next;
		counter++;
	}
	return (-1);
}
