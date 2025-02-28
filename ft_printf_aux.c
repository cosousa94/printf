/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaoli <carlaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:34 by carlaoli          #+#    #+#             */
/*   Updated: 2024/11/29 11:39:30 by carlaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int				count;
	unsigned long	ptr2;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	ptr2 = (unsigned long)ptr;
	write(1, "0x", 2);
	count = ft_print_hex_lower(ptr2);
	return (count + 2);
}

int	ft_printnbr(int n)
{
	char	number;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_printnbr(n / 10);
	}
	number = n % 10 + '0';
	write(1, &number, 1);
	count++;
	return (count);
}

int	ft_print_unsigned_nbr(unsigned int n)
{
	char	number;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += ft_print_unsigned_nbr(n / 10);
	}
	number = n % 10 + '0';
	write(1, &number, 1);
	count++;
	return (count);
}

int	ft_print_hex_lower(unsigned long n)
{
	char	number;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_lower(n / 16);
	}
	number = "0123456789abcdef"[n % 16];
	write(1, &number, 1);
	count++;
	return (count);
}

int	ft_print_hex_upper(unsigned long n)
{
	char	number;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_upper(n / 16);
	}
	number = "0123456789ABCDEF"[n % 16];
	write(1, &number, 1);
	count++;
	return (count);
}
