/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:34:10 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/20 17:03:06 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_wstring(t_flags *flags, va_list ap)
{
	flags->arg = (long long)va_arg(ap, wchar_t *);
	flags->out = wstr_to_str(flags);
}
