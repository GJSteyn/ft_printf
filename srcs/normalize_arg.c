/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:30:50 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 07:30:28 by gsteyn           ###   ########.fr       */
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
	else if (flags->spec == 'c' && flags->len == l)
		flags->spec = 'C';
	else if (flags->spec == 's' && flags->len == l)
		flags->spec = 'S';
	else if (flags->spec == 'O')
	{
		flags->spec = 'o';
		flags->len = l;
	}
}
