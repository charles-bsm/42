/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:48:56 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/17 15:02:56 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_disorder(double d)
{
	long	v;

	v = (long)(d * 10000 + 0.5);
	ft_putnbr_fd(v / 100, 2);
	write(2, ".", 1);
	if (v % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(v % 100, 2);
	write(2, "%\n", 2);
}

static void	ft_print_strategy(int type, double disorder)
{
	static const char	*const names[5] = {"", "Simple", "Medium",
		"Complex", "Adaptive"};
	static const char	*const cplx[5] = {"", "O(n²)", "O(n√n)",
		"O(n log n)", ""};

	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(names[type], 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(cplx[ft_effective(type, disorder)], 2);
	write(2, "\n", 1);
}

static void	ft_print_range(t_stacks *s, int from, int to)
{
	ft_putstr_fd("[bench] ", 2);
	while (from < to)
	{
		ft_putstr_fd(ft_op_name(from), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(s->ops[from], 2);
		if (from < to - 1)
			ft_putstr_fd("  ", 2);
		from++;
	}
	write(2, "\n", 1);
}

void	ft_bench(t_stacks *s, int type, double disorder)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
		total += s->ops[i++];
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_print_disorder(disorder);
	ft_print_strategy(type, disorder);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
	ft_print_range(s, OP_SA, OP_RA);
	ft_print_range(s, OP_RA, OP_COUNT);
}
