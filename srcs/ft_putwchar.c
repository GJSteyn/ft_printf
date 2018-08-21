/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:49:48 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:14:39 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <wchar.h>

static void		get_out(wchar_t wc, int len, char *out)
{
	if (len == 1)
		return ;
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

void			ft_putwchar(wchar_t wc)
{
	int			len;
	char		out[4];

	len = ft_wcharlen(wc);
	get_out(wc, len, out);
	write(1, out, len);
}
