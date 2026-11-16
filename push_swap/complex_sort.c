/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:32:23 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/16 18:20:44 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_complex(t_stacks *s)
{
	int	size;
	int	bit;
	int	i;

	size = s->size_a;
	bit = 0;
	while (bit < max_bits(size))
	{
		i = 0;
		while (i < size)
		{
			if (((s->a[0] >> bit) & 1) == 0)
				pb(s);
			else
				ra(s);
			i++;
		}
		while (s->size_b > 0)
			pa(s);
		bit++;
	}
}
