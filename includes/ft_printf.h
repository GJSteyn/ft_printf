/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:45:18 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/19 14:25:59 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_L "0123456789abcdef"
# define BASE_U "0123456789ABCDEF"

# include <string.h>
# include <inttypes.h>
# include <stdarg.h>
# include <wchar.h>

typedef enum			e_len
{
	normal,
	h,
	hh,
	l,
	ll,
	j,
	z
}						t_len;

typedef enum			e_sign
{
	none,
	plus,
	minus,
	space
}						t_sign;

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
	t_sign				sign;
	char				spec;
	long long			arg;
	char				*out;
}						t_flags;

int						ft_printf(const char *fmt, ...);

void					init_flags(t_flags *flags);
void					reset_flags(t_flags *flags);

int						is_valid(char c);
void					get_flag(char **fmt, t_flags *flags);
void					get_width(char **fmt, t_flags *flags);
void					get_precision(char **fmt, t_flags *flags);
void					get_len(char **fmt, t_flags *flags);
void					get_flags(char **fmt, t_flags *flags);

void					get_arg(t_flags *flags, va_list ap);
void					get_char(t_flags *flags, va_list ap);
void					get_int(t_flags *flags, va_list ap);
void					get_u_int(t_flags *flags, va_list ap);
void					get_string(t_flags *flags, va_list ap);
void					get_hex(t_flags *flags, va_list ap);
void					get_oct(t_flags *flags, va_list ap);
void					get_point(t_flags *flags, va_list ap);
void					get_percent(t_flags *flags);

void					format_int(t_flags *flags);
void					format_u_int(t_flags *flags);
void					format_string(t_flags *flags);
void					format_hex(t_flags *flags);
void					format_oct(t_flags *flags);
void					format_point(t_flags *flags);
void					format_percent(t_flags *flags);
void					format_char(t_flags *flags);

char					*ft_ltoa(long long c);
char					*ft_strnew(size_t size);
void					ft_insert(char **s, int index, long long c);
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
char					*ft_itoa_base(long long n, int b, int up);
void					*ft_memalloc(size_t size);
char					*ft_strdup(const char *s1);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					ft_strdel(char **as);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strfill(char *str, char f, int n);
char					*ft_strsub(char const *s, unsigned int start, size_t len);
void					ft_putwchar(wchar_t wc);
int						ft_wcharlen(wchar_t wc);
size_t					ft_wstrlen(wchar_t *wstr);
void					ft_putwstr(wchar_t *wstr);

#endif
