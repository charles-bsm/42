/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavenel <tavenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:20:01 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/10 16:45:03 by tavenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(int *tab, int size)
{
	int	last;
	int	i;

	if (size < 2)
		return ;
	last = tab[size - 1];
	i = size - 1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = last;
}

void	rra(int *a, int size_a)
{
	reverse_rotate(a, size_a);
	write(1, "rra\n", 4);
}

void	rrb(int *b, int size_b)
{
	reverse_rotate(b, size_b);
	write(1, "rrb\n", 4);
}

void	rrr(int *a, int *b, int size_a, int size_b)
{
	reverse_rotate(a, size_a);
	reverse_rotate(b, size_b);
	write(1, "rrr\n", 4);
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
// 	int	b[5] = {10, 20, 30};

// 	print_stack("a", a, 5);
// 	print_stack("b", b, 3);

// 	printf("\n--- rra ---\n");
// 	rra(a, 5);
// 	print_stack("a", a, 5);

// 	printf("\n--- rrb ---\n");
// 	rrb(b, 3);
// 	print_stack("b", b, 3);

// 	printf("\n--- rrr ---\n");
// 	rrr(a, b, 5, 3);
// 	print_stack("a", a, 5);
// 	print_stack("b", b, 3);

// 	printf("\n--- rra avec 1 element (ne doit rien changer) ---\n");
// 	rra(a, 1);
// 	print_stack("a", a, 5);

// 	printf("\n--- rrb x3 sur b (un tour complet) ---\n");
// 	rrb(b, 3);
// 	rrb(b, 3);
// 	rrb(b, 3);
// 	print_stack("b", b, 3);
// 	return (0);
// }
