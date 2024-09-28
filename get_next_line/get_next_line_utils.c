/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:59:30 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/28 11:45:43 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(t_list **list, t_list *new_list, char *buf)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (new_list->str_buf[0])
	{
		*list = new_list;
	}
	else
	{
		free(buf);
		free(new_list);
	}
}	

void	last_stuff(t_list **list)
{
	t_list	*last_list;
	t_list	*new_list;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	new_list = malloc(sizeof(t_list));
	if (buf == NULL || new_list == NULL)
		return ;
	last_list = ft_lstlast (*list);
	i = 0;
	j = 0;
	while (last_list->str_buf[i] && last_list->str_buf[i] != '\n')
		++i;
	while (last_list->str_buf[i] && last_list->str_buf[++i])
		buf[j++] = last_list->str_buf[i];
	buf[j] = '\0';
	new_list->str_buf = buf;
	new_list->next = NULL;
	free_all(list, new_list, buf);
}

void	cpy(t_list *list, char	*str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_endline(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}	
	return (len);
}

char	*gebline(t_list *list)
{
	int		str_len;
	char	*f_str;

	str_len = len_to_endline(list);
	f_str = malloc(str_len + 1);
	if (NULL == f_str)
		return (NULL);
	cpy(list, f_str);
	return (f_str);
}
