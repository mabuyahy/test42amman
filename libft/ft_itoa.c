/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:36:43 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/04 18:58:46 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	numlen(long nbr);
static char	*my_malloc(int len);

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		len;
	int		i;

	nbr = n;
	len = numlen(nbr);
	result = my_malloc(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}

static char	*my_malloc(int len)
{
	char	*tmp;

	tmp = malloc((len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

static int	numlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
/*int	main(void)
{
	int	num = 12345;
	printf("%s", ft_itoa(num));
	return (0);
}*/
