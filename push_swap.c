#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *a; //almacena puntero a stack a
    t_stack_node    *b; //almacena puntero a stack b


    //Comprobación de argc
    if (argc == 1 || argc == 2 && !argc[1][0])
        return (1);
    else if(argc == 2) //aquí compruebo si es igual a dos, porque significa que nos dan los números juntos, rollo "3 12 9" entonces son dos argumentos, el nombre del programa + los números 
        argv = ft_split(argv[1], ' '); // si hay solo un argumento útil lo separo con split

    


}