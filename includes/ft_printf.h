/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:18 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/16 12:06:30 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <inttypes.h>
# include <stdarg.h>

typedef enum			e_len
{
	normal,
	h,
	hh,
	l,
	ll,
	j,
	z,
	t
}						t_len;

typedef struct			s_flags
{
	int					plus;
	int					minus;
	int					space;
	int					hash;
	int					zero;
	int					width;
	int					precision;
	int					precision_len;
	t_len				len;
	char				spec;
	long long			arg;
}						t_flags;

int						ft_printf(const char *fmt, ...);

int						ft_atoi(const char *str);
void					ft_putstr(const char *s);
void					ft_putnstr(char *str, size_t n);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
size_t					ft_strlen(const char *s);
void					ft_putnbr(intmax_t n);
void					ft_putnbr_base(intmax_t n, int base);
void					ft_putchar(char c);
int						ft_isdigit(int c);
int						ft_intlen(intmax_t c);

#endif
