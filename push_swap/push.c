/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:29:11 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/19 13:53:54 by chbeseme         ###   ########.fr       */
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

void	pa(t_stacks *s)
{
	push(s->b, s->a, &s->size_b, &s->size_a);
	ft_op(s, OP_PA);
}

void	pb(t_stacks *s)
{
	push(s->a, s->b, &s->size_a, &s->size_b);
	ft_op(s, OP_PB);
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
