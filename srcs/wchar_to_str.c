/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:57:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:17:25 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_out(wchar_t wc, int len, char *out)
{
	if (len == 1)
		out[0] = wc;
	if (len == 2)
	{
		out[0] = (wc >> 6) | 0xc0;
		out[1] = (wc & 0x3f) | 0x80;
	}
	else if (len == 3)
	{
		out[0] = (wc >> 12) | 0xe0;
		out[1] = ((wc >> 6) & 0x3f) | 0x80;
		out[2] = (wc & 0x3f) | 0x80;
	}
	else if (len == 4)
	{
		out[0] = (wc >> 18) | 0xf0;
		out[1] = ((wc >> 12) & 0x3f) | 0x80;
		out[2] = ((wc >> 6) & 0x3f) | 0x80;
		out[3] = (wc & 0x3f) | 0x80;
	}
}

char			*wchar_to_str(t_flags *flags)
{
	int			len;
	char		*out;

	len = ft_wcharlen(flags->arg);
	out = ft_strnew(len);
	get_out(flags->arg, len, out);
	return (out);
}
