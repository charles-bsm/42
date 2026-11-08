#include "printf.h"

int	ft_print_number(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_number(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}
