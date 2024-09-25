/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:10:36 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/09 13:36:56 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*list);
	if (!last)
	{
		*list = new;
		return ;
	}
	last->next = new;
}
/*int	main(void)
{
	t_list *ls;

	char  *num = "1";
	char *num1  =  "2";
	char *num2 = "3";
	t_list *list;
	list = ft_lstnew(num);
	ft_lstadd_front(&list, ft_lstnew(num1));
	ft_lstadd_back(&list, ft_lstnew(num2));

	ls = list;
	while (ls)
	{
		printf("%s", (char *)ls->content);
		ls = ls->next;
	}
}*/
