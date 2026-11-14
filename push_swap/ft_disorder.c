/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavenel <tavenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:42:35 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/12 19:26:55 by tavenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *tab, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	if (size < 2)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (tab[i] > tab[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}

// int	main(void)
// {
// 	int	sorted[5] = {1, 2, 3, 4, 5};
// 	int	reversed[5] = {5, 4, 3, 2, 1};
// 	int	mixed[5] = {3, 1, 5, 2, 4};
// 	int	neg[5] = {-1, -5, -2, -3, -4};

// 	printf("%f\n", compute_disorder(sorted, 5));
// 	printf("%f\n", compute_disorder(reversed, 5));
// 	printf("%f\n", compute_disorder(mixed, 5));
// 	printf("%f\n", compute_disorder(neg, 5));
// 	return (0);
// }
