/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:50:47 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 10:56:25 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_dectohex(unsigned int n, char cc)
{
	int		c;
	char	*str;
	int		num;
	char	temp[9];

	c = 0;
	num = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (cc == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	while (n > 0)
	{
		temp[c++] = str[n % 16];
		n = n / 16;
		num++;
	}
	while (c > 0)
		write(1, &temp[--c], 1);
	return (num);
}
/*int	main(void)
{
	int	a;

	a = 450;
	my_dectohex(a, 'X');

	
}*/
