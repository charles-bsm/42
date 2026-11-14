/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:29:09 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/13 14:29:21 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *a, int *b, int size_a, int size_b)
{
	int	i;

	fprintf(stderr, "a : ");
	i = 0;
	while (i < size_a)
		fprintf(stderr, "%d ", a[i++]);
	fprintf(stderr, "\nb : ");
	i = 0;
	while (i < size_b)
		fprintf(stderr, "%d ", b[i++]);
	fprintf(stderr, "\n---\n");
}
