#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*nodo;

	nodo = malloc(sizeof(t_node));
	if (!nodo)
		return (NULL);
	nodo->value = value;
	nodo->index = 0;
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

void	add_node(t_stack *stack, t_node *new_node)
{
	if (!stack)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
		new_node->next = NULL;
	}
	stack->size++;
}
