/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:29:57 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/25 15:24:23 by mabuyahy         ###   ########.fr       */
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

char	*next_line(t_list *list)
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
		if (!char_read)
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
	next_lline = next_line(list);
	last_stuff(&list);
	return (next_lline);
}

/*int	main(void)
{
	char	*line;
	int	fd[3];
	int	i;

	i = 0;
	fd[0] = open("text1.txt",O_RDONLY);
	fd[1] = open("text2.txt",O_RDONLY);
	fd[2] = open("text3.txt",O_RDONLY);
	while((line = get_next_line(fd[i])) != NULL)
	{
		printf("%s",line);
		free(line);
		i++;
	}
	while(i--)
	close(fd[i]);
	return (0);
}*/
