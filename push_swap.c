// #include "push_swap.h"
// #include <stdio.h>

// static void	init_stack(t_stack *stack)
// {
// 	stack->top = NULL;
// 	stack->bottom = NULL;
// 	stack->size = 0;
// }

// static void	print_stack(t_stack *stack)
// {
// 	t_node	*tmp;

// 	tmp = stack->top;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

// static int	is_sorted(t_stack *stack)
// {
// 	t_node	*tmp;

// 	tmp = stack->top;
// 	while (tmp && tmp->next)
// 	{
// 		if (tmp->value > tmp->next->value)
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// static void	create_stack(t_stack *stack, int *values, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		add_node(stack, create_node(values[i]));
// 		i++;
// 	}
// }

// static void	run_test(char *name, int *values, int size)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	init_stack(&a);
// 	init_stack(&b);

// 	create_stack(&a, values, size);

// 	printf("\n===== %s =====\n", name);
// 	printf("Antes: ");
// 	print_stack(&a);

// 	if (size == 2)
// 		sort_two(&a);
// 	else if (size == 3)
// 		sort_three(&a);
// 	else if (size == 4)
// 		sort_four(&a, &b);
// 	else if (size == 5)
// 		sort_five(&a, &b);

// 	printf("Después: ");
// 	print_stack(&a);

// 	if (is_sorted(&a))
// 		printf("OK\n");
// 	else
// 		printf("ERROR\n");

// 	free_stack(&a);
// 	free_stack(&b);
// }

// int	main(void)
// {
// 	int	two_1[] = {1, 2};
// 	int	two_2[] = {2, 1};

// 	int	three_1[] = {1, 2, 3};
// 	int	three_2[] = {1, 3, 2};
// 	int	three_3[] = {2, 1, 3};
// 	int	three_4[] = {2, 3, 1};
// 	int	three_5[] = {3, 1, 2};
// 	int	three_6[] = {3, 2, 1};

// 	int	four_1[] = {4, 3, 2, 1};
// 	int	four_2[] = {2, 4, 1, 3};

// 	int	five_1[] = {1, 2, 3, 4, 5};
// 	int	five_2[] = {5, 4, 3, 2, 1};
// 	int	five_3[] = {2, 1, 5, 3, 4};
// 	int	five_4[] = {4, 2, 5, 1, 3};

// 	run_test("2 ordenados", two_1, 2);
// 	run_test("2 invertidos", two_2, 2);

// 	run_test("3 caso 1", three_1, 3);
// 	run_test("3 caso 2", three_2, 3);
// 	run_test("3 caso 3", three_3, 3);
// 	run_test("3 caso 4", three_4, 3);
// 	run_test("3 caso 5", three_5, 3);
// 	run_test("3 invertidos", three_6, 3);

// 	run_test("4 caso 1", four_1, 4);
// 	run_test("4 caso 2", four_2, 4);

// 	run_test("5 ordenados", five_1, 5);
// 	run_test("5 invertidos", five_2, 5);
// 	run_test("5 mezcla 1", five_3, 5);
// 	run_test("5 mezcla 2", five_4, 5);

// 	return (0);
// }