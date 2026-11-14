/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:42:45 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/13 16:31:57 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	find_min(int *a, int size)
{
	int	i;
	int	min_i;

	min_i = 0;
	i = 1;
	while (i < size)
	{
		if (a[i] < a[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

static void	bring_to_top(int *a, int size_a, int pos)
{
	int	i;

	if (pos <= size_a / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a, size_a);
	}
	else
	{
		i = pos;
		while (i++ < size_a)
			rra(a, size_a);
	}
}

void	sort_simple(int *a, int *b, int *size_a, int *size_b)
{
	while (*size_a > 1 && !is_sorted(a, *size_a))
	{
		bring_to_top(a, *size_a, find_min(a, *size_a));
		print_stacks(a, b, *size_a, *size_b);
		pb(a, b, size_a, size_b);
		print_stacks(a, b, *size_a, *size_b);
	}
	while (*size_b > 0)
	{
		pa(a, b, size_a, size_b);
		print_stacks(a, b, *size_a, *size_b);
	}
}
