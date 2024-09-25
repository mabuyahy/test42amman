/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:40:37 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/09 14:03:59 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
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
	ft_lstclear(list);
}*/
