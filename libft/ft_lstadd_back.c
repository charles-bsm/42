/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:42:03 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 15:32:36 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

// int	main(void)
// {
// 	t_list *lst;

// 	lst = ft_lstnew("Bonjour");

// 	ft_lstadd_back(&lst, ft_lstnew("Salut"));
// 	ft_lstadd_front(&lst, ft_lstnew("42"));

// 	while (lst)
// 	{
// 	printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }
