#include "push_swap.h"

static t_node	*find_bigger(t_stack *a, int index)
{
	t_node	*current;
	t_node	*target;

	current = a->top;
	target = NULL;
	while (current)
	{
		if (current->index > index
			&& (!target || current->index < target->index))
			target = current;
		current = current->next;
	}
	return (target);
}

t_node	*find_target(t_stack *a, int index)
{
	t_node	*target;

	target = find_bigger(a, index);
	if (!target)
		target = find_min_node(a);
	return (target);
}