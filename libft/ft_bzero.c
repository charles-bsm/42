/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 23:13:21 by chbeseme          #+#    #+#             */
/*   Updated: 2026/10/21 14:59:12 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char str[255] = {0};

// 	// char *str = "dpasdsa"
// 	str[0] = 'b';
// 	str[1] = 'o';
// 	str[2] = 'n';
// 	str[3] = 'j';
// 	str[4] = 'o';
// 	str[5] = 'u';
// 	str[6] = 'r';
// 	ft_bzero(str, 3);
// 	printf("%c", str[0]);
// 	printf("%c", str[1]);
// 	printf("%c", str[2]);
// 	printf("%c", str[3]);
// 	printf("%c", str[4]);
// 	printf("%c", str[5]);
// 	printf("%c", str[6]);
// 	return 0;
// }
