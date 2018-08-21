/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:30:50 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/20 16:31:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			normalize_arg(t_flags *flags)
{
	if (flags->spec == 'U')
	{
		flags->spec = 'u';
		flags->len = ll;
	}
	else if (flags->spec == 'D')
	{
		flags->spec = 'd';
		flags->len = ll;
	}
}
