/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 22:55:40 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/05 23:24:31 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i + 1] == '%')
			return -1;
		else
			ft_putchar(format[i]);
		i++;
	}
	return 0;
}

int main(void) {
	printf("\n%d", printf("salut coucou %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %s", "123456790"));
	return 0;
}