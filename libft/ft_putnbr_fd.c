/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:39:26 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/02 23:15:26 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_char('-', fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		ft_putnbr_fd((int)(nb % 10), fd);
	}
	else
	{
		ft_char(nb + 48, fd);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(-123456, 1);
// 	return (0);
// }
