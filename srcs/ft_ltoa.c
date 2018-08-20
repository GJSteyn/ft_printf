/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 07:58:47 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 10:37:24 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_ltoa(intmax_t c)
{
	char	*ret;
	int		len;

	len = ft_intlen(c);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	if (c == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	ft_insert(&ret, len, c);
	return (ret);
}
