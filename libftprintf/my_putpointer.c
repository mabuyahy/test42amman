/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:36:41 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 11:07:33 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	my_putpointer(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = my_dectohexp(ptr);
	return (i + 2);
}
/*int	main(void)
{

	int i = 120;
	char *s =&i;
	printf("%p", &i);

}*/
