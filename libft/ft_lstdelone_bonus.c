/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:58:59 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/07 15:11:46 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (del)
	{
		del(node->content);
		free(node);
	}
}
/*
void	del(void *s)
{
	free (s);
}
int	main(void)
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
	ft_lstdelone(list);
}*/