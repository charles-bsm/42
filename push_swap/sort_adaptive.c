/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:56:42 by tavenel           #+#    #+#             */
/*   Updated: 2026/11/19 13:30:26 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stacks *s)
{
	double	d;

	d = compute_disorder(s->a, s->size_a);
	if (d < 0.2)
		sort_simple(s);
	else if (d < 0.5)
		sort_medium(s);
	else
		sort_complex(s);
}
