 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:24:13 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 17:08:37 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char		*s;
	char			*d;

	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (d < s || d >= s + n)
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
/*#include <stdio.h>
int     main()
{
	char c[50] = "Hello Worldiiii"; 
	ft_memmove(c+6, c, 7);
	printf("%s\n", c);
}*/
