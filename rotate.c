#include "push_swap.h"

int	get_rotation_cost(t_stack *stack, t_node *node)
{
	int	position;

	if (!stack || !node)
		return (INT_MAX);
	position = get_position(stack, node);
	if (position == -1)
		return (INT_MAX);
	if (position <= stack->size / 2)
		return (position);
	return (stack->size - position);
}

int	rotate(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || !stack->top || stack->size <= 1)
		return (0);
	first_node = stack->top;
	second_node = stack->top->next;
	stack->top = second_node;
	second_node->prev = NULL;
	stack->bottom->next = first_node;
	first_node->prev = stack->bottom;
	first_node->next = NULL;
	stack->bottom = first_node;
	return (1);
}

void	ra(t_stack *stack)
{
	if (rotate(stack))
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	if (rotate(stack))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !b->top || a->size <= 1 || b->size <= 1)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
