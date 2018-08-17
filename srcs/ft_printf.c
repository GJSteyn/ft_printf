/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 14:34:03 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

// void		format_char(t_flags *flags)
// {
// 	return ;
// }

static void		add_precision(t_flags *flags)
{
	int			pr_len;
	char		*pr;
	char		*tmp;

	pr_len = 0;
	tmp = flags->out;
	if ((size_t)flags->precision_len > ft_strlen(flags->out))
		pr_len = flags->precision_len - ft_strlen(flags->out);
	if (pr_len)
	{
		pr = ft_strnew(pr_len);
		ft_strfill(pr, '0', pr_len);
		flags->out = ft_strjoin(pr, tmp);
		ft_strdel(&tmp);
		ft_strdel(&pr);
	}
}

static void		add_padding(t_flags *flags)
{
	int		pad_len;
	char	*pad;
	char	*tmp;
	char	cp;

	pad_len = 0;
	tmp = flags->out;
	cp = ' ';
	if (flags->zero && !flags->precision)
		cp = '0';
	if ((size_t)flags->width > ft_strlen(flags->out))
		pad_len = flags->width - ft_strlen(flags->out);
	if (pad_len)
	{
		pad = ft_strnew(pad_len);
		ft_strfill(pad, cp, pad_len);
		if (!flags->minus)
			flags->out = ft_strjoin(pad, tmp);
		else
			flags->out = ft_strjoin(tmp, pad);
		ft_strdel(&tmp);
		ft_strdel(&pad);
	}
}

static void	add_prefix(t_flags *flags)
{
	char		*tmp;

	tmp = flags->out;
	if (flags->spec == 'x')
		flags->out = ft_strjoin("0x", tmp);
	else if (flags->spec == 'X')
		flags->out = ft_strjoin("0X", tmp);
	ft_strdel(&tmp);
	flags->hash = 0;
}

void		format_hex(t_flags *flags)
{
	if (flags->hash && !flags->precision && !flags->zero)
		add_prefix(flags);
	if (flags->precision)
		add_precision(flags);
	if (flags->hash && !flags->zero)
		add_prefix(flags);
	if (flags->width)
		add_padding(flags);
	if (flags->hash && flags->zero)
		add_padding(flags);
}

void		format_arg(t_flags *flags)
{
	if (ft_strchr("cC", flags->spec))
		// format_char(flags);
		;
	else if (ft_strchr("idD", flags->spec))
		format_int(flags);
	else if (ft_strchr("uU", flags->spec))
		format_u_int(flags);
	else if (ft_strchr("sS", flags->spec))
		format_string(flags);
	else if (ft_strchr("xX", flags->spec))
		format_hex(flags);
	else if (ft_strchr("oO", flags->spec))
		// format_oct(flags);
		;
	else if (flags->spec == 'p')
		// format_point(flags);
		;
	else if (flags->spec == '%')
		// format_percent(flags);
		;
}

int			print_arg(t_flags *flags, va_list ap)
{
	get_arg(flags, ap);
	format_arg(flags);
	ft_putstr(flags->out);
	return (ft_strlen(flags->out));
}

int			ft_printf(const char *fmt, ...)
{
	int				ret;
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
		}
		if (*cpy)
			cpy++;
	}
	ft_putnstr(place, cpy - place);
	va_end(ap);
	return (0);
}
