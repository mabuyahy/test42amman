/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:43:22 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/08/29 14:22:08 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*tsrc;
	char		*tdest;
	size_t		i;

	i = 0;
	tdest = (char *)dest;
	tsrc = (const char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
    char c[50] = "Hello, World!";
    char s[50];
    
    ft_memcpy(s, c, 12);
    
    printf("%s\n", s); 
    
    return 0;
}*/
