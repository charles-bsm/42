/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:21:12 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/05 09:12:39 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_slen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*newstr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (start >= (unsigned int)ft_slen(s))
		len = 0;
	if (len > ft_slen(s) - start)
		len = ft_slen(s) - start;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (i < start)
		i++;
	while (j < len)
	{
		newstr[j] = s[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

// int main(void)
// {
// 	char const *s = "123456789";
// 	unsigned int start = 2;
// 	size_t len = 5;
// 	printf("%s\n", ft_substr(s, start, len));
// 	return 0;
// }
