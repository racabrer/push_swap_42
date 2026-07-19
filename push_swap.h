#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>

#define SIMPLE		1
#define MEDIUM		2
#define COMPLEX		3
#define ADAPTIVE	4

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/*
typedef struct s_stack_node
{
    int                     nbr;          // valor del número
    int                     index;        // rango/orden normalizado en la lista
    int                     push_cost;    // coste total para mover este nodo (rotaciones A+B)
    int                     cost_a;       // opcional: coste en stack A
    int                     cost_b;       // opcional: coste en stack B
    bool                    above_median; // si está por encima de la mitad del stack
    bool                    cheapest;     // marca el nodo elegido como más barato

    struct s_stack_node     *target_node; // nodo destino en la otra pila
    struct s_stack_node     *next;        // siguiente en la lista (hacia abajo)
    struct s_stack_node     *prev;        // anterior en la lista (hacia arriba)
}   t_stack_node;


typedef struct s_stack
{
    t_stack_node    *head;   // top de la pila
    t_stack_node    *tail;   // fondo de la pila
    int             size;    // número de elementos
}   t_stack;
*/

//Handle errors


//Stack initiation


//Model initiation


//Stack_utils


//Commands


//Algoritms



#endif