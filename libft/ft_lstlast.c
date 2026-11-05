/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:30:42 by chbeseme          #+#    #+#             */
/*   Updated: 2026/10/30 18:41:14 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = NULL;

// 	if (ft_lstlast(&a) == &c)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");

// 	return (0);
// }
