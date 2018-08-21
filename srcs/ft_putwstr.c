/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:24:01 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:18:45 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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

static void		get_out(wchar_t *wstr, char *out)
{
	int			len;

	while (*wstr)
	{
		len = ft_wcharlen(*wstr);
		out_bytes(*wstr, len, out);
		out += len;
		wstr++;
	}
}

void			ft_putwstr(wchar_t *wstr)
{
	size_t		len;
	char		*out;

	len = ft_wstrlen(wstr);
	out = ft_memalloc(len);
	get_out(wstr, out);
	write(1, out, len);
	ft_strdel(&out);
}
