/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:59:28 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/03 00:15:12 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[10];
// 	char	dest[10];

// 	src[0] = 's';
// 	src[1] = 'a';
// 	src[2] = 'l';
// 	src[3] = 'u';
// 	src[4] = 't';

// 	dest[0] = 'b';
// 	dest[1] = 'o';
// 	dest[2] = 'n';
// 	dest[3] = 'j';
// 	dest[4] = 'o';
// 	dest[5] = 'u';
// 	dest[6] = 'r';

// 	memcpy(dest, src, 20);
// 	printf("%c", dest[0]);
// 	printf("%c", dest[1]);
// 	printf("%c", dest[2]);
// 	printf("%c", dest[3]);
// 	printf("%c", dest[4]);
// 	printf("%c", dest[5]);
// 	printf("%c", dest[6]);
// 	return 0;
// }
