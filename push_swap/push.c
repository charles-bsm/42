/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavenel <tavenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:29:11 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/10 16:47:07 by tavenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int *src, int *dst, int *size_src, int *size_dst)
{
	int	val;
	int	i;

	if (*size_src == 0)
		return ;
	val = src[0];
	i = *size_dst;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = val;
	(*size_dst)++;
	i = 0;
	while (i < *size_src - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*size_src)--;
}

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	push(b, a, size_b, size_a);
	write(1, "pa\n", 3);
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	push(a, b, size_a, size_b);
	write(1, "pb\n", 3);
}

// void	print_stack(char *name, int *tab, int size)
// {
// 	int	i;

// 	printf("%s (size %d) : ", name, size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[5];
// 	int	size_a = 5;
// 	int	size_b = 0;

// 	print_stack("a", a, size_a);
// 	print_stack("b", b, size_b);

// 	printf("\n--- pb x2 ---\n");
// 	pb(a, b, &size_a, &size_b);
// 	pb(a, b, &size_a, &size_b);
// 	print_stack("a", a, size_a);
// 	print_stack("b", b, size_b);

// 	printf("\n--- pa x1 ---\n");
// 	pa(a, b, &size_a, &size_b);
// 	print_stack("a", a, size_a);
// 	print_stack("b", b, size_b);
// 	return (0);
// }
