#include "push_swap.h"

#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	**numbers;
// 	int		i;

// 	if (argc < 2)
// 		return (1);

// 	numbers = normalize_args(argc, argv, 1);
// 	if (!numbers)
// 		return (1);

// 	i = 0;
// 	while (numbers[i] != NULL)
// 	{
// 		printf("numbers[%d] = %s\n", i, numbers[i]);
// 		i++;
// 	}

// 	free_split(numbers);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	char	**numbers;
// 	t_stack	a;

// 	a.top = NULL;
// 	a.bottom = NULL;
// 	a.size = 0;

// 	numbers = normalize_args(argc, argv, 1);
// 	if (!numbers)
// 		return (1);

// 	if (!parse_numbers(numbers, &a))
// 	{
// 		write(2, "Error\n", 6);
// 		free_split(numbers);
// 		return (1);
// 	}

// 	printf("OK\n");

// 	free_split(numbers);
// 	free_stack(&a);
// 	return (0);
// }


#include "push_swap.h"
#include <stdio.h>

static void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("%s: ", name);
	current = stack->top;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;

	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;

	// Creamos stack A: 1 -> 2 -> 3
	add_node(&a, create_node(1));
	add_node(&a, create_node(2));
	add_node(&a, create_node(3));

	printf("Estado inicial:\n");
	print_stack("A", &a);
	print_stack("B", &b);

	// Probamos swap A
	printf("\nDespués de sa:\n");
	sa(&a, false);
	print_stack("A", &a);

	// Probamos pb
	printf("\nDespués de pb:\n");
	pb(&a, &b);
	print_stack("A", &a);
	print_stack("B", &b);

	// Probamos pa
	printf("\nDespués de pa:\n");
	pa(&a, &b);
	print_stack("A", &a);
	print_stack("B", &b);

	free_stack(&a);
	free_stack(&b);

	return (0);
}