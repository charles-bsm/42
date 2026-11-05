/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 19:37:33 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/05 09:09:34 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_set(char const s1, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*empty_str(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	j = len(s1) - 1;
	i = 0;
	k = 0;
	while (s1[i] && is_set(s1[i], set) == 1)
		i++;
	while (j >= 1 && is_set(s1[j], set) == 1)
		j--;
	if (i > j)
		return (empty_str());
	newstr = malloc(sizeof(char) * (j - i + 2));
	if (!newstr)
		return (NULL);
	while ((s1[i]) && (i <= j))
	{
		newstr[k++] = s1[i++];
	}
	newstr[k] = '\0';
	return (newstr);
}

// int main(void)
// {
// 	char const *str = "aaaabbbabababaabJustin + Charles = <3abbbbaaabababaa";
// 	char const *set = "ab";
// 	char *trim = ft_strtrim(str, set);
// 	printf("%s\n", trim);
// 	free(trim);
// 	return 0;
// }