/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesbeseme <charlesbeseme@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:53:12 by charlesbese       #+#    #+#             */
/*   Updated: 2026/11/11 19:05:03 by charlesbese      ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	*a;
	int	type;

	if (argc < 3)
		return (write(2, "Error\n", 6), 1);
	type = ft_is_valid_type(argv[1]);
	if (type == 0)
		return (write(2, "Error\n", 6), 1);
	a = ft_parser(argc, argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	free(a);
	return (0);
}
