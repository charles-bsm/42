/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 19:18:03 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 23:30:13 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*newstr;

	i = 0;
	j = 0;
	k = 0;
	newstr = malloc(sizeof(char) * ((ft_len(s1) + ft_len(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[k] = s1[i];
		i++;
		k++;
	}
	while (s2[j])
	{
		newstr[k] = s2[j];
		j++;
		k++;
	}
	newstr[k] = '\0';
	return (newstr);
}

// int main(void)
// {
// 	char const *s1 = "Justin ";
// 	char const *s2 = "l'amour de ma vie";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }
