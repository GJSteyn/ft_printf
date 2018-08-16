/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:05:04 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/15 07:25:13 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnstr(char *str, size_t n)
{
	size_t		len;

	if (str)
	{
		len = ft_strlen(str);
		if (len < n)
			write(1, str, len);
		else
			write(1, str, n);
	}
}
