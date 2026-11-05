/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:28:03 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/03 16:57:26 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (little[j] != '\0' && big[i + j] == little[j]
				&& (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char big[] = "bonjour ca va ?";
// 	char little[] = "bonjour";
// 	printf("%s\n", ft_strnstr(big, little, 12));
// 	printf("%s\n", strnstr(big, little, 12));
// 	return 0;
// }
