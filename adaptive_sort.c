/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:55:50 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/19 22:55:50 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b, double disorder)
{
	if (!a || !b || a->size <= 1)
		return ;
	if (disorder < 0.2)
		insertion_sort(a, b);
	else if (disorder < 0.5)
		sort_chunks(a, b);
	else
		radix_sort(a, b);
}