/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 07:53:49 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/28 15:37:42 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flags(char **fmt, t_flags *flags, va_list ap)
{
	(*fmt)++;
	while (is_valid(**fmt))
	{
		if (!**fmt)
			return ;
		if (ft_strchr("sSpdDioOuUxXcCfF%n", **fmt))
		{
			flags->spec = *((*fmt)++);
			return ;
		}
		if (ft_strchr("-+ #0*", **fmt))
			get_flag(fmt, flags, ap);
		else if (ft_isdigit(**fmt) && **fmt != '0')
			get_width(fmt, flags);
		else if (**fmt == '.')
			get_precision(fmt, flags, ap);
		else if (ft_strchr("hljz", **fmt))
			get_len(fmt, flags);
	}
	if (!flags->spec)
		flags->arg = *((*fmt)++);
}
