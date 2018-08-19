/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:40:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/19 17:33:31 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_arg(t_flags *flags, va_list ap)
{
	if (flags->spec == 'c')
		get_char(flags, ap);
	else if (flags->spec == 'C')
		get_wchar(flags, ap);
	else if (ft_strchr("idD", flags->spec))
		get_int(flags, ap);
	else if (ft_strchr("uU", flags->spec))
		get_u_int(flags, ap);
	else if (flags->spec == 's')
		get_string(flags, ap);
	else if (flags->spec == 'S')
		get_wstring(flags, ap);
	else if (ft_strchr("xX", flags->spec))
		get_hex(flags, ap);
	else if (ft_strchr("oO", flags->spec))
		get_oct(flags, ap);
	else if (flags->spec == 'p')
		get_point(flags, ap);
	else if (flags->spec == '%')
		get_percent(flags);
}

void		get_char(t_flags *flags, va_list ap)
{
	flags->arg = va_arg(ap, int);
	flags->out = ft_strnew(1);
	flags->out[0] = flags->arg;
}

void		get_int(t_flags *flags, va_list ap)
{
	flags->arg = (long long)va_arg(ap, long long);
	if ((int)flags->arg < 0)
	{
		flags->arg *= -1;
		flags->sign = minus;
	}
	if (flags->len == normal)
		flags->out = ft_ltoa((int)flags->arg);
	else if (flags->len == hh)
		flags->out = ft_ltoa((char)flags->arg);
	else if (flags->len == h)
		flags->out = ft_ltoa((short)flags->arg);
	else if (flags->len == l)
		flags->out = ft_ltoa((long)flags->arg);
	else if (flags->len == ll)
		flags->out = ft_ltoa((long long)flags->arg);
	else if (flags->len == j)
		flags->out = ft_ltoa((intmax_t)flags->arg);
	else if (flags->len == z)
		flags->out = ft_ltoa((size_t)flags->arg);
}

void		get_u_int(t_flags *flags, va_list ap)
{
	flags->arg = (unsigned int)va_arg(ap, unsigned int);
	if (flags->len == normal)
		flags->out = ft_ltoa((unsigned int)flags->arg);
	else if (flags->len == hh)
		flags->out = ft_ltoa((unsigned char)flags->arg);
	else if (flags->len == h)
		flags->out = ft_ltoa((unsigned short)flags->arg);
	else if (flags->len == l)
		flags->out = ft_ltoa((unsigned long)flags->arg);
	else if (flags->len == ll)
		flags->out = ft_ltoa((unsigned long long)flags->arg);
	else if (flags->len == j)
		flags->out = ft_ltoa((intmax_t)flags->arg);
	else if (flags->len == z)
		flags->out = ft_ltoa((size_t)flags->arg);
}

void		get_string(t_flags *flags, va_list ap)
{
	char		*tmp;

	tmp = (char *)va_arg(ap, char *);
	if (tmp)
		flags->out = ft_strdup(tmp);
	else
		flags->out = ft_strdup("(null)");
}
