/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:19:31 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/25 13:18:58 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

void	free_all(t_list **list, t_list *new_list, char *buf);
void	last_stuff(t_list **list);
void	cpy(t_list *list, char *buf);
int		len_to_endline(t_list	*list);
char	*next_line(t_list *list);
t_list	*ft_lstlast(t_list *list);
int		find_endline(t_list *list);
void	add(t_list **list, char *buf);
void	creat_list(t_list **list, int fd);
char	*get_next_line(int fd);
#endif
