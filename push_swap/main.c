/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:53:12 by charlesbese       #+#    #+#             */
/*   Updated: 2026/11/12 17:50:32 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	int	*norm;
	int	type;

	if (argc < 3)
		return (ft_error());
	type = ft_is_valid_type(argv[1]);
	if (type == 0)
		return (ft_error());
	a = ft_parser(argc, argv);
	if (!a)
		return (ft_error());
	norm = ft_normalize(a, argc - 2);
	free(a);
	if (!norm)
		return (ft_error());
	free(norm);
	return (0);
}
