/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:27:43 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/02 10:09:07 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*j;
	char	*str;

	str = (char *)s;
	i = 0;
	j = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			j = &str[i];
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (j);
}
/*int	main()
{
        char    str[50] = "hello, world!";
        printf("%s",ft_strrchr(str, 'l'));
}*/