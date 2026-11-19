/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:47:14 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/19 13:26:21 by chbeseme         ###   ########.fr       */
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

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef enum e_type
{
	T_SIMPLE = 1,
	T_MEDIUM,
	T_COMPLEX,
	T_ADAPTIVE
}	t_type;

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	ops[OP_COUNT];
}	t_stacks;

void		sa(t_stacks *s);
void		sb(t_stacks *s);
void		ss(t_stacks *s);
void		pa(t_stacks *s);
void		pb(t_stacks *s);
void		ra(t_stacks *s);
void		rb(t_stacks *s);
void		rr(t_stacks *s);
void		rra(t_stacks *s);
void		rrb(t_stacks *s);
void		rrr(t_stacks *s);
void		sort_simple(t_stacks *s);
void		sort_medium(t_stacks *s);
void		sort_complex(t_stacks *s);
void		ft_op(t_stacks *s, int op);
const char	*ft_op_name(int op);
int			ft_effective(int type, double disorder);
void		ft_bench(t_stacks *s, int type, double disorder);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
double		compute_disorder(int *tab, int size);
int			ft_strcmp(char *s1, char *s2);
int			*ft_parser(int count, char **nums);
int			*ft_normalize(int *a, int size);

#endif