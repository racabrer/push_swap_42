#include "push_swap.h"

int	swap_node(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap_node(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap_node(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b
		|| !a->top || !b->top
		|| !a->top->next || !b->top->next)
		return ;
	swap_node(a);
	swap_node(b);
	write(1, "ss\n", 3);
}