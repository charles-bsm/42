/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:33:36 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 19:14:41 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_word(const char *s, int *pos, char c)
{
	char	*word;
	int		len;
	int		save;
	int		i;

	len = 0;
	save = *pos;
	i = 0;
	while (s[*pos] && s[*pos] != c)
	{
		len++;
		*pos = *pos + 1;
	}
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (s[save] && s[save] != c)
	{
		word[i] = s[save];
		i++;
		save++;
	}
	word[i] = 0;
	return (word);
}

static int	count_word(char const *str, char sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (word);
}

static void	free_all(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = malloc_word(s, &i, c);
			if (!tab[j])
				return (free_all(tab, j), NULL);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

// int	main(void)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split("JC me manque <3", ' ');
// 	i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return 0;
// }
