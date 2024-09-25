/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/02 17:08:57 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char str1[] = "abcdef";
    char str2[] = "abcdez";
    int result;

    result = ft_memcmp(str1, str2, 6);
    if (result < 0)
        printf("str1 is less than str2\n");
    else if (result > 0)
        printf("str1 is greater than str2\n");
    else
        printf("str1 is equal to str2\n");

    result = ft_memcmp(str1, str2, 5);
    if (result < 0)
        printf("str1 is less than str2\n");
    else if (result > 0)
        printf("str1 is greater than str2\n");
   else
        printf("str1 is equal to str2\n");

    return 0;
}*/
