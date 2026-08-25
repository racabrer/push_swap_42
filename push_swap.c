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

static int	is_sorted(t_stack *a)
{
	t_node	*node;

	if (!a || a->size <= 1)
		return (1);
	node = a->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	sort_stack(t_stack *a, t_stack *b, int strategy)
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
			medium_sort(a, b);
		else if (strategy == COMPLEX)
			radix_sort(a, b);
		else
			adaptive_sort(a, b, compute_disorder(a));
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
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
	a = (t_stack){NULL, NULL, 0};
	b = (t_stack){NULL, NULL, 0};
	if (!parse_numbers(numbers, &a))
	{
		free_split(numbers);
		exit_error(&a, &b);
	}
	free_split(numbers);
	if (strategy == NONE)
		strategy = ADAPTIVE;
	sort_stack(&a, &b, strategy);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
