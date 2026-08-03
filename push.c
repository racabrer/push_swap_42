#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	t_node *moved_node;

	if (!src)
		return;
	moved_node = src->top;
	



}

/*
mover el top de src al siguiente nodo

    si src no está vacía
        el nuevo top apunta a NULL por prev
    si no
        bottom de src pasa a NULL

    si dest está vacía
        el nodo movido será también el bottom
    si no
        el antiguo top de dest apunta hacia atrás al nodo movido

    el nodo movido apunta al antiguo top de dest

    el nodo movido no tiene prev

    el top de dest pasa a ser el nodo movido

    actualizar los tamaños

fin
*/

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}