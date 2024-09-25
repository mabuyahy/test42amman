/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:53:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/22 14:40:15 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include <stddef.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*str2 == '\0')
		return ((char *)str1);
	if (n == 0)
		return (NULL);
	i = 0;
	while (str1[i] != '\0' && i < n)
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (str2[j] != '\0' && (i + j) < n && str1[i + j] == str2[j])
				j++;
			if (str2[j] == '\0')
				return ((char *)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
int main(void)
{
    char str1[] = "abcdefgh";
    char str2[] = "abc";
    char *result;

    result = ft_strnstr(str1, str2, 3);
    if (result != NULL)
    printf("%s", result);
    else
        printf("not found");
}

