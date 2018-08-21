/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:46:05 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 13:44:31 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		backwards_insert(long long in, int index, char *str)
{
	while (in)
	{
		str[index--] = (in % 10) + '0';
		in /= 10;
	}
}

char			*ft_ftoa(double f)
{
	char		*ret;
	long long	conv;
	int			i;

	i = 0;
	ret = ft_memalloc(64);
	if (f < 0.0)
	{
		ret[i++] = '-';
		f = -f;
	}
	conv = (long long)f;
	i += ft_intlen(conv);
	backwards_insert(conv, i - 1, ret);
	ret[i++] = '.';
	conv = (long long)(f * 1000000) - ((long long)f * 1000000);
	i += ft_intlen(conv);
	backwards_insert(conv, i - 1, ret);
	ret[i + 1] = '\0';
	return (ret);
}
