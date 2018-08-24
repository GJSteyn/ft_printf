/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:29:10 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/24 07:43:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_padding(t_flags *flags)
{
	int		pad_len;
	char	*pad;
	char	*tmp;
	char	cp;

	pad_len = 0;
	tmp = flags->out;
	cp = ' ';
	if (flags->zero && !flags->minus)
		cp = '0';
	if ((size_t)flags->width > ft_strlen(flags->out))
		pad_len = flags->width - ft_strlen(flags->out);
	if (pad_len && !flags->arg)
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

void			format_empty(t_flags *flags)
{
	if (flags->arg > 32 && flags->arg < 127)
		flags->out[0] = (char)flags->arg;
	if (!flags->minus)
		add_padding(flags);
	if (flags->minus)
		add_padding(flags);
}
