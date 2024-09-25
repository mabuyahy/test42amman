/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dectohexp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:21:37 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 10:55:43 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_dectohexp(unsigned long n)
{
	int		c;
	char	*str;
	int		num;
	char	temp[20];

	c = 0;
	num = 0;
	str = "0123456789abcedf";
	if (n == 0)
	{
		write(1, &str[0], 1);
		num++;
	}
	while (n != 0)
	{
		temp[c] = str[n % 16];
		n = n / 16;
		c++;
		num++;
	}
	while (c)
		write(1, &temp[--c], 1);
	return (num);
}
