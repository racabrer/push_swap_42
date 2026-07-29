#include "push_swap.h"

/*
** Sorts a stack of 2 elements.
** Checks if the stack is unsorted and swaps the top two elements 
** if the first element is strictly greater than the second.
*/

void	sort_two(t_stack **a)
{
	if (*a && (*a)->next && !ft_is_sorted(*a))
	{
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
	}
}

/*
** Sorts a stack of 3 elements in 2 moves or less.
** Identifies the highest value and rotates it to the bottom of the stack,
** then performs a final swap on the top two elements if necessary.
*/

void	sort_three(t_stack **a)
{
	if (ft_is_sorted(*a))
		return ;
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		ft_ra(a, 1);
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
		ft_rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 1);
}

/*
** Helper function that locates the smallest element in stack 'a',
** rotates the stack using the shortest path (ra or rra) to bring it 
** to the top, and pushes it onto stack 'b'.
*/

static void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int	min_idx;

	min_idx = ft_min_index(*a);
	while ((*a)->index != min_idx)
	{
		if (min_idx <= ft_stack_size(*a) / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
	ft_pb(a, b, 1);
}

/*
** Sorts a stack of 4 elements.
** Extracts the smallest element to stack 'b', delegates the remaining
** 3 elements to sort_three, and pushes the minimum element back to 'a'.
*/

void	sort_four(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a))
		return ;
	push_smallest_to_b(a, b);
	sort_three(a);
	ft_pa(a, b, 1);
}

/*
** Sorts a stack of 5 elements.
** Repeatedly pushes the smallest elements to stack 'b' until only 3 
** remain in 'a', calls sort_three, and restores the sorted elements 
** from 'b' back to 'a'.
*/

void	sort_five(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a))
		return ;
	while (ft_stack_size(*a) > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (*b)
		ft_pa(a, b, 1);
}