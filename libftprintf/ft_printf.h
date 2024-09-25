/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:24:24 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/09/14 10:53:52 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		my_putunbr(unsigned int nb);
int		my_putchr(char c);
int		my_dectohex(unsigned int n, char cc);
int		ft_printf(const char *format, ...);
int		my_putnbr(int nb);
int		my_putpointer(unsigned long r);
int		my_putstr(char *str);
int		my_dectohexp(unsigned long n);

#endif
