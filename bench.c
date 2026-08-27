/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:58:00 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/27 18:58:00 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Thresholds (0.2 / 0.5) mirror adaptive_sort.c's own branching, duplicated
** here only so --bench can report which sub-strategy actually ran. Keep the
** two in sync if the thresholds ever change.
*/
static void	resolve_strategy_label(int strategy, double disorder,
		const char **name, const char **complexity)
{
	if (strategy == SIMPLE)
		*name = "Simple";
	else if (strategy == MEDIUM)
		*name = "Medium";
	else if (strategy == COMPLEX)
		*name = "Complex";
	else
		*name = "Adaptive";
	if (strategy == SIMPLE || (strategy == ADAPTIVE && disorder < 0.2))
		*complexity = "O(n^2)";
	else if (strategy == MEDIUM || (strategy == ADAPTIVE && disorder < 0.5))
		*complexity = "O(n*sqrt(n))";
	else
		*complexity = "O(n log n)";
}

static void	print_strategy(int strategy, double disorder)
{
	const char	*name;
	const char	*complexity;

	resolve_strategy_label(strategy, disorder, &name, &complexity);
	write(2, "[bench] strategy: ", 19);
	write(2, name, ft_strlen(name));
	write(2, " / ", 3);
	write(2, complexity, ft_strlen(complexity));
	write(2, "\n", 1);
}

static void	print_op_counts(t_stats *stats)
{
	write(2, "[bench] ", 8);
	write_field(2, "sa", stats->sa, 0);
	write_field(2, "sb", stats->sb, 0);
	write_field(2, "ss", stats->ss, 0);
	write_field(2, "pa", stats->pa, 0);
	write_field(2, "pb", stats->pb, 1);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	write_field(2, "ra", stats->ra, 0);
	write_field(2, "rb", stats->rb, 0);
	write_field(2, "rr", stats->rr, 0);
	write_field(2, "rra", stats->rra, 0);
	write_field(2, "rrb", stats->rrb, 0);
	write_field(2, "rrr", stats->rrr, 1);
	write(2, "\n", 1);
}

void	print_bench(t_stack *a, int strategy, double disorder)
{
	unsigned int	total;

	total = a->stats->sa + a->stats->sb + a->stats->ss
		+ a->stats->pa + a->stats->pb + a->stats->ra
		+ a->stats->rb + a->stats->rr + a->stats->rra
		+ a->stats->rrb + a->stats->rrr;
	write(2, "[bench] disorder: ", 19);
	write_percent(2, disorder);
	write(2, "%\n", 2);
	print_strategy(strategy, disorder);
	write(2, "[bench] total_ops: ", 20);
	write_uint(2, total);
	write(2, "\n", 1);
	print_op_counts(a->stats);
}
