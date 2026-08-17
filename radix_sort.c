#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_stack *a, t_stack *b, int bit)
{
	int		i;
	int		size;
	t_node	*node;

	i = 0;
	size = a->size;
	while (i < size)
	{
		node = a->top;
		if (((node->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	push_to_a(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	if (!a || a->size <= 1)
		return ;
	bit = 0;
	max_bits = get_max_bits(a);
	while (bit < max_bits)
	{
		sort_bit(a, b, bit);
		bit++;
	}
}