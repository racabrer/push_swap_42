/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:13:46 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/08 20:13:46 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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