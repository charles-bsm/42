/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:53:12 by charlesbese       #+#    #+#             */
/*   Updated: 2026/11/16 18:25:29 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_valid_type(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (T_SIMPLE);
	if (ft_strcmp(s, "--medium") == 0)
		return (T_MEDIUM);
	if (ft_strcmp(s, "--complex") == 0)
		return (T_COMPLEX);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (T_ADAPTIVE);
	return (0);
}

static int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	ft_flags(int argc, char **argv, int *bench, int *type)
{
	int	i;

	i = 1;
	*bench = 0;
	*type = T_ADAPTIVE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		else if (ft_is_valid_type(argv[i]))
			*type = ft_is_valid_type(argv[i]);
		else
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_solve(int *norm, int size, int type, int bench)
{
	t_stacks	s;
	double		disorder;
	int			i;

	s.a = norm;
	s.size_a = size;
	s.size_b = 0;
	s.b = malloc(sizeof(int) * size);
	if (!s.b)
		return (1);
	i = 0;
	while (i < OP_COUNT)
		s.ops[i++] = 0;
	disorder = compute_disorder(s.a, s.size_a);
	if (ft_effective(type, disorder) == T_SIMPLE)
		sort_simple(&s);
	else
		sort_complex(&s);
	if (bench)
		ft_bench(&s, type, disorder);
	free(s.b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*norm;
	int	type;
	int	bench;
	int	start;

	if (argc == 1)
		return (0);
	start = ft_flags(argc, argv, &bench, &type);
	if (start < 0 || start >= argc)
		return (ft_error());
	a = ft_parser(argc - start, argv + start);
	if (!a)
		return (ft_error());
	norm = ft_normalize(a, argc - start);
	free(a);
	if (!norm)
		return (ft_error());
	if (ft_solve(norm, argc - start, type, bench))
		return (free(norm), ft_error());
	free(norm);
	return (0);
}
