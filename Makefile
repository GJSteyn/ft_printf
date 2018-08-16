# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 16:54:57 by gsteyn            #+#    #+#              #
#    Updated: 2018/08/16 11:49:51 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
SRC =		ft_printf.c ft_atoi.c ft_intlen.c ft_isdigit.c ft_numlen_base.c \
			ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putnstr.c ft_putstr.c \
			ft_strchr.c ft_strclr.c ft_strlen.c
SRCS =		$(patsubst %.c, src/%.c, $(SRC))
OBJS =		$(patsubst %.c, bin/%.o, $(SRC))
SRCDIR =	srcs
OBJDIR =	bin
FLAGS =		-Wall -Wextra -Werror
INCLUDES =	-I includes

all: $(NAME)

$(NAME): $(OBJS) #srcs/main.c
	ar rc $@ $^
	ranlib $(NAME)
	#make test

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc srcs/main.c -L. ./libftprintf.a $(INCLUDES)
