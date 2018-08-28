/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 07:50:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/28 16:27:26 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->precision_len = 0;
	flags->len = normal;
	flags->sign = none;
	flags->spec = 0;
	flags->out = NULL;
	flags->ret = 0;
}

void		reset_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->precision_len = 0;
	flags->len = normal;
	flags->sign = none;
	flags->spec = 0;
	if (flags->out)
		ft_strdel(&(flags->out));
	flags->out = NULL;
}
