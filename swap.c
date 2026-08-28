/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:59:02 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 16:49:02 by raqcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_node(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap_node(a))
		report_op(&a->stats->sa, "sa\n");
}

void	sb(t_stack *b)
{
	if (swap_node(b))
		report_op(&b->stats->sb, "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b
		|| !a->top || !b->top
		|| !a->top->next || !b->top->next)
		return ;
	swap_node(a);
	swap_node(b);
	report_op(&a->stats->ss, "ss\n");
}
