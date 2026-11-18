/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:20:01 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/17 15:01:07 by chbeseme         ###   ########.fr       */
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

void	rra(t_stacks *s)
{
	reverse_rotate(s->a, s->size_a);
	ft_op(s, OP_RRA);
}

void	rrb(t_stacks *s)
{
	reverse_rotate(s->b, s->size_b);
	ft_op(s, OP_RRB);
}

void	rrr(t_stacks *s)
{
	reverse_rotate(s->a, s->size_a);
	reverse_rotate(s->b, s->size_b);
	ft_op(s, OP_RRR);
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
