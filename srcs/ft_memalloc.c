/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:06:04 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 10:21:06 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = malloc(size);
	if (ret)
	{
		while (i < size)
			((char*)ret)[i++] = 0;
		return (ret);
	}
	else
	{
		free(ret);
		return (NULL);
	}
}
