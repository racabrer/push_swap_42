#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>

#define SIMPLE		1
#define MEDIUM		2
#define COMPLEX		3
#define ADAPTIVE	4

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;


//Errors
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);

//Parsing
int		parse_flags(int argc, char **argv, int *strategy, int *bench);
int		parse_numbers(int argc, char **argv, int first_number, t_stack *a);
int     is_number(char *str);
long    ft_atol(const char *str);
int     is_int_range(long value);
int     has_duplicates(t_stack *a);

#endif