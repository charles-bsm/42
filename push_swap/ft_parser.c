/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:48:38 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/12 17:54:11 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

static int	ft_atoi(const char *s, int *out)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

static int	ft_double(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_fill(int *a, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (!ft_is_valid_number(argv[i])
			|| !ft_atoi(argv[i], &a[i - 2]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_parser(int argc, char **argv)
{
	int	size;
	int	*a;

	size = argc - 2;
	a = malloc(sizeof(int) * size);
	if (!a)
		return (NULL);
	if (!ft_fill(a, argc, argv) || ft_double(a, size))
	{
		free(a);
		return (NULL);
	}
	int	i;

	i = 0;
	while (i < size)
	{
		printf("\t%d", a[i]);
		i++;
	}
	printf("\n");
	return (a);
}
