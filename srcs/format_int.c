/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:46:19 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/18 18:57:02 by gsteyn           ###   ########.fr       */
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
}

void			format_int(t_flags *flags)
{
	if (flags->precision)
		add_precision(flags);
	add_sign(flags);
	if (flags->width)
		add_padding(flags);
}
