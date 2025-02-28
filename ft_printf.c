/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaoli <carlaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:52:40 by carlaoli          #+#    #+#             */
/*   Updated: 2024/11/29 11:39:53 by carlaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_get_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (c == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_get_format(str[i], args);
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}
// int main(void)
// {
// 	int ft_printf_return;
// 	int printf_original;
// 	char c;
// 	char *str;
// 	unsigned long *ptr;
// 	int n;
// 	unsigned int u;
// 	unsigned int hex_low;
// 	unsigned int hex_upper;

// 	c = 'A';
// 	str = "teste";
// 	ptr = NULL;
// 	n = 123;
// 	u = 1;
// 	hex_low = 123456;
// 	hex_upper = 123456;

// 	// ft_printf_return = ft_printf("o caractere é: %c\n", c);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("o caractere é: %c\n", c);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("a string é: %s\n", str);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("a string é: %s\n", str);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("o endereço é: %p\n", ptr);
// 	// ft_printf("o retorno é: %p\n", ptr);

// 	// printf_original = printf("o endereço é: %p\n", ptr);
// 	// printf("o retorno é: %p\n", ptr);

// 	// ft_printf_return = ft_printf("o número é: %d\n", n);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("o número é: %d\n", n);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("o unsigned é: %u\n", u);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("o unsigned é: %u\n", u);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("o hex_low é: %x\n", hex_low);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("o hex_low é: %x\n", hex_low);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("o hex_upper é: %X\n", hex_upper);
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("o hex_upper é: %X\n", hex_upper);
// 	// printf("o retorno é: %d\n", printf_original);

// 	// ft_printf_return = ft_printf("percent: %%\n");
// 	// ft_printf("o retorno é: %d\n", ft_printf_return);

// 	// printf_original = printf("percent: %%\n");
// 	// printf("o retorno é: %d\n", printf_original);
// 	return(0);
// }
