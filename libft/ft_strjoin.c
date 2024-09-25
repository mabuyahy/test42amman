/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:54:20 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/03 10:22:06 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return(NULL);
	i = 0;
	j = 0;
	join = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = 0;
	return (join);
}
/*int	main(void)
{
	char *s = "hello, ";
	char *c = "world!";
	char *r = ft_strjoin(c, s);
	printf("%s", r);
}*/
