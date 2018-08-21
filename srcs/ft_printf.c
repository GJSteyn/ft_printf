/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 05:47:36 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>

size_t			print_arg(t_flags *flags, va_list ap)
{
	size_t		ret;

	ret = 0;
	if (flags->spec)
	{
		normalize_arg(flags);
		get_arg(flags, ap);
	}
	else
		flags->out = ft_strnew(1);
	format_arg(flags);
	if (flags->spec == 'c' && !flags->arg)
	{
		ret = ft_putstr(flags->out) + 1;
		ft_putchar(flags->arg);
	}
	else
		ret = ft_putstr(flags->out);
	return (ret);
}

int			ft_printf(const char *fmt, ...)
{
	size_t			ret;
	va_list			ap;
	t_flags			flags;
	char			*cpy;
	char			*place;

	ret = 0;
	cpy = (char*)fmt;
	place = cpy;
	va_start(ap, fmt);
	init_flags(&flags);
	while (*cpy)
	{
		if (*cpy == '%')
		{
			ret += cpy - place;
			ft_putnstr(place, cpy - place);
			get_flags(&cpy, &flags, ap);
			ret += print_arg(&flags, ap);
			reset_flags(&flags);
			place = cpy;
			continue ;
		}
		if (*cpy)
			cpy++;
	}
	reset_flags(&flags);
	ret += cpy - place;
	ft_putnstr(place, cpy - place);
	va_end(ap);
	return (ret);
}
