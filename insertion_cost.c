#include "push_swap.h"

static int	max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	get_separate_cost(int a, int b)
{
	return (a + b);
}

int	get_insert_cost(t_stack *a, t_stack *b, t_node *node)
{
	t_node	*target;
	int		pos_a;
	int		pos_b;

	target = find_target(a, node->index);
	pos_a = get_position(a, target);
	pos_b = get_position(b, node);
	if (pos_a <= a->size / 2 && pos_b <= b->size / 2)
		return (max_value(pos_a, pos_b) + 1);
	if (pos_a > a->size / 2 && pos_b > b->size / 2)
	{
		pos_a = get_reverse_position(a, target);
		pos_b = get_reverse_position(b, node);
		return (max_value(pos_a, pos_b) + 1);
	}
	if (pos_a <= a->size / 2)
		return (get_separate_cost(pos_a,
				get_reverse_position(b, node)) + 1);
	return (get_separate_cost(get_reverse_position(a, target),
			pos_b) + 1);
}
