#include "push_swap.h"

t_node	*find_min_node(t_stack *stack)
{
    t_node  *compare;
    t_node  *min;

    if (stack == NULL || stack->top == NULL)
        return (NULL);
    min = stack->top;
    compare = stack->top->next;
    while (compare != NULL) 
    {
        if (compare->value < min->value)
            min = compare;
        compare = compare->next;
    }
    return (min);
}

void move_a_to_top(t_stack *a, t_node *node)
{
    int pos;

    if (!a || !node || !a->top)
        return ;
    while (node != a->top)
    {
        pos = get_position(a, node);
        if (pos == -1)
            break ;
        if (pos <= a->size / 2)
            ra(a);
        else
            rra(a);
    }
}

void	move_b_to_top(t_stack *b, t_node *node)
{
	int	position;

	if (!b || !node || !b->top)
		return ;
	while (node != b->top)
	{
		position = get_position(b, node);
		if (position == -1)
			break ;
		if (position <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

// void move_a_to_top(t_stack *a, t_node *node)
// {
//     int position;

//     if (!a || !node || !a->top)
//         return ;
//     position = get_position(a, node);
//     if (position == -1)
//         return ;
//     if (position <= a->size / 2)
//     {
//         while (node != a->top)
//             ra(a);
//     }
//     else
//     {
//         while (node != a->top)
//             rra(a);
//     }
// }

// void move_b_to_top(t_stack *b, t_node *node)
// {
//     int position;

//     if (!b || !node || !b->top)
//         return ;
//     position = get_position(b, node);
//     if (position == -1)
//         return ;
//     if (position <= b->size / 2)
//     {
//         while (node != b->top)
//             rb(b);
//     }
//     else
//     {
//         while (node != b->top)
//             rrb(b);
//     }
// }

//COMENTADA POR PRUEBA 
// void	move_to_top(t_stack *stack, t_node *node)
// {
//     int position;
//     int half;

//     if (stack == NULL || node == NULL || stack->top == NULL)
//         return ;
//     position = get_position(stack, node);
//     half = stack->size / 2;
//     if (position <= half)
//     {
//         while (node != stack->top)
//             ra(stack);
//     }
//     else
//     {
//         while (node != stack->top)
//             rra(stack);
//     }
// }

/*
Lleva ese nodo hasta top.
Decide si usar ra o rra según la posición del nodo.
Modifica la pila.
*/

// t_node	*find_max_node(t_stack *stack)
// {
//     t_node  *compare;
//     t_node  *max;

//     if (stack == NULL || stack->top == NULL)
//         return (NULL);
//     max = stack->top;
//     compare = stack->top->next;
//     while (compare != NULL) 
//     {
//         if (compare->value > max->value)
//             max = compare;
//         compare = compare->next;
//     }
//     return (max);
// }
t_node	*find_max_node(t_stack *stack)
{
	t_node	*compare;
	t_node	*max;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	max = stack->top;
	compare = stack->top->next;
	while (compare != NULL)
	{
		if (compare->index > max->index)
			max = compare;
		compare = compare->next;
	}
	return (max);
}


int	get_position(t_stack *stack, t_node *node)
{
    t_node *position;
    int     counter;

    if (stack == NULL ||  node == NULL || stack->top == NULL)
        return (-1);
    position = stack->top;
    counter = 0;
    while(position != NULL)
    {
        if (position == node)
            return (counter);
        position = position->next;
        counter++;
    }
    return (-1);
}

/*
Recorre la pila desde top.
Cuenta cuántos nodos hay hasta llegar a node.
Devuelve esa posición (empezando en 0).
*/