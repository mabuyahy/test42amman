/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:16:47 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/03 09:58:52 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char*s, unsigned int start, size_t n)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (n > ft_strlen(s + start))
		n = ft_strlen(s + start);
	sub = ft_calloc(n + 1, 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < n)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}	
/*int	main(void)
{
	char *c = "";
	char *s = ft_substr(c,0,15);
	
	printf("%s", s);

	
	
}*/
