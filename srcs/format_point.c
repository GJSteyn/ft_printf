/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:06:43 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:13:22 by gsteyn           ###   ########.fr       */
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
	if (pad_len && flags->hash)
		pad_len -= 2;
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

static void		add_prefix(t_flags *flags)
{
	char		*tmp;

	tmp = flags->out;
	flags->out = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	flags->hash = 0;
}

void			format_point(t_flags *flags)
{
	if (flags->precision && !flags->arg)
	{
		flags->out[0] = '\0';
		add_precision(flags);
		add_prefix(flags);
		add_padding(flags);
		return ;
	}
	flags->hash = 1;
	if (!flags->precision && !flags->zero)
		add_prefix(flags);
	if (flags->hash && flags->precision)
		add_precision(flags);
	if (flags->arg && flags->hash)
		add_prefix(flags);
	if (flags->width)
		add_padding(flags);
	if (flags->hash && flags->zero)
		add_prefix(flags);
}
