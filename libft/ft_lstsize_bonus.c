/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:08:14 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/09 12:58:51 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list	*list)
{
	int		i;
	t_list	*n;

	n = list;
	i = 0;
	while (n)
	{
		i++;
		n = n->next;
	}
	return (i);
}
/*int   main(void)
{
        char  *num = "1";
        char *num1  =  "2";
        t_list *list;
        list = ft_lstnew(num);
        ft_lstadd_front(&list, ft_lstnew(num1));



        printf("%d", ft_lstsize(list));
}*/
