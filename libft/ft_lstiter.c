/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:16:47 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 15:36:24 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	upper(void *content)
// {
// 	char	*str;
// 	int		i;

// 	str = (char *)content;
// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = str[i] - 32;
// 		i++;
// 	}
// }

// int main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew(strdup("bonjour"));
// 	lst->next = ft_lstnew(strdup("salut"));
// 	lst->next->next = ft_lstnew(strdup("hello"));

// 	ft_lstiter(lst, upper);

// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
// 	printf("%s\n", (char *)lst->next->next->content);

// 	ft_lstclear(&lst, free);
// 	return (0);
// }
