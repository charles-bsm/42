/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:01:51 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 15:32:20 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

// void del_content(void *content)
// {
//     free(content);
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew(strdup("Bonjour"));
// 	lst->next = ft_lstnew(strdup("Salut"));
// 	lst->next->next = ft_lstnew(strdup("Hello"));

// 	printf("Avant suppression :\n");
// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
// 	printf("%s\n", (char *)lst->next->next->content);

// 	ft_lstclear(&lst, del_content);

// 	printf("\nApres suppression :\n");
// 	if (lst == NULL)
// 		printf("La liste est NULL ! Tout a ete supprime.\n");
// 	else
// 		printf("Erreur : la liste existe encore.\n");

// 	return (0);
// }