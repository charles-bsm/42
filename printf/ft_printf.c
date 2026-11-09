/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 22:55:40 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/09 14:03:07 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_dispatch(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
int	main(void)
{
	int	x = 42;
	int	a;
	int	b;

	a = ft_printf("ft : [%c%c]\n", 'a', 'b');
	b = printf("std: [%c%c]\n", 'a', 'b');
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%s|%s]\n", "hello", "");
	b = printf("std: [%s|%s]\n", "hello", "");
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%s]\n", (char *)NULL);
	b = printf("std: [%s]\n", (char *)NULL);
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%p|%p]\n", &x, (void *)NULL);
	b = printf("std: [%p|%p]\n", &x, (void *)NULL);
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%d|%d|%d|%i]\n", 0, INT_MAX, INT_MIN, -42);
	b = printf("std: [%d|%d|%d|%i]\n", 0, INT_MAX, INT_MIN, -42);
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%u|%u]\n", 0u, UINT_MAX);
	b = printf("std: [%u|%u]\n", 0u, UINT_MAX);
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [%x|%X|%x]\n", 0, 255, UINT_MAX);
	b = printf("std: [%x|%X|%x]\n", 0, 255, UINT_MAX);
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	a = ft_printf("ft : [100%%]\n");
	b = printf("std: [100%%]\n");
	printf("%s (%d / %d)\n\n", a == b ? "OK" : "KO", a, b);

	return (0);
}
