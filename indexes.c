/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:06:21 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 16:49:02 by raqcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		current->index = get_index(stack, current);
		current = current->next;
	}
}

int	get_index(t_stack *stack, t_node *node)
{
	t_node	*compare;
	int		counter;

	compare = stack->top;
	counter = 0;
	while (compare != NULL)
	{
		if (compare->value < node->value)
			counter++;
		compare = compare->next;
	}
	return (counter);
}
