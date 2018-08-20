/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:24:43 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 11:29:57 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_baselen(uintmax_t n, int base)
{
	int			ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

static void		ft_insert_base(uintmax_t n, int b, int up, char *s)
{
	int			ind;

	ind = ft_baselen(n, b) - 1;
	while (ind >= 0)
	{
		if (up)
			s[ind] = BASE_U[n % b];
		else
			s[ind] = BASE_L[n % b];
		n /= b;
		ind--;
	}
}

char			*ft_itoa_base(uintmax_t n, int base, int upper)
{
	int			len;
	char		*ret;

	len = ft_baselen(n, base);
	ret = ft_strnew(len);
	ft_insert_base(n, base, upper, ret);
	return (ret);
}
