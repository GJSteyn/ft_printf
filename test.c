/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:23:43 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/21 13:48:50 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	setlocale(LC_ALL, "");

	int i;
	int j;
	// printf("their[%10C]\n", L'1');
	// ft_printf("minee[%10C]\n", L'1');
	// printf("---------------------\n");
	// printf("their[%-10S]\n", L"123©");
	// ft_printf("minee[%-10S]\n", L"123©");
	// printf("---------------------\n");
	// printf("their[%.*d]\n", 5, 2);
	// ft_printf("minee[%.*d]\n", 5, 2);
	// printf("---------------------\n");
	// printf("their[%llu, %llu]\n", 0, ULLONG_MAX);
	// ft_printf("minee[%llu, %llu]\n", 0, ULLONG_MAX);
	// printf("---------------------\n");
	// printf("their[%.p, %.0p]\n", 0, 0);
	// ft_printf("minee[%.p, %.0p]\n", 0, 0);
	// printf("---------------------\n");
	// printf("their{%05.c}\n", 0);
	// ft_printf("minee{%05.c}\n", 0);
	// printf("---------------------\n");
	// printf("their{%05.s}\n", 0);
	// ft_printf("minee{%05.s}\n", 0);
	// printf("---------------------\n");
	// printf("their[%+C]\n", 0);
	// ft_printf("minee[%+C]\n", 0);
	// printf("---------------------\n");
	// printf("their[%ld]\n", LONG_MIN);
	// ft_printf("minee[%ld]\n", LONG_MIN);
	// printf("---------------------\n");
	// printf("their[%lc, %lc]\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// ft_printf("minee[%lc, %lc]\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// printf("---------------------\n");
	// printf("%d\n", i);
	// printf("%d\n", j);
	// i = printf("their[%S]\n", L"我是一只猫。");
	// j = ft_printf("minee[%S]\n", L"我是一只猫。");
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("---------------------\n");
	// printf("their[%.4S]\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// ft_printf("minee[%.4S]\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// printf("---------------------\n");
	// printf("their{%-15ZZZ}\n", 123);
	// ft_printf("minee{%-15ZZZ}\n", 123);
	// printf("---------------------\n");
	// printf("their[%hhO, %hhO]\n", 0, USHRT_MAX);
	// ft_printf("minee[%hhO, %hhO]\n", 0, USHRT_MAX);
	// printf("---------------------\n");
	// printf("their[%.u, %.0u]\n", 0, 0);
	// ft_printf("minee[%.u, %.0u]\n", 0, 0);
	// printf("---------------------\n");
	i = printf("%");
	j = ft_printf("%");
	printf("%d\n", i);
	printf("%d\n", j);
	// printf("---------------------\n");
	// printf("their{%05p}\n", 0);
	// ft_printf("minee{%05p}\n", 0);
	// printf("---------------------\n");
	// printf("their[%.5p]\n", 0);
	// ft_printf("minee[%.5p]\n", 0);
	// printf("---------------------\n");
	// printf("their{%*d}\n", -5, 42);
	// ft_printf("minee{%*d}\n", -5, 42);
	// printf("---------------------\n");
	// printf("their[%#o]\n", 0);
	// ft_printf("minee[%#o]\n", 0);
	// printf("---------------------\n");
	// printf("their{%*c}\n", -15, 0);
	// ft_printf("minee{%*c}\n", -15, 0);
	// printf("---------------------\n");
	// printf("their{%.*d}\n", -5, 42);
	// ft_printf("minee{%.*d}\n", -5, 42);
	// printf("---------------------\n");
	// printf("their{%.*s}\n", -5, "42");
	// ft_printf("minee{%.*s}\n", -5, "42");
	// printf("---------------------\n");
	// printf("their{%f}{%F}\n", -1.42, -1.42);
	// ft_printf("minee{%f}{%F}\n", -1.42, -1.42);
	// printf("---------------------\n");
	// printf("their{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// ft_printf("minee{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// printf("---------------------\n");
	// printf("their{% S}\n", L"(null)");
	// ft_printf("minee{% S}\n", L"(null)");
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("---------------------\n");
	// printf("their{% S}\n", NULL);
	// ft_printf("minee{% S}\n", NULL);
	// printf("---------------------\n");
	// i = printf("their{%.2S}\n", L"123456789");
	// j = ft_printf("minee{%.2S}\n", L"123456789");
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("---------------------\n");
	// printf("their[%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S]\n",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// ft_printf("minee[%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S]\n",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// printf("---------------------\n");
	// i = printf("their[%S", L"我是一只猫。]\n");
	// j = ft_printf("minee[%S", L"我是一只猫。]\n");
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("---------------------\n");
	// i = printf("their[%.4S\n", L"我是一只猫。]");
	// j = ft_printf("minee[%.4S\n", L"我是一只猫。]");
	// printf("%d\n", i);
	// printf("%d\n", j);

	// ft_putnbr(ft_strlen(test));
	// ft_putstr(test);
	// printf(29854, 0x7fff929d6380);
	// ft_printf(29854, 0x7fff929d6380);

	return (0);
}
