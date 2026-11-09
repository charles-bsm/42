/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeseme <chbeseme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:57:54 by chbeseme          #+#    #+#             */
/*   Updated: 2026/11/09 14:03:45 by chbeseme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char format);
int		ft_print_ptr(void *ptr);

#endif
