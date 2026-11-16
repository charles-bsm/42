/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:47:58 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/16 15:48:00 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_effective(int type, double disorder)
{
	if (type != T_ADAPTIVE)
		return (type);
	if (disorder < 0.2)
		return (T_SIMPLE);
	if (disorder < 0.5)
		return (T_MEDIUM);
	return (T_COMPLEX);
}
