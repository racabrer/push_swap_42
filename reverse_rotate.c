/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:48:07 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 16:49:02 by raqcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || !stack->top || stack->size <= 1)
		return (0);
	last = stack->bottom;
	prev = last->prev;
	prev->next = NULL;
	stack->bottom = prev;
	last->next = stack->top;
	last->prev = NULL;
	stack->top->prev = last;
	stack->top = last;
	return (1);
}

void	rra(t_stack *stack)
{
	if (reverse_rotate(stack))
	{
		write(1, "rra\n", 4);
		stack->stats->rra++;
	}
}

void	rrb(t_stack *stack)
{
	if (reverse_rotate(stack))
	{
		write(1, "rrb\n", 4);
		stack->stats->rrb++;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b
		|| !stack_a->top || !stack_b->top
		|| stack_a->size <= 1 || stack_b->size <= 1)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	stack_a->stats->rrr++;
}
