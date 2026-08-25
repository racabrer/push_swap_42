#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*aux;

	if (stack == NULL)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		aux = current->next;
		free(current);
		current = aux;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
