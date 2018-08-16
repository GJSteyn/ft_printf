/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/16 14:00:16 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void		init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->precision_len = 0;
	flags->len = normal;
	flags->spec = 0;
}

int			is_valid(char c)
{
	if (ft_strchr("-+ #0.sSpdDioOuUxXcC%hljz", c))
		return (1);
	else if (ft_isdigit(c))
		return (1);
	return (0);
}

void		get_flag(char c, t_flags *flags)
{
	if (c == '+')
		flags->plus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '0')
		flags->zero = 1;
}

void		get_width(char **fmt, t_flags *flags)
{
	flags->width = ft_atoi(*fmt);
	*fmt += ft_intlen(flags->width);
}

void		get_precision(char **fmt, t_flags *flags)
{
	(*fmt)++;
	flags->precision = 1;
	if (ft_isdigit(**fmt))
	{
		flags->precision_len = ft_atoi(*fmt);
		*fmt += ft_intlen(flags->precision_len);
	}
}

void		get_len(char **fmt, t_flags *flags)
{
	if (**fmt == 'h' && *((*fmt) + 1) == 'h')
		flags->len = hh;
	else if (**fmt == 'h')
		flags->len = h;
	else if (**fmt == 'l' && *((*fmt) + 1) == 'l')
		flags->len = ll;
	else if (**fmt == 'l')
		flags->len = l;
	else if (**fmt == 'j')
		flags->len = j;
	else if (**fmt == 'z')
		flags->len = z;
}

void		get_flags(char **fmt, t_flags *flags)
{
	(*fmt)++;
	while (is_valid(**fmt))
	{
		if (ft_strchr("sSpdDioOuUxXcC%", **fmt))
		{
			flags->spec = *((*fmt)++);
			break ;
		}
		if (ft_strchr("-+ #0", **fmt))
			get_flag(**fmt, flags);
		else if (ft_isdigit(**fmt) && **fmt != '0')
			get_width(fmt, flags);
		else if (**fmt == '.')
			get_precision(fmt, flags);
		else if (ft_strchr("hljz", **fmt))
			get_len(fmt, flags);
	}
}

int			ft_printf(const char *fmt, ...)
{
	int				ret;
	va_list			args;
	t_flags			flags;
	char			*cpy;
	char			*place;

	ret = 0;
	cpy = (char*)fmt;
	place = cpy;
	va_start(args, fmt);
	init_flags(&flags);
	while (*cpy)
	{
		if (*cpy == '%')
		{
			ret += cpy - place;
			ft_putnstr(place, cpy - place);
			get_flags(&cpy, &flags);
			ret += print_arg(flags);
			init_flags(&flags);
			place = cpy;
		}
		cpy++;
	}
	va_end(args);
	return (0);
}
