#include "push_swap.h"

int    get_chunk_size(int size)
{
    int result;

    if (size <= 0)
        return (0);
    result = ft_sqrt(size);
    return (result);    
}
// t_node	*find_max_node(t_stack *stack)
// {
// 	t_node	*compare;
// 	t_node	*max;

// 	if (stack == NULL || stack->top == NULL)
// 		return (NULL);
// 	max = stack->top;
// 	compare = stack->top->next;
// 	while (compare != NULL) 
// 	{
// 		if (compare->index > max->index)
// 			max = compare;
// 		compare = compare->next;
// 	}
// 	return (max);
// }

t_node	*find_chunk_node(t_stack *stack, int min, int max)
{
	t_node	*curr;
	t_node	*best;
	int		best_cost;
	int		cost;

	if (!stack || !stack->top)
		return (NULL);
	curr = stack->top;
	best = NULL;
	best_cost = INT_MAX;
	while (curr)
	{
		if (curr->index >= min && curr->index <= max)
		{
			cost = get_rotation_cost(stack, curr);
			if (cost < best_cost && (best = curr))
				best_cost = cost;
		}
		curr = curr->next;
	}
	return (best);
}

// t_node    *find_chunk_node(t_stack *stack, int chunk_min, int chunk_max)
// {
// 	t_node	*current;
// 	t_node	*best;
// 	int		cost;
// 	int		best_cost;

//     if (!stack || !stack->top)
//         return (NULL);
//     current = stack->top;
//     best = NULL;
//     best_cost = INT_MAX;
//     while (current)
//     {
//         if (current->index >= chunk_min && current->index <= chunk_max)
//         {
//             cost = get_rotation_cost(stack, current);
//             if (cost < best_cost)
//             {
//                 best_cost = cost;
//                 best = current;
//             }
//         }
//         current = current->next;
//     }
//     return (best);
// }

void    process_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max)
{
    t_node *node;

    node = find_chunk_node(a, chunk_min, chunk_max); 
    while (node)
    {
        move_a_to_top(a, node);
        pb(a, b);
        node = find_chunk_node(a, chunk_min, chunk_max);
    }
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || !b->top)
		return ;
	while (b->top)
	{
		node = find_max_node(b);
		move_b_to_top(b, node);
		pa(a, b);
	}
}

// void	push_back_to_a(t_stack *a, t_stack *b)
// {
// 	t_node	*node;
// 	int		count;

// 	if (!b || !b->top)
// 		return ;
// 	count = 0;
// 	while (b->top)
// 	{
// 		count++;
// 		if (count % 10 == 0)
// 			printf("Devueltos: %d | B: %d\n", count, b->size);
// 		node = find_max_node(b);
// 		move_to_top(b, node);
// 		pa(a, b);
// 	}
// }

//COMENTADA PARA HACER PRUEBAS
// void    push_back_to_a(t_stack *a, t_stack *b)
// {
//     t_node *node;

//     if (!b || !b->top)
//         return ;
//     while (b->top)
//     {
//         node = find_max_node(b);
//         move_to_top(b, node);
//         pa(a, b);
//     }
// }

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;

	if (!a || !b || is_sorted(a))
		return ;
	total_size = a->size;
	chunk_size = get_chunk_size(total_size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (a->top && chunk_min < total_size)
	{
		process_chunk(a, b, chunk_min, chunk_max);
		chunk_min = chunk_min + chunk_size;
		chunk_max = chunk_max + chunk_size;
		if (chunk_max >= total_size)
			chunk_max = total_size - 1;
	}
	push_back_to_a(a, b);
}


/* COMENTADO POR PRUEBA
void    sort_chunks(t_stack *a, t_stack *b)
{
    int total_size;
    int chunk_size;
    int chunk_min;
    int chunk_max;

    if (!a || !b || is_sorted(a))
        return ;
    total_size = a->size;
    chunk_size = get_chunk_size(total_size);
    chunk_min = 0;
    chunk_max = chunk_size - 1;
    while(a->top)
    {
        process_chunk(a, b, chunk_min, chunk_max);
        chunk_min = chunk_min + chunk_size;
        chunk_max = chunk_max + chunk_size;
        if (chunk_max >= total_size)
            chunk_max = total_size- 1;
    }
    push_back_to_a(a, b);
}

*/
