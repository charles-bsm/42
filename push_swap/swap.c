/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:33:06 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/16 18:18:14 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *tab, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sa(t_stacks *s)
{
	swap(s->a, s->size_a);
	ft_op(s, OP_SA);
}

void	sb(t_stacks *s)
{
	swap(s->b, s->size_b);
	ft_op(s, OP_SB);
}

void	ss(t_stacks *s)
{
	swap(s->a, s->size_a);
	swap(s->b, s->size_b);
	ft_op(s, OP_SS);
}

// void	print_stack(char *name, int *tab, int size)
// {
// 	int	i;

// 	printf("%s : ", name);
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

// 	printf("\n--- sa ---\n");
// 	sa(a, 5);
// 	print_stack("a", a, 5);

// 	printf("\n--- sb ---\n");
// 	sb(b, 3);
// 	print_stack("b", b, 3);

// 	printf("\n--- ss (doit tout remettre dans l'ordre initial) ---\n");
// 	ss(a, b, 5, 3);
// 	print_stack("a", a, 5);
// 	print_stack("b", b, 3);

// 	printf("\n--- sa avec 1 seul element (ne doit rien changer) ---\n");
// 	sa(a, 1);
// 	print_stack("a", a, 5);

// 	printf("\n--- sa avec pile vide (ne doit rien changer) ---\n");
// 	sa(a, 0);
// 	print_stack("a", a, 5);
// 	return (0);
// }
