/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:36:17 by chbeseme          #+#    #+#             */
/*   Updated: 2026/10/24 18:58:34 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*dup;

	i = 0;
	dup = malloc(size * nmemb);
	if (!dup)
		return (NULL);
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	while (i < (nmemb * size))
	{
		dup[i] = 0;
		i++;
	}
	return (dup);
}

// int main(void)
// {
// 	unsigned char	*dup = ft_calloc(3, 8);
// 	unsigned char	*dup2 = calloc(3, 8);

// 	printf("%p\n", dup);
// 	printf("%p\n", dup2);
// 	free(dup);
// 	free(dup2);
// 	return 0;
// }
