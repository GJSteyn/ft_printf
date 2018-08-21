/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:34:10 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 13:34:23 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_wstring(t_flags *flags, va_list ap)
{
	flags->arg = (long long)va_arg(ap, wchar_t *);
	if (flags->arg)
	{
		if (ft_wstrlen((wchar_t*)flags->arg))
			flags->out = wstr_to_str(flags);
		else
			flags->out = ft_strnew(1);
	}
	else
		flags->out = ft_strdup("(null)");
}

void		get_float(t_flags *flags, va_list ap)
{
	flags->darg = va_arg(ap, double);
	flags->out = ft_ftoa((double)flags->darg);
}
