/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:33:42 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/17 10:19:15 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr_base(intmax_t n, int base)
{
	if (base < 2 || base > 16)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= (long long)base)
	{
		ft_putnbr_base(n / base, base);
		ft_putchar(BASE_L[n % base]);
	}
	else
		ft_putchar(BASE_L[n % base]);
}
