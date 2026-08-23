#include "push_swap.h"
#include <stdio.h>

static void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

static void	create_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		node = create_node(ft_atol(argv[i]));
		add_node(stack, node);
		i++;
	}
}

static int	count_pipe_output(int fd)
{
	char	buffer[1024];
	int		bytes;
	int		moves;
	int		i;

	moves = 0;
	bytes = read(fd, buffer, 1023);
	while (bytes > 0)
	{
		i = 0;
		while (i < bytes)
		{
			if (buffer[i] == '\n')
				moves++;
			i++;
		}
		bytes = read(fd, buffer, 1023);
	}
	return (moves);
}

static int	run_sort(t_stack *a, t_stack *b)
{
	int	pipe_fd[2];
	int	saved_stdout;
	int	moves;

	if (pipe(pipe_fd) == -1)
		return (-1);
	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout == -1)
		return (-1);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (-1);
	close(pipe_fd[1]);
	sort_chunks(a, b);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	moves = count_pipe_output(pipe_fd[0]);
	close(pipe_fd[0]);
	return (moves);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		moves;

	if (argc < 2)
		return (1);
	init_stack(&a);
	init_stack(&b);
	create_stack(&a, argc, argv);
	assign_indexes(&a);
	moves = run_sort(&a, &b);
	printf("Elementos: %d\n", argc - 1);
	printf("Movimientos: %d\n", moves);
	printf("Ordenado: %d\n", is_sorted(&a));
	free_stack(&a);
	free_stack(&b);
	return (0);
}