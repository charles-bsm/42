/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 23:15:07 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 13:50:12 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *elem1 = ft_lstnew("deuxieme");
//     t_list *elem2 = ft_lstnew("premier");

//     ft_lstadd_front(&head, elem1);
//     ft_lstadd_front(&head, elem2);

//     if (head == elem2 && head->next == elem1)
//         printf("OK\n");
//     else
//         printf("FAIL\n");

//     free(elem1);
//     free(elem2);
//     return (0);
// }