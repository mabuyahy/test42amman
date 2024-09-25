/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:40:36 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/09 10:12:19 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;

	new_list = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
/*
void dell(void *n)
{
	free(n);
}
void *fn(void *content)
{
	char *value = (char *)content;
	cahr *new_value = malloc(ft_strlen(value) + 1));
	if (!new_value)
		return NULL;
	*new_value = *value + 1;
	return (void *)new_value;
}

int	main(void)
{
	t_list *ls;

	char  *num = "1";
	char *num1  =  "2";
	t_list *list;
	list = ft_lstnew(num);
	ft_lstadd_front(&list, ft_lstnew(num1));


	t_list *new_list;
	new_list = tt_lstmap(ls, ,dell);
}*/
