/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:03:16 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/24 07:45:14 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		out_bytes(wchar_t wc, int len, char *out)
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

static void		get_out(wchar_t *wstr, char *out, t_flags *flags)
{
	int			len;
	int			total;

	total = 0;
	while (*wstr)
	{
		len = ft_wcharlen(*wstr);
		total += len;
		if (flags->precision)
			if (total > flags->precision_len)
				break ;
		out_bytes(*wstr, len, out);
		out += len;
		wstr++;
	}
}

char			*wstr_to_str(t_flags *flags)
{
	size_t		len;
	char		*out;

	len = ft_wstrlen((wchar_t*)flags->arg);
	out = ft_memalloc(len + 1);
	get_out((wchar_t*)flags->arg, out, flags);
	return (out);
}
