/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:20:06 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 17:42:45 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_count(unsigned int r);

static void	my_ttputunbr(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = (n + 48);
		write(1, &c, 1);
	}
	else
	{
		my_ttputunbr(n / 10);
		my_ttputunbr(n % 10);
	}
}

int	my_putunbr(unsigned int n)
{
	my_ttputunbr(n);
	return (num_count(n));
}

static int	num_count(unsigned int i)
{
	int	num;

	num = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		num++;
		i /= 10;
	}
	return (num);
}
/*int	main(void)
  {
  int	i;

  i = -700000000;
  my_putunbr(i);
  }*/
