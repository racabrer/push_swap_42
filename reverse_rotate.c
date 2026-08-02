#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
    t_node *last_node;
    t_node *prev_last_node;

    if (!stack || stack->top == NULL || stack->size <= 1)
        return ;
    last_node = stack->bottom;                 //D
    prev_last_node = stack->bottom->prev;     //C
    stack->bottom = prev_last_node;
    prev_last_node->next = NULL;
    stack->top->prev = last_node;  
    last_node->next = stack->top;
    last_node->prev = NULL;
    stack->top = last_node; 
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}