/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:13:46 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/08 20:13:46 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

void	rotate_both(t_stack *a, t_stack *b, int *a_moves, int *b_moves)
{
	while (*a_moves && *b_moves)
	{
		rr(a, b);
		(*a_moves)--;
		(*b_moves)--;
	}
}

void	reverse_rotate_both(t_stack *a, t_stack *b,
		int *a_moves, int *b_moves)
{
	while (*a_moves && *b_moves)
	{
		rrr(a, b);
		(*a_moves)--;
		(*b_moves)--;
	}
}