/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:31:07 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/03 16:28:26 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_len(src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size -1)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
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

// 	printf("%ld", ft_strlcpy(dest, src, 5));
// 	return 0;
// }
