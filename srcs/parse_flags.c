/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 07:51:49 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/28 15:37:05 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_valid(char c)
{
	if (ft_strchr("-+ #0.*sSpdDioOuUxXcCfF%hljzn", c))
		return (1);
	else if (ft_isdigit(c))
		return (1);
	return (0);
}

void		get_flag(char **fmt, t_flags *flags, va_list ap)
{
	if (**fmt == '+')
		flags->plus = 1;
	else if (**fmt == '-')
		flags->minus = 1;
	else if (**fmt == ' ')
		flags->space = 1;
	else if (**fmt == '#')
		flags->hash = 1;
	else if (**fmt == '0')
		flags->zero = 1;
	else if (**fmt == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->plus)
		flags->sign = plus;
	else if (flags->space)
		flags->sign = space;
	(*fmt)++;
}

void		get_width(char **fmt, t_flags *flags)
{
	flags->width = ft_atoi(*fmt);
	*fmt += ft_intlen(flags->width);
}

void		get_precision(char **fmt, t_flags *flags, va_list ap)
{
	(*fmt)++;
	flags->precision = 1;
	if (ft_isdigit(**fmt))
	{
		flags->precision_len = ft_atoi(*fmt);
		*fmt += ft_intlen(flags->precision_len);
	}
	else if (**fmt == '*')
	{
		flags->precision_len = va_arg(ap, int);
		if (flags->precision_len < 0)
			flags->precision = 0;
		(*fmt)++;
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
	if (flags->len == hh || flags->len == ll)
		*fmt += 2;
	else
		*fmt += 1;
}
