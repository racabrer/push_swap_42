#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

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
//int		parse_numbers(int argc, char **argv, int first_number, t_stack *a);
int		parse_numbers(char **argv, t_stack *a);
int		is_number(char *str);
int		is_int_range(long value);
int		has_duplicates(t_stack *a);

/* Utils parser numbers */
long	ft_atol(const char *str);
int		count_numbers(int argc, char **argv, int first_number);
char	**normalize_args(int argc, char **argv, int first_number);
void	copy_split(char **new_array, char **split_tmp, int *index);
void	free_split(char **split);

/* Utils */
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

/* Disorder */
double compute_disorder(t_stack *stack);

/* Libft-utils */
size_t	ft_strlen(const char *s);

/* Split */
char		**ft_split(char const *s, char c);

/* Nodes */
t_node	*create_node(int value);
void	add_node(t_stack *stack, t_node *new_node);

/* Nodes Utils */
t_node	*find_min_node(t_stack *stack);
t_node	*find_max_node(t_stack *stack);
void	move_to_top(t_stack *stack, t_node *node);
int		get_position(t_stack *stack, t_node *node);

/* Little Numbers */
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

/* Insertion sort */
void	insertion_sort(t_stack *a, t_stack *b);
t_node	*find_target(t_stack *a, int index);
int		get_insert_cost(t_stack *a, t_stack *b, t_node *node);
t_node	*find_cheapest(t_stack *a, t_stack *b);
void	move_node(t_stack *a, t_stack *b, t_node *node);

/* Radix sort */
void	radix_sort(t_stack *a, t_stack *b);

/* Common moves */
void	push_to_b(t_stack *a, t_stack *b);
void	push_to_a(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b,
			int *a_moves, int *b_moves);
void	reverse_rotate_both(t_stack *a, t_stack *b,
			int *a_moves, int *b_moves);

/* Indexes */
void	assign_indexes(t_stack *stack);
int		get_index(t_stack *stack, t_node *node);

/* Errors / Stack */
void	free_stack(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);
void	error(void);

/* Rotate */
void	rotate(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);


/* Reverse Rotate */
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);


/* Swap */
void	swap_node(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* Push */
void	push(t_stack *dest, t_stack *src);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

#endif