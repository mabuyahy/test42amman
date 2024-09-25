/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:47:27 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/09 12:52:30 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (lst && newlst)
	{
		newlst->next = *lst;
		*lst = newlst;
	}
}
/*int	main(void)
{
	t_list *ls;

	char  *num = "1";
	char *num1  =  "2";
	t_list *list;
	list = ft_lstnew(num);
	ft_lstadd_front(&list, ft_lstnew(num1));


	ls = list;
	while (ls)
	{
		printf("%s", (char *)ls->content);
		ls = ls->next;
	}
}*/
