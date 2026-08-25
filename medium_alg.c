#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	result;

	if (size <= 0)
		return (0);
	result = (ft_sqrt(size) * 11) / 5;
	if (result < 1)
		result = 1;
	return (result);
}

t_node	*find_chunk_node(t_stack *stack, int min, int max)
{
	t_node	*curr;
	t_node	*best;
	int		best_cost;
	int		cost;

	if (!stack || !stack->top)
		return (NULL);
	curr = stack->top;
	best = NULL;
	best_cost = INT_MAX;
	while (curr)
	{
		if (curr->index >= min && curr->index <= max)
		{
			cost = get_rotation_cost(stack, curr);
			if (cost < best_cost)
			{
				best_cost = cost;
				best = curr;
			}
		}
		curr = curr->next;
	}
	return (best);
}

void	process_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max)
{
	t_node	*node;
	int		mid;

	mid = chunk_min + (chunk_max - chunk_min) / 2;
	node = find_chunk_node(a, chunk_min, chunk_max);
	while (node)
	{
		move_a_to_top(a, node);
		pb(a, b);
		if (b->top->index <= mid)
			rb(b);
		node = find_chunk_node(a, chunk_min, chunk_max);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || !b->top)
		return ;
	while (b->top)
	{
		node = find_max_node(b);
		move_b_to_top(b, node);
		pa(a, b);
	}
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;

	if (!a || !b || is_sorted(a))
		return ;
	total_size = a->size;
	chunk_size = get_chunk_size(total_size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (a->top && chunk_min < total_size)
	{
		process_chunk(a, b, chunk_min, chunk_max);
		chunk_min = chunk_min + chunk_size;
		chunk_max = chunk_max + chunk_size;
		if (chunk_max >= total_size)
			chunk_max = total_size - 1;
	}
	push_back_to_a(a, b);
}
