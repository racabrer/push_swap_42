#include "push_swap.h"

int		parse_flags(int argc, char **argv, int *strategy, int *bench)
{
    int i;

    i = 1;
    while (i < argc && argv[i] != NULL && argv[i][0] == '-' && argv[i][1] == '-')
    {
        // identificar la flag y guardar la estrategia / activar bench
        if (ft_strcmp(argv[i], "--simple") == 0)
            *strategy = SIMPLE;
        else if (ft_strcmp(argv[i], "--medium") == 0)
            *strategy = MEDIUM;
        else if (ft_strcmp(argv[i], "--complex") == 0)
            *strategy = COMPLEX;
        else if (ft_strcmp(argv[i], "--adaptive") == 0)
            *strategy = ADAPTIVE;
        else if (ft_strcmp(argv[i], "--bench") == 0)
            *bench = 1;
        else // Devuelve -1 si es una flag desconocida (ej. --error)
            return (-1);
        i++; // Avanza al siguiente argumento
    }
    // devolver el índice donde empiezan los números
    return (i);
}    
/*
** Analiza las flags.
**
** Devuelve:
**  - índice del primer número.
**  - -1 si hay error.
**
** Pseudocódigo:
**
** recorrer argv desde argv[1]
**
** mientras el argumento empiece por "--"
**
**     identificar la flag
**
**     guardar la estrategia
**
**     activar bench si aparece
**
** devolver el índice donde empiezan los números
*/


int		parse_numbers(int argc, char **argv, int first_number, t_stack *a)
{
/*
** Construye el stack.
**
** Devuelve:
**  1 -> correcto
**  0 -> error
**
** Pseudocódigo:
**
** recorrer todos los números
**
**     comprobar formato
**
**     convertir a long
**
**     comprobar rango int
**
**     crear nodo
**
**     añadir nodo al stack
**
** comprobar duplicados
**
** devolver éxito
*/
}

int is_number(char *str)
{
    int i;

    if (!str || str[0] == '\0')
        return (0);
    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
    /*
** Comprueba si una cadena representa un entero válido.
**
** Devuelve:
**  1 -> válido
**  0 -> inválido
**
** Pseudocódigo:
**
** comprobar cadena vacía
**
** comprobar signo
**
** comprobar que existen dígitos
**
** recorrer todos los caracteres
**
**     si alguno no es un dígito
**
**         inválido
**
** válido
*/

long ft_atol(const char *str)
{
    int i;
    int sign;
    long result;
   
    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
    /*
** Convierte una cadena a long.
**
** Pseudocódigo:
**
** leer signo
**
** resultado = 0
**
** mientras haya dígitos
**
**     resultado = resultado * 10 + dígito
**
** aplicar signo
**
** devolver resultado
*/

int is_int_range(long value)
{
   
    if (value >= INT_MIN && value <= INT_MAX)
        return (1);
    else
        return (0);
    /*
** Comprueba si un long cabe en un int.
**
** Devuelve:
**  1 -> sí
**  0 -> no
**
** Pseudocódigo:
**
** si value < INT_MIN
**
**     no
**
** si value > INT_MAX
**
**     no
**
** sí
*/
}

int		has_duplicates(t_stack *a)
{
    /*
** Busca valores repetidos.
**
** Devuelve:
**  1 -> hay duplicados
**  0 -> no hay duplicados
**
** Pseudocódigo:
**
** para cada nodo
**
**     recorrer los siguientes
**
**         si coinciden
**
**             duplicado
**
** no hay duplicados
*/
}

void	exit_error(t_stack *a, t_stack *b)
{
    /*
** Libera memoria y termina el programa.
**
** Pseudocódigo:
**
** liberar stack a
**
** liberar stack b
**
** escribir "Error"
**
** exit(EXIT_FAILURE)
*/
}

