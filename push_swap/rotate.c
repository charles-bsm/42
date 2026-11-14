/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavenel <tavenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:04:43 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/10 16:46:30 by tavenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *tab, int size)
{
	int	first;
	int	i;

	if (size < 2)
		return ;
	first = tab[0];
	i = 0;
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[size - 1] = first;
}

void	ra(int *a, int size_a)
{
	rotate(a, size_a);
	write(1, "ra\n", 3);
}

void	rb(int *b, int size_b)
{
	rotate(b, size_b);
	write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int size_a, int size_b)
{
	rotate(a, size_a);
	rotate(b, size_b);
	write(1, "rr\n", 3);
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

// 	printf("\n--- ra ---\n");
// 	ra(a, 5);
// 	print_stack("a", a, 5);

// 	printf("\n--- rb ---\n");
// 	rb(b, 3);
// 	print_stack("b", b, 3);

// 	printf("\n--- rr ---\n");
// 	rr(a, b, 5, 3);
// 	print_stack("a", a, 5);
// 	print_stack("b", b, 3);

// 	printf("\n--- ra avec 1 element (ne doit rien changer) ---\n");
// 	ra(a, 1);
// 	print_stack("a", a, 5);

// 	printf("\n--- ra x3 sur b
// 	rb(b, 3);
// 	rb(b, 3);
// 	rb(b, 3);
// 	print_stack("b", b, 3);
// 	return (0);
// }
