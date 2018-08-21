/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:29:10 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/20 16:29:24 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
