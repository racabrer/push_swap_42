/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:59:02 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 16:49:02 by raqcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *dest, t_stack *src)
{
	t_node	*moved_node;

	if (!dest || !src || !src->top)
		return (0);
	moved_node = src->top;
	src->top = moved_node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	if (dest->top)
		dest->top->prev = moved_node;
	else
		dest->bottom = moved_node;
	moved_node->next = dest->top;
	moved_node->prev = NULL;
	dest->top = moved_node;
	src->size--;
	dest->size++;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		report_op(&a->stats->pa, "pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		report_op(&a->stats->pb, "pb\n");
}
