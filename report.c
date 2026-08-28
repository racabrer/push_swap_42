/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	report_op(t_stats *stats, int *counter, const char *name)
{
	(*counter)++;
	write(1, name, ft_strlen(name));
}
