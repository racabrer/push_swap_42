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

int	get_index(t_stack *stack, t_node *node) 
{
    t_node *compare;
    int     counter;

    compare = stack->top; //Empiezo a recorrer la pila desde el principio
    counter = 0; // Contador empieza en cero porque no he comparado ningún nº menor
    while (compare != NULL) //Recorro todos los nodos
    {
        if (compare->value < node->value) //voy comparando el valor de los nodos
            counter++; // si encuentra nodos menores, aumenta el contador
        compare = compare->next; // avanza al siguiente 
    }
    return (counter); //devuelve el resultado del contador. 
}

