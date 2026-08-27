/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqcabre <raqcabre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:19:49 by raqcabre          #+#    #+#             */
/*   Updated: 2026/08/25 16:49:02 by raqcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow(long result, int digit, int sign)
{
	if (sign == 1)
	{
		if (result > LONG_MAX / 10)
			return (1);
		if (result == LONG_MAX / 10 && digit > 7)
			return (1);
	}
	else
	{
		if (result > LONG_MAX / 10)
			return (1);
		if (result == LONG_MAX / 10 && digit > 7)
			return (1);
	}
	return (0);
}

static long	get_number(const char *str, int *i, int sign)
{
	long	result;
	int		digit;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		digit = str[*i] - '0';
		if (overflow(result, digit, sign))
			return (LONG_MAX);
		result = result * 10 + digit;
		(*i)++;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

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
	result = get_number(str, &i, sign);
	return (result * sign);
}
