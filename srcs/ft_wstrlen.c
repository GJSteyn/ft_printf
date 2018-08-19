/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:24:29 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/19 14:24:42 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t		ret;

	ret = 0;
	while (*wstr)
		ret += ft_wcharlen(*wstr++);
	return (ret);
}
