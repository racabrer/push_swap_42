#include "push_swap.h"

/*
** TODO (pendiente, a propósito): esto NO es el algoritmo O(n * sqrt(n))
** que exige el enunciado (VI.3.3, punto 2). Es un stub temporal que
** reutiliza insertion_sort (O(n^2)) solo para que --medium y el modo
** adaptativo tengan una función real que llamar y el proyecto compile
** y ordene correctamente mientras se decide/implementa la estrategia
** de chunks/buckets definitiva.
**
** Mientras esta función exista tal cual, --medium y el tramo
** "desorden medio" del adaptativo NO cumplen la clase de complejidad
** O(n*sqrt(n)) exigida por el enunciado.
*/
void	medium_sort(t_stack *a, t_stack *b)
{
	insertion_sort(a, b);
}
