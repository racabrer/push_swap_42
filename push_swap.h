#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>

#define NONE        0
#define SIMPLE      1
#define MEDIUM      2
#define COMPLEX     3
#define ADAPTIVE    4

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


/* Parser flags */
int		flag_duplicates(char *flag, int strategy, int bench);
int		set_strategy(char *flag, int *strategy);
int		parse_flags(int argc, char **argv, int *strategy, int *bench);


/* Parser numbers */
int		parse_numbers(int argc, char **argv, int first_number, t_stack *a);
int		is_number(char *str);
long	ft_atol(const char *str);
int		is_int_range(long value);
int		has_duplicates(t_stack *a);


/* Nodes */
t_node	*create_node(int value);
void	add_node(t_stack *stack, t_node *new_node);


/* Errors / Stack */
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);


#endif