/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:32:23 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/13 16:42:39 by chbeseme         ###   ########.fr       */
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

void	sort_complex(int *a, int *b, int *size_a, int *size_b)
{
	int	size;
	int	bit;
	int	i;

	size = *size_a;
	bit = 0;
	while (bit < max_bits(size))
	{
		i = 0;
		while (i < size)
		{
			if (((a[0] >> bit) & 1) == 0)
				pb(a, b, size_a, size_b);
			else
				ra(a, *size_a);
			i++;
		}
		while (*size_b > 0)
			pa(a, b, size_a, size_b);
		bit++;
	}
}
