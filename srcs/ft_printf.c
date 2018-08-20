/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/19 17:38:21 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>

void		format_empty(t_flags *flags)
{
	char			*tmp;
	char			pad;

	tmp = flags->out;
	pad = ' ';
	if (flags->zero)
		pad = '0';
	if (flags->width)
	{
		flags->out = ft_strnew(flags->width - 1);
		ft_strfill(flags->out, pad, flags->width - 1);
		ft_strdel(&tmp);
	}
}

void		format_arg(t_flags *flags)
{
	if (!flags->spec)
		format_empty(flags);
	else if (flags->spec == 'c')
		format_char(flags);
	else if (ft_strchr("idD", flags->spec))
		format_int(flags);
	else if (ft_strchr("uU", flags->spec))
		format_u_int(flags);
	else if (ft_strchr("sS", flags->spec))
		format_string(flags);
	else if (ft_strchr("xX", flags->spec))
		format_hex(flags);
	else if (ft_strchr("oO", flags->spec))
		format_oct(flags);
	else if (flags->spec == 'p')
		format_point(flags);
	else if (flags->spec == '%')
		format_percent(flags);
}

// size_t		putwide(t_flags *flags)
// {

// }

void			normalize_arg(t_flags *flags)
{
	if (flags->spec == 'U')
	{
		flags->spec = 'u';
		flags->len = ll;
	}
	else if (flags->spec == 'D')
	{
		flags->spec = 'd';
		flags->len = ll;
	}
}

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
	// if (ft_strchr("CS", flags->spec))
	// 	ret = putwide(flags);
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
			get_flags(&cpy, &flags);
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
