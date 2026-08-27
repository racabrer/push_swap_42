/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:59:02 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 21:21:03 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '\t' || str[i] > '\r'))
			return (0);
		i++;
	}
	return (1);
}

static int	has_blank_arg(int argc, char **argv, int first)
{
	int	i;

	i = first;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_blank(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	sort_stack(t_stack *a, t_stack *b, int strategy, double disorder)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		assign_indexes(a);
		if (strategy == SIMPLE)
			insertion_sort(a, b);
		else if (strategy == MEDIUM)
			sort_chunks(a, b);
		else if (strategy == COMPLEX)
			radix_sort(a, b);
		else
			adaptive_sort(a, b, disorder);
	}
}

static void	run_and_report(t_stack *a, t_stack *b, int strategy, int bench)
{
	double	disorder;

	if (strategy == NONE)
		strategy = ADAPTIVE;
	disorder = compute_disorder(a);
	sort_stack(a, b, strategy, disorder);
	if (bench)
		print_bench(a, strategy, disorder);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
	int		strategy;
	int		bench;
	int		first;
	char	**numbers;

	if (argc < 2)
		return (0);
	strategy = NONE;
	bench = 0;
	first = parse_flags(argc, argv, &strategy, &bench);
	if (first < 0)
		error();
	if (first >= argc)
		return (0);
	if (has_blank_arg(argc, argv, first))
		error();
	numbers = normalize_args(argc, argv, first);
	if (!numbers)
		error();
	init_stacks(&a, &b, &stats);
	if (!parse_numbers(numbers, &a))
	{
		free_split(numbers);
		exit_error(&a, &b);
	}
	free_split(numbers);
	run_and_report(&a, &b, strategy, bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
