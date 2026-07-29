#include "push_swap.h"

static int overflow(long result, int digit, int sign)
{
    if (sign == 1)
    {
        if (result > LONG_MAX / 10)
            return (1);
        if (result == LONG_MAX && digit > 7)
            return (1);
    }
    else
    {
        if (result > LONG_MAX / 10)
            return (1);
        if (result == LONG_MAX && digit > 8)
            return (1);
    }
    return (0);
}

static long get_number(const char *str, int *i, int sign)
{
    long result;
    int digit;
   
    result = 0;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        digit = str[*i] - '0';
        if (overflow(result, digit, sign))
            return (1);
        result = result * 10 + digit;
        (*i)++; //incrementa el entero al que apunta
    }
    return (result);
}

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
    result = get_number(str, &i, sign);;
    return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h> // Cabecera obligatoria para atol

// int main(void) {
//     // Caso 1: Cadena con número estándar
//     char str1[] = "1234567890";
//     long res1 = atol(str1);
//     printf("Texto: \"%s\" -> Largo: %ld\n", str1, res1);

//     // Caso 2: Cadena con espacios y signos
//     char str2[] = "   -987654321";
//     long res2 = atol(str2);
//     printf("Texto: \"%s\" -> Largo: %ld\n", str2, res2);

//     // Caso 3: Cadena con letras al final (las ignora)
//     char str3[] = "555falsa_alarma";
//     long res3 = atol(str3);
//     printf("Texto: \"%s\" -> Largo: %ld\n", str3, res3);

//     // Caso 4: Cadena no válida (devuelve 0)
//     char str4[] = "abc123";
//     long res4 = atol(str4);
//     printf("Texto: \"%s\" -> Largo: %ld\n", str4, res4);

//     return 0;
// }
