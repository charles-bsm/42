/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:48:38 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/10 16:37:45 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_is_valid_type(char *type)
{
	if (ft_strcmp(type, "--simple") == 0)
		return (0);
	if (ft_strcmp(type, "--medium") == 0)
		return (0);
	if (ft_strcmp(type, "--complex") == 0)
		return (0);
	return (1);
}

static int	ft_is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	*ft_parser(int argc, char **argv)
{
	int	i;
	int	*a;

	(void)i;
	(void)argc;
	if (ft_type(argv[1]) == 1)
	{
		printf("type inconnu, retour => %d", ft_type(argv[1]));
		return (NULL);
	}
	a = malloc(sizeof(int) * (argc - 2));
	if (!a)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		a[i - 2] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (a[i])
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Erreur");
		return (1);
	}
	ft_parser(argc, argv);
	return (0);
}
