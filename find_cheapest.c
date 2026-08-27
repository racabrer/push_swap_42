/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:13:46 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/08 20:13:46 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;
	int		cost;
	int		best_cost;

	current = b->top;
	cheapest = current;
	best_cost = get_insert_cost(a, b, current);
	while (current)
	{
		cost = get_insert_cost(a, b, current);
		if (cost < best_cost)
		{
			best_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

