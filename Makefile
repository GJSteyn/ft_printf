# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 16:54:57 by gsteyn            #+#    #+#              #
#    Updated: 2018/08/21 10:33:37 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
SRC =		ft_printf.c ft_atoi.c ft_intlen.c ft_isdigit.c ft_numlen_base.c \
			ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putnstr.c ft_putstr.c \
			ft_strchr.c ft_strclr.c ft_strlen.c flags.c parse_flags.c \
			parse_flags2.c ft_ltoa.c ft_strnew.c ft_itoa_base.c ft_memalloc.c \
			ft_insert.c get_arg.c get_arg2.c ft_strdup.c ft_memcpy.c \
			ft_strdel.c ft_strjoin.c ft_strfill.c format_int.c format_u_int.c \
			ft_strsub.c format_string.c format_hex.c format_oct.c \
			format_point.c format_percent.c format_char.c ft_putwchar.c \
			ft_wcharlen.c ft_wstrlen.c ft_putwstr.c get_arg3.c format_arg.c \
			normalize_arg.c format_empty.c wchar_to_str.c wstr_to_str.c \
			ft_ftoa.c format_float.c
SRCS =		$(patsubst %.c, src/%.c, $(SRC))
OBJS =		$(patsubst %.c, bin/%.o, $(SRC))
SRCDIR =	srcs
OBJDIR =	bin
FLAGS =		-Wall -Wextra -Werror
INCLUDES =	-I includes

all: $(NAME)

$(NAME): $(OBJS) test.c
	ar rc $@ $^
	ranlib $(NAME)
	make test

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc test.c -L. ./libftprintf.a $(INCLUDES)
