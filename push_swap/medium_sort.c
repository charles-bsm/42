/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:08:54 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/19 13:29:55 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static int	find_max(int *b, int size)
{
	int	i;
	int	max_i;

	max_i = 0;
	i = 1;
	while (i < size)
	{
		if (b[i] > b[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

static void	bring_max_top(t_stacks *s)
{
	int	i;
	int	pos;

	pos = find_max(s->b, s->size_b);
	if (pos <= s->size_b / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(s);
	}
	else
	{
		i = pos;
		while (i++ < s->size_b)
			rrb(s);
	}
}

static void	push_chunks(t_stacks *s)
{
	int	chunk;
	int	limit;

	chunk = ft_isqrt(s->size_a);
	limit = chunk;
	while (s->size_a > 0)
	{
		if (s->a[0] < limit)
		{
			pb(s);
			if (s->size_b > 1 && s->b[0] < limit - chunk / 2)
				rb(s);
		}
		else
			ra(s);
		if (s->size_b == limit)
			limit += chunk;
	}
}

void	sort_medium(t_stacks *s)
{
	push_chunks(s);
	while (s->size_b > 0)
	{
		bring_max_top(s);
		pa(s);
	}
}
