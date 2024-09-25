/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:07:12 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/07 13:20:08 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*n;

	n = list;
	if (n == NULL)
	{
		return (NULL);
	}
	while (n->next)
	{
		n = n->next;
	}
	return (n);
}
/*int	main(void)
{

	char  *num = "1";
	char *num1  =  "2";
	t_list *list;
	list = ft_lstnew(num);
	ft_lstadd_front(&list, ft_lstnew(num1));
	printf("%s", (char *)ft_lstlast(list));

}*/
