#include "push_swap.h"

/*
** Algoritmo O(n * sqrt(n)) por chunks (ver medium_alg.c): divide la pila
** en tramos de tamaño sqrt(n) y va extrayendo de cada tramo el nodo más
** barato de rotar hasta 'b', para luego devolverlo todo ordenado a 'a'.
*/
void	medium_sort(t_stack *a, t_stack *b)
{
	sort_chunks(a, b);
}
