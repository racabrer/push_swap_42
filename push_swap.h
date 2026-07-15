#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>


typedef struct s_stack_node
{
    int     nbr;
    int     index;
    int     push_cost;
    bool    avove_median;
    bool    cheapest;

    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;


//Handle errors


//Stack initiation


//Model initiation


//Stack_utils


//Commands


//Algoritms



#endif