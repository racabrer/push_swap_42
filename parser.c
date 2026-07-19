#include "push_swap.h"

int		parse_args(int argc, char **argv, t_stack *a) // recibe los argumentos del main y construye el stack
{
/*
parse_args(argc, argv, stack)

    recorrer todos los argumentos
        comprobar si es un número

        convertirlo a long

        comprobar overflow

        crear nodo

        añadir nodo al stack

    comprobar duplicados

    devolver OK
*/
}

int		is_number(char *str) // comprueba si la cadena es un número válido
{

    /*si cadena vacía
        falso
    si primer carácter es + o -
        avanzar
    si ya terminó la cadena
        falso
    mientras no termine
        si no es un dígito
            falso
    return verdadero */
}

int		ft_atol_safe(char *str, long *value) // Convierte una cadena a número, además detecta overflow. No devuelve el número directamente. Lo escribe aquí: value y devuelve si ha ido bien.
{
    /*
    resultado = 0
    leer signo
    mientras haya dígitos
        resultado = resultado * 10
        resultado += dígito
    aplicar signo
    guardar resultado
    return éxito

    Luego parse_args() hará
    if resultado < INT_MIN
        error
    if resultado > INT_MAX
        error
    */
}

int		has_duplicates(t_stack *a) // Comprueba si existe algún número repetido.
{
    /*
    para cada nodo
    recorrer todos los siguientes
        si los valores son iguales
            duplicado
    return no duplicado
    */
}

void	exit_error(t_stack *a) // liberar memoria escribir "Error" terminar programa
{
    /*
    vaciar stack
    imprimir Error
    exit(EXIT_FAILURE)
    */
}