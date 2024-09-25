/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:45:12 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/04 19:47:47 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c[12];
	long	i;

	num = n;
	i = 0;
	if (num == 0)
	{
		write(fd, "0", 1);
	}
	if (num < 0)
	{
		num = num * -1;
		write(fd, "-", 1);
	}
	while (num > 0)
	{
		c[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	while (i > 0)
	{
		write(fd, &c[i-- - 1], 1);
	}
}
