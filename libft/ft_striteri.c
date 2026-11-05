/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:32:58 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 13:47:30 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	test(unsigned int index, char *c)
// {
// 	(void)index;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

// int	main(void)
// {
// 	char	str[] = "bonjour";

// 	printf("Avant : %s\n", str);
// 	ft_striteri(str, test);
// 	printf("Après : %s\n", str);
// 	return (0);
// }