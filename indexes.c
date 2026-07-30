#include "push_swap.h"

void	assign_indexes(t_stack *stack) // aquí stack es un puntero a una estructura
{
    // 1. Verifica si el puntero a la estructura es nulo
    // 2. Verifica si la pila está vacía (top es NULL)
    if(stack == NULL || stack->top == NULL)
        return;
    t_node *current; // tiene que ser de este tipo porque necesito un puntero a un nodo
    
    current = stack->top;
    while (current != NULL)
    {
        current->index = get_index(stack, current);
        current = current->next;
    }
}

int	get_index(t_stack *stack, t_node *node) /*Esta función está maluca*/
{
    t_node *compare;
    int     counter;

    compare = stack->top;
    counter = 0;
    while (compare != NULL)
    {
        if (compare > node->value->next)
            counter++;
        else 
            compare = node->value->next;
        compare = compare->next;
    }
    return (counter);
}
/*

La pregunta correcta es:

"¿El nodo que estoy recorriendo (compare) es menor que el nodo cuyo índice estoy calculando (node)?"

Es decir, compare no se compara con compare->next.

compare se compara con node.

Porque node es el protagonista.

compare solo va inspeccionando toda la lista.

get_index()

    comparar = top

    contador = 0

    mientras comparar exista

        comparar valores

    devolver contador
*/
