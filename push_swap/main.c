/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:53:12 by charlesbese       #+#    #+#             */
/*   Updated: 2026/11/13 16:49:12 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_valid_type(char *type)
{
	if (ft_strcmp(type, "--simple") == 0)
		return (1);
	if (ft_strcmp(type, "--medium") == 0)
		return (2);
	if (ft_strcmp(type, "--complex") == 0)
		return (3);
	return (0);
}

static int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int *norm;
	int	size_a;
	int	size_b;
	int	type;

	if (argc < 3)
		return (ft_error());
	type = ft_is_valid_type(argv[1]);
	if (type == 0)
		return (ft_error());
	a = ft_parser(argc, argv);
	if (!a)
		return (ft_error());
	size_a = argc - 2;
	size_b = 0;
	b = malloc(sizeof(int) * size_a);
	if (!b)
		return (free(a), ft_error());
	norm = ft_normalize(a, size_a);
	free(a);
	if (!norm)
		return (free(b), ft_error());
	if (type == 1)
		sort_simple(norm, b, &size_a, &size_b);
	if (type == 3)
		sort_complex(norm, b, &size_a, &size_b);
	int	i;

	i = 0;
	while (i < size_a)
	{
		printf("%d\t", norm[i]);
		i++;
	}
	free(norm);
	free(b);
	return (0);
}
