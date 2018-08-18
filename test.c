/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:23:43 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/18 18:29:06 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int				main(void)
// {
// 	char		*cp;
// 	char		c;

// 	c = 'a';
// 	cp = &c;
// 	ft_printf("[%c]\n", 'a');
// 	printf("[%c]\n", 'a');
// 	printf("--------------\n");
// 	ft_printf("[%06.5d]\n", 10);
// 	printf("[%06.5d]\n", 10);
// 	printf("--------------\n");
// 	ft_printf("[%06.5u]\n", -10);
// 	printf("[%06.5u]\n", -10);
// 	printf("--------------\n");
// 	ft_printf("[%-010.3s]\n", "Hello");
// 	printf("[%-010.3s]\n", "Hello");
// 	printf("--------------\n");
// 	ft_printf("[%#015x]\n", -500);
// 	printf("[%#015x]\n", -500);
// 	printf("--------------\n");
// 	ft_printf("[%X]\n", 500);
// 	printf("[%X]\n", 500);
// 	printf("--------------\n");
// 	ft_printf("[%#-10o]\n", 500);
// 	printf("[%#-10o]\n", 500);
// 	printf("--------------\n");
// 	ft_printf("[%020p]\n", cp);
// 	printf("[%020p]\n", cp);
// 	printf("--------------\n");
// 	ft_printf("[%.5%]\n");
// 	printf("[%.5%]\n");

// 	return (0);
// }

// int			main(void)
// {
	// int		one;
	// int		two;
	// int		*test;

	// test = &one;
	// one = printf("their[Hello %d%d%d%d%d%d%d%d%d %d] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// two = ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d %d] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// printf("One: %d\n", one);
	// printf("Two: %d\n", two);

// 	printf("their[Hello %d%d%d%d%d%d%d%d%d %d] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
// 	ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d %d] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
// 	printf("their[Hello %s %s %s] \n", "this is going to be one", "massive string, likke", "a huge one, a very long long long l ong one!");
// 	ft_printf("minee[Hello %s %s %s] \n", "this is going to be one", "massive string, likke" ,"a huge one, a very long long long l ong one!");
// 	printf("their[Hello %s %x HELLO] \n", "this is going", 56498);
// 	ft_printf("minee[Hello %s %x HELLO] \n", "this is going", 56498);

// 	printf("their[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');
// 	ft_printf("minee[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');


// 	printf("their [%-10d] \n", 10);
// 	ft_printf("minee [%-10d] \n", 10);

// 	printf("their[[% 23m] [%m] %20d% 1s] \n", -100, "hello");
// 	ft_printf("minee[[% 23m] [%m] %20d% 1s] \n", -100, "hello");
// 	printf("their[%20d  ] \n", -100);
// 	ft_printf("minee[%20d  ] \n", -100);
// 	printf("their[% 020d] \n", -100);
// 	ft_printf("minee[% 020d] \n", -100);
// 	printf("their[%020d] \n", 100);
// 	ft_printf("minee[%020d] \n", 100);
// 	printf("their[% 20d] \n", 100);
// 	ft_printf("minee[% 20d] \n", 100);
// 	printf("their[% 020-d] \n", 100);
// 	ft_printf("minee[% 020-d] \n", 100);
// 	printf("their[%20d] \n", 100);
// 	ft_printf("minee[%20d] \n", 100);
// 	printf("---------------------\n");
// 	printf("their[%020s] \n", "-100");
// 	ft_printf("minee[%020s] \n", "-100");
// 	printf("their[% 20s] \n", "-100");
// 	ft_printf("minee[% 20s] \n", "-100");
// 	printf("their[% 020s] \n", "-100");
// 	ft_printf("minee[% 020s] \n", "-100");
// 	printf("their[%020s] \n", "100");
// 	ft_printf("minee[%020s] \n", "100");
// 	printf("their[% 20s] \n", "100");
// 	ft_printf("minee[% 20s] \n", "100");
// 	printf("their[% 020s] \n", "100");
// 	ft_printf("minee[% 020s] \n", "100");
// 	printf("their[%20s] \n", "100");
// 	ft_printf("minee[%20s] \n", "100");
// 	printf("their %#x \n", 10);
// 	ft_printf("minee %#x \n", 10);
// 	printf("their %#X \n", 10);
// 	ft_printf("minee %#X \n", 10);
// 	printf("their %#o \n", 10);
// 	ft_printf("minee %#o \n", 10);
// 	printf("their [%s]\n", NULL);
// 	ft_printf("minee [%s]\n", NULL);

// 	printf("%.5d\n", 5000);
// 	ft_printf("%.5d\n", 5000);
// 	int		i;
// 	i = 5;
// 	int		*t = &i;
// 	printf("%20p\n", t);
// 	ft_printf("%020p\n", t);
// 	printf("---------------------\n");
// 	printf("their[%020.5p] \n", t);
// 	ft_printf("minee[%020.5p] \n", t);

// 	return (0);
// }
int		main(void)
{
	char	*p;
	int		oen;

	p = 'a';
	// printf("---------------------\n");
	// printf("their[%010.5s] [%.8s] [%.2s] \n","hellooooo", "hello", "HIfriends ");
	// ft_printf("minee[%010.5s] [%.8s] [%.2s]\n","hellooooo", "hello", "HIfriends ");
	// printf("---------------------\n");
	printf("their[%+023.5d] [%.8d] [%.2d] \n", -100, 3241,  10);
	ft_printf("minee[%+023.5d] [%.8d] [%.2d] \n", -100, 3241,  10);
	printf("---------------------\n");
	printf("their[%023.5c] \n", 'a');
	ft_printf("minee[%023.5c] \n", 'a');

	// printf("---------------------\n");
	// printf("their[%#023.5X] \n", 100);
	// ft_printf("minee[%#023.5X] \n", 100);
	printf("---------------------\n");
	printf("their[%#023.5o] \n", 100);
	ft_printf("minee[%#023.5o] \n", 100);
	printf("---------------------\n");
	printf("their[%#023.1o] \n", 100);
	ft_printf("minee[%#023.1o] \n", 100);
	printf("---------------------\n");
	printf("their[%#5o] \n", 100);
	ft_printf("minee[%#5o] \n", 100);
	printf("---------------------\n");
	printf("their[%5o] \n", 100);
	ft_printf("minee[%5o] \n", 100);
	printf("---------------------\n");
	printf("their[%.5o] \n", 100);
	ft_printf("minee[%.5o] \n", 100);

	// printf("---------------------\n");
	// printf("their[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// oen = ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);

	// printf("---------------------\n");
	// printf("their[Hello %s %s %s] \n", "this is going to be one", "massive string, likke", "a huge one, a very long long long l ong one!");
	// ft_printf("minee[Hello %s %s %s] \n", "this is going to be one", "massive string, likke" ,"a huge one, a very long long long l ong one!");
	// printf("---------------------\n");
	// printf("their[Hello %s %x HELLO] \n", "this is going", 56498);
	// ft_printf("minee[Hello %s %x HELLO] \n", "this is going", 56498);


	// printf("---------------------\n");
	// printf("their[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');
	// ft_printf("minee[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');

	// printf("---------------------\n");
	// printf("their [%-10d] \n", 10);
	// ft_printf("minee [%-10d] \n", 10);
	// printf("---------------------\n");
   	// printf("their[[% 23m] [%m] %20d% 1s] \n",  -100, "hello");
	// ft_printf("minee[[% 23m] [%m] %20d% 1s] \n",  -100, "hello");
	// printf("---------------------\n");
	// printf("their[%20d  ] \n",  -100);
	// ft_printf("minee[%20d  ] \n",  -100);
	// printf("---------------------\n");
	// printf("their[% 020d] \n",  -100);
	// ft_printf("minee[% 020d] \n",  -100);
	// printf("---------------------\n");
	// printf("their[%020d] \n",  100);
	// ft_printf("minee[%020d] \n",  100);
	// printf("---------------------\n");
	// printf("their[% 20d] \n",  100);
	// ft_printf("minee[% 20d] \n",  100);

	// printf("their[%20d] \n",  100);
	// ft_printf("minee[%20d] \n",  100);
	// printf("---------------------\n");
	// printf("their[%020s] \n",  "-100");
	// ft_printf("minee[%020s] \n",  "-100");
	// printf("---------------------\n");
	// printf("their[% 20s] \n",  "-100");
	// ft_printf("minee[% 20s] \n",  "-100");
	// printf("---------------------\n");
	// printf("their[% 020s] \n",  "-100");
	// ft_printf("minee[% 020s] \n",  "-100");
	// printf("---------------------\n");
	// printf("their[%020s] \n",  "100");
	// ft_printf("minee[%020s] \n",  "100");
	// printf("---------------------\n");
	// printf("their[% 20s] \n",  "100");
	// ft_printf("minee[% 20s] \n",  "100");
	// printf("---------------------\n");
	// printf("their[% 020s] \n",  "100");
	// ft_printf("minee[% 020s] \n",  "100");
	// printf("---------------------\n");
	// printf("their[%20s] \n",  "100");
	// ft_printf("minee[%20s] \n",  "100");
	// printf("---------------------\n");
    // printf("their %#x \n", 10);
	// ft_printf("minee %#x \n", 10);
	// printf("---------------------\n");
	// printf("their %#X \n", 10);
	// ft_printf("minee %#X \n", 10);
	// printf("---------------------\n");
    // printf("their %#o \n", 10);
	// ft_printf("minee %#o \n", 10);
	// printf("---------------------\n");
	// printf("their [%10s]\n", NULL);
	// ft_printf("minee [%10s]\n", NULL);
	// printf("---------------------\n");
	// printf("their[% 020d] \n", -100);
	// ft_printf("minee[% 020d] \n", -100);
	// printf("---------------------\n");
	// printf("their[% 020d] \n",  100);
	// ft_printf("minee[% 020d] \n",  100);
	// printf("---------------------\n");	
	// printf("their[% 020-d] \n",  100);
	// ft_printf("minee[% 020-d] \n",  100);
	// int		i;
	// i = 5;
	// int		*t = &i;

	// printf("---------------------\n");
	// printf("their[%020.5p] \n", p);
	// ft_printf("minee[%020.5p] \n", p);

	// printf("---------------------\n");
	// printf("%20p\n", t);
	// ft_printf("%20p\n", t);
	// printf("---------------------\n");
	// printf("their[%020.5p] \n", t);
	// ft_printf("minee[%020.5p] \n", t);

	return (1);
}
