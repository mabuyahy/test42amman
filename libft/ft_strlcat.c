/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:08:41 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/04 10:59:26 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		dl;
	int			sl;
	int			j;

	j = 0;
	i = ft_strlen(dest);
	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	if (size <= dl)
	{
		return (sl + size);
	}
	while (src[j] && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (sl + dl);
}
/*int	main()
  {
  char dest[20] = "a";

  size_t result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 20);
  printf("%s\n", dest);
  printf("%zu\n", result);
  return 0;
  }*/
