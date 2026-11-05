/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:25:50 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 15:00:54 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del_content(void *content)
// {
//     free(content);
// }

// int main(void)
// {
// 	t_list	*lst;

// 	lst = malloc(sizeof(t_list));
// 	if (!lst)
// 		return (1);

// 	lst->content = strdup("Bonjour");
// 	if (!lst->content)
// 	{
// 		free(lst);
// 		return (1);
// 	}

// 	lst->next = NULL;

// 	printf("Avant suppression : %s\n", (char *)lst->content);

// 	ft_lstdelone(lst, del_content);

// 	printf("Le maillon a ete supprime !\n");

// 	return (0);
// }