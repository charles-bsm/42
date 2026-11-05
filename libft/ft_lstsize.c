/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:10 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 13:49:13 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = NULL;

// 	printf("Taille de la liste : %d\n", ft_lstsize(&a));
// 	return (0);
// }
