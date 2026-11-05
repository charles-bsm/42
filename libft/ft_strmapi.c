/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:02:28 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 13:47:14 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_mapi(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*result;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen_mapi(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[j] = f(j, s[i]);
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

// char	test(unsigned int index, char c)
// {
// 	(void)index;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char	*src = "bonjour";
// 	char	*res = ft_strmapi(src, test);

// 	printf("fonction test => %c\n", test(2, 'c'));
// 	printf("Chaîne d'origine => %s\n", src);
// 	printf("Chaîne modifiée  => %s\n", res);
// 	free(res);
// 	return (0);
// }