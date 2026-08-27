/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-de <ldiaz-de@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:58:00 by ldiaz-de          #+#    #+#             */
/*   Updated: 2026/08/27 18:58:00 by ldiaz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_uint(int fd, unsigned int n)
{
	char	c;

	if (n >= 10)
		write_uint(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	write_percent(int fd, double disorder)
{
	unsigned int	hundredths;
	unsigned int	int_part;
	unsigned int	frac_part;

	hundredths = (unsigned int)(disorder * 10000.0 + 0.5);
	int_part = hundredths / 100;
	frac_part = hundredths % 100;
	write_uint(fd, int_part);
	write(fd, ".", 1);
	if (frac_part < 10)
		write(fd, "0", 1);
	write_uint(fd, frac_part);
}

void	write_field(int fd, const char *label, int count, int is_last)
{
	write(fd, label, ft_strlen(label));
	write(fd, ": ", 2);
	write_uint(fd, (unsigned int)count);
	if (!is_last)
		write(fd, "  ", 2);
}
