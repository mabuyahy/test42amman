/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:15:42 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/07 10:33:27 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = (t_list *) malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->content = content;
	nlist->next = NULL;
	return (nlist);
}
/*int	main(void)
{
	t_list *dd;
	int n;

	n = 100;
	dd = ft_lstnew(&n);
	printf("%d", *(int *)dd->content);
	free(dd);
}*/