/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:29:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 10:32:08 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_arg(t_flags *flags)
{
	if (!flags->spec)
		format_empty(flags);
	else if (ft_strchr("cC", flags->spec))
		format_char(flags);
	else if (ft_strchr("idD", flags->spec))
		format_int(flags);
	else if (ft_strchr("uU", flags->spec))
		format_u_int(flags);
	else if (ft_strchr("sS", flags->spec))
		format_string(flags);
	else if (ft_strchr("xX", flags->spec))
		format_hex(flags);
	else if (ft_strchr("oO", flags->spec))
		format_oct(flags);
	else if (ft_strchr("fF", flags->spec))
		format_float(flags);
	else if (flags->spec == 'p')
		format_point(flags);
	else if (flags->spec == '%')
		format_percent(flags);
}
