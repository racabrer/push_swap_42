#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

static int	arg_vacio(int argc, char **argv, int first)
{
	int	i;
	int	j;

	i = first;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void	run_parse(int argc, char **argv, t_stack *a)
{
	int		strategy;
	int		bench;
	int		first;
	char	**args;

	strategy = NONE;
	bench = 0;
	first = parse_flags(argc, argv, &strategy, &bench);
	if (first == -1 || first >= argc || arg_vacio(argc, argv, first))
		exit_error(a, NULL);
	args = normalize_args(argc, argv, first);
	if (!args)
		exit_error(a, NULL);
	if (!parse_numbers(args, a) || a->size == 0)
	{
		free_split(args);
		exit_error(a, NULL);
	}
	free_split(args);
}

static void	sort_small(t_stack *a, t_stack *b)
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
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	run_parse(argc, argv, &a);
	assign_indexes(&a);
	if (a.size <= 5)
		sort_small(&a, &b);
	else
		sort_chunks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
