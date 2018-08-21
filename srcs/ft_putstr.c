/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:07:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 09:19:07 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

size_t		ft_putstr(char const *s)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		return (len);
	}
	return (0);
}
