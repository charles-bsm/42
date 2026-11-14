/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:47:14 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/13 16:43:50 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>

void	sa(int *a, int size_a);
void	sb(int *b, int size_b);
void	ss(int *a, int *b, int size_a, int size_b);
void	pa(int *a, int *b, int *size_a, int *size_b);
void	pb(int *a, int *b, int *size_a, int *size_b);
void	ra(int *a, int size_a);
void	rb(int *b, int size_b);
void	rr(int *a, int *b, int size_a, int size_b);
void	rra(int *a, int size_a);
void	rrb(int *b, int size_b);
void	rrr(int *a, int *b, int size_a, int size_b);
void	sort_simple(int *a, int *b, int *size_a, int *size_b);
void	sort_complex(int *a, int *b, int *size_a, int *size_b);
double	compute_disorder(int *tab, int size);
int	ft_strcmp(char *s1, char *s2);
int	*ft_parser(int argc, char **argv);
int	*ft_normalize(int *a, int size);
void	print_stacks(int *a, int *b, int size_a, int size_b);

#endif
