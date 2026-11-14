/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavenel <tavenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:38:02 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/13 11:14:56 by tavenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_normalize(int *a, int size)
{
	int	*norm;
	int	i;
	int	j;
	int	rank;

	norm = malloc(sizeof(int) * size);
	if (!norm)
		return (NULL);
	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (a[j] < a[i])
				rank++;
			j++;
		}
		norm[i] = rank;
		i++;
	}
	return (norm);
}
// k = 0;
// while (k < size)
// {
// 	printf("\t%d", norm[k]);
// 	k++;
// }
// printf("\n");
