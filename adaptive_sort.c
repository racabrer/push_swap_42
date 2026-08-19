#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b, double disorder)
{
	if (!a || !b || a->size <= 1)
		return ;
	if (disorder < 0.2)
		insertion_sort(a, b);
	else if (disorder < 0.5)
		medium_sort(a, b);
	else
		radix_sort(a, b);
}