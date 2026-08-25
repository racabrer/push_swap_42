#include "push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		current->index = get_index(stack, current);
		current = current->next;
	}
}

int	get_index(t_stack *stack, t_node *node)
{
	t_node	*compare;
	int		counter;

	compare = stack->top;
	counter = 0;
	while (compare != NULL)
	{
		if (compare->value < node->value)
			counter++;
		compare = compare->next;
	}
	return (counter);
}
