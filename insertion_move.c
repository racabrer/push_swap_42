#include "push_swap.h"

static void	move_a(t_stack *a, t_node *target, int reverse)
{
	int	moves;

	moves = get_position(a, target);
	if (reverse)
		moves = get_reverse_position(a, target);
	while (moves--)
	{
		if (reverse)
			rra(a);
		else
			ra(a);
	}
}

static void	move_b(t_stack *b, t_node *node, int reverse)
{
	int	moves;

	moves = get_position(b, node);
	if (reverse)
		moves = get_reverse_position(b, node);
	while (moves--)
	{
		if (reverse)
			rrb(b);
		else
			rb(b);
	}
}

static void	move_same_direction(t_stack *a, t_stack *b,
		t_node *target, t_node *node)
{
	int	a_moves;
	int	b_moves;

	a_moves = get_position(a, target);
	b_moves = get_position(b, node);
	if (a_moves > a->size / 2)
	{
		a_moves = get_reverse_position(a, target);
		b_moves = get_reverse_position(b, node);
		reverse_rotate_both(a, b, &a_moves, &b_moves);
	}
	else
		rotate_both(a, b, &a_moves, &b_moves);
}

void	move_node(t_stack *a, t_stack *b, t_node *node)
{
	t_node	*target;
	int		rev_a;
	int		rev_b;

	target = find_target(a, node->index);
	rev_a = get_position(a, target) > a->size / 2;
	rev_b = get_position(b, node) > b->size / 2;
	if (rev_a == rev_b)
		move_same_direction(a, b, target, node);
	move_a(a, target, rev_a);
	move_b(b, node, rev_b);
}
