/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:01:07 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/04 18:28:27 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*free_all(char **f, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(f[i]);
		i++;
	}
	free(f);
	return (NULL);
}

static char	*fill_the_word(const char *s, int start, int end)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(end - start + 1);
	if (!c)
		return (NULL);
	while (start < end)
	{
		c[i] = s[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}

static void	no_space(int *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

static int	count_word(const char *s, char c)
{
	int	num;
	int	trigger;
	int	i;

	i = 0;
	num = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			num++;
			trigger = 1;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (num);
}

char	**ft_split(const char *s, char c)
{
	char	**f;
	int		i;
	int		j;
	int		start_word;

	if (!s)
		return (NULL);
	no_space (&i, &j, &start_word);
	f = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!f)
		return (NULL);
	while ((size_t)i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || (size_t)i == ft_strlen(s)) && start_word >= 0)
		{
			f[j] = fill_the_word(s, start_word, i);
			if (!f[j])
				return (free_all(f, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	f[j] = NULL;
	return (f);
}
/*int	main(void)
{
	int	i = 0;
char *c = "l Sed non risus. Suspendisse";
	char **s = ft_split(c , ' ' );
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	}*/
