#include "push_swap.h"

/*
** Sorts a stack of 2 elements.
** Checks if the stack is unsorted and swaps the top two elements 
** if the first element is strictly greater than the second.
*/

void	sort_two(t_stack *a)
{

}

/*
** Sorts a stack of 3 elements in 2 moves or less.
** Identifies the highest value and rotates it to the bottom of the stack,
** then performs a final swap on the top two elements if necessary.
*/

void	sort_three(t_stack *a)
{

}

/*
** Helper function that locates the smallest element in stack 'a',
** rotates the stack using the shortest path (ra or rra) to bring it 
** to the top, and pushes it onto stack 'b'.
*/

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{

}

/*
** Sorts a stack of 4 elements.
** Extracts the smallest element to stack 'b', delegates the remaining
** 3 elements to sort_three, and pushes the minimum element back to 'a'.
*/

void	sort_four(t_stack **a, t_stack **b)
{

}

/*
** Sorts a stack of 5 elements.
** Repeatedly pushes the smallest elements to stack 'b' until only 3 
** remain in 'a', calls sort_three, and restores the sorted elements 
** from 'b' back to 'a'.
*/

void	sort_five(t_stack *a, t_stack *b)
{

}