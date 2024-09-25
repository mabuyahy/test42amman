/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:59:37 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/07 18:12:54 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = malloc((ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

/*char ff(unsigned int i, char c)
{
	if (i == 2)
	return (c + 1);
	return (c);
}

int	main(void)
{
	char *s = "amer";
	char *c;
	
	c = ft_strmapi(s, ff);
	printf("%s", c);
}*/
