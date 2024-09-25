/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:26:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/07 18:30:20 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	while (list)
	{
		f(list->content);
		list = list->next;
	}
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
	new_list = tt_lstiter(ls,fn,dell);
}*/