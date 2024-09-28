/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:29:57 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/28 11:44:40 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	find_endline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	add(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!(find_endline (*list)))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read || char_read == -1)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_lline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	creat_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_lline = gebline(list);
	last_stuff(&list);
	return (next_lline);
}

/*int	main(void)
{
	char	*line;
	int	fd;
	int	i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		free(line);
		i++;
	}
	return (0);
}*/
