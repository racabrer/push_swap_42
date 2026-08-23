#include "push_swap.h"

int get_rotation_cost(t_stack *stack, t_node *node)
{
    int position;

    if (!stack || !node)
        return (INT_MAX);
    position = get_position(stack, node);
    if (position == -1)
        return (INT_MAX);
    if (position <= stack->size / 2)
        return (position);
    return (stack->size - position);
}

int	rotate(t_stack *stack)
{
    t_node *first_node;
    t_node *second_node;

    if (!stack || !stack->top || stack->size <= 1)
        return (0);
    first_node = stack->top;           //A
    second_node = stack->top->next;    //B
    stack->top = second_node;          // el segundo (B) ahora está en el top
    second_node->prev = NULL;          // el previo al segundo número (B) apunta a NULL
    stack->bottom->next = first_node;  // el siguiente del anterior stack_bottom (D) ahora apunta a A
    first_node->prev = stack->bottom;  // el anterior a A ahora apunta al final del stack (D)
    first_node->next = NULL;           // El siguiente a A (B) ahora apunta a null
    stack->bottom = first_node;        // A pasa a ser el nuevo bottom de la pila.
    return (1);
}

void	ra(t_stack *stack)
{
    if (rotate(stack))
        write(1, "ra\n", 3);
}

void rb(t_stack *stack)
{
    if (rotate(stack))
        write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !b->top || a->size <= 1 || b->size <= 1)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
