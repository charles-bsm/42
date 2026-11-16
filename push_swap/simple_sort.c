/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:42:45 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/16 18:20:17 by chbeseme         ###   ########.fr       */
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

static void	bring_to_top(t_stacks *s, int pos)
{
	int	i;

	if (pos <= s->size_a / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(s);
	}
	else
	{
		i = pos;
		while (i++ < s->size_a)
			rra(s);
	}
}

void	sort_simple(t_stacks *s)
{
	while (s->size_a > 1 && !is_sorted(s->a, s->size_a))
	{
		bring_to_top(s, find_min(s->a, s->size_a));
		pb(s);
	}
	while (s->size_b > 0)
		pa(s);
}
