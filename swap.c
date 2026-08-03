#include "push_swap.h"

void	swap_node(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
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
}

void	sa(t_stack *a)
{
	swap_node(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_node(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_node(a);
	swap_node(b);
	write(1, "ss\n", 3);
}