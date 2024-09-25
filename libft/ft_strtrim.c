/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:37:14 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/03 15:45:24 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*trim;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	trim = ft_calloc(len + 1, 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], end - start + 2);
	return (trim);
}
/*int	main(void)
{
	char *s = "asdfasdfasffdsaasddfadsfasdfasdfdsasdffdsaasdf";
	char *c = "asfd";
	char *r = ft_strtrim(s,c);
	printf("%s", r);

}*/
