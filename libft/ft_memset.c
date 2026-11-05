/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:28:21 by chbeseme          #+#    #+#             */
/*   Updated: 2026/10/21 14:59:29 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	int str[255] = {0};

// 	str[0] = 1;
// 	str[1] = 2;
// 	str[2] = 3;
// 	str[3] = 4;
// 	str[4] = 5;
// 	str[5] = 6;
// 	str[6] = 7;
// 	ft_memset(str, 3, 3);
// 	printf("%d", str[0]);
// 	printf("%d", str[1]);
// 	printf("%d", str[2]);
// 	printf("%d", str[3]);
// 	printf("%d", str[4]);
// 	printf("%d", str[5]);
// 	printf("%d", str[6]);
// 	return 0;
// }
