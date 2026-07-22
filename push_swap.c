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

int	main(int argc, char **argv)
{
	char	**numbers;
	t_stack	a;

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;

	numbers = normalize_args(argc, argv, 1);
	if (!numbers)
		return (1);

	if (!parse_numbers(numbers, &a))
	{
		write(2, "Error\n", 6);
		free_split(numbers);
		return (1);
	}

	printf("OK\n");

	free_split(numbers);
	free_stack(&a);
	return (0);
}