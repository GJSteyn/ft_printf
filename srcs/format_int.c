/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:46:19 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:19:47 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (flags->zero && !flags->precision && !flags->minus)
		cp = '0';
	if ((size_t)flags->width > ft_strlen(flags->out))
		pad_len = flags->width - ft_strlen(flags->out);
	if (pad_len && flags->zero && flags->sign)
		pad_len--;
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

static void		add_sign(t_flags *flags)
{
	char		*tmp;

	tmp = flags->out;
	if (flags->sign == plus)
	{
		flags->out = ft_strjoin("+", tmp);
		ft_strdel(&tmp);
	}
	else if (flags->sign == minus)
	{
		flags->out = ft_strjoin("-", tmp);
		ft_strdel(&tmp);
	}
	else if (flags->sign == space)
	{
		flags->out = ft_strjoin(" ", tmp);
		ft_strdel(&tmp);
	}
	flags->sign = none;
}

static void		take_sign(t_flags *flags)
{
	char		*tmp;

	tmp = flags->out;
	flags->out = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
	ft_strdel(&tmp);
	flags->sign = minus;
}

void			format_int(t_flags *flags)
{
	if (flags->precision && !flags->precision_len && !flags->arg)
	{
		flags->out[0] = '\0';
		add_padding(flags);
		return ;
	}
	if (flags->out[0] == '-')
		take_sign(flags);
	if (flags->precision)
		add_precision(flags);
	if (!flags->zero)
		add_sign(flags);
	if (flags->width)
		add_padding(flags);
	if (flags->zero)
		add_sign(flags);
}
