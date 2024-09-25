/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:10:36 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 17:39:46 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_count(int r);

static void	no_space(long *num, long *i, long *temp, int *nb)
{
	*num = (long)*nb;
	*i = 0;
	*temp = num_count(*nb);
}

int	my_putnbr(int nb)
{
	long	num;
	char	c[14];
	long	i;
	long	temp;

	no_space(&num, &i, &temp, &nb);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		num = num * -1;
		write(1, "-", 1);
	}
	while (num > 0)
	{
		c[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	while (i > 0)
		write(1, &c[i-- - 1], 1);
	return (temp);
}

static int	num_count(int i)
{
	int	num;

	num = 0;
	if (i < 0)
		num++;
	while (i != 0)
	{
		num++;
		i /= 10;
	}
	return (num);
}
