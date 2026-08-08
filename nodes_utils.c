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

void	move_to_top(t_stack *stack, t_node *node)
{
    int position;
    int half;

    if (stack == NULL || node == NULL || stack->top == NULL)
        return ;
    position = get_position(stack, node);
    half = stack->size / 2;
    if (position <= half)
    {
        while (node != stack->top)
            ra(stack);
    }
    else
    {
        while (node != stack->top)
            rra(stack);
    }
}

/*
Lleva ese nodo hasta top.
Decide si usar ra o rra según la posición del nodo.
Modifica la pila.
*/

t_node	*find_max_node(t_stack *stack)
{
    t_node  *compare;
    t_node  *max;

    if (stack == NULL || stack->top == NULL)
        return (NULL);
    max = stack->top;
    compare = stack->top->next;
    while (compare != NULL) 
    {
        if (compare->value > max->value)
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
int	get_reverse_position(t_stack *stack, t_node *node)
{
	int	position;

	position = get_position(stack, node);
	if (position < 0)
		return (-1);
	return (stack->size - position);
}