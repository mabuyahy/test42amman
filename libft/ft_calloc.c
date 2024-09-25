/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:11:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/04 10:59:57 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return ((void *)tmp);
}
/*
int main(void)
{
    int *arr;

    arr = (int *)ft_calloc(count, size);
    if (arr == NULL)
    {
        printf("no");
    }
    else 
	    printf("yes");
    return 0;
}
*/
