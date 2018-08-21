/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:51:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:18:55 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int			ft_wcharlen(wchar_t wc)
{
	if (wc <= 0x7f)
		return (1);
	if (wc <= 0x7ff)
		return (2);
	if (wc <= 0xffff)
		return (3);
	if (wc <= 0x10ffff)
		return (4);
	return (0);
}
