/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:58:47 by chbeseme          #+#    #+#             */
/*   Updated: 2026/10/21 16:22:20 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char str[] = "bonjour ca va ?";
// 	printf("%p\n", ft_memchr(str, '\0', 18));
// 	printf("%p\n", memchr(str, '\0', 18));
// 	return (0);
// }
