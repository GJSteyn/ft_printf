/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:42:49 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/18 17:06:02 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_hex(t_flags *flags, va_list ap)
{
	int			upper;

	upper = 0;
	if (flags->spec == 'X')
		upper = 1;
	flags->arg = (unsigned long long)va_arg(ap, unsigned long long);
	if (flags->len == normal)
		flags->out = ft_itoa_base((unsigned int)flags->arg, 16, upper);
	else if (flags->len == hh)
		flags->out = ft_itoa_base((unsigned char)flags->arg, 16, upper);
	else if (flags->len == h)
		flags->out = ft_itoa_base((unsigned short)flags->arg, 16, upper);
	else if (flags->len == l)
		flags->out = ft_itoa_base((unsigned long)flags->arg, 16, upper);
	else if (flags->len == ll)
		flags->out = ft_itoa_base((unsigned long long)flags->arg, 16, upper);
	else if (flags->len == j)
		flags->out = ft_itoa_base((intmax_t)flags->arg, 16, upper);
	else if (flags->len == z)
		flags->out = ft_itoa_base((size_t)flags->arg, 16, upper);
}

void		get_oct(t_flags *flags, va_list ap)
{
	flags->arg = (unsigned long long)va_arg(ap, unsigned long long);
	if (flags->len == normal)
		flags->out = ft_itoa_base((unsigned int)flags->arg, 8, 0);
	else if (flags->len == hh)
		flags->out = ft_itoa_base((unsigned char)flags->arg, 8, 0);
	else if (flags->len == h)
		flags->out = ft_itoa_base((unsigned short)flags->arg, 8, 0);
	else if (flags->len == l)
		flags->out = ft_itoa_base((unsigned long)flags->arg, 8, 0);
	else if (flags->len == ll)
		flags->out = ft_itoa_base((unsigned long long)flags->arg, 8, 0);
	else if (flags->len == j)
		flags->out = ft_itoa_base((intmax_t)flags->arg, 8, 0);
	else if (flags->len == z)
		flags->out = ft_itoa_base((size_t)flags->arg, 8, 0);
}

void		get_point(t_flags *flags, va_list ap)
{
	flags->arg = (unsigned long long)va_arg(ap, unsigned long long);
	flags->out = ft_itoa_base((unsigned long long)flags->arg, 16, 0);
}

void		get_percent(t_flags *flags)
{
	flags->out = ft_strnew(1);
	flags->out[0] = '%';
}
