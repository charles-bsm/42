/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:38:56 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 21:08:34 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	ft_del(void *content)
// {
// 	free(content);
// }

// void	*ft_toupper_list(void *content)
// {
// 	char	*str;
// 	char	*new_str;
// 	int		i;

// 	str = (char *)content;
// 	new_str = malloc(strlen(str) + 1);
// 	if (!new_str)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		new_str[i] = toupper((unsigned char)str[i]);
// 		i++;
// 	}
// 	new_str[i] = '\0';
// 	return (new_str);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new_lst;
// 	t_list	*tmp;

// 	lst = NULL;
// 	ft_lstadd_back(&lst, ft_lstnew(strdup("bonjour")));
// 	ft_lstadd_back(&lst, ft_lstnew(strdup("comment")));
// 	ft_lstadd_back(&lst, ft_lstnew(strdup("ca va")));

// 	new_lst = ft_lstmap(lst, ft_toupper_list, ft_del);

// 	printf("Liste originale :\n");
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}

// 	printf("\nNouvelle liste :\n");
// 	tmp = new_lst;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}

// 	ft_lstclear(&lst, ft_del);
// 	ft_lstclear(&new_lst, ft_del);
// 	return (0);
// }
