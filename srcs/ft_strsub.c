/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:17:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 14:04:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (s)
	{
		ret = ft_strnew(len);
		if (!ret)
			return (NULL);
		while (i < len)
		{
			ret[i] = s[i + start];
			i++;
		}
		return (ret);
	}
	return (NULL);
}
