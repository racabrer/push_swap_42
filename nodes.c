#include "push_swap.h"

t_node *create_node(int value)
{
   
    t_node *nodo;
   
    nodo = malloc(sizeof(t_node));
    if (!nodo)
        return (NULL);
    nodo->value = value;
    nodo->index = 0;
    nodo->next = NULL;
    nodo->prev = NULL;
    return (nodo);
}

void add_node(t_stack *stack, t_node *new_node) // Añade un nodo al final del stack
{
    if (!stack)
        return;
    if (stack->top == NULL) //Stack vacío
    {
        stack->top = new_node;
        stack->bottom = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else //Ya hay nodos
    {
        stack->bottom->next = new_node; //el antiguo último apunta al nuevo
        new_node->prev = stack->bottom; //El nuevo nodo apunta hacia atrás al antiguo último
        stack->bottom = new_node; //bottom actualiza su posición
        new_node->next = NULL; //Nuevo último apunta a NULL
    }
    stack->size++;
}

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


int	get_position(t_stack *stack, t_node *node)
{

}

/*
Recorre la pila desde top.
Cuenta cuántos nodos hay hasta llegar a node.
Devuelve esa posición (empezando en 0).
*/

void	move_to_top(t_stack *stack, t_node *node)
{

}

/*
Lleva ese nodo hasta top.
Decide si usar ra o rra según la posición del nodo.
Modifica la pila.
*/