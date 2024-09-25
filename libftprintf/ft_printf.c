/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:22:29 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 12:19:58 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatt(va_list *args, const char dd);

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	num;
	va_list	args;

	num = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			num += formatt(&args, format[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			num++;
			i++;
		}
	}
	va_end(args);
	return (num);
}

static int	formatt(va_list *args, const char sbs)
{
	int	num;

	num = 0;
	if (sbs == '%')
		num = my_putchr('%');
	else if (sbs == 'c')
		num = my_putchr(va_arg(*args, int));
	else if (sbs == 's')
		num = my_putstr(va_arg(*args, char *));
	else if (sbs == 'i' || sbs == 'd')
		num = my_putnbr(va_arg(*args, int));
	else if (sbs == 'u')
		num = my_putunbr(va_arg(*args, unsigned int));
	else if (sbs == 'x')
		num = my_dectohex(va_arg(*args, unsigned int), 'x');
	else if (sbs == 'X')
		num = my_dectohex(va_arg(*args, unsigned int), 'X');
	else if (sbs == 'p')
		num += my_putpointer(va_arg(*args, unsigned long));
	return (num);
}
/*
int	main(void)
{
	ft_printf("hello %s", "mohammed");
	return (0);
}
*/
